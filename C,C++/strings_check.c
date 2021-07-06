#include <stdio.h>
#include <string.h>

void stringcopy(char s1[50], char s2[50])
{
    int i=0;
    int n = strlen(s2);

    for (i=0; s1[i] != '\0'; i++)
    {
        s2[i] = s1[i];
    }

    while (i < n)
    {
        s2[i] = '\0';
        i++;
    }

    printf("%s", s2);
}

int main()
{
    char s1[50] = "hello";
    char s2[50] = "geeksforgeeks";

    stringcopy(s1, s2);
    
    return 0;
}