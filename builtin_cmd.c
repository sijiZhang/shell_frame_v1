#include "builtin_cmd.h"

void Help() 
{ 
    puts("\n***WELCOME TO MY SHELL HELP***"
        "\nCopyright @ Suprotik Dey"
        "\n-Use the shell at your own risk..."
        "\nList of Commands supported:"
        "\n>cd"
        "\n>ls"
        "\n>exit"
        "\n>all other general commands available in UNIX shell"
        "\n>pipe handling"
        "\n>improper space handling"); 
  
    return; 
} 

int builtin_cmd(char** parsed) 
{ 
    int cmd_number = 4, i, flag = 0; 
    char* ListOfOwnCmds[cmd_number]; 
    char* username; 
  
    ListOfOwnCmds[0] = "exit"; 
    ListOfOwnCmds[1] = "cd"; 
    ListOfOwnCmds[2] = "help"; 
    ListOfOwnCmds[3] = "clear"; 
  
    for (i = 0; i < cmd_number; i++) { 
        if (strcmp(parsed[0], ListOfOwnCmds[i]) == 0) { 
            flag = i + 1; 
            break; 
        } 
    } 
  
    switch (flag) { 
    case 1: 
        printf("\nGoodbye\n"); 
        exit(0); 
    case 2: 
        if(chdir(parsed[1]) == -1)
            printf("\nfailed to change the directory，check your input!!\n");
        return 1; 
    case 3: 
        Help(); 
        return 1; 
    case 4: 
        clear();
        return 1; 
    default: 
        break; 
    } 
    return 0; 
} 