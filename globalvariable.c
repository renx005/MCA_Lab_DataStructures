
#include <stdio.h>

// Global variables
int a[5];        // Stack array
int pos = -1;    // Stack top index
int choice;      // User menu choice

// Function to show menu and return choice
int menu()
{
    printf("\nINSERT - 1\nDELETE - 2\nDISPLAY ALL - 3\nSEARCH - 4\nSORT - 5\nEXIT - 6\nENTER YOUR CHOICE: ");
    scanf("%d", &choice);
    return choice;
}

// Main stack operation function
void processArray()
{
    for (choice = menu(); choice != 6; choice = menu())
    {
        switch (choice)
        {
            case 1: // INSERT
                if (pos + 1 == 5)
                {
                    printf("Error: Array is full.\n");
                }
                else
                {
                    int value;
                    printf("Enter the value to insert: ");
                    scanf("%d", &value);
                    a[++pos] = value;
                }
                break;

            case 2: // DELETE
                if (pos == -1)
                {
                    printf("Error: Array is empty.\n");
                }
                else
                {
                    printf("Deleted: %d\n", a[pos--]);
                }
                break;

            case 3: // DISPLAY
                if (pos == -1)
                {
                    printf("Stack is empty.\n");
                }
                else
                {
                	int i;
                    printf("Stack elements: ");
                    for ( i = 0; i <= pos; i++)
                    {
                        printf("%d ", a[i]);
                    }
                    printf("\n");
                }
                break;

            case 4: // SEARCH
                if (pos == -1)
                {
                    printf("Stack is empty. Nothing to search.\n");
                }
                else
                {
                	int i;
                    int target, found = 0;
                    printf("Enter the value to search: ");
                    scanf("%d", &target);
                    for ( i = 0; i <= pos; i++)
                    {
                        if (a[i] == target)
                        {
                            printf("Value %d found at position %d (index %d)\n", target, i + 1, i);
                            found = 1;
                            break;
                        }
                    }
                    if (!found)
                    {
                        printf("Value not found in the stack.\n");
                    }
                }
                break;

            case 5: // SORT
                if (pos == -1)
                {
                    printf("Stack is empty. Nothing to sort.\n");
                }
                else
                {
                	int i;
                	int j;
                    for (i = 0; i <= pos; i++)
                    {
                        for ( j = i + 1; j <= pos; j++)
                        {
                            if (a[i] > a[j])
                            {
                                int temp = a[i];
                                a[i] = a[j];
                                a[j] = temp;
                            }
                        }
                    }
                    printf("Stack sorted in ascending order.\n");
                }
                break;

            default:
                printf("Error: Wrong choice.\n");
                break;
        }
    }
}

int main()
{
    processArray();
    return 0;
}

