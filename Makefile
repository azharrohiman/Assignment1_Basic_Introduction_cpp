CC=g++

driver: driver.o database.o
	$(CC) driver.o database.o -o driver

driver.o: driver.cpp
	$(CC) -c driver.cpp

database.o: database.cpp database.h
	$(CC) -c database.cpp

clean:
	rm *.o driver
