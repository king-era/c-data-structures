//Deque using DLL
#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
		node *prev;
		node(int value){
			data=value;
			next=prev=NULL;
		}
};
class deque{
	node *front;
	node *rear;
	int deqsize;
	public:
		deque(){
			front=rear=NULL;
			deqsize=0;
		}
		void insertFront(int v);
		void insertRear(int v);
		void deleteFront();
		void deleteRear();
		int getFront();
		int getRear();
		bool isempty();
		int size();
		void erase();
};
main(){
	deque dq;
	dq.insertFront(2);
	dq.insertRear(34);
	dq.deleteFront();
	dq.deleteFront();
	dq.getRear();
}
void deque::insertFront(int v){
	if(front==NULL){
		front=new node(v);
		rear=front;
	}
	else{
		node *p = new node(v);
		p->next=front;
		front->prev=p;
		front = p;
	}
		++deqsize;
}
void deque::insertRear(int v){
	if(rear==NULL){
		rear = new node(v);
		front  = rear;
	}
	else{
		node *p = new node(v);
		rear->next=p;
		p->prev=rear;
		rear=p;
	}
	++deqsize;
}
void deque::deleteFront(){
	if(front!=NULL){
		front  = front->next;
		if(front==NULL){
			rear=NULL;
		}
		--deqsize;
	}
}
void deque::deleteRear(){
	if(rear!=NULL){
		rear=rear->prev;
		if(rear==NULL){
			front=NULL;
		}
		--deqsize;
	}
}
void deque::erase(){
	front = rear = NULL;
	deqsize=0;
}
bool deque::isempty(){
	if(front==NULL && rear==NULL){
		return true;
	}
	return false;
}
int deque::getFront(){
	if(front!=NULL){
		return front->data;
	}
}
int deque::getRear(){
	if(rear!=NULL){
		return rear->data;
	}
}
int deque::size(){
	return deqsize;
}
