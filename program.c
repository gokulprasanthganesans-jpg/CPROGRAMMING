#include <stdio.h>
int main() 
{
    int n, i;
    int age[100];
    int sum = 0;
    float average;
    printf("Enter number of persons: ");
    scanf("%d", &n);
    printf("Enter ages:\n");
    for (i = 0; i < n; i++) 
    {2
        scanf("%d", &age[i]);
        sum = sum + age[i];
    }
    average = (float)sum / n;
    printf("Average age = %.2f\n", average);
    return 0;
}
