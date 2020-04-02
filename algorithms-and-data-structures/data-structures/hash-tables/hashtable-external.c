#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>


#define MAX_NAME 256
#define TABLE_SIZE 10


// Our hashtable have information about people.
typedef struct person{
    char name[MAX_NAME];
    int age;
    
    struct person *next;
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
        }else{
            printf("\t%i\t",i);
            person *tmp = hashTable[i];
            while(tmp != NULL){
                printf("%s -> ", tmp->name);
                tmp = tmp -> next;
            }
            printf("\n");
        }
    }
    printf("\n----------- END -----------\n");
}

// Now we handling with collision with
// list of element at some position,
// we have list of lists
bool insertPerson(person *p){
    
    if(p == NULL) return false;
    int index = hash(p->name);
    p->next = hashTable[index];
    hashTable[index]=p;

    return true;
}

// Find person by the name
person *findPerson(char *name){
    int index = hash(name);
    person *tmp = hashTable[index];
    while(tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0){
        tmp = tmp->next;
    }
}


person *deletePerson(char *name){
   
    int index = hash(name);
    person *tmp = hashTable[index];
    person *prev = NULL;
    
    while(tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0){
        prev = tmp;
        tmp = tmp->next;
    }
    if(tmp == NULL) return NULL;
    if(prev == NULL){
        // deleting the head
        hashTable[index] = tmp->next;
    }else{
        prev->next = tmp->next;
    }

    return tmp;
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