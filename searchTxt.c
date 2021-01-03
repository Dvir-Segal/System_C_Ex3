#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LINE 256
#define WORD 30


int similar (char* s, char* t){
    if (!strcmp(s, t)){
        return 1;
    }
    if ((strlen(s)-strlen(t)>1) || (strlen(s)-strlen(t)==0)){
        return 0;
    }
    int noMatch=0;
    for (int i=0; s[i]; i++){
        if(*s!=*t){
            noMatch++;
            s++;
        }
        else{
            s++;
            t++;
        }
    }
    if(noMatch>1){
        return 0;
    }
    return 1;
}
    
    
int main(){
    char search[30];
    scanf("%s", search);
    char *pw=search;
    char ch='Q';
    scanf(" %c", &ch);
    char lines[250][LINE*WORD];
    char words[250*LINE][WORD];
    switch (ch)
    {
    case 'a':
        for (int i = 0; i < 250; i++){
            scanf("%[^\n]%*c",lines[i]);
        }
        for (int i = 0; i < 250; i++){
            if(strstr(*(lines+i), pw)){
               printf("%s\n", lines[i]);
            }
        }
        break;
    case 'b':
        for (int i = 0; i < 256; i++){
            scanf(" %s", words[i]);
            //printf("%s\n", words[i]);
        }
        for (int i = 0; i < 100; i++){
            if(similar(words[i], pw)){
                printf("%s\n", words[i]);
            }
        }
        break;
    }
    return 0;
}