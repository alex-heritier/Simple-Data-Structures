
build/cdata: lib/test.o lib/list.o lib/array.o
	cc -g -Wall lib/test.o lib/list.o  lib/array.o -o build/cdata
	
lib/test.o: src/data_structures.h src/test.c
	cc -g -Wall -c src/test.c -o lib/test.o
	
src/data_structures.h: src/list.h src/array.h
	
lib/list.o: src/list.c src/list.h
	cc -g -Wall -c src/list.c -o lib/list.o
	
lib/array.o: src/array.c src/array.h
	cc -g -Wall -c src/array.c -o lib/array.o
	
clean:
	rm -f build/*
	rm -f lib/*.o
	rm -rf *.dSYM
	
run: build/cdata
	./build/cdata