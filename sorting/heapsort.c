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
int DeleteMin(PriorityQueue h, FILE* fp2);
int Find(ElementType x, PriorityQueue h);
//int FindRecursive(ElementType x, PriorityQueue h);
void Print(PriorityQueue h, FILE* fp2);
int IsFull(PriorityQueue h);
int IsEmpty(PriorityQueue h);

int main() {

	FILE* fp1, * fp2;
	fp1 = fopen("input.txt", "r");
	fp2 = fopen("output.txt", "w");

	


	fclose(fp1);
	fclose(fp2);

	return 0;
}

PriorityQueue InitHeap(int heapsize) {
	PriorityQueue h = (PriorityQueue)malloc(sizeof(struct HeapStruct));
	h->capacity = heapsize;
	h->size = 0;
	h->elements = (ElementType*)malloc(sizeof(int) * h->capacity);
}
void Insert(ElementType x, PriorityQueue h, FILE* fp2) {
	if (IsFull(h)) {
		fprintf(fp2, "heap is full\n");
		return;
	}
	//after testing find -> no identities then, insert.
	int i;
	for (i = ++h->size; (h->size >1)&&h->elements[i / 2] > x; i / 2) {
		h->elements[i] = h->elements[i / 2];
	}
	h->elements[i] = x;
	fprintf(fp2, "insert %d\n", x);
	return;
}
ElementType DeleteMin(PriorityQueue h, FILE* fp2) {
	if (IsEmpty(h)) {
		fprintf(fp2, "heap is empty\n");
		return -1;
	}

	ElementType minElement = h->elements[1];
	ElementType lastElement = h->elementsp[h->size--];
	
	//percolating down;
	for () {

	}
}
void Print(PriorityQueue h, FILE* fp2);
int IsFull(PriorityQueue h) {
	return h->capacity == h->size;
}
int IsEmpty(PriorityQueue h) {
	return h->size == 0;
}