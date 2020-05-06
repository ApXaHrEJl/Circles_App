all: bin/circles_app bin/test_app

bin/test_app: build/props.o build/scan.o build/main_test.o build/func_tests.o
	gcc -Wall -Werror build/main_test.o build/props.o build/scan.o build/func_tests.o -o bin/test_app -lm

build/main_test.o: test/main.c
	gcc -Wall -Werror -I thirdparty -I src -c test/main.c -o build/main_test.o 

build/func_tests.o: test/func_tests.c
	gcc -Wall -Werror -I thirdparty -I src -c test/func_tests.c -o build/func_tests.o

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

.PHONY: all clean

