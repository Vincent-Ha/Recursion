/**

 * Vincent Ha

 * CIS 22C, Winter 2017

 */

#include <iostream>
#include <string>
#include "List.h"
using namespace std;

void intListTest();
void stringListTest();

int main() {
	cout << "Recursion Testing" << endl;
	cout << "-----------------" << endl;
	cout << endl;
	intListTest();
	cout << endl;
	cout << endl;
	stringListTest();
}

void intListTest() {
	List<int> LI1;
	cout << "Int List Testing" << endl;
	cout << "----------------" << endl;
	cout
			<< "Testing printReverse on an empty List (Should return an empty line):"
			<< endl;
	LI1.printReverse();
	cout << "Testing isSorted() on an empty List (Should return true): ";
	cout << boolalpha << LI1.isSorted() << endl;
	cout << "Testing getIndex() on an empty list (Would throw an assertion):"
			<< endl;
	//cout << LI1.getIndex() << endl;
	cout
			<< "Testing advanceToIndex() on an empty list (Would throw an assertion):"
			<< endl;
	//LI1.advanceToIndex(2);
	cout
			<< "Testing linearSearch() on an empty list (Would throw an assertion):"
			<< endl;
	//cout << LI1.linearSearch(3) << endl;
	cout
			<< "Testing binarySearch() on an empty list (Would throw an assertion):"
			<< endl;
	//cout << LI1.binarySearch(4) << endl;
	for (int a = 10; a >= 1; a--) {
		LI1.insertLast(a);
	}
	cout
			<< "Testing printReverse() on a list of ints (Should return 1,2,3,4,5,6,7,8,9,10):"
			<< endl;
	LI1.printReverse();
	cout << "Testing isSorted() on the list (Should return false): ";
	cout << boolalpha << LI1.isSorted() << endl;
	cout
			<< "Testing binarySearch() on an unsorted list (Would throw an assertion):"
			<< endl;
	//cout << LI1.binarySearch(2) << endl;
	cout << "Searching for 7 using linearSearch() (Should return 4): ";
	cout << LI1.linearSearch(7) << endl;

	while (!LI1.isEmpty()) {
		LI1.removeLast();
	}

	LI1.insertLast(1);
	cout << "Contents of new list (Should print 1):" << endl;
	LI1.printList();
	cout << "Testing isSorted() on new list (Should return true): ";
	cout << boolalpha << LI1.isSorted() << endl;
	for (int a = 2; a <= 5; a++) {
		LI1.insertLast(a);
	}

	cout
			<< "Contents of the new int list (Should print out 1 2 3 4 5): ";
	LI1.printList();
	cout << "Testing isSorted() on a sorted list (Should return true): ";
	cout << boolalpha << LI1.isSorted() << endl;
	cout
			<< "Testing getIndex() with iterator on NULL (Would throw an assertion): "
			<< endl;
	//cout << LI1.getIndex() << endl;
	LI1.startIterator();
	cout << "Started Iterator. Testing getIndex() (Should return 1): ";
	cout << LI1.getIndex() << endl;
	LI1.advanceToIndex(3);
	cout
			<< "Tested advanceToIndex(). Advanced the Iterator to index 3 (Should return 3): ";
	cout << LI1.getIterator() << endl;
	cout << "Testing advanceToIndex() to index 6 (Would throw an assertion):"
			<< endl;
	//LI1.advanceToIndex(6);
	cout
			<< "Testing getIndex() with iterator on the third int, 3. (Should return 3): ";
	cout << LI1.getIndex() << endl;
	cout << "Searching for 4 using linearSearch (Should return 4): ";
	cout << LI1.linearSearch(4) << endl;
	cout << "Searching for 2 using binarySearch (Should return 2): ";
	cout << LI1.binarySearch(2) << endl;
	cout << "Searching for 10 using linearSearch() (Should return -1): ";
	cout << LI1.linearSearch(10) << endl;
	cout << "Searching for 10 using binarySearch() (Should return -1): ";
	cout << LI1.binarySearch(10) << endl;

}

void stringListTest() {
	List<string> LS1;
	cout << "String List Testing" << endl;
	cout << "--------------------" << endl;
	cout
			<< "Testing printReverse() on an empty List (Should return an empty line):"
			<< endl;
	LS1.printReverse();
	cout << "Testing isSorted() on an empty list (Should return true): ";
	cout << boolalpha << LS1.isSorted() << endl;
	cout << "Testing getIndex() on an empty list (Would throw an assertion): "
			<< endl;
	//cout << LS1.getIndex() << endl;
	cout
			<< "Testing advanceToIndex() on an empty list (Would throw an assertion):"
			<< endl;
	//LS1.advanceToIndex(41);
	cout
			<< "Testing linearSearch() on an empty list (Would throw an assertion):"
			<< endl;
	//cout << LS1.linearSearch("BOB") << endl;
	cout
			<< "Testing binarySearch() on an empty list (Would throw an assertion):"
			<< endl;
	//cout << LS1.binarySearch("BOB") << endl;
	LS1.insertFirst("MARLEY");
	LS1.insertFirst("BOB");
	LS1.insertFirst("ANA");
	LS1.insertFirst("CHELSEA");
	cout
			<< "Testing printReverse() on a list of strings (Should return MARLEY,BOB,ANA,CHELSEA on a new line):"
			<< endl;
	LS1.printReverse();
	cout << "Testing isSorted() on the List (Should return false): ";
	cout << boolalpha << LS1.isSorted() << endl;
	cout
			<< "Testing binarySearch() on an unsorted list (Would throw an assertion): "
			<< endl;
	//cout << LS1.binarySearch("BOB") << endl;
	cout << "Searching for BOB using linearSearch (Should return 3): ";
	cout << LS1.linearSearch("BOB") << endl;

	while (!LS1.isEmpty()) {
		LS1.removeFirst();
	}

	LS1.insertLast("Ana");
	cout << "Contents of new string list (Should print out Ana): ";
	LS1.printList();
	cout << "Testing isSorted() on new list (Should return true): ";
	cout << boolalpha << LS1.isSorted() << endl;
	;
	LS1.insertLast("Bob");
	LS1.insertLast("Caroline");
	LS1.insertLast("David");
	cout
			<< "Contents of the new string list (Should print out Ana Bob Caroline David): ";
	LS1.printList();
	cout << "Testing isSorted() on a sorted list (Should return true): ";
	cout << boolalpha << LS1.isSorted() << endl;
	cout
			<< "Testing getIndex() with iterator on NULL (Would throw an assertion): "
			<< endl;
	//cout << LS1.getIndex() << endl;
	LS1.startIterator();
	cout << "Started Iterator. Testing getIndex() (Should return 1): ";
	cout << LS1.getIndex() << endl;
	LS1.advanceToIndex(3);
	cout
			<< "Tested advanceToIndex(). Advanced the Iterator to index 3 (Should return Caroline): ";
	cout << LS1.getIterator() << endl;
	cout << "Testing advanceToIndex() to index 5 (Would throw an assertion):"
			<< endl;
	//LS1.advanceToIndex(5);
	cout
			<< "Testing getIndex() with iterator on the third string, Caroline. (Should return 3): ";
	cout << LS1.getIndex() << endl;
	cout << "Searching for David using linearSearch (Should return 4): ";
	cout << LS1.linearSearch("David") << endl;
	cout << "Searching for Ana using binarySearch (Should return 1): ";
	cout << LS1.binarySearch("Ana") << endl;
	cout << "Searching for Something using linearSearch() (Should return -1): ";
	cout << LS1.linearSearch("Something") << endl;
	cout << "Searching for Something using binarySearch() (Should return -1): ";
	cout << LS1.binarySearch("Something") << endl;
}
