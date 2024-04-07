app: main.c
	clear && gcc main.c syntax_analysis_expression_evaluation.c -o bin/out
	./bin/out