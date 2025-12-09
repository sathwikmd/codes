
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Function to create a new node
struct node* createNode(int value) 
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}









// Insert at beginning
void insertAtBeginning(int value) {
    struct node *newnode = createNode(value);
    if (head == NULL) 
    {
        head = newnode;
        return;
    }

    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}
// Insert at end
void insertAtEnd(int value) {
    struct node *newnode = createNode(value);
    if (head == NULL) {
        head = newnode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}


// Delete from beginning
void deleteFromBeginning()
{
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    struct node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
    printf("\nNode deleted from beginning.\n");
}













// Delete from end
void deleteFromEnd() {
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    struct node *temp = head;

    if (temp->next == NULL) 
    { // Only one node
        free(head);
        head = NULL;
        printf("\nOnly node deleted.\n");
        return;
    }
    while (temp->next != NULL) 
{
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);

    printf("\nNode deleted from end.\n");
}





// Display list forward
void displayForward() 
{
    struct node *temp = head;

    if (temp == NULL) {
        printf("\nList is Empty\n");
        return;
    }

    printf("\nDoubly Linked List (Forward): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}













// Display list backward
void displayBackward() {
    struct node *temp = head;

    if (temp == NULL) {
        printf("\nList is Empty\n");
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;

    printf("\nDoubly Linked List (Backward): NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}












// Main menu
int main() 
{
    int choice, value;

    while (1) {
        printf("\n---- Menu ----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display Forward\n");
        printf("6. Display Backward\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 3:
                deleteFromBeginning();
                break;

            case 4:
                deleteFromEnd();
                break;

            case 5:
                displayForward();
                break;

            case 6:
                displayBackward();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}






int listLength() 
{
    int len = 0;
    struct node *temp = head;
    while (temp != NULL) {
        ++len;
        temp = temp->next;
    }
    return len;
}



















void insertAtPosition(int pos, int value)
 {
    if (pos < 1) {
        printf("Invalid position. Position should be >= 1.\n");
        return;
    }
    int len = listLength();
    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }
    if (pos == len + 1) {
        insertAtEnd(value);
        return;
    }
    if (pos > len + 1) {
        printf("Invalid position. Current list length = %d. Valid positions: 1 to %d\n", len, len + 1);
        return;
    }

    /* traverse to node at (pos-1) */
    struct node *temp = head;
    for (int i = 1; i < pos - 1; ++i)  # moves temp forward until it points to the node at position
temp = temp->next;

    struct node *newnode = createNode(value);
    newnode->next = temp->next;
    newnode->prev = temp;
# if there is a successor node (i.e., not inserting at the end), update that successor’s prev pointer to point back to the new node.
#This step is crucial to maintain the backward link from the successor to the new node.
    if (temp->next!=NULL)
 temp->next->prev = newnode;
    temp->next = newnode;
}
void deleteAtPosition(int pos) 
{
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (pos < 1) {
        printf("Invalid position. Position should be >= 1.\n");
        return;
    }

    int len = listLength();
    if (pos > len) {
        printf("Invalid position. Current list length = %d. Valid positions: 1 to %d\n", len, len);
        return;
    }

    if (pos == 1) {
        deleteFromBeginning();
        return;
    }
    if (pos == len) {
        deleteFromEnd();
        return;
    }

    struct node *temp = head;
    for (int i = 1; i < pos; ++i)
 temp = temp->next;

    /* temp is the node to be deleted */
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    printf("Node at position %d deleted.\n", pos);
}
