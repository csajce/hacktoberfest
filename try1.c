#include<stdio.h>
#include<ctype.h>
#include <string.h>
int main()
{
    int i,j=0,k;
   char word[1000],str1[10000];
   printf("Enter the sentence");
   gets(word);
   for(i=0;i<=strlen(word);i++)
   {

       if(isalpha(word[i]) || word[i] == ' ' )
       {
           str1[j++]=word[i];
       }
   }
   strrev(str1);
   printf("%s",str1);
}
