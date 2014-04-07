
build/cdata: lib/test.o lib/list.o lib/array.o lib/stack.o lib/queue.o lib/map.o lib/tree.o
	cc -g -Wall lib/test.o lib/list.o lib/array.o lib/stack.o \
	lib/queue.o lib/map.o lib/tree.o -o build/cdata
	
lib/test.o: src/data_structures.h src/test.c
	cc -g -Wall -c src/test.c -o lib/test.o
	
src/data_structures.h: src/list.h src/array.h src/stack.h src/queue.h src/map.h
	
lib/list.o: src/list.c
	cc -g -Wall -c src/list.c -o lib/list.o
	
lib/array.o: src/array.c
	cc -g -Wall -c src/array.c -o lib/array.o
	
lib/stack.o: src/stack.c src/array.c
	cc -g -Wall -c src/stack.c -o lib/stack.o
	
lib/queue.o: src/queue.c src/array.c
	cc -g -Wall -c src/queue.c -o lib/queue.o
	
lib/map.o: src/map.c src/array.c
	cc -g -Wall -c src/map.c -o lib/map.o
	
lib/tree.o: src/tree.c
	cc -g -Wall -c src/tree.c -o lib/tree.o
	
clean:
	rm -f build/*
	rm -f lib/*.o
	rm -rf *.dSYM
	
run: build/cdata
	./build/cdata