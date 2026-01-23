#include <stdio.h>
#include <stdlib.h>

int main() {
    int *emp_ids;
    int n, new_n;

    printf("Enter the initial number of employees: ");
    scanf("%d", &n);

    
    emp_ids = (int *)calloc(n, sizeof(int));
    if (emp_ids == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\nInitial employee IDs (should be zero):\n");
    for (int i = 0; i < n; i++) {
        printf("ID %d: %d\n", i + 1, emp_ids[i]);
    }

    printf("\nEnter employee IDs:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter ID %d: ", i + 1);
        scanf("%d", &emp_ids[i]);
    }

    printf("\nEnter the new total number of employees: ");
    scanf("%d", &new_n);

    
    emp_ids = (int *)realloc(emp_ids, new_n * sizeof(int));
    if (emp_ids == NULL) {
        printf("Memory reallocation failed!\n");
        free(emp_ids); 
        return 1;
    }

    if (new_n > n) {
        printf("\nEnter the additional employee IDs:\n");
        for (int i = n; i < new_n; i++) {
            printf("Enter ID %d: ", i + 1);
            scanf("%d", &emp_ids[i]);
        }
    }

    printf("\nUpdated list of employee IDs:\n");
    for (int i = 0; i < new_n; i++) {
        printf("ID %d: %d\n", i + 1, emp_ids[i]);
    }

    
    free(emp_ids);
    printf("\nMemory freed.\n");

    return 0;
}
