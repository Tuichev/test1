#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//The test task result should be located at any convenient Git repository
//Please, read the comments carefully.

//This method should revert the word sequences. (e.g. "word1 word2 word3" -> "word3 word2 word1") 
void revertWords(char* arr)
{
	if (!arr || strlen(arr) < 3)
		return;
	
	char * word = strtok(arr, " ");
	string tmp="";

	while (word != NULL)
	{
		tmp.insert(0, " ");
		tmp.insert(0, word);
		word = strtok(NULL, " ");
	}
	strncpy(arr, tmp.c_str(), tmp.size()-1);
}

//Revert words using previous method and return the longest.
std::string processWords(std::string const& input)
{
	char *cstr = new char[input.length() + 1];
	strcpy(cstr, input.c_str());
	revertWords(cstr);

	char rev_input[255];
	strncpy(rev_input, cstr,sizeof(rev_input)-1);
	rev_input[sizeof(rev_input) - 1] = '\0';

	string *ptr= const_cast<string*>(&input);
	*ptr = rev_input;

	char * word = strtok(cstr, " ");
	string longest_word(word);
	while (word != NULL)
	{
		if(longest_word.length()<strlen(word))
			longest_word.assign(word);
		
		word = strtok(NULL, " ");
	}

	delete[]cstr; 
	return longest_word;
}

//Create a method to generate an array of random length (10-20) random signed integer numbers.
//Print the generated sequence in console.
signed int* arr;
size_t array_size;///or change void intGenerator to size_t type and return array size
void intGenerator(signed int* &arr)
{
	array_size = rand() % 11 + 10;
	arr = new signed int[array_size];

	std::cout << "\n\n";
	
	for (size_t i = 0; i < array_size; i++)
	{
		arr[i] = rand() % 18 + (-9);
		cout << arr[i] << " ";
	}

	std::cout << "\n\n";
}

//Using the result of previous method, find the minimal value in the array.
signed int signedMin(signed int* &arr)
{
	intGenerator(arr);
	signed int min = arr[0];

	for (size_t i = 0; i < array_size; i++)
	{
		if (min > arr[i])
			min = arr[i];
	}
	///or use std::min_element() if we have big array
	delete[] arr;
	arr = NULL;
	return min;
};

int main() //DO NOT MODIFY THIS BLOCK
{
	std::cout << "Test started" << std::endl;
	std::cout << "Please input a text with several words" << std::endl;
	std::string input;
	std::getline(std::cin, input);
	std::cout << "Input text: " << input << std::endl;
	std::cout << "Longest word: " << processWords(input) << std::endl;
	std::cout << "Reverted text: " << input << std::endl;
	std::cout << "Minimal is : " << signedMin(arr) << std::endl;
	std::cout << std::endl << "Test ended";
	return 0;
}