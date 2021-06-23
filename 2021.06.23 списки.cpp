#include <iostream>	
using namespace std;
class List {	//односвяз список
	class Node {
	public:
		int data; Node* pNext;
		Node(int data = 0, Node* pNext = nullptr) :data{ data }, pNext{ pNext }{cout<<"Constructor Node " << this << endl; }
		~Node() { cout << "Distructor Node " << this << endl; }
	};
	Node* head;
	int size;
public:
	List() :head{ nullptr }, size{ 0 } { cout << "Constructor List " << this << endl; }
	~List() { cout << "Distructor List " << this << endl; }
	int getSize() { return size; }
	void push_back(int data) {
		if (head == nullptr) { head = new Node(data);	} 
		else {	
			Node* current = head;
			while (current->pNext != nullptr) {
				current = current->pNext;
			}
			current->pNext = new Node(data);
		}	
		size++;
	}
	int operator[](const int index){ // print [i]
		int counter = 0;
		Node* current = head;
		while (current != nullptr) {
			if (index == counter) return current->data;
			else {
				current = current->pNext;
				counter++;
			}
		}
	}
	void pop_front() {	//удаляем первый элемент с начала
		Node* temp = head->pNext;
		delete head;
		head = temp;
		size--;
	}
	void clear() {	//удаление всех элементов
		for (int i = 0; i < size; i++) {	pop_front();	}
	}
};
int main(){
	List list;
	cout<<"size "<<list.getSize()<<endl;
	list.push_back(5);
	cout << "size " << list.getSize() << endl;
	list.push_back(10);
	list.push_back(20);
	for (int i = 0; i < list.getSize(); i++)	{
		cout << list[i] << " "<<endl;
	}
	list.pop_front();
	for (int i = 0; i < list.getSize(); i++) {
		cout << list[i] << " " << endl;
	}
	list.clear(); //удаление всех элементов
  return 0;
}