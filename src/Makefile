
CC = gcc

all:
	echo "Make targets include: make des, make idea, and make clean."

des: main.c my_des.c my_des.h
	$(CC)  -DDO_DES -DCRYPT_BINARY_DES -o des.bin main.c my_des.c  

idea: main.c my_idea.c my_idea.h
	$(CC)  -DDO_IDEA -o idea.bin main.c my_idea.c 

clean:
	rm -rf des.bin idea.bin
