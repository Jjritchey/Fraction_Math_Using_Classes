#define FRACTION_H
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Fraction
{
private:
	int num;
	int denom;


public:

	//constructors
	Fraction();                           //default constructor
	Fraction(int);                        //constructor with only numerator entered
	Fraction(double);                     //consturctor when a number with a decimal
	Fraction(int, int);                   //constructor with both num and demon entered


	//functions
	Fraction addFrac(Fraction);           //add fractions that returns a new variable
	Fraction subFrac(Fraction);           //subtract fractions that returns a new variable
	Fraction multFrac(Fraction);          //Multiply fractions that returns a new variable
	Fraction divFrac(Fraction);           //Divide fractions that returns a new variable

	void addFrac(Fraction, Fraction);     //add fractions that updates a current value
	void subFrac(Fraction, Fraction);     //Subtract fractions that updates a current value
	void multFrac(Fraction, Fraction);    //Mulitply fractions that updates a current value
	void divFrac(Fraction, Fraction);     //Divide fractions that updates a current value

	int gcd(int, int);                    //function to find the gcd of two numbers

	Fraction input(ofstream&);            //function to gather num and denom from user

	const void print(ofstream&);          //function to print out to answer to console and file

};
