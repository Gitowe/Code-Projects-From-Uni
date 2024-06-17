#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *int_ptr = (int*) malloc(2 * sizeof(int));
    if (!int_ptr)
    {
        printf("An error in the program's memory usage has occued.\nThe program will now be terminated.");
        exit(1);
    }

    printf("Enter first integer: ");
    scanf("%d", int_ptr);

    printf("Enter first second: ");
    scanf("%d", int_ptr+1);

    printf("Original values: 1st = %d 2nd = %d\n", int_ptr[0], int_ptr[1]);

    int_ptr[0] = int_ptr[0] ^ int_ptr[1];
    int_ptr[1] = int_ptr[0] ^ int_ptr[1];
    int_ptr[0] = int_ptr[0] ^ int_ptr[1];

    printf("Swapped values: 1st = %d 2nd = %d\n", int_ptr[0], int_ptr[1]);



    free (int_ptr);
    return 0;


}