
test: lib/test.o lib/list.o
	cc -g -Wall lib/test.o lib/list.o -o build/clist
	
lib/test.o: src/test.c src/list.h
	cc -g -Wall -c src/test.c -o lib/test.o
	
lib/list.o: src/list.c src/list.h
	cc -g -Wall -c src/list.c -o lib/list.o
	
clean:
	rm -f build/clist
	rm -f lib/*.o
	rm -rf *.dSYM
	
run:
	./build/clist