opt = -c -Wall -Wextra -std=c11

main.exe : test_vecteur.o p_signal.o p_vecteur.o
	gcc -o test_vecteur.exe test_vecteur.o p_signal.o p_vecteur.o
	./test_vecteur.exe

main.o : test_vecteur.c p_signal.h p_vecteur.h
	gcc ${opt} test_vecteur.c

p_signal.o : p_signal.h p_signal.c
	gcc ${opt} p_signal.c

p_vecteur.o : p_vecteur.h p_vecteur.c
	gcc ${opt} p_vecteur.c