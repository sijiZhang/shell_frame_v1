#ifndef execute_h
#define execute_h
#include "builtin_cmd.h"
#include "externs.h"
#include "parse.h"
#include "shell.h"
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

void execvp_plus(char** parsed);

void execArgs(char** parsed);

void execArgsredirect(char** parsed);

void execArgsPiped(char** parsed, char** parsedpipe);

#endif /* execute_h */
