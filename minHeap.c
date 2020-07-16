#include <stdio.h>
#include <stdlib.h>

int leftChild(int i)
{
    return 2 * i;
}

int rightChild(int i)
{
    return 2 * i + 1;
}

int parent(int i)
{
    return i / 2;
}

void minHeap(int heap[], int heapSize, int i)
{
    int l = leftChild(i);
    int r = rightChild(i);
    int smallest, temp;

    if (l <= heapSize && heap[l] < heap[i])
    {
        smallest = l;
    }
    else
    {
        smallest = i;
    }
    if (r <= heapSize && heap[r] < heap[smallest])
    {
        smallest = r;
    }
    if (smallest != i)
    {
        temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        minHeap(heap, heapSize, smallest);
    }
}

void buildminHeap(int heap[], int heapSize)
{
    int i;
    for (i = heapSize / 2; i >= 1; i--)
    {
        minHeap(heap, heapSize, i);
    }
}

int main(void)
{
    int n;
    printf("Size(according to heap dimensions): ");
    scanf("%i", &n);
    int heap[n + 1];
    heap[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        printf("Value %i: ", i);
        scanf("%i", &heap[i]);
    }
    buildminHeap(heap, n);
    for (int i = 0; i <= n; i++)
    {
        printf("Value %i: %i \n", i, heap[i]);
    }
}