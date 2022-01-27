/*

   --------------- Muhammad Usman Shahid  ----------------
   --------------------  20i-1797 ------------------------
   ------------------- Question-01 -----------------------
   ------------------ Assignment-01 ----------------------

*/

#include <iostream>
#include <iomanip>

using namespace std;

//functions prototypes
void calAvg(int *, int);
void enterValue(int *, int);
void showArray(int *, int);

int main()
{

    //for assitance
    int a = 0;

    //for holding the size
    int size = 0;

    //for making the array
    int *avgArray = NULL;

    cout << "\n\t\t :::::: Dynamic 1D Array  :::::: " << endl;

    //validating the size of the array
    do
    {
        if (a == 0)
        {
            cout << "\n\t Enter the size for 1D Array : ";
            cin >> size;
        }
        else
        {

            cout << "\n\t ::::::: Error, inappropriate size :::::::" << endl;

            cout << "\n\t Enter the size for 1D Array again : ";
            cin >> size;
        }

        a++;

    } while (!(size > 0));//validating 

    //making the array of entered size ---- memory allocation
    avgArray = new int[size];

    enterValue(avgArray, size);
    showArray(avgArray, size);
    calAvg(avgArray, size);

    cout << endl;

    //deleting the memory cretaed ---- memory dealloction
    delete[] avgArray;
    avgArray = NULL;

    return 0;
}

//functions definitions

//will calculate the avg
void calAvg(int *Array, int s)
{
    int i = 0, sum = 0;
    float avg = 0;

    for (i = 0; i < s; i++)
    {
        sum += *(Array + i);
    }

    //typecasted s to have answers in floating points
    avg = sum / float(s);

    cout << "\n\t\t Average of entered array is : " << fixed << setprecision(3) << avg << endl;
}

//will take the values
void enterValue(int *Array, int s)
{

    int i = 0;

    cout << "\n\t ----- Enter the values for array elements ----- " << endl;

    for (i = 0; i < s; i++)
    {
        cout << "\n\t   Enter value for index (" << i << ") elemet #" << i + 1 << " : ";
        cin >> *(Array + i);
    }
}

//will show the array
void showArray(int *Array, int s)
{

    cout << "\n\t Entered Array is : { ";

    int i = 0;

    for (i = 0; i < s; i++)
    {
        cout << *(Array + i) << " ,";
    }

    cout << "\b} " << endl;
}