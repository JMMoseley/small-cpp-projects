/**********************************************************************
* Thisprogram that prompts the user to enter a telephone number expressed
* in letters (or digits and letters) and outputs the corresponding 
* telephone number in digits. 
**********************************************************************/

#include <iostream>
#include <string>

int main() {

	std::string input = ""; // user input of phone number expressed in characters
	std::string promptAgain = ""; // variable to prompt the user to enter more phone numbers 
	std::string transformedPhoneNumber = ""; // variable to transform
	bool isValid = true; // boolean variable to check for empty spaces and valid entry

	do 
	{	// initialize variables inside do loop
		input = "";
		promptAgain = "Y";
		transformedPhoneNumber = "";
		bool isValid = true;
		
		// prompts user to enter phone number in letters
		std::cout << "Enter a telephone number expresed in letters containing 1 letter minimum, 7 letters maximum, and with no spaces: ";
		std::getline(std::cin, input);

		// if statement checks the size of the user input, if larger than 7 tells the user "you did not enter a valid phone number size
		if (input.size() > 7) 
		{
			std::cout << "You did not enter in a valid phone number size.\n";
			continue;
		}
		// for loop to check input
		for (int index = 0; index < input.size(); index++) 
		{
			// when index is at 3 a "-" is inserted in the phone number
			if (index == 3) 
			{
				transformedPhoneNumber += "-";
			}
			// checks for empty spaces using bool
			char letter = input[index];
			if (letter == ' ') 
			{
				isValid = false;
				break;
			}
			// switch statement to transform letters into numbers
			switch (letter) 
			{
			case 'A':
			case 'a':
			case 'B':
			case 'b':
			case 'C':
			case 'c':
				transformedPhoneNumber += "2";
				break;
			case 'D':
			case 'd':
			case 'E':
			case 'e':
			case 'F':
			case 'f':
				transformedPhoneNumber += "3";
				break;
			case 'G':
			case 'g':
			case 'H':
			case 'h':
			case 'I':
			case 'i':
				transformedPhoneNumber += "4";
				break;
			case 'J':
			case 'j':
			case 'K':
			case 'k':
			case 'L':
			case 'l':
				transformedPhoneNumber += "5";
				break;
			case 'M':
			case 'm':
			case 'N':
			case 'n':
			case 'O':
			case 'o':
				transformedPhoneNumber += "6";
				break;
			case 'P':
			case 'p':
			case 'Q':
			case 'q':
			case 'R':
			case 'r':
			case 'S':
			case 's':
				transformedPhoneNumber += "7";
				break;
			case 'T':
			case 't':
			case 'U':
			case 'u':
			case 'V':
			case 'v':
				transformedPhoneNumber += "8";
				break;
			case 'W':
			case 'w':
			case 'X':
			case 'x':
			case 'Y':
			case 'y':
			case 'Z':
			case 'z':
				transformedPhoneNumber += "9";
					break;
				default:
					isValid = false;
					break;
			} // end switch
		}// end for loop

		// checks if input is valid using bool and outputs transformed phone number from letters to numbers
		if (isValid == true) 
		{
			std::cout << "The phone number you entered is: " << transformedPhoneNumber << "\n"; // outputs transformed number
		}
		else
		{
			std::cout << "The phone number you entered not valid!" << "\n"; // if phone number entered is an invalid character
		}																																	// contains spaces lets the user know of invalid input.
		// prompts user to continue or quit
		std::cout << "Would you like to enter in another phone number? (y/n) ";
		std::getline(std::cin , promptAgain);
		// checks prompt - if user enters y/y to continue entering numbers
	} while (promptAgain == "Y" || promptAgain == "y"); // end do - while loop
	return 0;
} // end main

