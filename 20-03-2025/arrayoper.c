#include <stdio.h>

#define MAX 5  

void display(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
    } else {
        printf("Array elements are: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int search(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;  
        }
    }
    return -1;  
}

void update(int arr[], int size, int position, int new_value) {
    if (position >= 1 && position <= size) {
        arr[position - 1] = new_value;
        printf("Element at position %d updated to %d.\n", position, new_value);
    } else {
        printf("Invalid position.\n");
    }
}

int main() {
    int arr[MAX], size = 0, choice, element, position, new_value, index;

    // Initialize the array
    while (1) {
        printf("\nArray Operations Menu\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display array\n");
        printf("4. Update an element\n");
        printf("5. Search for an element\n");
        printf("6. Traverse the array\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insertion operation
                if (size < MAX) {
                    printf("Enter the element to insert: ");
                    scanf("%d", &element);
                    arr[size] = element;
                    size++;
                    printf("Element inserted successfully.\n");
                } else {
                    printf("Array is full. Cannot insert element.\n");
                }
                break;

            case 2:
                // Deletion operation
                if (size > 0) {
                    printf("Enter the position to delete (1 to %d): ", size);
                    scanf("%d", &position);

                    if (position < 1 || position > size) {
                        printf("Invalid position.\n");
                    } else {
                        // Shift elements to the left
                        for (int i = position - 1; i < size - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        size--;
                        printf("Element deleted successfully.\n");
                    }
                } else {
                    printf("Array is empty. Cannot delete element.\n");
                }
                break;

            case 3:
                // Display the array
                display(arr, size);
                break;

            case 4:
                // Update operation
                printf("Enter the position (1 to %d) to update: ", size);
                scanf("%d", &position);
                printf("Enter the new value: ");
                scanf("%d", &new_value);
                update(arr, size, position, new_value);
                break;

            case 5:
                // Search operation
                printf("Enter the element to search: ");
                scanf("%d", &element);
                index = search(arr, size, element);
                if (index != -1) {
                    printf("Element %d found at position %d.\n", element, index + 1);
                } else {
                    printf("Element %d not found.\n", element);
                }
                break;

            case 6:
                // Traverse the array (same as displaying the array)
                display(arr, size);
                break;

            case 7:
                // Exit the program
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

