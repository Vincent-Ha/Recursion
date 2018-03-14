/**

 * Vincent Ha

 * CIS 22C, Winter 2017

 */

#ifndef LIST_H_
#define LIST_H_

typedef struct Node* Nodeptr;
#include <cstddef> //for NULL
#include <iostream>
#include <assert.h>

template<class listdata>
class List {
private:
	struct Node {
		listdata data;
		Node* next;
		Node* previous;
		Node(listdata data) :
				data(data), next(NULL), previous(NULL) {
		}
	};

	typedef struct Node* Nodeptr;

	Nodeptr first;
	Nodeptr last;
	Nodeptr iterator;

	int size;

	void reverse(Nodeptr node);
	//Helper function for the public printReverse() function.
	//Recursively prints the data in a List in reverse.

	bool isSorted(Nodeptr node);
	//Helper function for the public isSorted() function.
	//Recursively determines whether a list is sorted in ascending order.

	int binarySearch(int low, int high, listdata data);
	//Recursively searchs the list by dividing the search space in half
	//Returns the index of the element, if it is found in the List
	//Returns -1 if the element is not in the List

public:

	/**Constructors and Destructors*/

	List();
	//Default constructor; initializes and empty list
	//Postcondition: should give a default value for data and size
	// and make the next pointer, first pointer, last
	// pointers to NULL

	List(const List &obj);

	~List();
	//Destructor. Frees memory allocated to the list
	//Postcondition: should delete everything in the list

	/**Accessors*/

	listdata getFirst();
	//Returns the first element in the list
	//Precondition: the list should not be empty

	listdata getLast();
	//Returns the last element in the list
	//Precondition: the list should not be empty

	bool isEmpty();
	//Determines whether a list is empty.

	int getSize();
	//Returns the size of the list

	bool isSorted();
	//Wrapper function that calls the isSorted helper function to determine whether
	//a list is sorted in ascending order.
	//We will consider that a list is trivially sorted if it is empty.
	//Therefore, no precondition is needed for this function

	/**Manipulation Procedures*/

	void removeLast();
	//Removes the value of the last element in the list
	//Precondition: the list should not be empty
	//Postcondition: the previous last node is removed from the list

	void removeFirst();
	//Removes the value of the first element in the list
	//Precondition: the list should not be empty
	//Postcondition: the previous first node is removed from the list

	void insertLast(listdata data);
	//Inserts a new element at the end of the list
	//If the list is empty, the new element becomes both first and last
	//Postcondition: a new node with the given data is placed at the end
	//	 of the list

	void insertFirst(listdata data);
	//Inserts a new element at the start of the list
	//If the list is empty, the new element becomes both first and last
	//Postcondition: a new node with the given data is placed at the beginning
	//	 of the list
	/**Additional List Operations*/

	void printList();
	//Prints to the console the value of each element in the list sequentially
	//and separated by a blank space
	//Prints nothing if the list is empty

	void startIterator();
	//Moves the iterator to the start of the list
	//Will print out an error message if the list is empty

	void removeIterator();
	//Deletes the element the iterator is pointing to
	//Precondition: The list cannot be empty and the iterator should be somewhere
	//	in the list.
	//Postcondition: the node that the iterator is pointing to is removed from the
	// list

	void insertIterator(listdata data);
	//Inserts a new element into the slot where the iterator is
	//Precondition: The list cannot be empty and the iterator should be somewhere
	//	in the list.
	//Postcondition: a new node with the given data is placed after the iterator in
	//	 the list

	void advanceIterator();
	//Advances the iterator forward in the list
	//Precondition: The iterator has to be in the list and the list is not empty

	listdata getIterator();
	//Gets the information held by the iterator
	//Precondition: The iterator has be in the list and the list is not empty

	bool offEnd();
	//Determines if the iterator is in or out of the list

	bool operator ==(const List &list);
	//Compares two lists to see if they are equal

	int getIndex();
	//Indicates the index of the Node where the iterator is currently pointing
	//Nodes are numbered from 1 to size of the list
	//Pre: size != 0
	//Pre: !off_end()

	void advanceToIndex(int index);
	//Moves the iterator to the node whose index number is specified in the parameter
	//Pre: size != 0
	//Pre: index <= size

	int linearSearch(listdata data);
	//Searchs the list, element by element, from the start of the List to the end of the List
	//Returns the index of the element, if it is found in the List
	//Calls the above indexing functions in its implementation
	//Returns -1 if the element is not in the List
	//Pre: size != 0

	int binarySearch(listdata data);
	//Returns the index where data is located in the List
	//Calls the private helper function binarySearch to perform the search
	//Pre: size != 0
	//Pre: List is sorted (must test on a sorted list)


	/**Additional Operations*/

	void printReverse();
	//Wrapper function that calls the reverse helper function to print a list in reverse
	//prints nothing if the List is empty
};

template<class listdata>
void List<listdata>::reverse(Nodeptr node) {
	if (node != NULL) {
		if (node != first)
			std::cout << node->data << ",";
		else
			std::cout << first->data << std::endl;

		reverse(node->previous);
	}

}

template<class listdata>
bool List<listdata>::isSorted(Nodeptr node){
	if(node->next != NULL){
		if(node->data > node->next->data)
			return false;
		else
			isSorted(node->next);
	}
	return true;
}

template<class listdata>
int List<listdata>::binarySearch(int low, int high, listdata data){
	assert(isSorted());
	if(high < low)
		return -1;


	int mid = low + ((high - low)/2);
	int count = 1;
	Nodeptr temp = first;
	while(count != mid){
		temp = temp->next;
		count++;
	}

	if(temp->data == data){
		return mid;
	}
	else if(data < temp->data){
		return binarySearch(low, mid - 1, data);
	}
	else{
		return binarySearch(mid + 1, high, data);
	}
}

template<class listdata>
List<listdata>::List() :
		first(NULL), last(NULL), iterator(NULL), size(0) {
}

template<class listdata>
List<listdata>::List(const List &obj) :
		size(obj.size) {
	if (obj.size == 0) {
		first = last = iterator = NULL;
	} else {
		Nodeptr temp = obj.first;
		Nodeptr previous;
		first = new Node(temp->data);
		iterator = first;
		first->previous = NULL;
		while (temp->next != NULL) {
			previous = iterator;
			temp = temp->next;
			iterator->next = new Node(temp->data);
			iterator = iterator->next;
			iterator->previous = previous;
		}
		last = iterator;
		iterator = NULL;
	}
}

template<class listdata>
List<listdata>::~List() {
	Nodeptr cursor = first;
	Nodeptr temp;
	while (cursor != NULL) {
		temp = cursor->next;
		delete cursor;
		cursor = temp;
	}
}

template<class listdata>
void List<listdata>::printList() {
	Nodeptr temp = first; //create a temporary iterator
	while (temp != NULL) {
		//Add two lines of code here
		//Hint: One statement should contain a cout
		std::cout << temp->data << " ";
		temp = temp->next;
	}

	std::cout << std::endl; //What does this do?
}

template<class listdata>
void List<listdata>::insertFirst(listdata data) {
	if (size == 0) //Why is this necessary?
			{
		first = new Node(data);
		last = first; //notice the order here. Assignment is right to left
	}

	else {
		Nodeptr N = new Node(data); //create the new node by calling the node constructor
		N->next = first; //set the new node's next field to point to the first node
		first->previous = N;
		first = N; //point the first pointer to the new node
	}
	size++;
}

template<class listdata>
void List<listdata>::insertLast(listdata data) {
	if (size == 0) {
		last = new Node(data);
		first = last;
	}

	else {
		Nodeptr N = new Node(data);
		N->previous = last;
		last->next = N;
		last = N;
	}

	size++;
}

template<class listdata>
void List<listdata>::removeFirst() {
	assert(size != 0);
	if (size == 1) {
		delete first;
		first = last = NULL;
		size = 0;
	}

	else {
		Nodeptr temp = first; //store pointer to first so we don't lose access to it
		first = first->next; //advance the pointer
		first->previous = NULL;
		delete temp; //free the memory for the original first node
		size--;
	}
}

template<class listdata>
void List<listdata>::removeLast() {
	assert(size != 0);
	if (size == 1) {
		//fill in the missing lines here
		delete last;
		first = last = NULL;
		size = 0;
	}

	else {
		Nodeptr temp = last->previous;
		temp->next = NULL;
		delete last; //free the memory for the original last node
		last = temp;
		size--;
	}
}

template<class listdata>
bool List<listdata>::isEmpty() {
	return (size == 0);
}

template<class listdata>
int List<listdata>::getSize() {
	return size;
}

template<class listdata>
bool List<listdata>::isSorted()
{
	if(size == 0){
		return true;
	} else{
		return isSorted(first);
	}
}

template<class listdata>
listdata List<listdata>::getFirst() {
	assert(!isEmpty());
	return first->data;
}

template<class listdata>
listdata List<listdata>::getLast() {
	assert(!isEmpty());
	return last->data;
}

template<class listdata>
listdata List<listdata>::getIterator() {
	assert(size != 0);
	assert(iterator != NULL);
	return iterator->data;
}

template<class listdata>
bool List<listdata>::offEnd() {
	return iterator == NULL;
}

template<class listdata>
void List<listdata>::startIterator() {
	assert(size != 0);
	iterator = first;
}

template<class listdata>
void List<listdata>::removeIterator() {
	assert(size != 0);
	assert(!offEnd());

	if (iterator == first) {
		removeFirst();
	}

	else if (iterator == last) {
		removeLast();
	}

	else {
		iterator->previous->next = iterator->next;
		iterator->next->previous = iterator->previous;
		delete iterator;
		size--;
	}

	iterator = NULL;
}

template<class listdata>
void List<listdata>::insertIterator(listdata data) {
	assert(size != 0);
	assert(!offEnd());
	if (iterator == last) {
		insertLast(data);
	} else {
		Nodeptr N = new Node(data);
		N->next = iterator->next;
		N->previous = iterator;
		iterator->next->previous = N;
		iterator->next = N;
		size++;
	}
}

template<class listdata>
bool List<listdata>::operator==(const List& list) {
	if (size != list.size)
		return false;
	Nodeptr temp1 = first;
	Nodeptr temp2 = list.first;
	while (temp1 != NULL) {
		if (temp1->data != temp2->data)
			return false;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return true;
}

template<class listdata>
void List<listdata>::advanceIterator() {
	assert(!offEnd());
	iterator = iterator->next;
}

template<class listdata>
int List<listdata>::getIndex(){
	assert(size != 0);
	assert(!offEnd());
	Nodeptr temp = first;
	int index = 1;
	while(temp->data != iterator->data){
		index++;
		temp = temp->next;
	}
	return index;
}

template <class listdata>
void List<listdata>::advanceToIndex(int index){
	assert(size != 0);
	assert(index <= size);
	startIterator();
	int currentIndex = 1;
	while(currentIndex != index){
		currentIndex++;
		advanceIterator();
	}
}

template <class listdata>
int List<listdata>::linearSearch(listdata data){
	assert(size != 0);
	Nodeptr iter = first;
	int count = 1;
	while(iter != NULL){
		if(iter->data == data){
			return count;
		}
		count++;
		iter = iter->next;
	}

	return -1;
}

template<class listdata>
void List<listdata>::printReverse() {
	if (size == 0) {
		std::cout << std::endl;
	} else {
		reverse(last);
	}
}

template<class listdata>
int List<listdata>::binarySearch(listdata data){
	assert(size != 0);
	assert(isSorted());
	return binarySearch(1,size,data);
}


#endif /* LIST_H_ */
