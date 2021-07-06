#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "aaaabbcccdee";

    int n = strlen(str);
    char temp;
    int count = 1;
    
    for (int i=0; i<n; i++)
    {
        temp = str[i];
        if (str[i] == str[i+1])
        {
            count++;
        }
        else
        {
            printf("%c%d", temp, count);
            count = 1;
        }
    }
    
    return 0;
}