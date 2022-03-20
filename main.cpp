#include <iostream>
#include <vector>
#include "vector.hpp"

int main () 
{
	std::cout << "\n===== CONSTRUCTORS =====" << std::endl;
	ft::vector<int> myVector (5u, 100);
    std::vector<int> originalVector (5, 100);

	std::cout << "\n===== myVector =====" << std::endl;
	std::cout << myVector[1] << std::endl;
	myVector[2] = 2121;
	myVector[3] = 21;
	std::cout << myVector[3] << std::endl;
	std::cout << "front: " << myVector.front() << std::endl;
	std::cout << "back: " << myVector.back() << std::endl;
	std::cout << "at(2): " << myVector.at(2) << std::endl;
	std::cout << "size: " << myVector.size() << std::endl;
	std::cout << "data: " << myVector.data() << std::endl;
	std::cout << "*data: " << *myVector.data() << std::endl;
	std::cout << "*(data + 2): " << *(myVector.data() + 2) << std::endl;
	std::cout << "empty: " << (myVector.empty() ? "Empty!" : "Not empty!") << std::endl;
	std::cout << "capacity: " << myVector.capacity() << std::endl;
	std::cout << "poping back..." << std::endl;
	myVector.pop_back();
	std::cout << "pushing..." << std::endl;
	myVector.push_back(10);
	myVector.push_back(10);
	std::cout << "clearing..." << std::endl;
	myVector.clear();
	std::cout << "capacity: " << myVector.capacity() << std::endl;
	std::cout << "size: " << myVector.size() << std::endl;
	std::cout << "max_size: " << myVector.max_size() << std::endl;
	
	std::cout << "\n===== originalVector =====" << std::endl;
	std::cout << originalVector[1] << std::endl;
	originalVector[2] = 2121;
	originalVector[3] = 21;
	std::cout << originalVector[3] << std::endl;
	std::cout << "front: " << originalVector.front() << std::endl;
	std::cout << "back: " << originalVector.back() << std::endl;
	std::cout << "at(2): " << originalVector.at(2) << std::endl;
	std::cout << "size: " << originalVector.size() << std::endl;
	std::cout << "data: " << originalVector.data() << std::endl;
	std::cout << "*data: " << *originalVector.data() << std::endl;
	std::cout << "*(data + 2): " << *(originalVector.data() + 2) << std::endl;
	std::cout << "empty: " << (originalVector.empty() ? "Empty!" : "Not empty!") << std::endl;
	std::cout << "capacity: " << originalVector.capacity() << std::endl;
	std::cout << "poping back..." << std::endl;
	originalVector.pop_back();
	std::cout << "pushing..." << std::endl;
	originalVector.push_back(10);
	originalVector.push_back(10);
	std::cout << "clearing..." << std::endl;
	originalVector.clear();
	std::cout << "capacity: " << originalVector.capacity() << std::endl;
	std::cout << "size: " << originalVector.size() << std::endl;
	std::cout << "max_size: " << originalVector.max_size() << std::endl;


	std::cout << std::endl;
}