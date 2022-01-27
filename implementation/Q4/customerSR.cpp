/*

   --------------- Muhammad Usman Shahid  ----------------
   --------------------  20i-1797 ------------------------
   ------------------- Question-04 -----------------------
   ------------- Class Functions Definitions -------------
   ------------------ Assignment-01 ----------------------

*/

#include "customerSR.h"

//--------------------------------------------------------------------
//----------- Classes Functions Definitions --------------------------
//--------------------------------------------------------------------

//default constructor definition
customerSR::customerSR()
{

    string s1 = "CSR_0";             //the default string to be added in ID
    string s2 = to_string(assignID); //converting the number int to string

    //concatenation of two strings
    csrID = s1 + s2;

    //each time constructor, new object mades increment
    assignID++;

    csrName = "";
    hours = 0;
    complaintsResolved = 0;
    payRate = 0.0;
    wages = 0.0;
}

//initalizing of the static member
int customerSR::assignID = 1;

//set the data
void customerSR::setName(string n)
{
    csrName = n;
}

void customerSR::setHours(int h)
{
    hours = h;
}

void customerSR::set_compResol(int c)
{
    complaintsResolved = c;
}

void customerSR::set_payRate(double p)
{
    payRate = p;
}

void customerSR::setWages(double w)
{
    wages = w;
}

//to access the data
string customerSR::getID() const
{
    return csrID;
}

string customerSR::getName() const
{
    return csrName;
}

int customerSR::getHour() const
{
    return hours;
}

int customerSR::get_compResolv() const
{
    return complaintsResolved;
}

double customerSR::get_payRate() const
{
    return payRate;
}

double customerSR::getWages() const
{
    return wages;
}

//tocalculate the wages
void customerSR::calWages()
{

    //will calculate and store in wages
    wages = hours * payRate;
}

//for displaying the data
void customerSR::display()
{
}
