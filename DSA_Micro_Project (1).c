/*******************************************************
This program store people's name and age in queue.
In this program we can add person, remove person, 
search any people and display all people.
This program store data in first in first out order.
*******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Declare front and rear variable for Queue.
//Declare head for traversing in queue.
int front = -1;
int rear = -1;
int head = -1;
bool underflow = true;
bool overflow = true;

struct person {
    char name[50];
    int age;
};

//Check the queue is empty or not.
int isUnderflow() {
    if (rear < 0) {
        underflow = true;
    } else {
        underflow = false;
    }
    return underflow;
}

//Check the queue is full or not.
int isOverflow() {
    if (rear >= 49) {  
        overflow = true;
    } else {
        overflow = false;
    }
    return overflow;
}

//Add new person in queue(enqueue).
void addPerson(struct person p[], char n[], int a) {
    if (isOverflow()) {
        printf("Queue is full, you can't add new person\n");
        return;
    }

    rear += 1;
    strcpy(p[rear].name, n);
    p[rear].age = a;
    
    //When we add first element in queue, front and head
    //points the first element.
    if (front == -1) {
        front = 0;
        head = 0;
    }
}

//Remove a person from queue(dequeue).
void removePerson(struct person p[]) {
    if (isUnderflow()) {
        printf("Queue is empty, no person to remove\n");
        return;
    }

    printf("Removed person: %s\n", p[front].name);
    
    //When front and rear points same location that means
    //queue is now empty so set front and rear at -1.
    if (front == rear) {
        front = rear = -1;  
        head = -1;
    } 
    else{
        front++;
    }
}

//Find any eprson in queue.
void searchPerson(struct person p[], char name[]) {
    if (isUnderflow()) {
        printf("Queue is empty, no person to search\n");
        return;
    }

    for (int i = front; i <= rear; i++) {
        if (strcmp(p[i].name, name) == 0) {
            printf("Person found successfully\n");
            printf("Name: %s\n", p[i].name);
            printf("Age: %d\n", p[i].age);
            return;
        }
    }
    printf("Person not found\n");
}

//Display every person's name and age
void displayPerson(struct person p[]) {
    if (isUnderflow()) {
        printf("Queue is empty, no person to display\n");
        return;
    }
    int cnt = 1;
    for (int i = front; i <= rear; i++) {
        printf("Person %d\n", cnt);
        printf("Name: %s\n", p[i].name);
        printf("Age: %d\n", p[i].age);
        cnt++;
    }
}

int main() {
    //We can add maximum 50 people.
    struct person p[50];  
    int age;
    char name[50];
    int choice;

    while (1) {
        printf("1. Add person\n");
        printf("2. Remove person\n");
        printf("3. Search person\n");
        printf("4. Display people\n");
        printf("5. Exit program\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);  
                printf("Enter age: ");
                scanf("%d", &age);
                addPerson(p, name, age);
                break;

            case 2:
                removePerson(p);
                break;

            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                searchPerson(p, name);
                break;

            case 4:
                displayPerson(p);
                break;

            case 5:
                printf(".....THE END.....\n");
                return 0;

            default:
                printf("INVALID CHOICE!!! TRY AGAIN\n");
        }
    }
}
