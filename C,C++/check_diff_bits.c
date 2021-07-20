#include <stdio.h>
#include <stdlib.h>

int checkDiff(int n)
{
    int count = 0;
    while (n != 0)
    {
        n = n&(n-1);
        count++;
    }
    return count;
}

int main()
{
    int a = -1;
    int b = -2;

    printf("%d", checkDiff(a^b));
    
    return 0;
}