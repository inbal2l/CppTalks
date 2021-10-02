all: app

main.o: main.cpp
		gcc -c -o main.o -O0 main.cpp

mylib.o: mylib.cpp mylib.hpp
		g++ -c -O0 mylib.cpp -o mylib.o

nlibcpp.o: newlibstdcpp.cpp newlibstdcpp.hpp
		g++ -c -O0 newlibstdcpp.cpp -o newlibstdcpp.o

app: main.o mylib.o newlibstdcpp.o  
		g++ main.o mylib.o newlibstdcpp.o -O0 -o app

.PHONY : clean

clean:
	rm -f main.o mylib.o newlibstdcpp.o app
