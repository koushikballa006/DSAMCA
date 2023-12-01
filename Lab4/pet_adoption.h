#ifndef PET_ADOPTION_H
#define PET_ADOPTION_H

struct Pet {
    int id;
    char name[50];
    char breed[50];
    int age;
    struct Pet* next;
};

struct Pet* createPet(int id, char name[], char breed[], int age);
void linearEnqueue(int id, char name[], char breed[], int age);
void linearDequeue();
void displayLinearQueue();
void circularEnqueue(int id, char name[], char breed[], int age);
void circularDequeue();
void displayCircularQueue();
void priorityEnqueue(int id, char name[], char breed[], int age, int priority);
void priorityDequeue();
void displayPriorityQueue();

#endif // PET_ADOPTION_H
