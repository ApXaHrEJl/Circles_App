all: bin/circles_app

bin/circles_app: build/main.o build/props.o build/scan.o
	gcc -Wall -Werror build/main.o build/props.o build/scan.o -o bin/circles_app -lm

build/props.o: src/props.c
	gcc -Wall -Werror -c src/props.c -o build/props.o 

build/scan.o: src/scan.c
	gcc -Wall -Werror -c src/scan.c -o build/scan.o 

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o 

clean:
	rm -rf build/*.o bin/circles_app

.PHONY: all clean install uninstall

