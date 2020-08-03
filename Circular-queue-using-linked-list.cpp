//Circular queue using linked list
#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node *next;
	node(int v){
		data=v;
	}
};
class cque{
	node *front;
	node *rear;
	public:
		cque(){
			front = rear = NULL;
		}
		int Front();
		int Rear();
		void enQueue(int v);
		void deQueue();
};
main(){
	cque cq;
	cout<<cq.Front()<<endl;
	cout<<cq.Rear()<<endl;
	cq.deQueue();
	cq.enQueue(2);
	cout<<cq.Rear()<<endl;
	cout<<cq.Front()<<endl;
	cq.deQueue();
	cout<<cq.Front()<<endl;
	cq.enQueue(2);
	cq.enQueue(4);
		cq.enQueue(6);
	cq.enQueue(8);
	cout<<cq.Front()<<endl;
	cout<<cq.Rear()<<endl;
}
void cque::enQueue(int v){
	if(front==NULL){
		front=new node(v);
		front->next=front;
		rear=front;
	}
	else{
		node *p=new node(v);
		p->next=rear->next;
		rear->next=p;
		rear=p;
	}
}
int cque::Front(){
	if(front!=NULL){
		return front->data;
	}
}
int cque::Rear(){
	if(rear!=NULL){
		return rear->data;
	}
}
void cque::deQueue(){
	if(front!=NULL){
		if(front->next=front){
			front=rear=NULL;
		}
		else{
			front=front->next;
		}
		
	}
}
