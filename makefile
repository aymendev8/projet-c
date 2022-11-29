opt = -c -Wall -Wextra -std=c11

test.exe: main.o p_nanodom.o p_texte_enrichi.o
	gcc -o test.exe main.o p_nanodom.o p_texte_enrichi.o

test_nanodom.exe: test_nanodom.o p_nanodom.o p_texte_enrichi.o
	gcc -o test_nanodom.exe test_nanodom.o p_nanodom.o p_texte_enrichi.o

main.o: main.c
	gcc ${opt} main.c

p_nanodom.o : p_nanodom.c
	gcc ${opt} p_nanodom.c

p_texte_enrichi.o: p_texte_enrichi.c
	gcc ${opt} p_texte_enrichi.c

clean :
	rm *.o
	rm *.exe