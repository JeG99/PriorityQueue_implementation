#include <iostream>
#include "PriorityQueue.h"

//José Elías Garza Vázquez - A00824494 

int main(){
	
	PriorityQueue test(true);

	test.push(6);
	test.push(7);
	test.push(8);
	test.push(10);
	test.push(11);
	test.push(12);
	test.push(8);
	test.push(15);

	int size = test.size();

	for(int i = 0; i < size; i++){
		std::cout << test.top() << ' ';
		test.pop();
	}

/*
	test.pop();
	std::cout << test.top() << "\n";
	test.print();
	
	test.pop();
	std::cout << test.top() << "\n";
	test.print();

	test.pop();
	std::cout << test.top() << "\n";
	test.print();

	test.pop();
	std::cout << test.top() << "\n";
	test.print();

	test.pop();
	std::cout << test.top() << "\n";
	test.print();

	test.pop();
	std::cout << test.top() << "\n";
	test.print();

	test.pop();
	std::cout << test.top() << "\n";
	test.print();
*/
	std::cout << '\n';

}
