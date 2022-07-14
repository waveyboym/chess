main:
	g++ -std=c++98 stack.cpp main.cpp -o main
run:
	./main
clean:
	rm *.o main
valgrind:
	valgrind --tool=memcheck --leak-check=yes ./main
