A91: main.o function_1.o function_2.o function_3.o
	gcc -o A91 main.o function_1.o function_2.o function_3.o
main.o: main.c
	gcc -c main.c
function_1.o: function_1.c
	gcc -c function_1.c
function_2.o: function_2.c
	gcc -c function_2.c
function_3.o: function_3.c
	gcc -c function_3.c
