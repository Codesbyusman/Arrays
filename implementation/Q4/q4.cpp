/*

   --------------- Muhammad Usman Shahid  ----------------
   --------------------  20i-1797 ------------------------
   ------------------- Question-04 -----------------------
   ------------------ Assignment-01 ----------------------

*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//the header file for class
#include "customerSR.cpp"

//function prototypes
void takeData(customerSR[], const int);
void calPayrate(customerSR[], const int);
void displayAll(customerSR[], const int);
void menu(customerSR[], const int);
void sortByhour(customerSR[], const int);
void sortBycomplains(customerSR[], const int);

int main()
{

    int i = 0;

    const int totalCSR = 7;
    //the array for 7 as mentioned in question
    customerSR CSR[totalCSR] = {};

    cout << "\n\t\t\t\t :::::: EMPLOYEE PERFORMANCE REPORTING ::::::" << endl;

    //will take data
    takeData(CSR, totalCSR);

    //will calculate payrates
    calPayrate(CSR, totalCSR);

    //will calculates wages
    for (i = 0; i < totalCSR; i++)
    {
        CSR[i].calWages();
    }

    cout << endl
         << endl;
    system("pause");

    //will display the data
    cout << "\n\t\t\t ::::::::: Entered Data of CSR's is as follow ::::::::: " << endl;
    displayAll(CSR, totalCSR);
    
    menu(CSR, totalCSR);

    cout<<endl<<endl;

    return 0;
}

//--------------------------------------------------------------------
//------------------- Functions Definitions --------------------------
//--------------------------------------------------------------------

//to take the input
void takeData(customerSR C[], const int s)
{

    int a = 0;
    string data = "";
    int hour = 0, complains = 0;

    int i = 0;

    cout << "\n\t\t\t Enter the data for the Customer Support Representatives " << endl;

    for (i = 0; i < s; i++)
    {
        cout << "\n\t\t\t :::::::::: Enter information for CSR ID : " << C[i].getID() << "  ::::::::::  \n"
             << endl;

        //to avoid the not taking input situation
        if (i > 0)
        {
            cin.ignore();
        }

        cout << "\n\t\t Name : ";
        getline(cin, data);

        a = 0;
        do
        {

            if (a == 0)
            {
                cout << "\t\t Number of hours worked : ";
                cin >> hour;
            }
            else
            {

                cout << "\n\t\t\t :::::: Error , inappropriate input :::::: " << endl;
                cout << "\t\t Number of hours worked : ";
                cin >> hour;
            }

            a++;

        } while (!(hour >= 0)); //validation of entered hours

        a = 0;

        do
        {

            if (a == 0)
            {
                cout << "\t\t Number of Complaints Resolved : ";
                cin >> complains;
            }
            else
            {
                cout << "\n\t\t\t :::::: Error , inappropriate input :::::: " << endl;
                cout << "\t\t Number of Complaints Resolved : ";
                cin >> complains;
            }

            a++;

        } while (!(complains >= 0)); //validation of complain number

        //assigning the data
        C[i].setName(data);
        C[i].setHours(hour);
        C[i].set_compResol(complains);
    }
}

//to calculate pay rate
void calPayrate(customerSR C[], const int s)
{

    int i = 0;

    double totalComplians = 0;

    //storing the pay rate
    double payR = 0;
    for (i = 0; i < s; i++)
    {
        totalComplians += C[i].get_compResolv();
    }

    //calculating the pay rate for each and storing that
    for (i = 0; i < s; i++)
    {

        //payrate calculating formula
        payR = 25 + (25 * (C[i].get_compResolv() / totalComplians));

        //setting the value of pay rate
        C[i].set_payRate(payR);
    }
}

//will display the data
void displayAll(customerSR C[], const int s)
{

    int i = 0;

    //general labels
    cout << left << "\n\t\t" << setw(10) << "  ID " << setw(20) << " Name " << setw(15) << " # of Hours" << setw(25) << "Complains Resolved " << setw(15) << fixed << setprecision(3) << "Pay Rate" << setw(10) << "    Wages" << endl;

    //data of each CSR
    for (i = 0; i < s; i++)
    {
        cout << left << "\n\t\t " << setw(10) << C[i].getID() << left << setw(20) << C[i].getName() << setw(15) << C[i].getHour() << setw(25) << C[i].get_compResolv() << "$" << setw(15) << C[i].get_payRate() << "$" << setw(10) << C[i].getWages() << endl;
    }

    cout<<endl<<endl;
}

//for asking for which priority user want to see
void menu(customerSR C[], const int s)
{

    int a = 0;

    char choice;

    do
    {
        if (a == 0)
        {

            cout << "\n\t\t Enter 1 to see top CSR's on Number of hours worked " << endl;
            cout << "\t\t Enter 2 to see top CSR's on Number of complaints resolved " << endl;

            cout << "\n\t\t Enter the option : ";
            cin >> choice;
        }
        else
        {

            cout << "\n\t\t\t ::::::: Error, Inapproprite input :::::::" << endl;

            cout << "\n\t\t Enter 1 to see top CSR's on Number of hours worked " << endl;
            cout << "\t\t Enter 2 to see top CSR's on Number of complaints resolved " << endl;

            cout << "\n\t\t Enter the option again : ";
            cin >> choice;
        }

        a++;

    } while (!( choice == '1' || choice == '2')); //validating the choice

    //using switch to move according to user
    switch (choice)
    {


        //top on the bases of hours worked
        case '1':
        {
            sortByhour(C, s);

            cout << "\n\t\t\t :::::::::: The top CSR's according to the Hours worked ::::::::::" << endl;

            displayAll(C, s);

            break;
        }

        //top on the basis of complains resolved
        default:
        {
            sortBycomplains(C, s);

            cout << "\n\t\t\t :::::::::: The top CSR's according to the complains resolved ::::::::::" << endl;

            displayAll(C, s);

           
        }

    }

    
        system("pause");

        cout << "\n\n\t\t Enter any character to again have the menu " << endl;
        cout << "\t\t Enter 0 to exit the program " << endl;

        cout << "\n\t\t Enter the option : ";
        cin>>choice;

        //exit
        if(choice=='0')
        {
            return;
        }
        else //run again
        {
            menu(C, s);
        }

}

//will sort top by hour
void sortByhour(customerSR C[], const int s)
{
    int i = 0, j = 0;

    //for swaping whole object
    customerSR swap = {};

    //for seeing on iteration swaped or not if not mean sorted
    bool see = false;

    //bubble sort

    //will run for sorting each time
    //first will sort some then have to move to sort others
    for (i = 0; i < s - 1; i++)
    {

        //in each row a number will be on right position
        //thus -i means to not check for those elements
        for (j = 0; j < s - 1 - i; j++)
        {
            if (C[j].getHour() < C[j + 1].getHour())
            {

                //swap
                swap = C[j];
                C[j] = C[j + 1];
                C[j + 1] = swap;

                see = true;
            }
        }

        //not a single was swaped mean sorted thus break
        if (see == false)
        {
            break;
        }
    }
}

//will sort top by complains resolved
void sortBycomplains(customerSR C[], const int s)
{

    int i = 0, j = 0;

    //for swaping whole object
    customerSR  swap = {};

    //for seeing on iteration swaped or not if not mean sorted
    bool see = false;

    //bubble sort

    //will run for sorting each time
    //first will sort some then have to move to sort others
    for (i = 0; i < s - 1; i++)
    {

        //in each row a number will be on right position
        //thus -i means to not check for those elements
        for (j = 0; j < s - 1 - i; j++)
        {
            if (C[j].get_compResolv() < C[j + 1].get_compResolv())
            {

                //swap
                swap = C[j];
                C[j] = C[j + 1];
                C[j + 1] = swap;

                see = true;
            }
        }

        //not a single was swaped mean sorted thus break
        if (see == false)
        {
            break;
        }
    }
}


