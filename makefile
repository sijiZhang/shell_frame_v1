cc = gcc
prom = shell
obj = shell.o parse.o execute.o builtin_cmd.o main.o
 
$(prom): $(obj)
	$(cc)   -lreadline -o $(prom) $(obj)
 
builtin_cmd.o: builtin_cmd.c $(deps)
	$(cc) -c builtin_cmd.c
 
parse.o: parse.c $(deps)
	$(cc) -c parse.c
 
execute.o: execute.c $(deps)
	$(cc) -c execute.c
 
shell.o: shell.c $(deps)
	$(cc) -lreadline -c shell.c

main.o: main.c $(deps)
	$(cc) -lreadline -c main.c
