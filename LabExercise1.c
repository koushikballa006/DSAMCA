#include <stdio.h>
#include <string.h>

#define MAX_PETS 100
#define MAX_ROWS 2
#define MAX_COLUMNS 2

struct Pet {
    int id;
    char name[50];
    char breed[50];
    int age;
};

void insertPet(struct Pet pets[MAX_PETS], int *petCount, int petAges[MAX_ROWS][MAX_COLUMNS]) {
    struct Pet newPet;
    printf("Enter Pet ID: ");
    scanf("%d", &newPet.id);
    printf("Enter Pet Name: ");
    scanf("%s", newPet.name);
    printf("Enter Pet Breed: ");
    scanf("%s", newPet.breed);
    printf("Enter Pet Age: ");
    scanf("%d", &newPet.age);
    pets[*petCount] = newPet;
    petAges[*petCount / MAX_COLUMNS][*petCount % MAX_COLUMNS] = newPet.age;
    (*petCount)++;
}

void deletePet(struct Pet pets[MAX_PETS], int *petCount, int petAges[MAX_ROWS][MAX_COLUMNS], int id) {
    int found = 0;
    for (int i = 0; i < *petCount; i++) {
        if (pets[i].id == id) {
            for (int j = i; j < *petCount - 1; j++) {
                pets[j] = pets[j + 1];
                petAges[j / MAX_COLUMNS][j % MAX_COLUMNS] = petAges[(j + 1) / MAX_COLUMNS][(j + 1) % MAX_COLUMNS];
            }
            (*petCount)--;
            found = 1;
            printf("Pet with ID %d deleted successfully.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Pet with ID %d not found.\n", id);
    }
}

void searchPet(struct Pet pets[MAX_PETS], int petCount, int petAges[MAX_ROWS][MAX_COLUMNS], int id) {
    int found = 0;
    for (int i = 0; i < petCount; i++) {
        if (pets[i].id == id) {
            found = 1;
            printf("Pet found:\n");
            printf("ID: %d\nName: %s\nBreed: %s\nAge: %d\n", pets[i].id, pets[i].name, pets[i].breed, pets[i].age);
            break;
        }
    }
    if (!found) {
        printf("Pet with ID %d not found.\n", id);
    }
}

void linearSearchPet(struct Pet pets[MAX_PETS], int petCount, int petAges[MAX_ROWS][MAX_COLUMNS], int id) {
    int found = 0;
    for (int i = 0; i < petCount; i++) {
        if (pets[i].id == id) {
            found = 1;
            printf("Pet found:\n");
            printf("ID: %d\nName: %s\nBreed: %s\nAge: %d\n", pets[i].id, pets[i].name, pets[i].breed, pets[i].age);
            break;
        }
    }
    if (!found) {
        printf("Pet with ID %d not found.\n", id);
    }
}

void matrixAddition(int matrixA[MAX_ROWS][MAX_COLUMNS], int matrixB[MAX_ROWS][MAX_COLUMNS], int result[MAX_ROWS][MAX_COLUMNS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void matrixMultiplication(int matrixA[MAX_ROWS][MAX_COLUMNS], int matrixB[MAX_ROWS][MAX_COLUMNS], int result[MAX_ROWS][MAX_COLUMNS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < MAX_COLUMNS; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void displayPets(struct Pet pets[MAX_PETS], int petCount) {
    printf("\nPets entered:\n");
    for (int i = 0; i < petCount; i++) {
        printf("ID: %d | Name: %s | Breed: %s | Age: %d\n", pets[i].id, pets[i].name, pets[i].breed, pets[i].age);
    }
}

void displayMatrix(int matrix[MAX_ROWS][MAX_COLUMNS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct Pet pets[MAX_PETS];
    int petAges[MAX_ROWS][MAX_COLUMNS];
    int result[MAX_ROWS][MAX_COLUMNS];
    int choice, id; // Declare variables outside the switch

    int petCount = 0;

    do {
        printf("\nMenu:\n");
        printf("1. Insert Pet\n");
        printf("2. Delete Pet\n");
        printf("3. Search Pet\n");
        printf("4. Linear Search Pet\n");
        printf("5. Display Pets\n");
        printf("6. Matrix Addition\n");
        printf("7. Matrix Multiplication\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertPet(pets, &petCount, petAges);
                break;
            case 2:
                printf("Enter Pet ID to delete: ");
                scanf("%d", &id);
                deletePet(pets, &petCount, petAges, id);
                break;
            case 3:
                printf("Enter Pet ID to search: ");
                scanf("%d", &id);
                searchPet(pets, petCount, petAges, id);
                break;
            case 4:
                printf("Enter Pet ID to linear search: ");
                scanf("%d", &id);
                linearSearchPet(pets, petCount, petAges, id);
                break;
            case 5:
                displayPets(pets, petCount);
                break;
            case 6:
                printf("Matrix Addition Result:\n");
                matrixAddition(petAges, petAges, result);
                displayMatrix(result);
                break;
            case 7:
                printf("Matrix Multiplication Result:\n");
                matrixMultiplication(petAges, petAges, result);
                displayMatrix(result);
                break;
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 8);

    return 0;
}
