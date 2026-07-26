#include<stdio.h>
#include<string.h>
void string (int n);
int main()
{
    int i;
    scanf("%d",&i);
    string (i);
    return 0;
}
void string (int n)
{
    char word[105];
    
    while (n--)
    {
        scanf("%s",word);
        int len = strlen(word);

        if (len > 10)
            printf("%c%d%c\n",word[0],len-2,word[len-1]);
        else
            printf("%s\n",word);
    }
}