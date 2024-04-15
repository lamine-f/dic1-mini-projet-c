app: src/main.c
	clear && gcc src/structs/*.c src/*.c -o bin/arithmetic-resolver
	./bin/arithmetic-resolver