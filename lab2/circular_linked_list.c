#include <stdio.h>
#include <stdlib.h>
#include <pet.h>

struct Pet* initializeList() {
    return NULL;
}

struct Pet* insertAtBeginning(struct Pet* head, int petID, char name[], char breed[], int age) {
    struct Pet* newNode = (struct Pet*)malloc(sizeof(struct Pet));
    newNode->petID = petID;
    // Copy other details...
    if (head == NULL) {
        newNode->next = newNode; // Point to itself in a circular list
        return newNode;
    } else {
        struct Pet* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        return newNode;
    }
}

struct Pet* insertAtEnd(struct Pet* head, int petID, char name[], char breed[], int age) {
    struct Pet* newNode = (struct Pet*)malloc(sizeof(struct Pet));
    newNode->petID = petID;
    // Copy other details...
    if (head == NULL) {
        newNode->next = newNode; // Point to itself in a circular list
        return newNode;
    } else {
        struct Pet* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        return head;
    }
}

struct Pet* deleteNode(struct Pet* head, int petID) {
    struct Pet* current = head;
    struct Pet* prev = NULL;

    if (head == NULL) {
        return head;
    }

    do {
        if (current->petID == petID) {
            if (current == head) {
                struct Pet* temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                if (head == head->next) {
                    free(head);
                    return NULL;
                }
                temp->next = head->next;
                free(head);
                return temp->next;
            } else {
                prev->next = current->next;
                free(current);
                return head;
            }
        }
        prev = current;
        current = current->next;
    } while (current != head);

    return head;
}

struct Pet* searchByID(struct Pet* head, int petID) {
    if (head == NULL) {
        return NULL;
    }

    struct Pet* current = head;
    do {
        if (current->petID == petID) {
            return current;
        }
        current = current->next;
    } while (current != head);

    return NULL;
}

void displayList(struct Pet* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Pet* temp = head;
    do {
        // Display pet details...
        temp = temp->next;
    } while (temp != head);
}

int main() {
    struct Pet* myList = initializeList();
    int choice, petID, age;
    char name[50], breed[50];
    struct Pet* foundPet = NULL;

    do {
        printf("\nCircular Linked List Operations\n");
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
