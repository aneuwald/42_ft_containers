#include <iomanip>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"

int indexPrint = 0;

template <typename T, typename U>
void printParams(std::string msg, T mine, U orig) {
	std::cout << (mine == orig ? "\e[0;32m[OK" : "\e[0;31m[NOK") << "]\e[0m ";
	std::cout << msg << ":\t";
	std::cout << "\e[1;32m" << mine << "\e[0m | ";
	std::cout << "\e[1;35m" << orig << "\e[0m";
	std::cout << std::endl;
}

template <typename T, typename U>
void printParamsIterator(T mine, U orig) {

	std::cout << (mine == orig ? "\e[0;32m[OK" : "\e[0;31m[NOK") << "]\e[0m ";
	std::cout << '[' << indexPrint++ << "]:\t";
	std::cout << "\e[1;32m" << mine << "\e[0m | ";
	std::cout << "\e[1;35m" << orig << "\e[0m";
	std::cout << std::endl;
}

template <typename ArrayMine, typename ArrayOrig>
void test(ArrayMine mine, ArrayOrig orig) {

	printParams("position[1]", mine[1], orig[1]);

	std::cout << "\n** reserving 30 ** " << std::endl;
	mine.reserve(42);
	orig.reserve(42);

	std::cout << "\n** populating ** " << std::endl;
	std::cout << "[2] = 2121" << std::endl;
	std::cout << "[3] = 21" << std::endl;
	mine[2] = 2121;	orig[2] = 2121;
	mine[3] = 21;	orig[3] = 21;;

	printParams(".back()", mine.back(), orig.back());

	printParams(".size()", mine.size(), orig.size());

	std::cout << "\nclearing..." << std::endl;
	mine.clear();	orig.clear();

	printParams(".size()", mine.size(), orig.size());

	printParams(".capacity()", mine.capacity(), orig.capacity());

	printParams(".max_size()", mine.max_size(), orig.max_size());
}


int main()
{
	// ft::stack<int> stack;
	std::map<std::string, int> map;
    // stack.push(21);
    // stack.push(22);
    // stack.push(24);
    // stack.push(25);
     
    // stack.pop();
    // stack.pop();
 
    // while (!stack.empty()) {
    //    	std::cout << stack.top() << std::endl;
    //     stack.pop();
    // }

	ft::vector<int> testMine(8u, 100);
	std::vector<int> testOrig(testMine.begin(), testMine.end());
	test(testMine, testOrig);

	std::cout << "\niterators!!" << std::endl;
	{
		ft::vector<int>::iterator itMine = testMine.begin();
		std::vector<int>::iterator itOrig = testOrig.begin();
		indexPrint = 0;
		while (itMine != testMine.end() && itOrig != testOrig.end())
			printParamsIterator(*(itMine++), *(itOrig++));
	}

	return (0);

	std::cout << "\n===== CONSTRUCTORS =====" << std::endl;
	ft::vector<int> myVector_3(8u, 100);
	ft::vector<int> myVector_2 = myVector_3;
	ft::vector<int> myVector(myVector_2);
	std::vector<int> origVector(myVector_3.begin(), myVector_3.end());
	std::cout << std::endl;

	printParams("position[1]", myVector[1], origVector[1]);

	std::cout << "\n** reserving 30 ** " << std::endl;
	myVector.reserve(42);
	origVector.reserve(42);

	std::cout << "\n** populating ** " << std::endl;
	std::cout << "[2] = 2121" << std::endl;
	std::cout << "[3] = 21" << std::endl;
	myVector[2] = 2121;	origVector[2] = 2121;
	myVector[3] = 21;	origVector[3] = 21;;

	std::cout << "\niterators!!" << std::endl;
	{
		ft::vector<int>::iterator itMine = myVector.begin();
		std::vector<int>::iterator itOrig = origVector.begin();
		indexPrint = 0;
		while (itMine != myVector.end() && itOrig != origVector.end())
			printParamsIterator(*(itMine++), *(itOrig++));
	}

	std::cout << "\nreverse iterators!!" << std::endl;
	{
		ft::vector<int>::reverse_iterator itMine = myVector.rbegin();
		std::vector<int>::reverse_iterator itOrig = origVector.rbegin();
		indexPrint = 0;
		while (itMine != myVector.rend() && itOrig != origVector.rend())
			printParamsIterator(*(itMine++), *(itOrig++));
	}
	std::cout << std::endl; 

	
	std::cout << "\n** resize (14) ** " << std::endl;
	myVector.resize(99, 1);
	origVector.resize(99, 1);

	printParams("position[3]", myVector[3], origVector[3]);
	
	printParams(".front()", myVector.front(), origVector.front());

	printParams(".back()", myVector.back(), origVector.back());

	printParams(".at(2)", myVector.at(2), origVector.at(2));

	printParams(".size()", myVector.size(), origVector.size());

	std::cout << "\n** assigning (12, 42) ** " << std::endl;
	myVector.assign((std::size_t)12, 42);
	origVector.assign(12, 42);


	printParams(".data()", myVector.data(), origVector.data());

	printParams("*(.data())", *myVector.data(), *origVector.data());

	printParams("*(.data() + 2)", *(myVector.data() + 2), *(origVector.data() + 2));

	printParams(".empty()",  (myVector.empty() ? "Empty!" : "Not empty!"), (origVector.empty() ? "Empty!" : "Not empty!"));

	printParams(".capacity()", myVector.capacity(), origVector.capacity());

	printParams(".back()", myVector.back(), origVector.back());

	std::cout << "poping back..." << std::endl;
	myVector.pop_back();	origVector.pop_back();

	printParams(".back()", myVector.back(), origVector.back());

	std::cout << "pushing back..." << std::endl;
	std::cout << "push_back(42)" << std::endl;
	std::cout << "push_back(240)" << std::endl;
	myVector.push_back(42);		origVector.push_back(42);
	myVector.push_back(240);	origVector.push_back(240);

	std::cout << "\niterators!!" << std::endl;
	{
		indexPrint = 0;
		ft::vector<int>::iterator itMine = myVector.begin();
		std::vector<int>::iterator itOrig = origVector.begin();
		while (itMine != myVector.end() && itOrig != origVector.end())
			printParamsIterator(*(itMine++), *(itOrig++));
	}

	std::cout << "\nerasing begin() & end()" << std::endl;
	{
		indexPrint = 0;
		ft::vector<int>::iterator retMine;
		std::vector<int>::iterator retOrig;
		retMine = myVector.erase(myVector.begin());
		retOrig = origVector.erase(origVector.begin());
		printParamsIterator(*(retMine), *(retOrig));
		retMine = myVector.erase(myVector.begin());
		retOrig = origVector.erase(origVector.begin());
		printParamsIterator(*(retMine), *(retOrig));

	}

	std::cout << "\nreverse iterators!!" << std::endl;
	{
		indexPrint = 0;
		ft::vector<int>::reverse_iterator itMine = myVector.rbegin();
		std::vector<int>::reverse_iterator itOrig = origVector.rbegin();
		while (itMine != myVector.rend() && itOrig != origVector.rend())
			printParamsIterator(*(itMine++), *(itOrig++));
	}

	std::cout << "\nerasing (begin(), begin() += 2)..." << std::endl;
	{
		indexPrint = 0;
		ft::vector<int>::iterator retMine;
		std::vector<int>::iterator retOrig;
		retMine = myVector.erase(myVector.begin(),  myVector.begin() += 2);
		retOrig = origVector.erase(origVector.begin(), origVector.begin() += 2);
		printParamsIterator(*(retMine), *(retOrig));
	}

	std::cout << "\nconst iterators!!" << std::endl;
	{
		indexPrint = 0;
		ft::vector<int>::const_iterator itMine = myVector.begin();
		std::vector<int>::const_iterator itOrig = origVector.begin();
		//*itMine = 10; -> can't be done!
		while (itMine != myVector.end() && itOrig != origVector.end())
			printParamsIterator(*(itMine++), *(itOrig++));
	}

	std::cout << "\nreverse const iterators!!" << std::endl;
	{
		indexPrint = 0;
		ft::vector<int>::const_reverse_iterator itMine = myVector.rbegin();
		std::vector<int>::const_reverse_iterator itOrig = origVector.rbegin();
		//*itMine = 10; -> can't be done!
		while (itMine != myVector.rend() && itOrig != origVector.rend())
			printParamsIterator(*(itMine++), *(itOrig++));
	}

	std::cout <<  std::endl;

	printParams(".back()", myVector.back(), origVector.back());

	printParams(".size()", myVector.size(), origVector.size());

	std::cout << "\nclearing..." << std::endl;
	myVector.clear();	origVector.clear();

	printParams(".size()", myVector.size(), origVector.size());

	printParams(".capacity()", myVector.capacity(), origVector.capacity());

	printParams(".max_size()", myVector.max_size(), origVector.max_size());

	std::cout << "\nSwap between ft::vector's!!" << std::endl;
	{
		ft::vector<int> myVector_1(8u, 100);
		ft::vector<int> myVector_2(4u, 42);
		myVector_1.swap(myVector_2);
		ft::vector<int>::iterator iter_1 = myVector_1.begin();
		ft::vector<int>::iterator iter_2 = myVector_2.begin();
		indexPrint = 0;
		while (iter_1 != myVector_1.end())
			printParamsIterator(*(iter_1), *(iter_1++));
		indexPrint = 0;
		while (iter_2 != myVector_2.end())
			printParamsIterator(*(iter_2), *(iter_2++));
	}

	std::cout << std::endl;

}

/** MAIN 42 **/

// #include <iostream>
// #include <string>
// #include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
// 	#include <map.hpp>
// 	#include <stack.hpp>
// 	#include <vector.hpp>
// #endif

// #include <stdlib.h>

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };

// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs)
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	ft::map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	ft::vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}

// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(ft::make_pair(rand(), rand()));
// 	}

// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	{
// 		ft::map<int, int> copy = map_int;
// 	}
// 	MutantStack<char> iterable_stack;
// 	for (char letter = 'a'; letter <= 'z'; letter++)
// 		iterable_stack.push(letter);
// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }