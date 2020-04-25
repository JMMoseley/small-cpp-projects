/**********************************************************************
* This program converts the time from 24-hour notation to 
* 12-hour notation and vice versa. 
**********************************************************************/
#include <iostream>
#include <iomanip>
#include <string>

// function prototypes
void userInputOne(int&, int&, char&);
void userInputTwo(int&, int&);
void convertTime(int, int, char, int);
void display(int, int, std::string, int);

// function to prompt user option menu to convert time
void promptMenu()
{
    std::cout << "Options --" << std::endl;
    std::cout << "1: To convert time from 12-hour notation to 24-hour notation." << std::endl;
    std::cout << "2: To convert time from 24-hour notation to 12-hour notation." << std::endl;
    std::cout << "0: To quit the program." << std::endl;
    std::cout << "Choose: ";
} // end promptMenu

// function to take in user input for convertion from 12-hour notation to 24-hour notation
void userInputOne(int& hour/*OUT*/, int& minutes/*OUT*/, char& timeOfDay/*OUT*/)
{ // do-while loop to test case when hours entered are not in 24-hour notation.
  do 
  {
    std::cout << "\nEnter hours: ";
    std::cin >> hour;
    if (hour > 12 || hour < 0)
      std::cout << "\nInvalid hour input. Try again.\n";
  } while (hour > 12 || hour < 0);
  // do-while loop to test case when minutes entered are not in 24-hour notation and minutes no more than 59.
  do 
  {
    std::cout << "Enter minutes: ";
    std::cin >> minutes;
    if (minutes >= 60 || minutes < 0)
      std::cout << "Invalid minutes input. Try again.\n";
  } while (minutes >= 60 || minutes < 0);
  // do-while loop to test case when AM/PM (A or P) entered are other than lower or upper case A and P
  do 
  {
    std::cout << "Enter AM/PM (A or P): ";
    std::cin >> timeOfDay;

    if (timeOfDay == 'A') 
    {
      break;
    }
    if (timeOfDay == 'a') 
    {
      break;
    }
    if (timeOfDay == 'P') 
    {
      break;
    }
    if (timeOfDay == 'p') 
    {
      break;
    }
    std::cout << "Invalid time of day intput. Try again.\n";
  } while (true); // while condition is true and input is other than A-a or P-p prints invalid input
} // end user userInputOne

// function to take in user input for convertion from 24-hour notation to 12-hour notation
void userInputTwo(int& hour/*OUT*/, int& minutes/*OUT*/)
{ // do loop to test case when minutes entered are not in 12-hour notation, hour is not more than 23 and minutes no more than 59.
  do 
  {
    std::cout << "\nEnter hours: ";
    std::cin >> hour;
    if(hour >= 24 || hour < 0)
      std::cout << "\nInvalid hour input. Try again.\n";
  } while (hour >= 24 || hour < 0);
  do 
  {
    std::cout << "Enter minutes: ";
    std::cin >> minutes;
    if(minutes >= 60 || minutes < 0)
    std::cout << "Invalid minutes input. Try again.\n";
  } while (minutes >= 60 || minutes < 0);
} // end user userInputTwo

// function which converts the time from 12-hr notation to 24-hr notation.
void convertTime(int hour/*IN*/, int minutes/*IN*/, char timeOfDay/*IN*/, int choice/*IN*/) 
{ // 12 to 24 hour format conversion 
  if (choice == 1) 
  {
    if (hour == 12 && (timeOfDay == 'a' || timeOfDay == 'A'))
    {
      int displayHour = hour - 12;
      int displayMinutes = minutes;
      int displayChoice = choice;

      display(displayHour, displayMinutes, " ", displayChoice); // invokes the display fucntion
    }
    else if (hour != 12 && (timeOfDay == 'a' || timeOfDay == 'A'))
    {
      int displayHour = hour;
      int displayMinutes = minutes;
      int displayChoice = choice;

      display(displayHour, displayMinutes, " ", displayChoice); // invokes the display fucntion
    }
    else if (hour == 12 && (timeOfDay == 'p' || timeOfDay == 'P'))
    {
      int displayHour = hour;
      int displayMinutes = minutes;
      int displayChoice = choice;

      display(displayHour, displayMinutes, " ", displayChoice); // invokes the display fucntion
    }
    else if (hour != 12 && (timeOfDay == 'p' || timeOfDay == 'P'))
    {
      int displayHour = hour + 12;
      int displayMinutes = minutes;
      int displayChoice = choice;

      display(displayHour, displayMinutes, " ", displayChoice); // invokes the display fucntion
    }
  }
  // 24 to 12 hour format conversion 
  if (choice == 2) 
  {
    if (hour == 0)
    {
      int displayHour = hour + 12;
      int displayMinutes = minutes;
      int displayChoice = choice;

      display(displayHour, displayMinutes, " AM", displayChoice); //invokes the display fucntion
    }
    else if (hour == 12)
    {
      int displayHour = hour;
      int displayMinutes = minutes;
      int displayChoice = choice;

      display(displayHour, displayMinutes, " PM", displayChoice); //invokes the display fucntion
    }
    else if (hour < 12)
    {
      int displayHour = hour;
      int displayMinutes = minutes;
      int displayChoice = choice;

      display(displayHour, displayMinutes, " AM", displayChoice); //invokes the display fucntion
    }
    else if (hour > 12)
    {
      int displayHour = hour - 12;
      int displayMinutes = minutes;
      int displayChoice = choice;

      display(displayHour, displayMinutes, " PM", displayChoice); //invokes the display fucntion
    }
  }
}// end convertTime

// display time for 12 and 24 hour convertion
void display(int hour/*IN*/, int minutes/*IN*/, std::string timeOfDay/*IN*/, int choice/*IN*/)
{
  if (choice == 1)
  {
    std::cout << "The time is: " << std::setw(2) << std::setfill('0') << hour << ":" << std::setw(2) << std::setfill('0') << minutes << std::endl << std::endl;
  }
  else if (choice == 2) 
  {
    std::cout << "The time is: " << std::setw(2) << std::setfill('0') << hour << ":" << std::setw(2) << std::setfill('0') << minutes << timeOfDay << std::endl << std::endl;
  }
} // end display 

int main()
{
  int hour = 0; // hour to convert 
  int minutes = 0; // minutes to convert
  char timeOfDay = ' '; // time of day AM or PM
  int choice; // user input for choice
  bool isValid = true; // check for invalid entry other than 1, 2, 0.
  do
  {
    choice = 0;
    bool isValid = true;
    promptMenu(); // invokes proptMenu function
    std::cin >> choice;

    // switch for user options
    switch (choice)
    {
    case 0:
      break;
    case 1:
      userInputOne(hour, minutes, timeOfDay); // invokes userInputOne
      convertTime(hour, minutes, timeOfDay, choice); // invokes convertTime
      break;
    case 2:
      userInputTwo(hour, minutes); // invokes userInputTwo
      convertTime(hour, minutes, timeOfDay, choice); // invokes convertTime
      break;
    default:
      isValid = false;
      break;
    } //end switch
    // for invalid option entry
    if (isValid == false) 
    {
      std::cout << choice << " is an invalid entry. Try again!" << std::endl;
    }
  } while (choice != 0); // end do-while 
    return 0;
} // end main

