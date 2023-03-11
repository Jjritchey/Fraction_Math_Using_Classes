#include "fraction.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <iomanip>
#include <fstream>
#include <ostream>

using namespace std;

void main()
{
	char quit = '\0';                                                        //char to hold the character for when the user wants to quit
	Fraction a;                                                              //Fraction a that will be used across the program to hold the unused third fraction for the math functions
	Fraction x;                                                              //will hold the first fraction entered by the user
	Fraction y;                                                              //will hold the second fraction entered by the user
	char math = '\0';                                                        //will hold the math operation the user wants to use
	ofstream output;                                                         //output file
	output.open("output.txt");


	while (!(quit == 'q' || quit =='Q'))                                     //while loop that will end once the users changes the quit variable to q or Q
	{
		x=x.input(output);                                                   //calls the input fucntion to have the user enter the first fraction
		y=y.input(output);                                                   //calls the input fucntion to have the user enter the second fraction

		cout << "Please enter the math operation you would like to complete for these fractions(+, -, *, /): ";
		output << "Please enter the math operation you would like to complete for these fractions(+, -, *, /): ";
		cin >> math;

		while (!(math == '+' || math == '-' || math == '*' || math == '/'))       //makes sure the user entered a useable math fucntion
		{
			cout << "Please re-enter the math function to be one of these (+, -, *, /): ";
			output << "Please re-enter the math function to be one of these (+, -, *, /): ";
			cin >> math;
		}
		

		if (math == '+')                                                  //once a useable math operator has been entered. this loop will place it with the right math fucntiona and print out the results
		{
			a = x.addFrac(y);
			a.print(output);
			a.addFrac(x, y);
			a.print(output);
		}
		else if (math == '-')
		{
			a = x.subFrac(y);
			a.print(output);
			a.subFrac(x, y);
			a.print(output);
		}
		else if (math == '*')
		{
			a = x.multFrac(y);
			a.print(output);
			a.multFrac(x, y);
			a.print(output);
		}
		else if (math == '/')
		{
			a = x.divFrac(y);
			a.print(output);
			a.divFrac(x, y);
			a.print(output);
			
		}
	
		cin.ignore();             

		cout << "Enter q or Q to stop: ";                             //will ask the user if they want to quit or not. if they hit enter, or another other key it will start the program over
		output << "Enter q or Q to stop: ";
		if (cin.peek() == '\n')
		{
			quit = 'p';
		}
		else
		{
			cin >> quit;                                              
		}

	}
	system("PAUSE");
}