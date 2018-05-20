/*
Given two strings, the task is to check whether these strings are meta strings or not. Meta strings are the strings which can be made equal by exactly one swap in any of the strings. Equal string are 
not considered here as Meta strings.

Examples:

Input : str1 = "geeks" 
        str2 = "keegs"
Output : Yes
By just swapping 'k' and 'g' in any of string, 
both will become same.

Input : str1 = "rsting"
        str2 = "string
Output : No

Input :  str1 = "Converse"
         str2 = "Conserve"
*/
#include <stdio.h>
#include <string.h>

int metaString(char str1[], char str2[]){
    int str1Length = strlen(str1);
    int str2Length = strlen(str2);
    int i, firstMismatch=0;
    int i1=0; //indexes of mismatches
    char temp;
    if (str1Length != str2Length)
        return 0;
    for(i=0; i<str1Length; i++){
        if(str1[i] != str2[i]){
            if(firstMismatch==1){
                temp=str2[i1];
                str2[i1]=str2[i];
                str2[i]=temp;
                if(strcmp(str1,str2) == 0)
                    return 1;
                else
                    return 0;
            }else{
                i1=i;
                firstMismatch=1;
            }
        }
    }
    return 0;
}
int main() {
    char s1[] = "accddef";
    char s2[] = "fccddea";
    int result = metaString(s1, s2);
    if(result)
        printf("\nProvided strings are meta strings");
    else
        printf("\nProvided strings are not meta strings");
    return 0;
}
