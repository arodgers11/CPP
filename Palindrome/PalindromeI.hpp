// palindromeI.hpp -- iterative palindrome tester
// c. 2017 Andy Rodgers

#ifndef PALINDROMEI_HPP
#define PALINDROMEI_HPP

#include <string>
#include <iostream>

using namespace std;

//STACK CLASS
struct stack {
	struct node {
	char data;
	node *next;
	};
	private:
	node *top;
	int size;
	public:
	node* gettop() const;
	stack();
	stack(const stack  &);
	~stack();
	int getsize(){return size;}
	bool isempty() const {return top==nullptr;}
	void push(char);
	char pop();
};
//END STACK

//QUEUE CLASS
struct queue {
	private:
	int maxsize,size,front,rear;
	char *qarray;
	public:
	int getfront(){return front;}
	int getrear(){return rear;}
	int used(){return size;}
	int capacity(){return maxsize;}
	bool isempty(){return size==0 || rear==-1;}
	bool isfull(){return size==maxsize;}
	queue(size_t);
	queue(const queue &);
	~queue(){if(qarray!=nullptr)delete [] qarray;}
	void push(char);
	char pop();
};
//END QUEUE

class PalindromeI {
	public:
	PalindromeI();
	int test_string(const string& s);
	~PalindromeI();
};

#endif
