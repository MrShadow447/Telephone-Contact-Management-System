#include <stdio.h>
#include <string.h>

#define MAX 100

struct Contact {
    char name[50];
    char phone[15];
};

struct Contact contacts[MAX];
int count = 0;

// Add Contact
void addContact() {
    if (count >= MAX) {
        printf("Contact list is full!\n");
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", contacts[count].name);

    printf("Enter Phone Number: ");
    scanf("%s", contacts[count].phone);

    count++;
    printf("Contact added successfully!\n");
}

// Display Contacts
void displayContacts() {
    if (count == 0) {
        printf("No contacts to display!\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s | Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

// Search Contact
void searchContact() {
    char name[50];
    int found = 0;

    printf("Enter name to search: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Found! Name: %s | Phone: %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
        }
    }

    if (!found) {
        printf("Contact not found!\n");
    }
}

// Delete Contact
void deleteContact() {
    char name[50];
    int found = 0;

    printf("Enter name to delete: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            count--;
            printf("Contact deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found!\n");
    }
}

// Update Contact
void updateContact() {
    char name[50];
    int found = 0;

    printf("Enter name to update: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Enter new phone number: ");
            scanf("%s", contacts[i].phone);
            printf("Contact updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found!\n");
    }
}

// Main Function
int main() {
    int choice;

    do {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Update Contact\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: updateContact(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}