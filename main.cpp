#include <iomanip>
#include <iostream>
#include <vector>
#include "vector.hpp"

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



int main()
{
	std::cout << "\n===== CONSTRUCTORS =====" << std::endl;
	ft::vector<int> myVector(5u, 100);
	std::vector<int> origVector(myVector.begin(), myVector.end());

	origVector.reserve(42);

	printParams("position[1]", myVector[1], origVector[1]);

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

	printParams("position[3]", myVector[3], origVector[3]);
	
	printParams(".front()", myVector.front(), origVector.front());

	printParams(".back()", myVector.back(), origVector.back());

	printParams(".at(2)", myVector.at(2), origVector.at(2));

	printParams(".size()", myVector.size(), origVector.size());

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

	std::cout << "\nreverse iterators!!" << std::endl;
	{
		indexPrint = 0;
		ft::vector<int>::reverse_iterator itMine = myVector.rbegin();
		std::vector<int>::reverse_iterator itOrig = origVector.rbegin();
		while (itMine != myVector.rend() && itOrig != origVector.rend())
			printParamsIterator(*(itMine++), *(itOrig++));
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