#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//AAAA

char *str_trim(char *string){
    if (string == NULL || *string == 0) return string;

    while (isspace(*string))
        string ++;

    char *strEnd = string + strlen(string) - 1;

    while (isspace(*strEnd))
        strEnd--;
    *(strEnd+1) = 0;

    return string;
}

char *str_cut(char *s, int start, int end){
    char *strEnd = s + end -1;
    *strEnd = 0;
    
    s += start;
    // char *strEnd = s + strlen(s) - 1;
    // for(int i = strlen(s)-1; i >= end; i--){
    //     *strEnd = 0;
    //     strEnd --; 
    // }
    return s;
}
