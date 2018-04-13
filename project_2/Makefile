CXXFLAGS=-std=c++14

main: main_project2.o funcs_project2.o
	g++ -o main main_project2.o funcs_project2.o

main.o: main_project2.cpp header_project2.h
	g++ $(CXXFLAGS) -c main_project2.cpp

funcs.o: funcs_project2.cpp header_project2.h
	g++ $(CXXFLAGS) -c funcs_project2.cpp

clean:
	rm -f main_project2.o funcs_project2.o

run:
	./main
