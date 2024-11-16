#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <random>
#include <chrono>

using namespace std;

// Class representing a Bank Account
class BankAccount {
private:
    int accountNumber;
    double balance;
    mutable std::mutex mtx; // Mutex for thread-safe operations

public:
    BankAccount(int accountNumber, double initialBalance) 
        : accountNumber(accountNumber), balance(initialBalance) {}

    // Deposit money
    void deposit(double amount) {
        std::lock_guard<std::mutex> lock(mtx);
        balance += amount;
        cout << "Account " << accountNumber << " Deposit: " << amount 
             << ", New Balance: " << balance << endl;
    }

    // Withdraw money
    bool withdraw(double amount) {
        std::lock_guard<std::mutex> lock(mtx);
        if (amount <= balance) {
            balance -= amount;
            cout << "Account " << accountNumber << " Withdraw: " << amount 
                 << ", New Balance: " << balance << endl;
            return true;
        } else {
            cout << "Account " << accountNumber << " Withdrawal Failed: Insufficient Funds\n";
            return false;
        }
    }

    // Get current balance
    double getBalance() const {
        std::lock_guard<std::mutex> lock(mtx);
        return balance;
    }
};

// Simulate deposit operations
void simulateDeposits(BankAccount& account, int numDeposits, double maxAmount) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1, maxAmount);

    for (int i = 0; i < numDeposits; ++i) {
        double amount = dis(gen);
        account.deposit(amount);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

// Simulate withdrawal operations
void simulateWithdrawals(BankAccount& account, int numWithdrawals, double maxAmount) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1, maxAmount);

    for (int i = 0; i < numWithdrawals; ++i) {
        double amount = dis(gen);
        account.withdraw(amount);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    // Create bank accounts
    vector<BankAccount> accounts = {
        BankAccount(1, 1000.0),
        BankAccount(2, 2000.0),
        BankAccount(3, 1500.0)
    };

    // Create threads for deposits and withdrawals for each account
    vector<thread> threads;
    for (auto& account : accounts) {
        threads.emplace_back(simulateDeposits, std::ref(account), 5, 500.0); // 5 deposits
        threads.emplace_back(simulateWithdrawals, std::ref(account), 5, 300.0); // 5 withdrawals
    }

    // Wait for all threads to complete
    for (auto& t : threads) {
        t.join();
    }

    // Display final balances
    cout << "\nFinal Balances:\n";
    for (const auto& account : accounts) {
        cout << "Account " << account.getBalance() << "\n";
    }

    return 0;
}
