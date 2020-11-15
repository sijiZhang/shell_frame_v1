#include "shell.h"

void init_shell() 
{ 
    clear(); 
    printf("\n\n\n\n\n\t\t\t\t欢迎来到shell世界\n"); 
    sleep(2);
    clear();
    printf("\n\n\n\n\n\t\t\t\t你的时间非常宝贵\n");
    sleep(2); 
    clear();
    printf("\n\n\n\n\n\t\t\t\t你被我偷走了5秒钟哈哈哈哈哈哈哈哈哈哈哈哈\n");
    sleep(1);
    clear(); 
} 
  
// Function to take input 
int takeInput(char* str) 
{ 
    char* buf; 
  
    buf = readline(" "); 
    if (strlen(buf) != 0) { 
        add_history(buf); 
        strcpy(str, buf); 
        return 0; 
    } else { 
        return 1; 
    } 
} 
  
// Function to print Current Directory. 
void printDir() 
{ 
    char* username = getenv("USER");
    char hostname[100];
    int a = gethostname(hostname, sizeof(hostname));
    char* s;
    if(username == "root")
        s = "$";
    else
        s = "#";
    
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("[%s@%s%s]%s ", username, hostname, cwd,s);
} 
