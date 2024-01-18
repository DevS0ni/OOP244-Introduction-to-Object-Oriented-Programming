# Project: Valet Parking Application

### Milestones

|Milestone| Revision | Overview | Comments |
|------|:---:|:----|:----| 
| [MS1](#milestone-1) | V1.0 | [Watch](https://youtu.be/NsQK5V7hQN0)|  |


Your task for the project for this semester is to create an application that keeps track of a Valet Parking that can park Cars and Motorcycles in a parking and retrieve them back when requested. 

## Milestones due dates
This project will be done in 5 milestones and each milestone will have its due date. The due date of each milestone is stated below, and it is based on the amount of work to be done for that milestone. 

## Final project mark

> To make the final submission of the project easier and to make it possible to partially submit a project we have divided the submission of milestone 5 into six small ones. Each submission is worth 10% of the project mark. Your project will be marked only if you have all four milestones and at least have one of the 6 six submissions of milestone 5. 


> The first 4 milestones will not be marked based on the code, but their success and their timely submissions. You may modify or debug your previous code as you are going through the milestones. The only milestone that is going to scrutinized based your code will be milestone 5. If you require any feedback on your first four milestones you need to ask your professor to do so.


You can check the due date of each milestone using the ```-due``` flag in the submission command:
```bash
~profname.proflastname/submit 2??/prj/m? -due
```
- replace **2??** with the subject code
- replace **m?** with the milestone number
> Different sections may have different due dates based on their section's progress. Always check the due date using this command. The due date returned by this command always have priority over the due dates stated above.
## Citation, Sources

When submitting your work, all the files submitted should carry full student information along with the "citation and sources" information. See the following example:

If you have multiple submissions of the same milestone, please update the Revision History in each submission so your professor knows what changes to look for.

```C++
/* Citation and Sources...
Final Project Milestone ? 
Module: Whatever
Filename: Whatever.cpp
Version 1.0
Author	John Doe
Revision History
-----------------------------------------------------------
Date      Reason
2020/?/?  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my project milestones.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and 
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
```

**Failing to include the above citation to any of the files containing your work will cause the rejection of your project submission**

#### See below for details:

### For work that is done entirely by you (ONLY YOU)

If the file contains only your work or the work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my project milestones.

### For work that is done partially by you.

If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.


> :warning: This [Submission Policy](#submission-policy) only applies to the project. All other assessments in this subject have their own submission policies.

### If you have helped someone with your code

If you have helped someone with your code. Let them know of these regulations and in an email write exactly which part of your code was copied and who was the recipient of this code.<br />By doing this you will be clear of any wrongdoing if the recipient of the code does not honour these regulations.

## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ms file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ms`: the compiled application will be named `ms`

After compiling and testing your code, run your program as follows to check for possible memory leaks (assuming your executable name is `ms`):

```bash
valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ms
```

- `--show-error-list=yes`: show the list of detected errors
- `--leak-check=full`: check for all types of memory problems
- `--show-leak-kinds=all`: show all types of memory leaks identified (enabled by the previous flag)
- `--track-origins=yes`: tracks the origin of uninitialized values (`g++` must use `-g` flag for compilation, so the information displayed here is meaningful).

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.


### Adding alias to `.bash_profile` on matrix
You can add the following two lines to the end of your `.bash_profile` file in your matrix home directory to create two aliases for the above C++ compilation and valgrind testing so you don't have to type such a long command to compile and execute your programs:
```bash
alias msc++="g++ -Wall -std=c++11 -g -o ms"
alias vrun="valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes"
```
By adding the above to the '.bash_profile' (you must logoff and log back it so it takes effect) you can compile your c++ files as follows:
```bash
msc++ file1.cpp file2.cpp file3.cpp...<ENTER>
```
The above will compile your files and if successful it will create an executable called `ms`.
```bash
vrun ms<ENTER>
```
The above will execute your `ms` executable under the tester `valgrind` for detailed test on leaks and runtime errors.

> Note: All the code written in this project must be implemented in the **sdds** namespace, unless instructed otherwise.

> Make sure that all the debugging code and debugging comments are removed before submission.

## Project Implementation notes:  *Very Important, read carefully*
- All the code written in this project should be within the namespace sdds.

- You are free and encouraged to add any attributes(member variables), functions and methods (member functions) you find necessary to complete your code. If you are not sure about your strategy for adding functionalities and properties to your classes, ask your professor for advice.  

- If any methods are being added and they are not called outside the scope of the class, make sure they are private.

- Unless you are asked for a specific definition, name the variables, and functions yourself. Use proper names and follow the naming conventions instructed by your professor. Having meaningless and misleading names will attract a penalty.

- When creating methods (member functions) make sure to make them constant if in their logic, they are not modifying their class.

- When passing an object or variable by address or reference, if they are not to be modified, make sure they are passed as constant pointers and references.

- If an Empty state is required for an object, it is considered to be an “invalid” empty state, and objects in this state should be rendered unusable.

- A module called **Utils** is added to the project that can be used for your custom functions and classes in your implementation. Leave this module empty if you don't have any custom functionalities. <br />
You can add any custom code/class of your own to the **Utils** module to be used throughout the project. 

- Throughout the project, if any class is capable of displaying or writing itself, the member function will always have the following signature: 
The function will return a reference of an **ostream** and will receive a reference on an **ostream** as an optional argument. If this argument is not provided, the object “**cout**” will be passed instead. 

- Throughout the project, if any class is capable of reading or receiving its content from a stream, the member function will always have the following signature: 
The function will return a reference of an **istream** and will receive a reference on an **istream** as an optional argument. If this argument is not provided, the object “**cin**” will be passed instead. 

- When passing an object or variable by address or reference, if they are not to be modified, make sure they are passed as constant pointers and references.

- You may reuse and copy any code your professor provided for your workshops or functions you may have from previous work in this subject or other subjects and place it in the Utils module. 

# The Project; Valet Parking Application

We will start the development of the project by creating its user interface (MS1, Menu system). Then we will create a mockup application that represents what the application will look like and act without actually doing anything(MS2 Parking app). In short, we are creating a prototype of the application (in ms1 and ms2) then coding its engine (in ms3 and ms4) and finally adding functionality to Parking (ms2) to make it fully functional (in ms5).

# Milestone 1 (The Menu Module)

This Module contains two classes; MenuItem and Menu. MenuItem is a fully private class owned by the Menu Class (Menu is a friend of MenuItem). Therfore, Only the Menu class can construct and use the MenuItem and because of this the two classes reside in the same module.

## Purpose:

Menu displays a menu title and several menu items with a row number attached to each, and lets the user make a selection. After user makes the selection, the row number of the selected menu item is returned to the caller program. 

## The MenuItem class:

Create a fully private class (no public members) called MenuItem that is owned by the Menu class. (i.e. Menu is a friend of MenuItem).

To make this possible (since Menu is not yet implemented), forward declare the Menu class to be able to make it a friend of MenuItem class.

MenuItem can hold a C-style character string with a maximum length of 50 as its content. Any attempt to set the content to more than 50 characters should store the truncated value instead (down to 50 characters). 

### Construction:

Menuitem can be created by a constant C-style character string to be used to set its content. If the provided string is invalid (null) then the object is set to an Empty state. 

### Member function:
The MenuItem can display itself by writing its content on the screen and printing a new line. 

If MenuItem is in an empty state, nothing is printed. 

### Copy and Assignment:
MenuItem can not get copied or assigned to another MenuItem. This, must be enforced in your code.

### Other member functions:
Add other members to MenuItem if needed during the development of this module 

 
## The Menu class:
Before starting to implement the Menu class, create a constant int value in the Menu module called MAX_NO_OF_ITEMS and set it to 10. 

## Properties: (member variables)
### Title:
Menu can hold a C-style character string with a maximum length of 50 as its title. Any attempt to set the content to more than 50 characters should store the truncated value instead (down to 50 characters). 

### MenuItems: 
The Menu class holds an array of MenuItems with a size of MAX_NO_OF_ITEMS. Throughout the program, as menu items are added to the Menu, the elements of the array are set to individual MenuItems for each addition. 

Make sure you keep track of the number of added MenuItems to the Menu for printing the Menu and item selection validation.

### Indentation: 

When displaying the menu, the title and menu items may be indented to the right. For each indentation level (value of 1) indent the menu 4 spaces to the right. (You can keep this value in an integer attribute)

Menu example without indentation (value of 0):
```text
** The Menu **
1- Option one
2- Option Two
3- Option three
4- Option four
5- Exit
>
```
Menu example with indentation value of 2:
```text
        ** The Menu **
        1- Option one
        2- Option Two
        3- Option three
        4- Option four
        5- Exit
        >
```

### Other properties: 
Add other properties if or when needed. 

### Construction:
A Menu object can be created by a constant C-style character string, to be used to set its title and an optional integer value for indentation. If indentation is not provided, the value “0” will be passed instead.

If the string is invalid (null) then Menu is set to an invalid empty state.

### Copy and Assignment:
Menu can not get copied or assigned to another Menu. This, must be enforced in your code.

### Member functions, operator and cast overloads:

#### bool cast overload
Overload the cast operator so if the Menu object is casted to a bool, it returns true if the Menu is valid and usable, otherwise it returns false if the Menu is in an invalid empty state.

#### isEmpty() function
Write an isEmpty function that returns true if the Menu is in an invalid empty State or false if it is valid and usable.

Note that isEmpty works the opposite of the bool cast overload.

#### display function
The Menu should display itself as follows:

If the Menu is in an invalid empty state, it will print: ```"Invalid Menu!"``` and a new line

If the Menu has no MenuItems, it will print: ```"No Items to display!"``` and a new line

##### Otherwise:

First it will print its title and go to new line.<br />
Then it will display a row number, starting with number one (1) and a dash.<br />
Afterwards it will print a space and then the first MenuItem in the array. <br />
It will continue printing the row numbers and the MenuItems to the number of menu items added to the Menu.<br /> 
At end it will print a greater-than operator (“>”) and a space as the prompt for user selection. 
##### Menu example:
```text
** The Menu **
1- Option one
2- Option Two
3- Option three
4- Option four
5- Exit
> 
```
#### Assignment 
A Menu should be able to be assigned to a constant character C-string. This should reset the title of the Menu to the newly assigned string. If the string is invalid (null) the Menu is set to an invalid empty state.

##### Assignment example:
```C++
Menu lunchMenu("Lunch Menu");
lunchMenu = "New Title"; //<<---- Assignment
```

#### add function: 
write an add function that returns nothing and receives a constant character C-string to build a MenuItem and add it to the MenuItems of the Menu. 

If the string is invalid (null) then the Menu is set to an invalid empty state and nothing is added.

The add function should use the C-string argument to add a MenuItem to the Menu if possible. 

If the MenuItem array is full, then the function should silently ignore the addition and exit. Also, the add function will do nothing and exit silently if the Menu is in an invalid empty state.

#### left shift operator overload (“<<”)
Overload the left shift operator to insert a constant character C-string into the Menu as a MenuItem. This overload should work exactly like the add function and work as follows: 

Insertion example to add three MenuItems to the lunchMenu:
```C++
Menu lunchMenu("Lunch Menu");
lunchMenu << "Hamburger" << "Chicken Sandwich" << "Pasta and meatballs";
```

Displaying the above menu should result the following:

```text
Lunch Menu
1- Hamburger
2- Chicken Sandwich
3- Pasta and meatballs
> 
```

Insertion example to add invalid MenuItems to the lunchMenu:
```text
Menu lunchMenu("Lunch Menu");
lunchMenu << nullptr << "Chicken Sandwich" << "Pasta and meatballs";
```
Displaying the above menu should result the following:
```text
Invalid Menu!
```

#### Menu class in action (run function):
Create a function called run that returns an integer. In this function displays the Menu and waits for the user’s response to select an option by entering the row number of the MenuItems. 

If the user enters non-integer value print the following error message: ```"Invalid Integer, try again: "```
 and wait for the user’s response.

If the user enters an integer, but out of the boundary of the available options print the following error message: ```"Invalid selection, try again: "``` and wait for the user’s response.

When user selects a valid option, end the function and return the selected option value.

If the Menu has no MenuItems, no selection is made and 0 returned with no user interaction.

Run function example:

```C++
Menu lunchMenu("Lunch Menu");
lunchMenu << "Hamburger" << "Chicken Sandwich" << "Pasta and meatballs";
int choice = lunchMenu.run();
cout << "You selected " << choice << endl;
```
### Integer cast overload
After creating the run function, overload the cast operator so if the Menu object is casted to an integer, the run function is called, and its value is returned as the integer cast value. 

Integer cast example:
```C++
Menu lunchMenu("Lunch Menu");
lunchMenu << "Hamburger" << "Chicken Sandwich" << "Pasta and meatballs";
int choice = lunchMenu;
cout << "You selected " << choice << endl;
```
#### Other member functions:
Add other member functions to the Menu if needed.


## MS1 Tester program

Write your own tester or use the following tester program to test and debug your Date class.

```C++
/* ------------------------------------------------------
Final Project Milestone 1
Module: Menu
Filename: main.cpp
Version 1.0
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------*/

#include <iostream>
#include "Utils.h"
#include "Menu.h"
using namespace std;
using namespace sdds;
int showSelection(int n);
void prompt(const char* message);
void pause();
void testMenus(const Menu& m, const Menu& sub1, const Menu& sub2);
void TT(const char* title);
int main() {
   TT("M1T1: constructors");
   Menu mainMenu("** Main Menu **");
   Menu subMenu1("** Sub Menu One **", 1);
   Menu subMenu2("** Sub Menu **", 2);
   Menu tempMenu("** Temp **");
   Menu invMenu("** To test Invalid Menu **");

   TT("M1T2: operator<< adding MenuItems");
   tempMenu << "One" << "Two" << "three";

 

   TT("M1T3: Menu::run()");
   prompt("Do the following: \nabc <ENTER>\n0 <ENTER>\n4 <ENTER>\n3 <ENTER>");
   cout << tempMenu.run() << " selected!" << endl;
   pause();


   TT("M1T4: Reseting Menu title and running an empty menu with no Items");
   tempMenu.clear();
   tempMenu = "** New Title **"; //<<---- Assignment
   cout << tempMenu.run() << " returned by the Menu with no Items." << endl;
   pause();

   TT("M1T5: Menu::add() and operator<<");
   mainMenu.add("Option one");
   mainMenu.add("Option Two");
   mainMenu.add("Sub Options");
   mainMenu.add("Option four");
   mainMenu.add("Exit");
   subMenu1 << "Selection one" << "Sub Selections two" << "Selection three" << "Selection four";
   subMenu2 << "The first" << "The second" << "The third";



   TT("M1T6: Submenu and indentation display");
   testMenus(mainMenu, subMenu1, subMenu2);

   TT("M1T7: operator bool()");
   if (mainMenu) {
      cout << "The mainMenu is valid and usable." << endl;
   }

   TT("M1T8: Invalid Menu and its usage");
   mainMenu.add(nullptr);
   if (!mainMenu) {
      cout << "The mainMenu is invalid(empty) and not usable." << endl;
   }
   mainMenu.run();
   mainMenu.display();
   
   TT("M1T9: Adding invalid string to render Menu invalid");
   invMenu << nullptr << "This should not be added" << "This shouldn't be added either";
   invMenu.run();
   invMenu.display();
   return 0;
}
int showSelection(int n) {
   cout << "You selected " << n << "." << endl;
   return n;
}

void prompt(const char* message) {
   cout << message << endl;
}
void pause() {
   cout << "Press enter to continue..." << endl;
   cin.ignore(1000, '\n');
}
void testMenus(const Menu& m, const Menu& sub1, const Menu& sub2) {
   int selection;
   prompt("Do the following:\n2 <ENTER>\n3 <ENTER>");
   while ((selection = m.run()) != 5) {
      showSelection(selection);
      if (selection == 3) {
         prompt("Do the following:\n2 <ENTER>");
         if (showSelection(sub1) == 2) {
            prompt("Do the following:\n3 <ENTER>\n5 <ENTER>");
            showSelection(sub2);
         }
      }
   }
}
void TT(const char* title) {
   cout << "******************************************************************" << endl;
   cout << title << endl;
   cout << "==================>" << endl;
}


```

### output sample


```Text
******************************************************************
M1T1: constructors
==================>
******************************************************************
M1T2: operator<< adding MenuItems
==================>
******************************************************************
M1T3: Menu::run()
==================>
Do the following:
abc <ENTER>
0 <ENTER>
4 <ENTER>
3 <ENTER>
** Temp **
1- One
2- Two
3- three
> abc
Invalid Integer, try again: 0
Invalid selection, try again: 4
Invalid selection, try again: 3
3 selected!
Press enter to continue...

******************************************************************
M1T4: Reseting Menu title and running an empty menu with no Items
==================>
** New Title **
No Items to display!
0 returned by the Menu with no Items.
Press enter to continue...

******************************************************************
M1T5: Menu::add() and operator<<
==================>
******************************************************************
M1T6: Submenu and indentation display
==================>
Do the following:
2 <ENTER>
3 <ENTER>
** Main Menu **
1- Option one
2- Option Two
3- Sub Options
4- Option four
5- Exit
> 2
You selected 2.
** Main Menu **
1- Option one
2- Option Two
3- Sub Options
4- Option four
5- Exit
> 3
You selected 3.
Do the following:
2 <ENTER>
    ** Sub Menu One **
    1- Selection one
    2- Sub Selections two
    3- Selection three
    4- Selection four
    > 2
You selected 2.
Do the following:
3 <ENTER>
5 <ENTER>
        ** Sub Menu **
        1- The first
        2- The second
        3- The third
        > 3
You selected 3.
** Main Menu **
1- Option one
2- Option Two
3- Sub Options
4- Option four
5- Exit
> 5
******************************************************************
M1T7: operator bool()
==================>
The mainMenu is valid and usable.
******************************************************************
M1T8: Invalid Menu and its usage
==================>
The mainMenu is invalid(empty) and not usable.
Invalid Menu!
Invalid Menu!
******************************************************************
M1T9: Adding invalid string to render Menu invalid
==================>
Invalid Menu!
Invalid Menu!

```


## MS1 Submission 

> If you would like to successfully complete the project and be on time, **start early** and try to meet all the due dates of the milestones.

Upload your source code and the tester program to your `matrix` account. Compile and run your code using the `g++` compiler [as shown in the introduction](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 2??/prj/m1
```
and follow the instructions.

- *2??* is replaced with your subject code


### The submit program's options:
```bash
~prof_name.prof_lastname/submit DeliverableName [-submission options]<ENTER>
[-submission option] acceptable values:
  "-due":
       Shows due dates only
       This option cannot be used in combination with any other option.
  "-skip_spaces":
       Do the submission regardless of incorrect horizontal spacing.
       This option may attract penalty.
  "-skip_blank_lines":
       Do the submission regardless of incorrect vertical spacing.
       This option may attract penalty.
  "-feedback":
       Check the program execution without submission.
```

## [Back to milestones](#milestones)


# Milestone 2

To be continued

## [Back to milestones](#milestones)


# Milestone 3

To be continued

## [Back to milestones](#milestones)


# Milestone 4

To be continued

## [Back to milestones](#milestones)


# Milestone 5

To be continued

## [Back to milestones](#milestones)


