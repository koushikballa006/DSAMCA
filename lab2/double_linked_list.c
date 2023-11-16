#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pet {
    int petID;
    char name[50];
    char breed[50];
    int age;
    struct Pet* next;
    struct Pet* prev;
};

struct Pet* initializeList() {
    return NULL;
}

struct Pet* insertAtBeginning(struct Pet* head, int petID, char name[], char breed[], int age) {
    struct Pet* newNode = (struct Pet*)malloc(sizeof(struct Pet));
    newNode->petID = petID;
    strcpy(newNode->name, name);
    strcpy(newNode->breed, breed);
    newNode->age = age;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}

struct Pet* insertAtEnd(struct Pet* head, int petID, char name[], char breed[], int age) {
    struct Pet* newNode = (struct Pet*)malloc(sizeof(struct Pet));
    newNode->petID = petID;
    strcpy(newNode->name, name);
    strcpy(newNode->breed, breed);
    newNode->age = age;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    struct Pet* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

struct Pet* deleteNode(struct Pet* head, int petID) {
    struct Pet* current = head;

    if (head == NULL) {
        return head;
    }

    if (current->petID == petID) {
        struct Pet* temp = current;
        head = current->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }

    while (current != NULL && current->petID != petID) {
        current = current->next;
    }

    if (current == NULL) {
        return head;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    current->prev->next = current->next;
    free(current);
    return head;
}

struct Pet* searchByID(struct Pet* head, int petID) {
    struct Pet* current = head;

    while (current != NULL) {
        if (current->petID == petID) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

void displayList(struct Pet* head) {
    struct Pet* temp = head;
    while (temp != NULL) {
        printf("Pet ID: %d, Name: %s, Breed: %s, Age: %d\n", temp->petID, temp->name, temp->breed, temp->age);
        temp = temp->next;
    }
}

int main() {
    struct Pet* myList = initializeList();
    int choice, petID, age;
    char name[50], breed[50];
    struct Pet* foundPet = NULL;

    do {
        printf("\nLinked List Operations\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete Node\n");
        printf("4. Search by ID\n");
        printf("5. Display List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Pet ID: ");
                scanf("%d", &petID);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Breed: ");
                scanf("%s", breed);
                printf("Enter Age: ");
                scanf("%d", &age);
                myList = insertAtBeginning(myList, petID, name, breed, age);
                break;
            case 2:
                printf("Enter Pet ID: ");
                scanf("%d", &petID);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Breed: ");
                scanf("%s", breed);
                printf("Enter Age: ");
                scanf("%d", &age);
                myList = insertAtEnd(myList, petID, name, breed, age);
                break;
            case 3:
                printf("Enter Pet ID to delete: ");
                scanf("%d", &petID);
                myList = deleteNode(myList, petID);
                break;
            case 4:
                printf("Enter Pet ID to search: ");
                scanf("%d", &petID);
                foundPet = searchByID(myList, petID);
                if (foundPet != NULL) {
                    printf("Found Pet with ID %d\n", foundPet->petID);
                } else {
                    printf("Pet with ID %d not found\n", petID);
                }
                break;
            case 5:
                printf("Current List:\n");
                displayList(myList);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    // Clean up memory (free nodes) - Not implemented in this example

    return 0;
}
