# chess
An object oriented approach to chess in C++

# class diagram
![class diagram](preview-img/chess%20class%20diagrams.jpg "class diagram")

# brief
uses object oriented principles such as inheritance and polymorphism to implement a chess game on a board which aggregrate from the chess pieces. This project is done in C++98.

link to 2d version: https://github.com/waveyboym/chess2d

# features to be implemented
1. en passant
2. castling

# to run this code you will need to install:
1. make: https://linuxhint.com/install-make-ubuntu/
2. valgrind: https://wiki.ubuntu.com/Valgrind
3. gcc: https://linuxize.com/post/how-to-install-gcc-compiler-on-ubuntu-18-04/
4. zip(optional): https://speedysense.com/zip-and-unzip-command-in-ubuntu-terminal/
5. unzip(optional): https://speedysense.com/zip-and-unzip-command-in-ubuntu-terminal/
6. gdb: http://www.gdbtutorial.com/tutorial/how-install-gdb


# to run the code:
open a terminal in the directory where the file is located, you would open a terminal in a directory like so: "parent_directory/child_directory/chess"
1. type in the command make to compile the files
2. type in the command make run to run the files
3. type in make clean to clear out compilation files after running(optional, compilation takes a bit of time so you can decide to not clean out the object code)

*all of the files have already been compiled and linked so you only need to run them but you can still recompile them if you'd like to*

# make commands
1. make - compiles files
2. make run - runs the compiled files
3. make clean - removes the compiled files
4. make vangaurd - checks for memory leaks and reports if any are found
5. make gdb - opens up the gdb debugging tool in the terminal

# makefile and file paths
the makefile may be modified but if you modify the file paths, you'll have to change both file paths in the makefiles and in the individual .h files which inherit from the file that has had it's file path changed. The class diagram will show which files inherit and aggregrate from each other
