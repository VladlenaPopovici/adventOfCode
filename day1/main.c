#include "../include/linked_list/linked_list.h"
#include <string.h>
#include <limits.h>

int my_strcmp(char *, char *);
int my_atoi(char *);

int main()
{
    FILE *ptr = fopen("input.txt", "r");

    if (ptr == NULL)
    {
        printf("Can not open file");
        return 0;
    }

    
    int group_of_weights[100];
    size_t group_size = 0;
    
    int max1 = INT_MIN + 2;
    int max2 = INT_MIN + 1;
    int max3 = INT_MIN;
    
    char line[20];

    while (fgets(line, sizeof(line), ptr) != NULL) {
        if (my_strcmp(line, "\n"))
        {
            int x = my_atoi(line);
            ++group_size;
            group_of_weights[group_size - 1] = x;
        } else
        {
            int sum = 0;
            for (size_t i = 0; i < group_size; i++)
            {
                sum += group_of_weights[i];
            }
            if (sum > max1) 
            {
                max3 = max2;
                max2 = max1;
                max1 = sum;
            }
            else if (sum > max2)
            {
                max3 = max2;
                max2 = sum;
            }
            else if (sum > max3)
            {
                max3 = sum;
            }
            
            
            
            group_size = 0;
        }
    }

    printf("sum of 3: %d", max1 + max2 + max3);
    fclose(ptr);
}

int my_strcmp(char *s1, char *s2)
{
    while (*s1 != '\0' || *s2 != '\0')
    {
        if (*s1 != *s2)
        {
            return 1;
        }
        s1++;
        s2++;
    }
    return !(*s1 == '\0' && *s2 == '\0');
}

int my_atoi(char *s)
{
    const int pow = 10;
    int result = 0;

    while (*s != '\n')
    {
        result += *s - '0';
        result *= pow;
        s++;
    }
    result /= pow;

    return result;
}