#include <iostream>	
using namespace std;
//class List {	//односвяз список
//	class Node {
//	public:
//		int data; Node* pNext;
//		Node(int data = 0, Node* pNext = nullptr) :data{ data }, pNext{ pNext }{cout<<"Constructor Node " << this << endl; }
//		~Node() { cout << "Distructor Node " << this << endl; }
//	};
//	Node* head;
//	int size;
//public:
//	List() :head{ nullptr }, size{ 0 } { cout << "Constructor List " << this << endl; }
//	~List() { cout << "Distructor List " << this << endl; }
//	int getSize() { return size; }
//	void push_back(int data) {
//		if (head == nullptr) { head = new Node(data);	} 
//		else {	
//			Node* current = head;
//			while (current->pNext != nullptr) {
//				current = current->pNext;
//			}
//			current->pNext = new Node(data);
//		}	
//		size++;
//	}
//	int operator[](const int index){ // print [i]
//		int counter = 0;
//		Node* current = head;
//		while (current != nullptr) {
//			if (index == counter) return current->data;
//			else {
//				current = current->pNext;
//				counter++;
//			}
//		}
//	}
//	void pop_front() {	//удаляем первый элемент с начала
//		Node* temp = head->pNext;
//		delete head;
//		head = temp;
//		size--;
//	}
//	void clear() {	//удаление всех элементов
//		for (int i = size; i >0; i--) {	pop_front();	} //с кажд.интерац обрезает по одному элементу
//	}
//	void output() {
//		cout<<"output elements " << endl;
//		for (int i = 0; i < size; i++)	{
//			cout<< (*this)[i] << " ";
//		}
//	}
//	void input(int size) {
//		srand(time(NULL));
//		for (int i = 0; i < size; i++)	{
//			push_back(rand() % 100);
//		}
//	}
//};
//int main(){
//	List list;
//	list.input(10);
//	list.output();
//	list.pop_front();
//	list.output();
//	list.clear(); //удаление всех элементов
//  return 0;
//}
class List {
	class Node {
	public:
		int data; Node* pNext;
		Node(int data = 0, Node* pNext = nullptr) :data{ data }, pNext{ pNext }{ cout << "Constructor Node "<<this<< endl; }
		~Node() { cout << "distructor Node "<<this<<endl; }
	};
	Node* head;	int size;
public:
	List() : head{ nullptr }, size{ 0 }{ cout << "constructor List "<<this<<endl; }
	~List() { cout << "distructor List " << this << endl; }
	void push_back(int data) {
		if (head == nullptr) new Node(data);
		else {
			Node* temp = head;
			while (temp->pNext != nullptr) {
				temp = temp->pNext;
			}
			temp->pNext = new Node(data);
		}
		size++;
	}
	void output() {
		cout << "output " << endl;
		for (int i = 0; i < size; i++)	{
			cout << (*this)[i] << " ";
		}
		cout << endl;
	}
	void input_push_back(int var) {		
		srand(time(NULL));
	for (int i = 0; i < var; i++)	{
		push_back(rand() % 10);
	}
	}
	int operator[](const int index) { // print [i]
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
	void push_front(int data) {
		head = new Node(data, head);
		size++;
	}
	void insert(int data, int index) {//вставляем элемент в определенный индекс
		if (index == 0)push_front(data);
		else {
			Node* previs = head;//мы работаем с адресом head
			for (int i = 0; i < index-1; i++)	{
				previs = previs->pNext;
			}
			Node* newNode=(data, previs->pNext);
			previs->pNext = newNode;
			size++;
		}
	}
	void removeAt(int index) { //удаление определенного элемента
		if (index == 0);// pop_front();
		else {
		Node* previs = head;
		for (int i = 0; i < index - 1; i++) {
			previs = previs->pNext;
		}
		Node* toDelete = previs->pNext;
		previs->pNext = toDelete->pNext;
		delete toDelete;
		size--;
		}	
	}
	void pop_back() { //удаление последнего элемента
		removeAt(size - 1);
	}
};

int main() {
	List list;
	list.output();
	list.input_push_back(10);
	list.output();
//	list.insert(10, 1);
	list.output();
	return 0;
}