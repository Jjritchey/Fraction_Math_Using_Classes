#include "fraction.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;


//constructors
Fraction::Fraction()                                      //Default constructor
{
	num = 0;
	denom = 1;
}

Fraction::Fraction(int numerator)                         //Constructor when only numerator is entered
{
	num = numerator;
	denom = 1;
}
 
Fraction::Fraction(double createFrac)                    //Construtor when a decimal number is entered
{
	int gcd1;                                            //Will hold the gcd of the num and denom

	num = createFrac * 100000;	                         //taking a decimal and creating a fraction
	denom = 100000;

	gcd1 = gcd(num, denom);                              //finding the gcd of the num and denom

	num = num / gcd1;                                    //applying the gcd to gather the lowest terms for the fraction
	denom = denom / gcd1;

}

Fraction::Fraction(int numerator, int denomenator)      //Consturctor when both numerator and denomator are entered
{
	num = numerator;
	denom = denomenator;
}


//functions
Fraction Fraction::input(ofstream& output)                                      //function to gather numerator and denomantor from user
{
	Fraction a;                                                                 //used the the third function withen the program for all math functions
	double numerator = 0;                                                       //holds the numerator
	char abrv = '\0';                                                           //holds the "/" when the user enters the fraction
	int denominator = 0;                                                        //holds the denominator entered by the user

	cout << "Please enter a fraction(Numerator/Denominator): ";                 //Asking the user for the fration
	output << "Please enter a fraction(Numerator/Denominator): ";
	cin >> numerator;

	if (cin.peek() == '\n')                                                     //if the user presses enter instead of entering a number this will update the denominator to 1
	{
		denominator = 1;
	}
	else                                                                        //otherwise the denominator will be placed into its variable
	{
		cin >> abrv >> denominator;
	}

	if (denominator == 0)                                                       //if the entered denominator is 0, this will force an update until a number other than 0 is entered.
	{
		while (denominator == 0)                                             
		{
			cin.ignore();
			cout << "Denominator cannot be 0. Please re-enter a new denominator: ";
			output << "Denominator cannot be 0. Please re-enter a new denominator: ";
			if (cin.peek() == '\n')                                            //if user presses enter this will make the denomniator 1
			{
				denominator = 1;
			}
			else                                                               //otherwise the denominator will be placed
			{
				cin >> denominator;
			}
			
		}
	}

	if (floor(numerator) == numerator)                                          //checking for a decimal place if there is one will create the function variable with the correct constructor
	{
		a.num = numerator;
		a.denom = denominator;
	}
	else                                                                        //sending to the decimal constructor if there is decimal places
	{
		a = Fraction(numerator);
	}

	return a;                                                                   //returning the fraction
}

Fraction Fraction::addFrac(Fraction x)                                          //a=b.add(x)   adds two fractions and returns a new fraction
{
	Fraction a;     
	int numb = 0;                                                               //number to hold the denominator for multuplying after it has been updated
	numb = denom;        
	int gcd1;                                                                   //will hold the gcd of the numerator and denominator

	denom = numb * x.denom;                                                     //multiplying the fractions by the opposite fractions denominators to make the denominators equal
	num = x.denom * num;
	x.denom = numb * x.denom;
	x.num = numb * x.num;

	a.num = num + x.num;                                                       //now that the denominators are equal I am am adding the numerators and assining to the new fraction
	a.denom = denom;

	gcd1 = gcd(a.num, a.denom);                                                //gathering the gcd of the numerator and denominator


	a.num= a.num/gcd1;                                                         //using the gcd to reduce the fraction to its lowest values
	a.denom =a.denom/gcd1;

	return a;                                                                  //returning the new fraction after adding two.
}
Fraction Fraction::subFrac(Fraction x)                                         //a=b.subFrac(x) subtracts two fractions and returns a new fraction
{
	Fraction a;

	int numb = 0;                                                              //number to hold the denominator for multuplying after it has been updated
	numb = denom;
	int gcd1;                                                                  //will hold the gcd of the numerator and denominator

	denom = numb * x.denom;                                                    //multiplying the fractions by the opposite fractions denominators to make the denominators equal
	num = x.denom * num;
	x.denom = numb * x.denom;
	x.num = numb * x.num;

	a.num = num - x.num;                                                       //subtracting the first numerator from the second numerator and assinging to the new fraction
	a.denom = denom;

	gcd1 = gcd(a.num, a.denom);                                                //gathering the gcd of the numerator and denominator


	a.num = a.num / gcd1;                                                      //using the gcd to reduce the fraction to its lowest values
	a.denom = a.denom / gcd1;


	return a;
}
Fraction Fraction::multFrac(Fraction x)                                        //a=b.multFrac(x) multiplies two fractions and returns a new fraction
{
	Fraction a;
	int gcd1 = 0;                                                              //will hold the gcd of the numerator and denominator

	a.num = x.num * num;                                                       //multiplying the numerators and denominators and updating the new fraction
	a.denom = x.denom * denom;

	gcd1 = gcd(a.num, a.denom);                                                //gathering the gcd of the numerator and denominator

	a.num = a.num / gcd1;                                                      //using the gcd to reduce the fraction to its lowest values
	a.denom = a.denom / gcd1;

	return a;
}
Fraction Fraction::divFrac(Fraction x)                                         //a=b.divFrac(x)  divides two fraction and returns a new fraction
{ 
	Fraction a;

	int gcd1 = 0;                                                              //will hold the gcd of the numerator and denominator

	a.num = num * x.denom;                                                     //multiplying the first fraction by the recipricol of the second fraction
	a.denom = denom * x.num;

	gcd1 = gcd(a.num, a.denom);                                                //gathering the gcd of the numerator and denominator

	a.num = a.num / gcd1;                                                      //using the gcd to reduce the fraction to its lowest values
	a.denom = a.denom / gcd1;

	return a;
}


void Fraction::addFrac(Fraction x, Fraction y)                                //a.addFrac(x, y)  adds two fractiosn and updates a current fraction
{ 
	int numb = 0;                                                             //int to hold the value of the denominator to multiply with after the denominator has been updated
	numb = x.denom;
	int gcd1;                                                                 //will hold the gcd of the num and denom

	x.denom = numb * y.denom;                                                 //multiplying the fractions by the opposite fractions denominators to make the denominators equal                                                
	x.num = x.num * y.denom;

	y.denom = numb * y.denom;
	y.num = numb * y.num;

	num = y.num + x.num;                                                      //adding the numerators and updating the current fraction
	denom = y.denom;

	gcd1 = gcd(num, denom);                                                   //finding the gcd of the num and denom

	num = num / gcd1;                                                         //applying the gcd to find the lowest value of the num and denom
	denom = denom / gcd1;

}

void Fraction::subFrac(Fraction x, Fraction y)                                //a.subFrac(x, y) subtracts two fractionsa dn updates the current fraction
{
	int numb = 0;                                                             //int to hold the value of the denominator to multiply with after the denominator has been updated
	numb = x.denom;
	int gcd1;                                                                 //will hold the gcd of the num and denom

	x.denom = numb * y.denom;                                                 //multiplying the fractions by the opposite fractions denominators to make the denominators equal
	x.num = x.num * y.denom;

	y.denom = numb * y.denom;
	y.num = numb * y.num;

	num = x.num - y.num;                                                      //subtracting the numerators and updating the current fraction
	denom = y.denom;

	gcd1 = gcd(num, denom);                                                   //finding the gcd of the num and denom

	num = num / gcd1;                                                         //applying the gcd to find the lowest value of the num and denom
	denom = denom / gcd1;
}

void Fraction::multFrac(Fraction x, Fraction y)                               //a.multFrac(x, y)  multuplys two fractions and updates a current fraction
{
	int gcd1 = 0;                                                             //will hold the gcd of the num and denom

	num = x.num * y.num;                                                      //multiplying the fractions 
	denom = x.denom * y.denom;

	gcd1 = gcd(num, denom);                                                   //finding the gcd of the num and denom

	num = num / gcd1;                                                         //applying the gcd to find the lowest value of the num and denom
	denom = denom / gcd1;

}

void Fraction::divFrac(Fraction x, Fraction y)                               //a.divFrac(x, y) divides two fractions and updates a current fraction object
{  
	int gcd1 = 0;                                                            //will hold the gcd of the num and denom

	num = x.num * y.denom;                                                   //multiplying the first fraction by the recipricol of the second
	denom = x.denom * y.num;

	gcd1 = gcd(num, denom);                                                  //finding the gcd of the num and denom                      

	num = num / gcd1;                                                        //applying the gcd to find the lowest value of the num and denom
	denom = denom / gcd1;
}

int Fraction::gcd(int x, int y)                                       //functiont to find the GCD of 2 numbers
{
	int gcdTotal = 0;                                                 
	int remainder = 0;

	if (x == 0)                                                       //if the numerator is 0, it will return 0. 
	{
		return 0;
	}
	else if (x==y)                                                    //if the num and denom are equal it will return the numerator as the fraction will be a whole number
	{
		return x;
	}
	else                                                              //finding the remainder using that to find the lowest term of gcd
	{
		remainder = (x % y);

		while (remainder < 0 || remainder >0)
		{
			x = y;
			y = remainder;
			remainder = (x % y);

		}
		gcdTotal = y;
	}

	return gcdTotal;

}

const void Fraction::print(ofstream& output)                          //function to print out the result to file and console
{
	cout << "Here is the result: " << num << "/" << denom << "\n";
	output << "Here is the result: " << num << "/" << denom << "\n";
}