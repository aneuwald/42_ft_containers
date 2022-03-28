#include <iostream>
#include <vector>
#include "vector.hpp"

enum t_mine {
	MINE,
	ORIG  //original
};

template <typename T>
void printParams(t_mine which, T msg) {

	std::cout << (which == MINE ? "\e[1;32mMine:" : "\e[1;35mOrig:") << "\t\e[0m";
	
	std::cout << msg << std::endl;
}


int main()
{
	std::cout << "\n===== CONSTRUCTORS =====" << std::endl;
	ft::vector<int> myVector(5u, 100);
	std::vector<int> origVector(5, 100);

	std::cout << "\n** position[1] ** " << std::endl;
	printParams(MINE, myVector[1]);
	printParams(ORIG, origVector[1]);

	std::cout << "\n** populating ** " << std::endl;
	std::cout << "[2] = 2121" << std::endl;
	std::cout << "[3] = 21" << std::endl;
	myVector[2] = 2121;	origVector[2] = 2121;
	myVector[3] = 21;	origVector[3] = 21;;

	std::cout << "\n** position[3] ** " << std::endl;
	printParams(MINE, myVector[3]);
	printParams(ORIG, origVector[3]);
	
	std::cout << "\n** front() ** " << std::endl;
	printParams(MINE, myVector.front());
	printParams(ORIG, origVector.front());

	std::cout << "\n** back() ** " << std::endl;
	printParams(MINE, myVector.back());
	printParams(ORIG, origVector.back());

	std::cout << "\n** at(2) ** " << std::endl;
	printParams(MINE, myVector.at(2));
	printParams(ORIG, origVector.at(2));

	std::cout << "\n** size() ** " << std::endl;
	printParams(MINE, myVector.size());
	printParams(ORIG, origVector.size());

	std::cout << "\n** data() ** " << std::endl;
	printParams(MINE, myVector.data());
	printParams(ORIG, origVector.data());

	std::cout << "\n** *data() ** " << std::endl;
	printParams(MINE, *myVector.data());
	printParams(ORIG, *origVector.data());

	std::cout << "\n** *(data + 2) ** " << std::endl;
	printParams(MINE, *(myVector.data() + 2));
	printParams(ORIG, *(origVector.data() + 2));

	std::cout << "\n** empty() ** " << std::endl;
	printParams(MINE, (myVector.empty() ? "Empty!" : "Not empty!"));
	printParams(ORIG, (origVector.empty() ? "Empty!" : "Not empty!"));

	std::cout << "\n** capacity() ** " << std::endl;
	printParams(MINE, myVector.capacity());
	printParams(ORIG, origVector.capacity());
	
	std::cout << "\n** back() ** " << std::endl;
	printParams(MINE, myVector.back());
	printParams(ORIG, origVector.back());

	std::cout << "\npoping back..." << std::endl;
	myVector.pop_back();	origVector.pop_back();

	std::cout << "\n** back() ** " << std::endl;
	printParams(MINE, myVector.back());
	printParams(ORIG, origVector.back());

	std::cout << "\npushing back..." << std::endl;
	std::cout << "push_back(42)" << std::endl;
	std::cout << "push_back(240)" << std::endl;
	myVector.push_back(42);		origVector.push_back(42);
	myVector.push_back(240);	origVector.push_back(240);

	std::cout << "\n** back() ** " << std::endl;
	printParams(MINE, myVector.back());
	printParams(ORIG, origVector.back());

	std::cout << "\n** size() ** " << std::endl;
	printParams(MINE, myVector.size());
	printParams(ORIG, origVector.size());

	std::cout << "\nclearing..." << std::endl;
	myVector.clear();	origVector.clear();

	std::cout << "\n** size() ** " << std::endl;
	printParams(MINE, myVector.size());
	printParams(ORIG, origVector.size());

	std::cout << "\n** capacity() ** " << std::endl;
	printParams(MINE, myVector.capacity());
	printParams(ORIG, origVector.capacity());

	std::cout << "\n** max_size() ** " << std::endl;
	printParams(MINE, myVector.max_size());
	printParams(ORIG, origVector.max_size());


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