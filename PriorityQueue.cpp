// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <iterator> 
#include <functional> 

using namespace std;

template <typename E, typename C>
class ListPriorityQueue {
public:
	int size() const;
	bool empty() const;
	void insert(const E& e);
	const E& min() const;
	void removeMin();
private:
	list<E> L;
	C isLess;
};
template <typename E, typename C>
int ListPriorityQueue<E,C>::size() const{
	return L.size();
}
template <typename E, typename C>
bool ListPriorityQueue<E,C>::empty() const{
	return L.empty();
}
template <typename E, typename C>
void ListPriorityQueue<E, C>::insert(const E& e){
	typename list<E>::iterator p;
	p = L.begin();
	while (p != L.end() && !isLess(e, *p)) ++p;
	L.insert(p, e);
}
template <typename E, typename C>
const E& ListPriorityQueue<E,C>::min() const{
	return L.front();
}
template <typename E, typename C>
void ListPriorityQueue<E, C>::removeMin() {
	L.pop_back_front();
}



int main()
{
	ListPriorityQueue<int, less<int>> LPQ;
	cout << "The beginning size is " << LPQ.size() << endl;
	int p;
	p = 8;
	LPQ.insert(p);
	p = 18;
	LPQ.insert(p);
	p = 1;
	LPQ.insert(p);

	cout << "The size is " << LPQ.size() << endl;
	cout << "The min value is " << LPQ.min() << endl;
	
	return 0;
}

