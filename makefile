
CC = gcc
CFLAGS = -g -Wall

all: isort txtfind
 #operate both of the programs

#The main program
isort: sort.o sort.a
	$(CC) $(CFLAGS) -o isort sort.o sort.a

#Static library				
sort.a: sort.o
	ar -rcs sort.a sort.o			

#compilation of sort.c
sort.o: sort.c 
	$(CC) $(CFLAGS) -c sort.c

#The main program
txtfind: searchTxt.o searchTxt.a
	$(CC) $(CFLAGS) -o txtfind searchTxt.o searchTxt.a

#Static library				
searchTxt.a: searchTxt.o
	ar -rcs searchTxt.a searchTxt.o			

#compilation of searchTxt.c
searchTxt.o: searchTxt.c 
	$(CC) $(CFLAGS) -c searchTxt.c

#those are not real files
.PHONY: all clean

clean:
	rm -f *.o *.a *.so isort