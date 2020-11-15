#ifndef parse_h
#define parse_h
#include "builtin_cmd.h"
#include "execute.h"
#include "parse.h"
#include "shell.h"
#include "externs.h"
// C Program to design a shell in Linux 
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h> 
#include<readline/readline.h> 
#include<readline/history.h> 
  
#define MAXCOM 1000 // max number of letters to be supported 
#define MAXLIST 100 // max number of commands to be supported 
  
// Clearing the shell using escape sequences 
#define clear() printf("\033[H\033[J") 

char *infile;
char *outfile;

int reflag;

int parsePipe(char* str, char** strpiped);

int parse_redirect(char* str,char** strredirect);

void parseSpace(char* str, char** parsed);

int processString(char* str, char** parsed, char** parsedpipe);



#endif /* parse_h */
