#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int no_args = argc - 1; // excluding ./a.out because it is counted towards argc as well
    int arr[no_args]; // array to store the numbers
    int sum = 0, i;
    for (i = 1; i <= argc - 1; i++)
        arr[i - 1] = atoi(argv[i]); // using atoi() to convert string to integer

    for (i = 0; i < no_args; i++)
        sum = sum + arr[i];

    printf("%d %d\n", no_args, sum);
}
