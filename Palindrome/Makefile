CC = g++
FLAGS = -std=c++11

all: palindrome.out clean

PalindromeI.o: PalindromeI.cpp
	    ${CC} ${FLAGS} -c PalindromeI.cpp
		
PalindromeR.o: PalindromeR.cpp
	    ${CC} ${FLAGS} -c PalindromeR.cpp

palindrome.out: PalindromeI.o PalindromeR.o test_palindrome.cpp
		${CC} ${FLAGS} test_palindrome.cpp *.o -o palindrome.out
		
clean:  
	rm -f *.o
	rm -f *~
	rm -f \#*