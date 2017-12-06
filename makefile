dealer: dealer.o readline.o car.o
	gcc -o dealer dealer.o readline.o car.o

dealer.o: dealer.c readline.h car.h
	gcc -c dealer.c

readline.o: readline.c readline.h
	gcc -c readline.c

car.o: car.c car.h readline.h
	gcc -c car.c


