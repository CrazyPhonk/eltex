#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Record{
    char surname[MAX_SIZE];
    int number;
    char faculty[MAX_SIZE];
    char group[MAX_SIZE];
} Record;

void inputRecord(Record *record) {
    printf("Surname: ");
    scanf("%s", record->surname);
    printf("Credit card: ");
    scanf("%d", &record->number);
    printf("Faculty: ");
    scanf("%s", record->faculty);
    printf("Group: ");
    scanf("%s", record->group);
}

void printRecord(Record record) {
    printf("Surname: %s\n", record.surname);
    printf("Credit card: %d\n", record.number);
    printf("Faculty: %s\n", record.faculty);
    printf("Group: %s\n", record.group);
    printf("\n");
}

void loadTable(Record table[], int *size, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        *size = 0;
        while (!feof(file) && *size < MAX_SIZE) {
            fscanf(file, "%s %d %s %s", table[*size].surname, &table[*size].number, table[*size].faculty, table[*size].group);
            (*size)++;
        }
        fclose(file);
        printf("Table downoloaded\n");
    } else {
        printf("Open file error\n");
    }
}

void saveTable(const Record table[], int size, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file) {
        for (int i = 0; i < size; i++) {
            fprintf(file, "%s %d %s %s\n", table[i].surname, table[i].number, table[i].faculty, table[i].group);
        }
        fclose(file);
        printf("Table saved to file\n");
    } else {
        printf("Open file error\n");
    }
}

void viewTable(const Record table[], int size) {
    for (int i = 0; i < size; i++) {
        printRecord(table[i]);
    }
}

void sortTable(Record table[], int size) {
    for (int i = 0; i < size - 1; i++) {
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

void searchTable(const Record table[], int size, char* group) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (table[i].group == group) {
            printRecord(table[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Element was not found\n");
    }
}


void deleteRecord(Record table[], int *size, const char *surname) {
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (strcmp(table[i].surname, surname) == 0) {
            for (int j = i; j < *size - 1; j++) {
                table[j] = table[j + 1];
            }
            (*size)--;
            found = 1;
            printf("Deleted\n");
            break;
        }
    }
    if (!found) {
        printf("Element was not found\n");
    }
}

void editRecord(Record table[], int size, const char *surname) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(table[i].surname, surname) == 0) {
            inputRecord(&table[i]);
            found = 1;
            printf("Table updated\n");
            break;
        }
    }
    if (!found) {
        printf("Element was not found\n");
    }
}

void calculateTable(const Record table[], int size, char* group) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (table[i].group == group) {
            count++;
        }
    }
    printf("The number of records with the specified group number: %d\n", count);
}

int main(int argc, char * argv[]){
    Record table[MAX_SIZE];
    int size = 0;
    int choice;
    char group[MAX_SIZE];

    while (1) {
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
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                if (size < MAX_SIZE) {
                    inputRecord(&table[size]);
                    size++;
                } else {
                    printf("SIZE > MAX_SIZE\n");
                }
                break;
            case 2:
                loadTable(table, &size, "table.txt");
                break;
            case 3:
                saveTable(table, size, "table.txt");
                break;
            case 4:
                viewTable(table, size);
                break;
            case 5:
                sortTable(table, size);
                break;
            case 6:
                printf("Group: ");
                scanf("%s", group);
                searchTable(table, size, group);
                break;
            case 7:
                printf("Surname to delete: ");
                char deleteSurname[100];
                scanf("%s", deleteSurname);
                deleteRecord(table, &size, deleteSurname);
                break;
            case 8:
                printf("Surname to update: ");
                char editSurname[100];
                scanf("%s", editSurname);
                editRecord(table, size, editSurname);
                break;
            case 9:
                printf("Group: ");
                scanf("%s", group);
                calculateTable(table, size, group);
                break;
            case 10:
                return 0;
            default:
                printf("Wrong function.\n");
        }

        printf("\n");
    }
}