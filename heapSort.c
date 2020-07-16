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

void maxHeap(int heap[], int heapSize, int i)
{
    int l = leftChild(i);
    int r = rightChild(i);
    int largest, temp;

    if (l <= heapSize && heap[l] > heap[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if (r <= heapSize && heap[r] > heap[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        maxHeap(heap, heapSize, largest);
    }
}

void buildmaxHeap(int heap[], int heapSize)
{
    int i;
    for (i = heapSize / 2; i >= 1; i--)
    {
        maxHeap(heap, heapSize, i);
    }
}

void heapSort(int heap[], int heapSize)
{
    int i, t;
    for (i = heapSize; i > 1; i--)
    {
        t = heap[1];
        heap[1] = heap[i];
        heap[i] = t;

        heapSize--;
        maxHeap(heap, heapSize, 1);
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
    buildmaxHeap(heap, n);
    for (int i = 0; i <= n; i++)
    {
        printf("Value %i: %i \n", i, heap[i]);
    }
    heapSort(heap, n);
    printf("Sorted Heap: ");
    for (int i = 0; i <= n; i++)
    {
        printf("Value %i: %i \n", i, heap[i]);
    }
}