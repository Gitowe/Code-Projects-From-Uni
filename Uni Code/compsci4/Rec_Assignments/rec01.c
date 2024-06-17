#include<stdio.h>

int main()
{

    unsigned char input;
    int i;
    int temp1;

    printf("Enter an ASCII character: ");
    scanf("%c", &input);

    printf("The ASCII value of %hhu is: \n", input);


    printf("    dec -- %d\n", input);
    printf("    hex -- %X\n", input);
    printf("    bin -- ");

    for (i = 7; i >= 0; i--) {
        temp1 = input >> i;
        if (temp1 & 1)
        {
            printf("1");
        }
        else
        {
            printf("0");        
        }
    }
    printf("\n");

    return 0;
}
