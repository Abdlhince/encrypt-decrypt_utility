#
# =======================================================
#                  cryptoMagic
# =======================================================
# FINAL BINARY Target
./bin/cryptoMagic : ./obj/cryptoMagic.o ./obj/encrypt.o
	cc ./obj/cryptoMagic.o ./obj/encrypt.o -o ./bin/cryptoMagic
#
# =======================================================
#                     Dependencies
# =======================================================                     
./obj/cryptoMagic.o : ./src/cryptoMagic.c ./inc/encrypt.h
	cc -c ./src/cryptoMagic.c -o ./obj/cryptoMagic.o

./obj/encrypt.o : ./src/encrypt.c ./inc/encrypt.h
	cc -c ./src/encrypt.c -o ./obj/encrypt.o

#
# =======================================================
# Other targets
# =======================================================                     
all : ./bin/cryptoMagic

clean:
	rm -f ./bin/*
	rm -f ./obj/*.o
	


