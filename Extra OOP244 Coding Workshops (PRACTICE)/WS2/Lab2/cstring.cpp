/*
*****************************************************************************
							  cstring.cpp
Full Name  : Dev Soni
Student ID#: 130759210
Email      : dasoni4@myseneca.ca

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include<iostream>  // Including the standard input/ output C++ stream library..
#include"cstring.h" // Including the cstring.h header file in this implementation file..

namespace sdds {

	// Copies the source character string into the destination
	void strCpy(char* des, const char* src) {
		int ind = 0; // This denotes the index of the character arrays...

		// To ensure the source string, from which we going to copy
		// the string to destination string variable is not NULL.
		if (src != nullptr) {
			for (ind = 0; src[ind] != '\0'; ind++) {
				des[ind] = src[ind];  // The string is being copied character by character.
			}
			des[ind] = '\0'; // To insert the null-terminator character at the end of the string.
		}

		// This block will be executed if the source string we inherited is NULL...
		else {
			std::cout << "The source string is NULL, hence the operation can't be completed.";

			des[ind] = '\0';  // The source string was NULL, so the destination string is being inserted will NULL
			// character from its first index.
		}
	}

	// Copies the source character string into the destination upto "len"
	// characters. The destination will be null terminated only if the number
	// of the characters copied is less than "len"
	void strnCpy(char* des, const char* src, int len)
	{
		int ind = 0; // This denotes the index of the character arrays...
		int srcLength = 0; // This denotes the length of the src character array..

		if (src != nullptr) { // Ensuring that the source string is not NULL...

			for (ind = 0; src[ind] != '\0'; ind++) {  // Calculating the number of characters
				srcLength++;                          // in the src string of characters.
			}

			// The condition to check if we should end the
			// destination string with a null-terminator '\0'
			// or not ? Only if srcLength is smaller than 'len' provided...
			if (srcLength >= len) {
				for (ind = 0; ind < len && src[ind] != '\0'; ind++) {
					des[ind] = src[ind]; // Copying the string character by character, into
					// the destination string.
				}
			}

			// This block will be executed if the
			// srcLength < len provided as argument
			// through the function.
			else {
				for (ind = 0; ind < len && src[ind] != '\0'; ind++) {
					des[ind] = src[ind]; // Copying the string character by character, into
					// the destination string.
				}
				des[ind] = '\0'; // Terminating the destination string with the null character.
			}
		}
		// This block will be executed if the src string is NULL, or invaild!
		else {
			std::cout << "The source string is NULL, hence the operation can't be completed.";
		}

	}

	// Compares two C-strings 
	// returns 0 if they are the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strCmp(const char* s1, const char* s2)
	{
		// The universal law of setting variables/ pointers to 0 or NULL.
		int result = 0; // To return this variable after the execution of this function...
		// In order to let the program know, if the string is matched or not...

		int matchNum = 0; // This will be calculated on the basis of the characters matched or not...
		int ind = 0; // This denotes the index of the character arrays...
		int length1 = 0; // This is to denote the length of the s1 character array...
		int length2 = 0; // This is to denote the length of the s2 character array...

		// ensures that the s1 character string is NULL or not..
		if (s1 != nullptr) {
			for (ind = 0; s1[ind] != '\0'; ind++) {
				length1++;  // counting the length of the total indexes of..
				// the s1 character array.
			}
		}

		// This block is executed if the s1 string passed..
		// through the function is NULL/ empty/ invaild...
		else {
			std::cout << "The s1 string is NULL ...";
		}

		// ensures that the s2 character string is NULL or not..
		if (s2 != nullptr) {
			for (ind = 0; s2[ind] != '\0'; ind++) {
				length2++;                           // counting the length of the total indexes of..
				// the s2 character array.
			}
		}

		// This block of code is executed if the...
		// string passed is NULL or invaild.
		else {
			std::cout << "The s2 string passed is NULL ...";
		}

		// Condition checking for the string matching :

		// if the two lengths are equal in number..
		// the the strings will be checked for matching.
		if (length1 == length2) {
			for (ind = 0; s1[ind] != '\0' && s2[ind] != '\0'; ind++) {
				if (s1[ind] == s2[ind]) {
					matchNum++;
				}
			}
			if (matchNum == length1 && matchNum == length2) {
				result = 0;
			}
			else {
				result = 1;
			}
		}

		// if length1 is greater than length2, then the result will be assigned as 1.
		else if (length1 > length2) {
			result = 1;
		}

		// if the length of string1 is less than string2, then the result obtained is -1.
		else {
			result = -1;
		}

		// the result (int) passed at the end of the function execution. 
		return result;
	}

	// Compares two C-strings, with regards to the length mentioned.
	// returns 0 if they are the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2

	int strnCmp(const char* s1, const char* s2, int len)
	{
		// The universal law of setting variable/ pointer to 0 or NULL.
		int result = 0; // To return this variable after the execution of this function...
		// In order to let the program know, if the string is matched or not...

		int length1 = 0; // This calculates the length of the s1 string.
		int length2 = 0; // This calculates the length of the s2 string.
		int matchNum = 0; // This will be calculated on the basis of the..
		// characters matched in a string.

		int ind = 0; // This denotes the index of the character arrays...

		// ensures that the s1 character string is NULL or not..
		if (s1 != nullptr) {
			for (ind = 0; s1[ind] != '\0'; ind++) {
				length1++;  // counting the length of the total indexes of..
				// the s1 character array.
			}
		}

		// This block is executed if the s1 string passed..
		// through the function is NULL/ empty/ invaild...
		else {
			std::cout << "The s1 string is NULL ...";
		}

		// ensures that the s2 character string is NULL or not..
		if (s2 != nullptr) {
			for (ind = 0; s2[ind] != '\0'; ind++) {
				length2++;     // counting the length of the total indexes of..
				// the s2 character array.
			}
		}

		// This block of code is executed if the...
		// string passed is NULL or invaild.
		else {
			std::cout << "The s2 string passed is NULL ...";
		}

		if (length1 > len && length2 > len) {
			for (ind = 0; ind < len; ind++) {
				if (s1[ind] == s2[ind]) {
					matchNum++;
				}
			}

			if (matchNum == len) {
				result = 0;
			}

			else {
				result = 1;
			}
		}

		else {
			result = 1;
		}

		return result;
	}

	// returns the length of the C-string in characters
	int strLen(const char* s)
	{
		int length = 0; // It will be used to calculate the number of...
		// characters in a character array or string..

		int ind = 0;    // This denotes the index of the character arrays...

		// Ensuring that the string/ character array is not NULL..
		if (s != nullptr) {
			for (ind = 0; s[ind] != '\0'; ind++) {
				length++;  // calculating the number of characters in the character array/ string.
			}
		}
		return length;  // returning the number of characters present in the character araray/ string.
	}


	// returns the address of first occurance of "str2" in "str1"
	// returns nullptr if no match is found
	const char* strStr(const char* str1, const char* str2)
	{
		int flag = 1; // This is a flag variable, used to halt the execution...
		// of the loop, set to true (1).


		if (*str2 == '\0') {  // Empty substring, return the original string
			//const char* resultantString1 = str1;
		}

		// The while loop is executed if the source string (src1)...
		// is not NULL/ null-terminated.
		while (*str1 != '\0') {

			// If a potential match is found in the strings...
			if (*str1 == *str2) {
				const char* temp_str1 = str1;
				const char* temp_str2 = str2;
				bool match = true;

				while (*temp_str2 != '\0' && flag) {
					// For the characters which doesn't match in the strings...
					if (*temp_str1 != *temp_str2) {
						match = false;
						flag = 0;  // This will help to stop the execution of the loop,
						// by making the condition go wrong.
					}
					temp_str1++;
					temp_str2++;
				}

				if (match) {  // Substring found
					return str1;
				}
			}

			str1++;
		}

		return nullptr;
	}

	// Concantinates "src" C-string to the end of "des"
	void strCat(char* des, const char* src)
	{
		int ind = 0; // Indicates the indexes of the character array.
		int desLength = 0; // Indicates the length of the destination character array.

		if (src != nullptr && des != nullptr) {  // ensures that both of the strings - 
			// destination and source are not NULL.
			for (ind = 0; des[ind] != '\0'; ind++) {
				desLength++;  // Calculates the length of the destination string.
			}

			for (ind = 0; src[ind] != '\0'; ind++, desLength++) {
				des[desLength] = src[ind];  // concatenating the source string, at the end
				// of the destination string...
			}
			des[desLength] = '\0';  // attaching the null terminator at the end of the
			// destination string...
		}
	}
}