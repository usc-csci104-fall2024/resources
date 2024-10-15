#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>

/**
Hash Table for CS104 lab 13. Only stores strings.
*/
class HashTable {
public:
	HashTable(int size);
	~HashTable();

	void  insert(std::string str);
	bool  find(std::string str);
	void  remove(std::string str);
	void  print();

private:
	//data is an array of pointers to strings
	//this is so we can denote empty cells by a nullptr
	std::string** data;
	int size;
};

#endif