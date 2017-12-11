all: control.c
	gcc -o control control.c

clean:
	rm *o
	rm *~

run: all
	./control
