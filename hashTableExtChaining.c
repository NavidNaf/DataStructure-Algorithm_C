//each location in the table becomes the head of a linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct person
{
    char name[MAX_NAME];
    int age;
    struct person *next; //points to the next one
} person;

person *hashTable[TABLE_SIZE];

//hashtable initialize
bool initHashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = NULL;
    }
    //empty table
}

//printing the table
void printTable(void)
{
    printf("-----START-----\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i] == NULL)
        {
            printf("%i\t---- \n", i);
        }
        else
        {
            printf("%i\t", i);
            //prints each value in the linked list
            person *temp = hashTable[i];
            while (temp != NULL)
            {
                printf("%s - ", temp->name);
                temp = temp->next;
            }
            printf("\n");
        }
    }
    printf("-----END-----\n");
}

//making the hash function
unsigned int hashFunc(char *name)
{
    int length = strlen(name);
    unsigned int hashVal = 0;
    for (int i = 0; i < length; i++)
    {
        hashVal = hashVal + name[i];
        hashVal = hashVal * name[i];
        hashVal = (hashVal % MAX_NAME) % TABLE_SIZE;
    }
    return hashVal;
}

//inserting value in the hash table
bool hashTable_Insert(person *p)
{
    if (p == NULL)
    {
        return false;
    }
    int index = hashFunc(p->name);
    //after hashing the function, generates an index
    p->next = hashTable[index]; //persons next pointer points to the hashtable array
    hashTable[index] = p;       //hashtable index value is set
    return true;
}

//searching
person *search(char *name)
{
    int index = hashFunc(name);
    person *temp = hashTable[index]; //temp value to the head
    //comparing with the value and also running till null
    while (temp != NULL && strcmp(temp->name, name) != 0)
    {
        temp = temp->next;
    }

    return temp;
}

//delete
person *delete (char *name)
{
    int index = hashFunc(name);
    person *temp = hashTable[index]; //temp to head
    person *prev = NULL;             //prev to null
    while (temp != NULL && strcmp(temp->name, name) != 0)
    {
        prev = temp; //tracking the prev
        temp = temp->next;
    }

    if (temp == NULL)
    {
        return NULL;
    }
    if (prev == NULL) //prev becomes null means missed the value and if that happens change head to temp next
    {
        hashTable[index] = temp->next;
    }
    else //if not linked list fix, the prev next points to temp next, even if its null
    {
        prev->next = temp->next;
    }

    return temp;
}

int main(void)
{
    initHashTable();
    printTable();

    person jacob = {.name = "jacob", .age = 25};
    person kate = {.name = "kate", .age = 23};
    person hamim = {.name = "hamim", .age = 21};
    person selim = {.name = "selim", .age = 33};
    person naf = {.name = "naf", .age = 25};

    hashTable_Insert(&jacob);
    hashTable_Insert(&kate);
    hashTable_Insert(&hamim);
    hashTable_Insert(&selim);
    hashTable_Insert(&naf);

    printTable();

    person *temp = search("kate");

    if (temp == NULL)
    {
        printf("Not Found.");
    }
    else
    {
        printf("Found %s\n", temp->name);
    }

    delete ("hamim");
    printTable();

    person *temp2 = search("hamim");

    if (temp2 == NULL)
    {
        printf("Not Found.");
    }
    else
    {
        printf("Found %s\n", temp2->name);
    }

    //printTable();

    // printf("Jacob => %u\n", hashFunc("Jacob"));
    // printf("Kuddus => %u\n", hashFunc("Kuddus"));
    // printf("Elahi => %u\n", hashFunc("Elahi"));
    // printf("Chikilaka => %u\n", hashFunc("Chikilaka"));
    // printf("Halum => %u\n", hashFunc("Halum"));
    // printf("Naf => %u\n", hashFunc("Naf"));
    // printf("Barsha => %u\n", hashFunc("Barsha"));
}