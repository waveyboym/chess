# chess
An object oriented approach to chess in C++

# class diagram


# brief
uses object oriented principles such as inheritance and polymorphism to implement a chess game on a board which aggregrate from the chess pieces. This project is done in C++98.

#features to be implemented
en passant
castling
an interactive board

#to run this code you will need to install:
1. make: https://linuxhint.com/install-make-ubuntu/
2. valgrind: https://wiki.ubuntu.com/Valgrind
3. gcc: https://linuxize.com/post/how-to-install-gcc-compiler-on-ubuntu-18-04/
4. zip(optional): https://speedysense.com/zip-and-unzip-command-in-ubuntu-terminal/
5. unzip(optional): https://speedysense.com/zip-and-unzip-command-in-ubuntu-terminal/
6. gdb: http://www.gdbtutorial.com/tutorial/how-install-gdb


#to run the code:
open a terminal in the directory where the file is located, so if you wanted to test run the c++ version, you would open a terminal in a directory like so: "parent_directory/child_directory/c++"
type in the command make to compile the files
type in the command make run to run the files
type in make clean to clear out compilation files after running
shared commands
make - compiles files
make run - runs the compiled files
make clean - removes the compiled files
make vangaurd - checks for memory leaks and reports if any are found
make gdb - opens up the gdb debugging tool in the terminal

#mkefile and file paths
the makefile may be modified but if you modify the file paths, you'll have to change both file paths in the makefiles and in the individual .h files which inherit from the file that has had it's file path changed. The class diagram will show which files inherit and aggregrate from each other
