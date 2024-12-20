labyrinth: main.o
	gcc main.o roomManip.o stringManip.o construction.o -o labyrinth -Wall

main.o: main.c roomManip.o stringManip.o construction.o
	gcc main.c -c -o main.o -Wall

roomManip.o: roomManip.c roomManip.h
	gcc roomManip.c -c -o roomManip.o -Wall

construction.o: construction.c construction.h
	gcc construction.c -c -o construction.o -Wall

stringManip.o: stringManip.c stringManip.h
	gcc stringManip.c -c -o stringManip.o -Wall

clean:
	rm *.o
	rm labyrinth