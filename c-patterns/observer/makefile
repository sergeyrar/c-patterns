all:
	gcc -c -Wall -Werror -fpic timesource.c -g
	gcc -c -Wall -Werror -fpic observer.c -g
	gcc -shared -o libclock.so *.o -lpthread -g
	gcc -L`pwd` -Wall -o test client.c -lclock -g 

clean:
	rm -f *.o
	rm -f test
