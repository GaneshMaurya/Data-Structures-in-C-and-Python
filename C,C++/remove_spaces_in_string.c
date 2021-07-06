#include <stdio.h>

void removeSpace(char s[100])
{
    int i=0, j=0;

    while (s[i])
    {
        if (s[i] != ' ')
        {
            s[j++] = s[i];
        }
        i++;
    }
    s[j] = '\0';

    printf("%s", s);
}

int main()
{
    char s[100] = " g e e k  ";

    removeSpace(s);
    
    return 0;
}