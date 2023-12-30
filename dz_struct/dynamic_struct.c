#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Record{
    char surname[MAX_SIZE];
    int number;
    char faculty[MAX_SIZE];
    char group[MAX_SIZE];
    struct Record* next;
} Record;

/*void init(Record* obj);
void inputRecord(Record** table, char * surname, int number, char*faculty, char * group);
int count(Record* list_copy, char * surname);
void pop_from_position(Record* list, char* surname);
void printAll(Record* list_copy);
*/

/*
void init(Record* obj){
    printf("Surname:");
    scanf("%s", obj -> surname);
    printf("Credit card num:");
    scanf("%d", &obj -> number);
    printf("Faculty:");
    scanf("%s", obj -> faculty);
    printf("Group:");
    scanf("%s", obj -> group);
    inputRecord(obj, obj -> surname, obj -> number, obj -> faculty, obj -> group);
}*/

void inputRecord(Record** table, char * surname, int number, char*faculty, char * group){
    Record *tmp = (Record*)malloc (sizeof(Record));
    strcpy(tmp ->surname, surname);
    tmp -> number = number; 
    strcpy(tmp ->faculty, faculty);
    strcpy(tmp ->group, group);
    tmp -> next = *table;
    *table = tmp;
}

int count(Record* list_copy, char * surname) {
    int x = 0;
    for (; list_copy != NULL; list_copy = list_copy->next) 
        if (strcmp(list_copy -> surname, surname) != 0) 
        x++;   
        else{
            break;
        }
    return x;
}

void pop_from_position(Record* list, char* surname) {
    int position = count(list, surname);
    Record* list_copy = list;   
    Record* tmp = list_copy;  
    for (int i = 0; i < position; i++, list_copy = (list_copy)->next) 
        tmp = list_copy;  
    int res = list_copy->number;  
    tmp->next = list_copy->next;   
    free(list_copy);  
}

void printAll(Record* list_copy){
    for(;list_copy!=NULL; list_copy = list_copy->next){
        printf("Surname: %s\n", list_copy -> surname);
        printf("Credit card: %d\n", list_copy -> number);
        printf("faculty: %s\n", list_copy -> surname);
        printf("Group: %s\n", list_copy -> group);
    }
}

void saveTable(Record* table, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file) {
        for (; table != NULL; table = table->next) {
            fprintf(file, "%s %d %s %s\n", table -> surname, table -> number, table -> faculty, table -> group);
        }
        fclose(file);
        printf("Table saved to file\n");
    } else {
        printf("Open file error\n");
    }
}

void loadTable(Record* table, const char *filename) { //not working correctly
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        while (!feof(file)) {
            Record *tmp = (Record*)malloc (sizeof(Record));
            fscanf(file, "%s %d %s %s", tmp -> surname, &tmp -> number, tmp -> faculty, tmp -> group);
            table -> next = tmp;
        }
        fclose(file);
        printf("Table downoloaded\n");
    } else {
        printf("Open file error\n");
    }
}
/*
void sortTable(Record* table) {
    for (;table != NULL ; table = table -> next) {
        for (int j = 0; j < size - i - 1; j++) {
            if (table[j].group > table[j + 1].group) {
                Record temp = table[j];
                table[j] = table[j + 1];
                table[j + 1] = temp;
            }
        }
    }
    printf("Table sorted\n");
}
*/
int main (int argc, char * argv[]){
    Record* p_table = NULL;
    char surname[MAX_SIZE];
    int number;
    char faculty[MAX_SIZE];
    char group[MAX_SIZE];
    int func = 0;
    while(1){
        printf("1. Enter from keyboard\n");
        printf("2. Pull from file\n");
        printf("3. Push to file\n");
        printf("4. Print all\n");
        printf("5. Sort table\n");
        printf("6. Search for element\n");
        printf("7. Delete record\n");
        printf("8. Update\n");
        printf("9. Find to a given condition\n");
        printf("10. Exit\n");

        printf("Выберите действие: ");
        scanf("%d", &func);
    switch(func){
        case 1:
            printf("Surname:");
            scanf("%s", surname);
            printf("Credit card num:");
            scanf("%d", &number);
            printf("Faculty:");
            scanf("%s", faculty);
            printf("Group:");
            scanf("%s", group);
            inputRecord(&p_table, surname, number, faculty, group);
        break;
        case 2:
            loadTable(p_table, "table.txt"); 
        break;
        case 3:
            saveTable(p_table, "table.txt"); 
        break;
        case 4:
            printAll(p_table);
        break;
        case 5:
        break;
        case 6:
        break;
        case 7:
            pop_from_position(p_table, surname);
        break;
        case 8:
        break;
        case 9:
        break;
        case 10:
        //free all
            return 0;
        break;
        default:
        printf("Wrong function\n");
        break;
        }
    }
    
    

    
}