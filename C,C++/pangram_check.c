#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool checkPangram(char s[100])
{
    int n = strlen(s);
    int arr[26];

    for (int i=0; i<26; i++)
    {
        arr[i] = 0;
    }

    for (int i=0; i<n; i++)
    {
        if (s[i] == '\0')
        {
            break;
        }
        else if ('a' <= s[i] && s[i] <= 'z')
        {
            arr[s[i]-97]++;
        }
    }

    for (int i=0; i<26; i++)
    {
        if (arr[i] == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    char s[100] = "the quick brown fox jumps over the dog";

    if (checkPangram(s))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
    
    return 0;
}