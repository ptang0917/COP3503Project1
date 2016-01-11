all: project2

project2: main.o project2.o
	g++ main.cpp project2.cpp -o project2

main.o: main.cpp project2.h
	g++ -c main.cpp

project2.o: project2.cpp project2.h
	g++ -c project2.cpp

clean:
	rm -rf * .o
	rm -rf graph
    

