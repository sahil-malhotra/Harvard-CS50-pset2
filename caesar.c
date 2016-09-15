#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar <key>\n");
        return (1);
    }
    else
    {
        int k = atoi(argv[1]);
        string str;
        str = GetString();
        long n, i, j;
        for(i=1; i<k+1; i++)
        {
            for (j=0, n=strlen(str); j<n; j++)
            {
                if (isalpha(str[j]))
                {
                    if(str[j]=='z')
                    {
                        str[j]= 'a';
                    }
                    else if (str[j]=='Z')
                    {
                        str[j]='A';
                    }
                    else
                    {
                        str[j]=str[j]+1;
                    }
                }
            }
            
            if(i==k)
            {
                 printf("%s\n", str);
            }
        }
    }
}