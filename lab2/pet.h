#ifndef PET_H
#define PET_H

struct Pet {
    int petID;
    char name[50];
    char breed[50];
    int age;
    struct Pet* next;
    struct Pet* prev;
};

// Function declarations
struct Pet* initializeList();
struct Pet* insertAtBeginning(struct Pet* head, int petID, char name[], char breed[], int age);
struct Pet* insertAtEnd(struct Pet* head, int petID, char name[], char breed[], int age);
struct Pet* deleteNode(struct Pet* head, int petID);
struct Pet* searchByID(struct Pet* head, int petID);
void displayList(struct Pet* head);

#endif /* PET_H */
