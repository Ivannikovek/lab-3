#include <iostream>
#include "Tree.h"

using namespace std;

int main() {
	Tree t;

	size_t counter_of_exceptions = 0;

	//checking removing from empty tree values from 1 to 99:
	for (size_t i = 0; i < 100; i++) {
		try {
			t.remove(i);
		}
		catch (...) {
			counter_of_exceptions++;
		}
	}

	cout << (counter_of_exceptions== 0u);

	//checking removing from empty tree values of array's elements:

	int arr[] = { 16,40,66,23,12,14,15,5 };

	for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++) {
		try {
			t.remove(arr[i]);
		}
		catch (...) {
			counter_of_exceptions++;
		}
	}

	cout << (counter_of_exceptions == 0u);

	//checking that three will remove all even elements:
	for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
		t.insert(arr[i]);

	for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
		if (i % 2 == 0)
			t.remove(arr[i]);

	for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
		if (i % 2 == 0)
			cout << (t.contains(arr[i]));
		else
			cout << (t.contains(arr[i]));

	//Tree t;

	//int arr[] = { 16,40,66,23,12,14,15,5 };

	//std::cout << "Order of adding to three: " << std::endl;
	//for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
	//	std::cout << arr[i] << ' ';
	//std::cout << std::endl;

	//for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
	//	t.insert(arr[i]);

	//std::cout << std::endl << "Depth traversing: " << std::endl;
	//DepthIterator di = t.create_dft_iterator();

	//for (di; di.has_next(); di.next())
	//	std::cout << di.get_value() << ' ';
	//std::cout << std::endl;


	//std::cout << std::endl << "Breadth traversing: " << std::endl;
	//BreadthIterator bi = t.create_bft_iterator();

	//for (bi; bi.has_next(); bi.next())
	//	std::cout << bi.get_value() << ' ';

	//std::cout << std::endl;

	//Tree t2(t);

	//std::cout << std::endl << "Depth traversing: " << std::endl;

	//di = t2.create_dft_iterator();

	//for (di; di.has_next(); di.next())
	//	std::cout << di.get_value() << ' ';
	//std::cout << std::endl;

	//std::cout << std::endl << "Breadth traversing: " << std::endl;
	//bi = t2.create_bft_iterator();

	//for (bi; bi.has_next(); bi.next())
	//	std::cout << bi.get_value() << ' ';

	//std::cout << std::endl;

	return 0;
}