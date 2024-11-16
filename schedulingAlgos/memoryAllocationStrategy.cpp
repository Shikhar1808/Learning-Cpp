#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MemoryChunk{
    public:
        int size;
        bool isFree;

        MemoryChunk(int size){
            this->size = size;
            this->isFree = true;
        }
};

class MemoryAllocator{
    vector<MemoryChunk> memoryChunks;
    int memorySize;

    public:
        void initializeMemory(int memorySize){
            this->memorySize = memorySize;
            memoryChunks.clear();
            memoryChunks.emplace_back(memorySize);
        }

        void displayMemoryState(){
            cout << "Current Memory State: "<<endl;
            cout<<"Index\tSize\tStatus"<<endl;
            for(int i=0; i<memoryChunks.size(); ++i){
                cout << i << "\t" << memoryChunks[i].size << "\t" << (memoryChunks[i].isFree ? "Free" : "Allocated") << endl;
            }
        }

        void firstFit(int blockSize){
            for(int i=0; i<memoryChunks.size(); ++i){
                if(memoryChunks[i].isFree && memoryChunks[i].size >= blockSize){
                    memoryChunks[i].isFree = false;

                    splittingMemoryChunks(i, blockSize);
                    return;
                }
            }
            cout << "Memory Allocation Failed!" << endl;
        }

        void bestFit(int blockSize){
            int index = -1;
            int minSize = memorySize + 1;
            for(int i=0; i<memoryChunks.size(); ++i){
                if(memoryChunks[i].isFree && memoryChunks[i].size >= blockSize && memoryChunks[i].size < minSize){
                    index = i;
                    minSize = memoryChunks[i].size;
                }
            }

            if(index == -1){
                cout << "Memory Allocation Failed!" << endl;
                return;
            }

            memoryChunks[index].isFree = false;

            splittingMemoryChunks(index, blockSize);
        }

        void worstFit(int blockSize){
            int index = -1;
            int maxSize = 0;

            for(int i=0; i<memoryChunks.size(); ++i){
                if(memoryChunks[i].isFree && memoryChunks[i].size >= blockSize && memoryChunks[i].size > maxSize){
                    index = i;
                    maxSize = memoryChunks[i].size;
                }
            }

            if(index == -1){
                cout << "Memory Allocation Failed!" << endl;
                return;
            }

            memoryChunks[index].isFree = false;

            splittingMemoryChunks(index, blockSize);
        }

        void splittingMemoryChunks(int index, int blockSize){
            if(memoryChunks[index].size > blockSize){ // Splitting the memory chunk
                memoryChunks.insert(memoryChunks.begin() + index + 1, MemoryChunk(memoryChunks[index].size - blockSize));
                memoryChunks[index].size = blockSize;
            }

            cout << "Memory Allocated Successfully!" << endl;
        }


        void deallocateMemory(int index){
            if(index < 0 || index >= memoryChunks.size()){
                cout << "Invalid Memory Index!" << endl;
                return;
            }

            if(memoryChunks[index].isFree){
                cout << "Memory is already free!" << endl;
                return;
            }

            memoryChunks[index].isFree = true;

            // Merging free memory chunks
            if(index > 0 && memoryChunks[index - 1].isFree){
                memoryChunks[index - 1].size += memoryChunks[index].size;
                memoryChunks.erase(memoryChunks.begin() + index);
                index--;
            }

            if(index < memoryChunks.size() - 1 && memoryChunks[index + 1].isFree){
                memoryChunks[index].size += memoryChunks[index + 1].size;
                memoryChunks.erase(memoryChunks.begin() + index + 1);
            }

            cout << "Memory Deallocated Successfully!" << endl;
        }
};

int main(){
    MemoryAllocator memoryAllocator;
    int memorySize = 100;
    memoryAllocator.initializeMemory(memorySize);

    while(true){
        cout<<"\nMemory Allocation Menu:\n";
        cout<<"1. Display Memory State\n";
        cout<<"2. Allocate Memory (First Fit)\n";
        cout<<"3. Allocate Memory (Best Fit)\n";
        cout<<"4. Allocate Memory (Worst Fit)\n";
        cout<<"5. Deallocate Memory\n";
        cout<<"6. Exit\n";

        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                memoryAllocator.displayMemoryState();
                break;
            case 2:
                int blockSize;
                cout<<"Enter the block size to allocate: ";
                cin>>blockSize;
                memoryAllocator.firstFit(blockSize);
                break;
            case 3:
                cout<<"Enter the block size to allocate: ";
                cin>>blockSize;
                memoryAllocator.bestFit(blockSize);
                break;
            case 4:
                cout<<"Enter the block size to allocate: ";
                cin>>blockSize;
                memoryAllocator.worstFit(blockSize);
                break;
            case 5:
                int index;
                cout<<"Enter the memory index to deallocate: ";
                cin>>index;
                memoryAllocator.deallocateMemory(index);
                break;
            case 6:
                cout<<"Exiting..."<<endl;
                return 0;
            default:
                cout<<"Invalid Choice!"<<endl;
        }
    }

    return 0;
}