all:main.o Ctest/test.o
	gcc main.o Ctest/test.o -o ./bin/CRun
main.o:main.c 
	gcc -c main.c
Ctest/test.o:Ctest/test.c
	gcc -c Ctest/test.c -o Ctest/test.o
.PHONY:clean
clean:
	rm -rf *.o Ctest/*.o
