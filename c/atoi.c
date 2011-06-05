/* Given two numbers on command line, output average */

#include <stdio.h>
#include <math.h>
#include <string.h>

/*
 * Given a char array of digits, convert to an integer.
 * Assumes given string is just digits.
 */

int a2i(char* num_str) {
    int len = strlen(num_str);
    int sum = 0;
    int i = 0;
    int mult = 0;

    /* For 3 digit number, start multiplier at 100 and divide by 10 until 1 */
    for (mult = pow(10,len-1); mult >= 1; mult /= 10, i++) {
        sum += (num_str[i]-'0') * mult;
    }
    return sum;
}

int main(int argc, char** argv) {
    int a, b;
    float avg;
    if (argc == 3) {
        a = a2i(argv[1]);
        b = a2i(argv[2]);
        avg = (a+b) / 2.0;
        printf("%.2f\n", avg);
    }
    else {
        printf("Outputs average of two numbers\n");
        printf("Usage:  %s <num1> <num2>\n", argv[0]);
    }
    return 0;
}
