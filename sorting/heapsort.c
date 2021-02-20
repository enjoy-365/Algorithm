#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define DEBUG

void PrintDebug(const char* format, ...) {
#ifdef DEBUG
	va_list ap;
	va_start(ap, format);
	vprintf(format, ap);
	va_end(ap);
#endif
}

typedef int ElementType;
typedef struct HeapStruct* PriorityQueue;
struct HeapStruct {
	int capacity;// max heap capacity
	int size;// current heap size
	ElementType* elements;
};

PriorityQueue InitHeap(int heapsize);
void Insert(ElementType x, PriorityQueue h, FILE* fp2);
int Find(ElementType x, PriorityQueue h);
//int FindRecursive(ElementType x, PriorityQueue h);
void Print(PriorityQueue h, FILE* fp2);
int IsFull(PriorityQueue h);

int main() {

	FILE* fp1, * fp2;
	fp1 = fopen("input.txt", "r");
	fp2 = fopen("output.txt", "w");

	


	fclose(fp1);
	fclose(fp2);

	return 0;
}