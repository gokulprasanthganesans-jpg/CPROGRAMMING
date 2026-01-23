#include <stdio.h>
#include <stdlib.h>

int main() {
    int subjects, *marks;

    printf("Enter the number of subjects: ");
    if (scanf("%d", &subjects) != 1 || subjects <= 0) {
        printf("Invalid input for the number of subjects.\n");
        return 1;
    }

    marks = (int*) malloc(subjects * sizeof(int));

    if (marks == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter marks for each subject:\n");
    for (int i = 0; i < subjects; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &marks[i]);
    }

    printf("\nEntered marks:\n");
    for (int i = 0; i < subjects; i++) {
        printf("Subject %d: %d\n", i + 1, marks[i]);
    }

    free(marks);
    marks = NULL;

    return 0;
}
