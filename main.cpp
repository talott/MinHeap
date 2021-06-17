#include <iostream>
#include <fstream>
#include <stdio.h>
#include <ostream>
#include "heap.h"
#include "util.h"


int main() {
    char c;
    int count;
    int i;
    int n;
    int flag;
    FILE *ifile;
    int f;
    HEAP *heap;

    while(1){
        c = nextCommand(&n, &f, &flag, &i);
        switch (c) {
            case 's':
            case 'S':
               // printf("COMMAND: %c\n", c);
                exit(0); //stops program
            case 'c':
            case 'C':
                //printf("COMMAND: %c %d\n", c, n);
                heap = Initialize(n); //Creates a new heap
                break;
            case 'r':
            case 'R':
               // printf("COMMAND: %c\n", c);
                ifile = fopen("HEAPinput.txt", "r"); //open file in read mode

                // if file not opened
                if (!ifile){
                    std::cout << "Error: cannot open file for reading\n";
                    break;
                }

                fscanf(ifile, "%d", &n); //read first int  from file

                //if heap is null OR capacity < n, print heap overflow
                if(heap == NULL)
                {
                    std::cout << "Error: heap overflow\n";
                    break;
                }
                if ((*heap).capacity < n)
                {
                    std::cout << "Error: heap overflow\n";
                    break;
                }

                //Reads each number after first from file
                //allocates memory for ELEMENT

                //sets its key to the number from file
                //lets H in heap point to element
                int temp;
                //(*heap).size++;
                for (i=1; i<=n; i++) {
                    fscanf(ifile, "%d", &temp); //store the number in file into temp
                    (*heap).H[i] = (ElementT)malloc(sizeof(ELEMENT)); //dynamically allocates memory of element
                    (*heap).H[i]->key = temp; //sets key equal to number from file
                    (*heap).size++; //increases size of heap
                }

                //calls the buildheap
                counterZero(&count);
                buildHeap(*heap);
                //if flag = 1,
                if (flag == 1)
                {
                    //print the number of min-Heapify functions called by buildheap
                    count = returnHeapifyCounter(&count);
                    std::cout << "Number of Heapify calls: " << count << "\n";
                    counterZero(&count);
                }

                break;
            case 'p':
            case 'P':
               // printf("COMMAND: %c\n", c);

                //if heap is null
                if(heap == NULL)
                {
                    std::cout << "Error: heap is NULL\n";
                    break;
                }

                //Print out the heap
                printHeap(*heap);

                break;
            case 'w':
            case 'W':{
               // printf("COMMAND: %c\n", c);

                //opens file HEAPoutput.txt in write mode
                ifile = fopen("HEAPoutput.txt", "a");

                //if not opened, write "Error: cannot open file for writing" and break
                if(!ifile)
                {
                    std::cout << "Error: cannot write\n";

                    break;
                }
                //if heap is NULL "Error: heap is NULL" and break
                if(heap==NULL)
                {
                    std::cout << "Error: cannot write\n";
                    break;
                }

                //writeHeap(*heap);

                //write heap into into HEAPoutput.txt
                fprintf(ifile, "%d\n", heap->size+1);
                for (i=0; i<heap->size; i++) {
                    fprintf(ifile, "%d\n", ((*heap).H[i]->key));
                }
                break;}
            case 'd':
            case 'D':
               // printf("COMMAND: %c\n", c);

                //if heap is null or size is 0
                if(heap == NULL || heap->size==0)
                {
                    //print Error: heap is NULL or empty
                    std::cout << "Error: heap is NULL or empty\n";
                    break;
                }
                //delete min element from heap and write key of deleted element
                //ExtractMin(*heap);
                counterZero(&count);
                std::cout << "Deleted key: " << ExtractMin(*heap) <<"\n";
                heap->size--;
                //if flag == 1
                if (flag == 1)
                {
                    //print number of minheapify functions
                    count = returnHeapifyCounter(&count);
                    std::cout << "Number of Heapify calls: " << count << "\n";
                    counterZero(&count);
                }
                break;
            case 'i':
            case 'I':
              //  printf("COMMAND: %c\n", c);

                //if heap is null or size is 0
                if(heap == NULL || heap->size == heap->capacity) {
                    //print Error: heap is NULL or full
                    std::cout <<"Error: heap is NULL or full\n";
                    break;
                }
                //Allocate memory for element
                    //set key = to value and insert into heap
                (*heap).H[heap->size+1] = (ElementT)malloc(sizeof(ELEMENT));

                ELEMENT element;
                element.key = n;
                Insert(*heap, &element);
                heap->size++;
                break;
            case 'k':
            case 'K':
                // If heap is NULL or index is not within the interval[1, heap->size],
                // or value is greater than or equal to heap->H[index]->key,
                // writes the following line to stdout:
                    // Error: invalid call to DecreaseKey
                std::cin >> i >> n;
                //scanf("%d", n);
                if(heap == NULL)
                {
                    std::cout << "Error: invalid call to DecreaseKey\n";
                    break;
                }
                if(i < 1 || i > heap->size)
                {
                    std::cout << "Error: invalid call to DecreaseKey\n";
                    break;
                }
                if(n >= heap->H[i]->key)
                {
                    std::cout << "Error: invalid call to DecreaseKey\n";
                    break;
                }
                //decrease key tp value
                DecreaseKey(*heap, i, n);
                break;
            default:
                break;
        }
    }
    exit(0);
}

