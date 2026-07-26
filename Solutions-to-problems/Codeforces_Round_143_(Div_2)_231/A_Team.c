#include<stdio.h>
int main()
{
    int i;
    int a,b,c;
    int n = 0;
    scanf("%d",&i);
    while (i>0)
    {
        scanf("%d%d%d",&a,&b,&c);
        if (a == 1 && b == 1 && c == 0)
        {
            n++;
        }
        else if (b == 1 && c == 1 && a == 0)
        {
            n++;
        }
        else if (a == 1 && c  == 1 && b == 0)
        {
            n++;
        }
        else if (a == 1 && b == 1 && c == 1)
        {
            n++;
        }
        i--;
    }
    printf("%d\n",n);
    return 0;
}