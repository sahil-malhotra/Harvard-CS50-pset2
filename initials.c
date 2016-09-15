#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string name;
    name = GetString();
    int i, n;
    
    for(i=0, n=strlen(name); i<n; i++)
    {
        if(name[i]==name[0])
        {
            printf("%c", toupper(name[i]));
        }
        else if(name[i]==' ')
        {
            printf("%c", toupper(name[i+1]));
        }
        else if(i == n-1)
        {
            printf("\n");
        }
    }
}