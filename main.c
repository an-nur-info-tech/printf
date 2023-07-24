#include <limits.h>
#include <stdio.h>
#include <stddef.h>
#include "main.h"

/**
 * main - Entry point
 * test for integer (%i and %d) but also others
 * Return: Always 0
 */
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;

    int num8 = 1000000000;  /*10 digits*/
    int num9 = -1000000000; /*10 digits*/
    int num10 = 123;        /*3 digits*/

    int num5 = -9876;
    int num6 = -123456789;
    int num7 = INT_MIN;

    int num1 = 12345;
    int num2 = 0;
    int num3 = 987654321;
    int num4 = INT_MAX;


    _printf("TESTING NULL FORMAT\n");

    len = _printf(NULL);
    len2 = printf(NULL);
    _printf("%d\n", len);
    printf("%d\n", len2);

    _printf("TESTING s specifier with NULL\n");

    len = _printf("%s\n", NULL);
    len2 = printf("%s\n", NULL);

    _printf("%d\n", len);
    printf("%d\n", len2);

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);

    len = _printf("Current YEAR \t : %d\n", 2023);
    len2 = printf("Current YEAR \t : %d\n", 2023);
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);

    len = _printf("I love it%r: %d\n", 2023);
    len2 = printf("I love it%r: %d\n", 2023);
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);

    len = _printf("NON_INTEGER:%d\n", "NON INTEGER");
    len2 = printf("NON_INTEGER:%d\n", "NON INTEGER");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);

    len = _printf("LARGE NUMBERS:%d\n", INT_MIN);
    len2 = printf("LARGE NUMBERS:%d\n", INT_MIN);
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);

    len = _printf("LARGE NUMBERS:%d\n", INT_MAX);
    len2 = printf("LARGE NUMBERS:%d\n", INT_MAX);
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);

    len = _printf("CHARS:%d\n", 'a');
    len2 = printf("CHARS:%d\n", 'a');
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);

    len = _printf("LEADING ZEROS:%d\n", 0045);
    len2 = printf("LEADING ZEROS:%d\n", 0045);
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);

    _printf("\n::::::MORE TESTS:::::::::\n");

    /*Test cases for positive numbers*/
    printf("Positive Numbers:\n");

    _printf("num1: %d (bytes printed: %d)\n", num1, print_int(num1));
    printf("num1: %d (bytes printed: %d)\n", num1, print_int(num1));

    _printf("num2: %d (bytes printed: %d)\n", num2, print_int(num2));
    printf("num2: %d (bytes printed: %d)\n", num2, print_int(num2));

    _printf("num3: %d (bytes printed: %d)\n", num3, print_int(num3));
    printf("num3: %d (bytes printed: %d)\n", num3, print_int(num3));

    _printf("num4: %d (bytes printed: %d)\n", num4, print_int(num4));
    printf("num4: %d (bytes printed: %d)\n", num4, print_int(num4));

    /*Test cases for negative numbers*/
    printf("\nNegative Numbers:\n");

    _printf("num5: %d (bytes printed: %d)\n", num5, print_int(num5));
    printf("num5: %d (bytes printed: %d)\n", num5, print_int(num5));

    _printf("num6: %d (bytes printed: %d)\n", num6, print_int(num6));
    printf("num6: %d (bytes printed: %d)\n", num6, print_int(num6));

    _printf("num7: %d (bytes printed: %d)\n", num7, print_int(num7));
    printf("num7: %d (bytes printed: %d)\n", num7, print_int(num7));

    /*Test cases for special cases*/
    printf("\nSpecial Cases:\n");

    _printf("num8: %d (bytes printed: %d)\n", num8, print_int(num8));
    printf("num8: %d (bytes printed: %d)\n", num8, print_int(num8));

    _printf("num9: %d (bytes printed: %d)\n", num9, print_int(num9));
    printf("num9: %d (bytes printed: %d)\n", num9, print_int(num9));

    _printf("num10: %d (bytes printed: %d)\n", num10, print_int(num10));
    printf("num10: %d (bytes printed: %d)\n", num10, print_int(num10));

    len = _printf("SMALL:%d\n", -1);
    len2 = printf("SMALL:%d\n", -1);

    _printf("len=%d\n", len);
    printf("len2=%d\n", len2);

    len = _printf("SMALL:%d\n", 5);
    len2 = printf("SMALL:%d\n", 5);

    _printf("len=%d\n", len);
    printf("len2=%d\n", len2);
    return (0);
}
