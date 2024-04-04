app: app.c
	clear && gcc app.c not_formal.c expression_struct.c term_struct.c utils.c session.c -o out
	./out