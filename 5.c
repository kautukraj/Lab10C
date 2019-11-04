#include <stdio.h>
#define MAX(x, y) ((x > y) ? x : y) // macro to find maximum of two numbers

void my_sum(double*, double*, double*, int, int, int); // function prototypes
void my_product(double*, double*, double*, int, int);

int main()
{
    int p1_deg, p2_deg;

    scanf("%d", &p1_deg);
    int p1_size = p1_deg + 1; // adding one for the constant term
    double p1[p1_size];
    for (int i = 0; i < p1_size; i++)
        scanf("%lf", &p1[i]); // accepting the coefficients

    scanf("%d", &p2_deg);
    int p2_size = p2_deg + 1;
    double p2[p2_size];
    for (int i = 0; i < p2_size; i++)
        scanf("%lf", &p2[i]);

    int size = MAX(p1_size, p2_size); // finding higher degree polynomial
    double sum[size];
    double product[p1_size + p2_size - 1];

    my_sum(sum, p1, p2, p1_size, p2_size, size); // calling the functions
    my_product(product, p1, p2, p1_size, p2_size);

    return 0;
}

void my_sum(double* sum, double* p1, double* p2, int p1_size, int p2_size, int size)
{
    for (int i = 0; i < p1_size; i++)
        sum[i] = p1[i];

    for (int i = 0; i < p2_size; i++)
        sum[i] += p2[i];

    printf("%d ", size - 1); // degree of polynomial
    for (int i = 0; i < size; i++)
        printf("%.2lf ", sum[i]); // print upto 2 dp
}

void my_product(double* product, double* p1, double* p2, int p1_size, int p2_size)
{

    for (int i = 0; i < p1_size + p2_size - 1; i++)
        product[i] = 0; // initializing array elements to 0

    for (int i = 0; i < p1_size; i++)
    {
        for (int j = 0; j < p2_size; j++)
            product[i + j] += p1[i] * p2[j];
    }
    putchar('\n');
    for (int i = 0; i < p1_size + p2_size - 1; i++)
        printf("%.2lf ", product[i]);
}

