#include <stdio.h>
#include <stdarg.h>

void minprintf(char*, ...); // function prototypes
void print_number(int);

int main()
{

    int i;
    char ch;
    scanf("%d\n", &i);
    scanf("%c", &ch);
    minprintf("%d\n%c\n", i, ch); // calling the minprintf() function with the format specifier and the variable name

    return 0;
}

void print_number(int n) // function to print an integer using only putchar()
{

    if (n < 0)
    {
        putchar('-');
        n = -n;
    }

    if (n == 0)
        putchar('0');

    if (n / 10 != 0)
        print_number(n / 10);

    putchar(n % 10 + '0'); // 0 is added to convert integer to char
}

void minprintf(char* format, ...) // ...(ellipsis) denote variable argument length
{
    va_list ap; // create a variable of type va_list
    char* p;
    int ival;
    char cval;

    va_start(ap, format); // macro

    for (p = format; *p; p++)
    {
        if (*p != '%')
        {
            putchar(*p);
            continue;
        }

        switch (*++p) // switch based on the format specifier supplied
        {
            case 'd':
                ival = va_arg(ap, int); // accessing the next element using macro
                print_number(ival); // calling the print_number() function
                break;

            case 'c':
                cval = va_arg(ap, int); // typecast from int to char
                putchar(cval);
                break;

            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap); // cleaning up
}
