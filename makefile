app: app.c
	clear && gcc app.c not_formal.c -o out
	./out