#include "execute.h"

void execvp_plus(char** parsed){
    if (strcmp(parsed[0], "cat")==0){
            parsed[0] = "./cat";
            execvp(parsed[0], parsed);
        }
        else if (strcmp(parsed[0], "cp")==0){
            parsed[0] = "./cp";
            execvp(parsed[0], parsed);
        }
        else if (strcmp(parsed[0], "lsdir")==0){
     	    printf("------------------------\n");
            parsed[0] = "./lsdir";
            execvp(parsed[0], parsed);
        }
        else if (strcmp(parsed[0], "pwd")==0){
            printf("-----------\n");
            parsed[0] = "./pwd";
            execvp(parsed[0], parsed);
        }
        else if (strcmp(parsed[0], "rm")==0){
            parsed[0] = "./rm";
            execvp(parsed[0], parsed);
        }
        else if (strcmp(parsed[0], "help")==0){
            parsed[0] = "./help";
            execvp(parsed[0], parsed);
        }
        else if (strcmp(parsed[0], "touch")==0){
            parsed[0] = "./mytouch";
            execvp(parsed[0], parsed);
        }
        else if (strcmp(parsed[0], "mv")==0){
            parsed[0] = "./mytouch";
            execvp(parsed[0], parsed);
        }
        else if (strcmp(parsed[0], "cd")==0){
            parsed[0] = "./mytouch";
            execvp(parsed[0], parsed);
        }
        else if (strcmp(parsed[0], "mkdir")==0){
            parsed[0] = "./mymkdir";
            execvp(parsed[0], parsed);
        }
        else{
            execvp(parsed[0], parsed);
        }
}

void execArgs(char** parsed)
{
    pid_t pid = fork();

    if (pid == -1) {
        printf("\nFailed forking child..");
        return;
    } else if (pid == 0) {
        if (execvp(parsed[0], parsed) < 0) { 
            printf("\nCould not execute command.."); 
        } 
        exit(0);
    } else {
        // waiting for child to terminate
        wait(NULL);
        return;
    }
}

void execArgsredirect(char** parsed)
{
    if(strlen(infile)  == 0){
        printf("\nfile is missing ,please check your input.\n");
    }

    else{
        pid_t pid = fork();
        if (pid == -1) {
        printf("\nFailed forking child..");
        return;
    } else if (pid == 0) {
        if(reflag == 1){
            freopen(infile, "r", stdin);
        }else if(reflag == 2){
            freopen(outfile, "r", stdout);
        }
        if (execvp(parsed[0], parsed) < 0) { 
            printf("\nCould not execute command.."); 
        } 
        exit(0);
    } else {
        // waiting for child to terminate
        wait(NULL);
        return;
    }
    }
}

void execArgsPiped(char** parsed, char** parsedpipe) 
{ 
    // 0 is read end, 1 is write end 
    int pipefd[2];  
    pid_t p1, p2; 
  
    if (pipe(pipefd) < 0) { 
        printf("\nPipe could not be initialized"); 
        return; 
    } 
    p1 = fork(); 
    if (p1 < 0) { 
        printf("\nCould not fork"); 
        return; 
    } 
  
    if (p1 == 0) { 
        // Child 1 executing.. 
        // It only needs to write at the write end 
        close(pipefd[0]); 
        dup2(pipefd[1], STDOUT_FILENO); 
        close(pipefd[1]); 
  
        if (execvp(parsed[0], parsed) < 0) { 
            printf("\nCould not execute command 1.."); 
            exit(0); 
        } 
    } else { 
        // Parent executing 
        p2 = fork(); 
  
        if (p2 < 0) { 
            printf("\nCould not fork"); 
            return; 
        } 
  
        // Child 2 executing.. 
        // It only needs to read at the read end 
        if (p2 == 0) { 
            close(pipefd[1]); 
            dup2(pipefd[0], STDIN_FILENO); 
            close(pipefd[0]); 
            if (execvp(parsedpipe[0], parsedpipe) < 0) { 
                printf("\nCould not execute command 2.."); 
                exit(0); 
            } 
        } else { 
            // parent executing, waiting for two children 
            wait(NULL); 
            wait(NULL); 
        } 
    } 
}
