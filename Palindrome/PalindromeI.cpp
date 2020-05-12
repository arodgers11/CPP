#include "PalindromeI.hpp"
#include<string>

using namespace std;

stack::node* stack::gettop() const {return top;}
//default constructor
stack::stack(){top=nullptr;size=0;}
//copy constructor
stack::stack(const stack  &s) {
		if(s.isempty()){top=nullptr;}
		else{
			node *temp=s.gettop();
			node *newstack=new node;
			newstack->data=temp->data;
			top=newstack;
			size=1;
			while(temp->next!=nullptr){
				temp=temp->next;
				newstack->next=new node;
				newstack=newstack->next;
				newstack->data=temp->data;
				size++;
			}
		}
	}
//destructor keeps popping until empty
stack::~stack(){
		if(top==nullptr)delete top;
		else{while(!isempty())pop();}
		}
//adds a value to the top of the stack
void stack::push(char x){
		node *newnode=nullptr;
		newnode=new node;
		newnode->data=x;
		if(isempty()){top=newnode;newnode->next=nullptr;size=1;}
		else{newnode->next=top;top=newnode;size++;}
	}
//takes the top value off the stack
char stack::pop(){
		if(!isempty()){
			node *temp=nullptr;
			char value=top->data;
			temp=top->next;
			delete top;
			top=temp;
			size--;
			return value;
		}
		else throw "empty stack";
	}

//constructs empty queue of size num
queue::queue(size_t num) {qarray=new char[num];maxsize=num;front=0;rear=-1;size=0;}
//copy constructor
queue::queue(const queue &q) {
		qarray=new char[q.maxsize];
		for(int i=0;i<maxsize;i++)push(q.qarray[i]);
	}
//adds a new vlaue to the rear of the queue
void queue::push(char c) {
		if(size<maxsize){
			rear=(rear+1)%maxsize;
			qarray[rear]=c;
			size++;
		}
		else throw "queue is full\n";
	}
//takes the front value off the queue
char queue::pop(){
		if(isempty())
			throw "empty queue\n";
		else {
			char value=qarray[front];
			front=(front+1)%maxsize;
			size--;
			return value;
		}
	}

//default constructor of the PalindromeI object	
PalindromeI::PalindromeI(){}
//default destructor
PalindromeI::~PalindromeI(){}
//tests strings for palindromeness
int PalindromeI::test_string(const string& s) {
		stack st;
		queue q=queue(s.length());
		int l=s.length();
		//adds the chars from string to stack and queue
		for(int i=0;i<l;i++) {
			if(isalnum(s[i])){st.push(s[i]);q.push(s[i]);}
		}
		if(st.isempty() && q.isempty()) return -1;
		int u=q.used();
		int matches=0;;
		char a;
		char b;
		for(int i=0;i<u;i++) {
			if(u==0 || u==1)return -1;
			//change both chars to upper becuase A!=a but A==A
			a=toupper(st.pop());
			b=toupper(q.pop());
			if(a==b)matches++;
			//return number of matched chars
			else return matches;
			//only returns -1 if both stack and queue are empty
			if(st.isempty() && q.isempty()) return -1;
		}
		//just in case something goes horribly wrong
		return 999;
	}