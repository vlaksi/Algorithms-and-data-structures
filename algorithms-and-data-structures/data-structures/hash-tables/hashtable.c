#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>


#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person*)(0xFFFFFFUL)            // to mark all deleted node

// Our hashtable have information about people.
typedef struct{
    char name[MAX_NAME];
    int age;
    //... other stuff later, maybe
} person;

// Our hash table is array of pointers.
person *hashTable[TABLE_SIZE];

/* 
    Our hash-function give us hashValue.
    We get name and then for each character
    we add ascii value to hashValue.
*/
unsigned int hash(char *name){
    int length = strnlen(name, MAX_NAME);
    unsigned int hashValue = 0;

    for(int i = 0; i < length; i++){
        hashValue += name[i];
        hashValue = (hashValue * name[i])%TABLE_SIZE;           // just to get more random to our hash function
        // and hash value is between 0 and TABLE_SIZE

    }

    return hashValue;
}

// When two names map to same location in the table,
// that is collision.

void initHashTable(){
    for(int i = 0; i < TABLE_SIZE; i++){
        hashTable[i] = NULL;
    }
    // now is hashTable empty
}

void printTable(){
    printf("\n---------- START ----------\n");
    for(int i = 0; i < TABLE_SIZE; i++){
        if(hashTable[i] == NULL){
            printf("\t%i\t---\n",i);
        }else if(hashTable[i] == DELETED_NODE){
            printf("\t%i\t---<deleted>\n",i);
        }else{
            printf("\t%i\t%s\n",i,hashTable[i]->name);
        }
    }
    printf("\n----------- END -----------\n");
}

// We are handling collision with linear probing
// that include we just go and check for another free space.
bool insertPerson(person *p){
    if(p == NULL) return false;
    int index = hash(p->name);
    for(int i = 0; i < TABLE_SIZE; i++){
        int try = (i+index)%TABLE_SIZE;
        if(hashTable[try] == NULL){
            hashTable[try]=p;
            return true;
        }
    }
    return false;               // if we do not have free space
}

// Find a person in the table by their name [ this is O(1) ]
// we have little problem with collision because for loop 
// and we get O(n) for this type of handling with collision
// but with check for deleted node and null node we speed up
// this solution
person *findPerson(char *name){
    int index = hash(name);
    for(int i = 0; i < TABLE_SIZE; i++){
        int try = (index+i) % TABLE_SIZE;
        
        if(hashTable[try] == NULL) return NULL; // not there
        if(hashTable[try] == DELETED_NODE) continue;

        if(hashTable[try] != NULL && strncmp(hashTable[try]->name,name,TABLE_SIZE) == 0){
            return hashTable[try];
        }
    }
    return NULL;
}


// If we reat null node, there is no that Person
// but if we are at deleted_node, we go further
person *deletePerson(char *name){
    int index = hash(name);
    for(int i = 0; i < TABLE_SIZE; i++){
        int try = (index+i) % TABLE_SIZE;

        if(hashTable[try] == NULL) return NULL; // not there
        if(hashTable[try] == DELETED_NODE) continue;
        
        if(hashTable[try] != NULL && strncmp(hashTable[try]->name,name,TABLE_SIZE) == 0){
            person* tmp = hashTable[try];
            hashTable[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL;
}

int main(){
    initHashTable();
    

    // Test for insert
    person mico = {.name = "mico", .age=21};
    person jovo = {.name = "jovo", .age=36};
    person slobo = {.name = "slobo", .age=63};

    insertPerson(&mico);
    insertPerson(&jovo);
    insertPerson(&slobo);

    printTable();

    // Test for findPerson
    printf("Test for findPerson(mico)\n");
    person *tmp = findPerson("mico");
    if(tmp == NULL){
        printf("Not found !\n");
    }else{
        printf("%s is found.\n",tmp->name);
    }

    tmp = findPerson("dragan");
    if(tmp == NULL){
        printf("Not found !\n");
    }else{
        printf("%s is found.\n",tmp->name);
    }

    // Test for deletePerson
    printf("\nTest for deletePerson(mico)\n");
    deletePerson("mico");
    tmp = findPerson("mico");
    if(tmp == NULL){
        printf("Not found !\n");
    }else{
        printf("%s is found.\n",tmp->name);
    }
    
    // end
    printTable();

    // Now we represent handling with collison
    person siki = {.name = "siki", .age=21};
    person dovla = {.name = "dovla", .age=36};
    person maja = {.name = "maja", .age=63};
    person una = {.name = "una", .age=9};
    person ana = {.name ="dunav", .age=19};
    person zoka = {.name ="zoka", .age= 21};
    person kaja = {.name ="kaja", .age=22};
    person duca = {.name="duca",.age=24};

    insertPerson(&siki);
    insertPerson(&dovla);
    insertPerson(&maja);
    insertPerson(&una);
    insertPerson(&ana);
    insertPerson(&zoka);
    insertPerson(&kaja);
    insertPerson(&duca);
 
    printTable();

    deletePerson("siki");
    printf("\nAfter we delete 'siki' \n");
    printTable();

    return 0;
}