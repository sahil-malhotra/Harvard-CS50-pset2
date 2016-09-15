#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

string VigenereCipher(string plain, string key);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: vigenere <key>\n");
        printf("Wrong number of parameters, string or negative number supplied. Aborting.\n");
        return (1);
    }
    
    string key = argv[1];
    
    for(int i=0, j = strlen(key); i<j; i++)
    {
        if(!isalpha(key[i]))
        {
            printf("Usage: ./vigenere <key>\n");
            printf("Non-alphabetic characters given. Aborting.\n");
            return(1);
        }
    }
    
  
    string plaintext;
    
    do
    {
        plaintext = GetString();
    } while (strlen(plaintext)==0);
    
    string result = VigenereCipher(plaintext,key);
    
    printf("%s\n", result);
    
    return 0;
}

string VigenereCipher(string plain, string key)
{
    int keylength = strlen(key);
    
    char* cipher=plain;
    
    for(int i=0, j=0, n=strlen(plain); i<n; i++)
    {
        if(isalpha(plain[i]))
        {
         char keyReferenceValue = (isupper(key[j % keylength])) ? 'A' : 'a';
         
         char referenceValue = (isupper(plain[i])) ? 'A' : 'a';
         
          cipher[i] = ((plain[i] - referenceValue + (key[(j % keylength)] - keyReferenceValue)) % 26) + referenceValue;
          
          j++;
        }
        else
        {
            cipher[i]=plain[i];
        }
    }
    
    return cipher;
}