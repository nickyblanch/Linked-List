#define logmsg std::cout

#include "List.hpp"

#include <iostream>
#include <sstream>
#include <string>

namespace ec = ECE275Lib::containers;

void printDivider() { std::cout << "==========================\n"; };

int main (void){

	printDivider();

	/* DEBUG
	logmsg << "Creating int_list_test_4" << std::endl;
	ec::List<int>* int_list_test_4 = new ec::List<int>(6);
	int_list_test_4->assign(0, 1133338);
	int_list_test_4->assign(1, 9322797);
	int_list_test_4->assign(2, 1527502);
	int_list_test_4->assign(3, 7295054);
	int_list_test_4->assign(4, 3959748);
	int_list_test_4->assign(5, 7386960);

	for (unsigned int i = 0; i <int_list_test_4->size(); i++)
		std::cout << "Initial list, element " << i << ": " << int_list_test_4->at(i) << std::endl;

	int_list_test_4->remove(3);
	int_list_test_4->remove(4);
	int_list_test_4->insert(3, 2018004);
	int_list_test_4->insert(3, 5596799);
	int_list_test_4->insert(5, 2091887);

	for (unsigned int i = 0; i < int_list_test_4->size(); i++)
		std::cout << "Final list, element " << i << ": " << int_list_test_4->at(i) << std::endl;

	printDivider();

	logmsg << "Creating in_list_nicky" << std::endl;
	ec::List<int>* int_list_nicky = new ec::List<int>(10);
	for (unsigned int i = 0; i < int_list_nicky->size(); i++)
		std::cout << "element " << i << ": " << int_list_nicky->at(i) << std::endl;
	std::cout << "Size: " << int_list_nicky->size() << std::endl;
	std::cout << "Front: " << int_list_nicky->front()->data << std::endl;
	std::cout << "Back: " << int_list_nicky->back()->data << std::endl;

	ec::Node<int>* node = int_list_nicky->front(); // start with the head node
	unsigned int i = 0;
	while (node != nullptr) { // Traverse and count how many nodes there are
		node = node->next;
		i++;
	}
	std::cout << "Size == i: " << bool(i == 10) << std::endl;

	logmsg << "Assigning in_list_nicky" << std::endl;
	for (unsigned int i = 0; i < 10; i++)
		int_list_nicky->assign(i, i);

	ec::List<int> int_list_2;
	for (unsigned int i = 100; i < 110; i++)
		int_list_2.push_back(i);

	ec::List<int> int_list_3;
	for (unsigned int i = 100; i < 110; i++)
		int_list_3.push_back(i);
	//int_list_nicky->insert(9, int_list_2);
	//int_list_nicky->insert(2, int_list_3);
	//int_list_nicky->insert(int_list_nicky->size() - 1, 11111);
	int_list_nicky->insert(9, 11111);
	int_list_nicky->remove(9);

	for (unsigned int i = 0; i < int_list_nicky->size(); i++)
		std::cout << "element " << i << ": " << int_list_nicky->at(i) << std::endl;
	std::cout << "Front: " << int_list_nicky->front()->data << std::endl;
	std::cout << "Back: " << int_list_nicky->back()->data << std::endl;

	printDivider();
	*/

	// BEGIN TESTING PROGRAM
	
	logmsg << "Creating in_list" << std::endl;
	ec::List<int> int_list;
	for (unsigned int i = 0; i < 10; i++)
		int_list.push_back(i);
		
	for (unsigned int i = 0; i < int_list.size(); i++)
		std::cout << "element " << i << ": " << int_list.at(i) << std::endl;
		
	printDivider();
		
	logmsg << "Removing element 3" << std::endl;
	// Test that delete is working
	int_list.remove(3); // Delete index 3
	for (unsigned int i = 0; i < int_list.size(); i++)
		std::cout << "element " << i << ": " << int_list.at(i) << std::endl;
    
    printDivider();
    
    logmsg << "Adding data 125 at element 1" << std::endl;
    int_list.insert(1, 125);
    for (unsigned int i = 0; i < int_list.size(); i++)
		std::cout << "element " << i << ": " << int_list.at(i) << std::endl;
		
	printDivider();
	
	logmsg << "Inserting another list at element 3" << std::endl;
	ec::List<int> int_list2;
	for (unsigned int i = 100; i < 110; i++)
		int_list2.push_back(i);
	
	int_list.insert(3, int_list2);
	for (unsigned int i = 0; i < int_list.size(); i++)
		std::cout << "element " << i << ": " << int_list.at(i) << std::endl;
	
	printDivider();
	
	logmsg << "Removing elements 1 through 5" << std::endl;
	int_list.remove(1, 5);
	for (unsigned int i = 0; i < int_list.size(); i++)
		std::cout << "element " << i << ": " << int_list.at(i) << std::endl;
	printDivider();
	
	ec::List<char> char_list(5);
	logmsg << "Char list size = " << char_list.size() << std::endl;
	for (unsigned int i = 0; i < char_list.size(); i++){
		char_list.assign(i, 'a');
		std::cout << "element " << i << ": " << char_list.at(i) << std::endl;
	}
	
	printDivider();
	
    
    ec::List<std::string> str_list;
    str_list.push_back("ECE 275!");
    str_list.push_back("UArizona");
    str_list.push_back("Tucson, AZ");
    
    for (unsigned int i = 0; i < str_list.size(); i++)
        std::cout << "element i: " << str_list.at(i) << std::endl;

	printDivider();    
    
    return 0;
}