#include "parse.h"

int parsePipe(char* str, char** strpiped) 
{ 
    int i; 
    for (i = 0; i < 2; i++) { 
        strpiped[i] = strsep(&str, "|"); 
        if (strpiped[i] == NULL) 
            break; 
    } 
  
    if (strpiped[1] == NULL) 
        return 0; // returns zero if no pipe is found. 
    else { 
        return 1; 
    } 
} 

int parse_redirect(char* str,char** strredirect)
{
    char* b = str;
    while(*b != '\0'){
    if(*b == '<')
          reflag = 1;
    if(*b == '>')
          reflag = 2;
    b++;
}
    int i;
   for (i = 0; i < 2; i++) { 
        strredirect[i] = strsep(&str, "><"); 
        if (strredirect[i] == NULL) 
            break; 
    } 
   
    if (strredirect[1] == NULL) 
        return 0; // returns zero if no pipe is found. 
    else {
        infile = strredirect[1];
        outfile = strredirect[1];
        return 2; 
    } 
}

// function for parsing command words 
void parseSpace(char* str, char** parsed) 
{ 
    int i; 
  
    for (i = 0; i < MAXLIST; i++) { 
        parsed[i] = strsep(&str, " \t\r\n"); 
  
        if (parsed[i] == NULL) 
            break; 
        if (strlen(parsed[i]) == 0) 
            i--; 
    } 
} 
  
int processString(char* str, char** parsed, char** parsedpipe)
{
    char* strpiped[2];
    char* strredirect[2];
    int piped = 0,redirect = 0; 
  
    piped = parsePipe(str, strpiped); 
    
    redirect = parse_redirect(str,strredirect);

    if (piped) { 
        parseSpace(strpiped[0], parsed); 
        parseSpace(strpiped[1], parsedpipe); 
  
    }else if(redirect){
        parseSpace(strredirect[0],parsed);
    }else { 
        parseSpace(str, parsed); 
    } 
  
    if (builtin_cmd(parsed)) 
        return 0; 
    else
        return 1 + piped + redirect; 
}