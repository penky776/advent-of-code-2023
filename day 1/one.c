#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char *filename = "input.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    char line[200];
    int two_digit_index = 0;
    int two_digit_number[1000];

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        printf("Checking line: %s \n", line);

        int first_digit = -1;
        int last_digit = -1;

        int digit_index = 0;

        for (int i = 0; line[i] != '\0'; i++)
        {
            int prev_digit_index = digit_index;
            if (isdigit(line[i]))
            {
                if (digit_index == 0)
                {
                    first_digit = line[i] - '0';
                }
                printf("%c is a number. \n", line[i]);

                digit_index++;
            }
            else
            {
                printf("%c is not a number. \n", line[i]);
            }

            if (prev_digit_index < digit_index)
            {
                last_digit = line[i] - '0';
            }
        }

        // concatenate the first and last digits
        printf("%d is the first digit. \n", first_digit);
        printf("%d is the last digit. \n", last_digit);

        int two_digit_no = first_digit * 10 + last_digit;

        printf("%d is the two digit number. \n", two_digit_no);

        two_digit_number[two_digit_index] = two_digit_no;
        two_digit_index++;
    }

    fclose(fp);

    // print all the two digit numbers
    int loop;

    int i_i = 1;

    int length = sizeof(two_digit_number) / sizeof(two_digit_number[0]);
    for (loop = 0; loop < length; loop++)
    {
        printf("%d) %d \n ", i_i, two_digit_number[loop]);
        i_i++;
    }

    // add all the two digit numbers

    int sum = 0;
    for (loop = 0; loop < length; loop++)
    {
        sum = sum + two_digit_number[loop];
    }

    printf("Total: %d \n", sum);

    return 0;
}