opt = -c -Wall -Wextra -std=c11

calculette.exe : calculette.o
	gcc -o calculette.exe calculette.o

calculette.o : calculette.c
	gcc ${opt} calculette.c