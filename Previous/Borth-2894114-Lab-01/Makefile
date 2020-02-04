Program: main.o Executive.o ClassRegister.o Course.o
	g++ -std=c++11 -g -Wall main.o Executive.o ClassRegister.o Course.o -o Program

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

ClassRegister.o: ClassRegister.h ClassRegister.cpp
	g++ -std=c++11 -g -Wall -c ClassRegister.cpp

Course.o: Course.h Course.cpp
	g++ -std=c++11 -g -Wall -c Course.cpp

clean:
	rm *.o Program
