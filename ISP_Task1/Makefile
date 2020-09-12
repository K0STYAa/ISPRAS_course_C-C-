all: QuadraticEquationSolver

QuadraticEquationSolver: FilesEq/main.o FilesEq/Quad.o FilesEq/Test.o
	g++ FilesEq/main.o FilesEq/Quad.o FilesEq/Test.o -o QuadraticEquationSolver

main.o: FilesEq/main.cpp
	g++ -c FilesEq/main.cpp

Quad.o: FilesEq/Quad.cpp
	g++ -c FilesEq/Quad.cpp

Test.o: FilesEq/Test.cpp
	g++ -c FilesEq/Test.cpp

clean:
	rm FilesEq/*.o

clean_exe:
	rm QuadraticEquationSolver
