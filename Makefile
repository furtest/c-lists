

compile : list.c test.c
	gcc -g -Wall $^ -o $@

mem : compile
	valgrind ./$^

clean :
	rm -rf compile