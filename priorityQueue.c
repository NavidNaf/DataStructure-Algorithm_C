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

int extractMax(int heap[], int heapSize)
{
    int max = heap[1];
    heap[1] = heap[heapSize];
    heapSize--;
    maxHeap(heap, heapSize, 1);
    return max;
}

int insertNode(int heap[], int heapSize, int node)
{
    heapSize++;
    heap[heapSize] = node;
    int i, p, temp;
    i = heapSize;
    while (i > 1 && heap[i] > heap[parent(i)])
    {
        p = parent(i);

        temp = heap[p];
        heap[p] = heap[i];
        heap[i] = temp;

        i = p;
    }
    return heapSize;
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

    int newhsize = insertNode(heap, n, 24);
    for (int i = 0; i <= newhsize; i++)
    {
        printf("Value %i: %i \n", i, heap[i]);
    }
    int extract = extractMax(heap, n);
    printf("Extracted Value: %i", extract);
}