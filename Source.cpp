/*
Author: Alexandrea Teigeler
Starter Code Provided by: Professor Linda Noss
Date Last Modified: June 17th, 2021
Program Details:
				This program will communicate with Python code
				---------------------------------------------------------------------
				It will read through a text records that are created
				from the Corner Grocer System
				---------------------------------------------------------------------
				It will sort the items in order to help the business
				understand what are their most popular products
				---------------------------------------------------------------------
				It will read this file, then write to .dat file
				will read the .dat file and create a histogram with that data
				---------------------------------------------------------------------
				This information will be used to increase efficiency in their store
				---------------------------------------------------------------------


*/


#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>



using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("CS210_Starter_PY_Code");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"CS210_Starter_PY_Code");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"CS210_Starter_PY_Code");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}


void Menu() {
	/*
	This function will print a menu to the console and give the user 4 options
	The do while will continue until user exits program
	the try catch is to ensure the user enters the right type of input
	*/

	bool program_Run = true;  //runs do while loop
	bool correct_Input;
	int user_Choice;          //takes input for menu choice
	string grocery_Type;      //takes input for type of grocery item to be looked up



	
	
	do {

		
		cout << endl;
		cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		cout << "|||                       Please Select an option                          |||" << endl;
		cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		cout << endl;
		cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		cout << "|||   1. Print List of All Purchased Items and How Many Were Purchased     |||" << endl;
		cout << "|||   2. Print Total Amount Purchased of a Specific Item                   |||" << endl;
		cout << "|||   3. Display Text Histogram                                            |||" << endl;
		cout << "|||   4. Exit The Program                                                  |||" << endl;
		cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		cout << endl;

		try {
			std::cin >> user_Choice;
			cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << endl;
			//To catch error if userChoice gets input that IS NOT an integer
			//Retrieved from http://www.cplusplus.com/reference/istream/istream/ignore/
			while (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(256, '\n');
				cout << "Unknown Entry. Please Try Again." << endl;

				cout << "Please enter only 1, 2, 3, or 4." << endl;
				std::cin >> user_Choice;
				cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
				cout << endl;
			}
			if (user_Choice >= 0) {
				//Passes the try test
				//Makes sure the user entered a POSITIVE integer
				//exits the do-while
				correct_Input = true;
			}
			else { throw (user_Choice); }
		}
		catch (...) { cout << "Please Enter only 1, 2, 3, or 4." << endl; }


		if (user_Choice == 1) {

			//Prints the total amount of products that were purchased that day and stored in a file
			system("Color 0D");
			
			cout << endl;
			cout << "##############################################################################" << endl;
			cout << "#                         Total Produce Purchased Today                      #" << endl;
			cout << "##############################################################################" << endl;
			cout << endl;

			CallProcedure("read_File"); //reads the file in python
			
			
		}
		else if (user_Choice == 2) {
			
			// Will ask user for a product, will call a python function, the frequency
			// Will be returned, and then it will be printed to the console 
			system("Color 03");
			string userString; 
			cout << "Please Enter the Product you wish to look up: ";
			std::cin >> userString; //Grabs product the user wishes to look up
		
			int tot = callIntFunc("locate_Total_Product_Amount", userString); //Gets frequency of chosen user item product

			if (tot == -1) {
				cout << "The item could not be located within the data file. Make sure input is correct." << endl; // this validates that the item was not in file due to mispelling, or a integer put into string
			}
			else {
				cout << "There were a total of " << tot << " " << userString << " sold today." << endl; // validates correct input AND prints to console the amount of product purchased/located within file
			}
		}
		else if (user_Choice == 3) {

			// Calls python function that will read a file, count and sort product amount
			// write it to a .dat file
			// read that .dat file and create a visual histogram with it
			system("Color 06");
			CallProcedure("read_AND_Write_File");
			
		}
		else { program_Run = false; system("Color 04"); } // Ends Program

	} while (program_Run == true); //controls program flow
}



int main()
{

	system("Color 03");

	//starter code calls
	CallProcedure("printsomething");
	cout << callIntFunc("PrintMe", "House") << endl;
	cout << callIntFunc("SquareValue", 2);

	//calls menu for main functionality of the program
	Menu();


	//Message when user exits program
	cout << endl;
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "|||                      Program Shutting Down...                          |||" << endl;
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;

	return 0;
}