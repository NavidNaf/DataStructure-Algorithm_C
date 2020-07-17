#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct
{
    char name[MAX_NAME];
    int age;
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
            printf("%i\t%s\n", i, hashTable[i]->name);
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
    //hashes the names through the hash function and places in array (does not deal with the collision yet)
    int index = hashFunc(p->name);
    if (hashTable[index] != NULL)
    {
        return false;
        //returns false if collision happens
    }
    hashTable[index] = p;
    return true;
}

//open addressing
bool hashTable_InsertOpen(person *p)
{
    if (p == NULL)
    {
        return false;
    }
    //hashes the names through the hash function and places in array (does not deal with the collision yet)
    int index = hashFunc(p->name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int hash = ((i + index) % TABLE_SIZE);
        if (hashTable[hash] == NULL)
        {
            hashTable[hash] = p;
            return true;
        }
    }
    return false;
}

//searching
person *search(char *name)
{
    int index = hashFunc(name);
    if (hashTable[index] != NULL && strcmp(name, hashTable[index]->name) == 0)
    {
        return hashTable[index];
    }
    else
    {
        return NULL;
    }
}

//delete
person *delete (char *name)
{
    int index = hashFunc(name);
    if (hashTable[index] != NULL && strcmp(name, hashTable[index]->name) == 0)
    {
        person *temp = hashTable[index];
        hashTable[index] = NULL;
        return temp;
    }
    else
    {
        return NULL;
    }
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

    hashTable_InsertOpen(&jacob);
    hashTable_InsertOpen(&kate);
    hashTable_InsertOpen(&hamim);
    hashTable_InsertOpen(&selim);
    hashTable_InsertOpen(&naf);

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

    //delete ("kate");

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