#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pet {
    int petID;
    char petName[50]; // Assuming pet names are up to 50 characters long
    struct Pet* next;
};

struct Pet* initializeList() {
    return NULL;
}

struct Pet* insertAtBeginning(struct Pet* head, int petID, char petName[]) {
    struct Pet* newNode = (struct Pet*)malloc(sizeof(struct Pet));
    newNode->petID = petID;
    strcpy(newNode->petName, petName);
    newNode->next = head;
    return newNode;
}

struct Pet* insertAtEnd(struct Pet* head, int petID, char petName[]) {
    struct Pet* newNode = (struct Pet*)malloc(sizeof(struct Pet));
    newNode->petID = petID;
    strcpy(newNode->petName, petName);
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Pet* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct Pet* deleteNode(struct Pet* head, int petID) {
    struct Pet* current = head;
    struct Pet* previous = NULL;

    if (current != NULL && current->petID == petID) {
        struct Pet* temp = current;
        head = current->next;
        free(temp);
        return head;
    }

    while (current != NULL && current->petID != petID) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return head;
    }

    previous->next = current->next;
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
        printf("Pet ID: %d, Pet Name: %s\n", temp->petID, temp->petName);
        temp = temp->next;
    }
}

int main() {
    struct Pet* myList = initializeList();
    int choice, petID;
    char petName[50];
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
                printf("Enter Pet Name: ");
                scanf("%s", petName);
                myList = insertAtBeginning(myList, petID, petName);
                break;
            case 2:
                printf("Enter Pet ID: ");
                scanf("%d", &petID);
                printf("Enter Pet Name: ");
                scanf("%s", petName);
                myList = insertAtEnd(myList, petID, petName);
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
                    printf("Found Pet with ID %d, Name: %s\n", foundPet->petID, foundPet->petName);
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
