#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pet_adoption.h"

struct Pet {
    int id;
    char name[50];
    char breed[50];
    int age; 
    struct Pet* next; 
};

struct Pet* createPet(int id, char name[], char breed[], int age) {
    struct Pet* newPet = (struct Pet*)malloc(sizeof(struct Pet));
    newPet->id = id;
    strcpy(newPet->name, name);
    strcpy(newPet->breed, breed);
    newPet->age = age;
    newPet->next = NULL;
    return newPet;
}

struct Pet* linearQueueFront = NULL;
struct Pet* linearQueueRear = NULL;

void linearEnqueue(int id, char name[], char breed[], int age) {
    struct Pet* newPet = createPet(id, name, breed, age);
    if (linearQueueRear == NULL) {
        linearQueueFront = linearQueueRear = newPet;
    } else {
        linearQueueRear->next = newPet;
        linearQueueRear = newPet;
    }
}

void linearDequeue() {
    if (linearQueueFront == NULL) {
        printf("Linear Queue is empty\n");
        return;
    }
    struct Pet* temp = linearQueueFront;
    linearQueueFront = linearQueueFront->next;
    free(temp);
}

void displayLinearQueue() {
    struct Pet* current = linearQueueFront;
    printf("Linear Queue: ");
    while (current != NULL) {
        printf("(%d, %s, %s, %d) ", current->id, current->name, current->breed, current->age);
        current = current->next;
    }
    printf("\n");
}


struct Pet* circularQueueFront = NULL;
struct Pet* circularQueueRear = NULL;

void circularEnqueue(int id, char name[], char breed[], int age) {
    struct Pet* newPet = createPet(id, name, breed, age);
    if (circularQueueRear == NULL) {
        circularQueueFront = circularQueueRear = newPet;
        newPet->next = circularQueueFront;
    } else {
        circularQueueRear->next = newPet;
        circularQueueRear = newPet;
        circularQueueRear->next = circularQueueFront;
    }
}

void circularDequeue() {
    if (circularQueueFront == NULL) {
        printf("Circular Queue is empty\n");
        return;
    }
    struct Pet* temp = circularQueueFront;
    if (circularQueueFront == circularQueueRear) {
        circularQueueFront = circularQueueRear = NULL;
    } else {
        circularQueueFront = circularQueueFront->next;
        circularQueueRear->next = circularQueueFront;
    }
    free(temp);
}

void displayCircularQueue() {
    struct Pet* current = circularQueueFront;
    printf("Circular Queue: ");
    if (current != NULL) {
        do {
            printf("(%d, %s, %s, %d) ", current->id, current->name, current->breed, current->age);
            current = current->next;
        } while (current != circularQueueFront);
    }
    printf("\n");
}


struct Pet* priorityQueueFront = NULL;

void priorityEnqueue(int id, char name[], char breed[], int age, int priority) {
    struct Pet* newPet = createPet(id, name, breed, age);
    newPet->age = priority; 
    if (priorityQueueFront == NULL || priority < priorityQueueFront->age) {
        newPet->next = priorityQueueFront;
        priorityQueueFront = newPet;
    } else {
        struct Pet* current = priorityQueueFront;
        while (current->next != NULL && priority > current->next->age) {
            current = current->next;
        }
        newPet->next = current->next;
        current->next = newPet;
    }
}


void priorityDequeue() {
    if (priorityQueueFront == NULL) {
        printf("Priority Queue is empty\n");
        return;
    }
    struct Pet* temp = priorityQueueFront;
    priorityQueueFront = priorityQueueFront->next;
    free(temp);
}

void displayPriorityQueue() {
    struct Pet* current = priorityQueueFront;
    printf("Priority Queue: ");
    while (current != NULL) {
        printf("(%d, %s, %s, %d) ", current->id, current->name, current->breed, current->age);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, id, age, priority;
    char name[50], breed[50];

    do {
        printf("\nPet Adoption System\n");
        printf("1. Linear Queue Enqueue\n");
        printf("2. Linear Queue Dequeue\n");
        printf("3. Display Linear Queue\n");
        printf("4. Circular Queue Enqueue\n");
        printf("5. Circular Queue Dequeue\n");
        printf("6. Display Circular Queue\n");
        printf("7. Priority Queue Enqueue\n");
        printf("8. Priority Queue Dequeue\n");
        printf("9. Display Priority Queue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter pet ID: ");
                scanf("%d", &id);
                printf("Enter pet name: ");
                scanf("%s", name);
                printf("Enter pet breed: ");
                scanf("%s", breed);
                printf("Enter pet age: ");
                scanf("%d", &age);
                linearEnqueue(id, name, breed, age);
                break;
            case 2:
                linearDequeue();
                break;
            case 3:
                displayLinearQueue();
                break;
            case 4:
                printf("Enter pet ID: ");
                scanf("%d", &id);
                printf("Enter pet name: ");
                scanf("%s", name);
                printf("Enter pet breed: ");
                scanf("%s", breed);
                printf("Enter pet age: ");
                scanf("%d", &age);
                circularEnqueue(id, name, breed, age);
                break;
            case 5:
                circularDequeue();
                break;
            case 6:
                displayCircularQueue();
                break;
            case 7:
                printf("Enter pet ID: ");
                scanf("%d", &id);
                printf("Enter pet name: ");
                scanf("%s", name);
                printf("Enter pet breed: ");
                scanf("%s", breed);
                printf("Enter pet age (priority): ");
                scanf("%d", &priority);
                priorityEnqueue(id, name, breed, age, priority);
                break;
            case 8:
                priorityDequeue();
                break;
            case 9:
                displayPriorityQueue();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
