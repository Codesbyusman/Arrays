/*

   --------------- Muhammad Usman Shahid  ----------------
   --------------------  20i-1797 ------------------------
   ------------------- Question-02 -----------------------
   ------------------ Assignment-01 ----------------------

*/

#include <iostream>
#include <iomanip>

using namespace std;

//function prototypes
void enterValue(int **, int, int);
void showMatrix(int **, int, int);

//for allocating and deallocating the memory
int **allocate(int **, int, int);
void deallocate(int **, int);

//will check in part b whether matrices can be multiplied
bool mulCheck(int, int);
void multiply(int **, int **, int **, int, int, int, int);

int main()
{
    //for taking columns and rows size
    int rowsA = 0, colsA = 0;
    int rowsB = 0, colsB = 0;

    //for assitance
    int a = 0;

    int i = 0, j = 0;

    //for making the arrays
    int **matrixA = NULL;

    //will use in part B of the task
    int **matrixB = NULL;

    //for storing the result of multiplication
    int **multipliedMatrix = NULL;

    //-------------------------------------------------------------------
    //--------------------------- Part a --------------------------------
    //-------------------------------------------------------------------

    cout << "\n\t\t :::::::::::::: PART - A ::::::::::::: " << endl;

    cout << "\n\t\t :::::::::::::: MATRIX-A ::::::::::::: " << endl;

    //validating the size of the array
    do
    {
        if (a == 0)
        {
            cout << "\n\t Enter the row    size for Matrix A : ";
            cin >> rowsA;
            cout << "\t Enter the column size for Matrix A : ";
            cin >> colsA;
        }
        else
        {

            cout << "\n\t ::::::: Error, inappropriate input :::::::" << endl;

            cout << "\n\t Enter the row    size for Matrix A : ";
            cin >> rowsA;
            cout << "\t Enter the column size for Matrix A : ";
            cin >> colsA;
        }

        a++;

    } while (!(rowsA > 0 && colsA > 0));

    //allocates, take values and show the matrix
    matrixA = allocate(matrixA, rowsA, colsA);
    enterValue(matrixA, rowsA, colsA);

    //row wise and column wise showing the matrix
    cout << "\n\t   Entered Matrix A is : " << endl;

    showMatrix(matrixA, rowsA, colsA);

    cout << endl
         << endl;
    ;

    //pause to see the values
    system("pause");

    //-------------------------------------------------------------------
    //--------------------------- Part b --------------------------------
    //-------------------------------------------------------------------

    cout << "\n\t\t :::::::::::::: PART - B ::::::::::::: " << endl;

    cout << "\n\t\t ::::: Multiplication of Matrices :::: " << endl;

    cout << "\n\t\t :::::::::::::: MATRIX-B ::::::::::::: " << endl;
    cout << "\n\t\t :Matrix to be multiplied by Matrix-A: " << endl;

    a = 0;
    //validating the size of the array
    do
    {
        if (a == 0)
        {
            cout << "\n\t Enter the row    size for Matrix B : ";
            cin >> rowsB;
            cout << "\t Enter the column size for Matrix B : ";
            cin >> colsB;
        }
        else
        {

            cout << "\n\t ::::::: Error, inappropriate input :::::::" << endl;

            cout << "\n\t Enter the row    size for Matrix B : ";
            cin >> rowsB;
            cout << "\t Enter the column size for Matrix B : ";
            cin >> colsB;
        }

        a++;

    } while (!(rowsB > 0 && colsB > 0));

    if (mulCheck(colsA, rowsB))
    {
        //allocation of sizes and taking input
        matrixB = allocate(matrixB, rowsB, colsB);
        enterValue(matrixB, rowsB, colsB);

        //row wise and column wise showing the matrix
        cout << "\n\t   Entered Matrix B is : " << endl;

        showMatrix(matrixB, rowsB, colsB);

        cout << endl;

        cout << "\n\t\t ::::: --------- Multiplying ------- :::::" << endl
             << endl;
        ;

        //pause to see the values
        system("pause");

        //the order of resultant when multiplies is the
        //the rows of first matrix and the col of second matrix
        multipliedMatrix = allocate(multipliedMatrix, rowsA, colsB);

        //will do the multiplication
        multiply(multipliedMatrix, matrixA, matrixB, rowsA, colsA, rowsB, colsB);

        //row wise and column wise showing the matrix
        cout << "\n\t   Multiplication of Matrix A & Matrix B is : " << endl;

        showMatrix(multipliedMatrix, rowsA, colsB);

        cout << endl;

        //deallocating all memories created for multiplication
        deallocate(matrixB, rowsB);
        deallocate(matrixB, rowsA);
    }
    else //not able to multiply
    {
        cout << "\n\t\t ::::::::: Not Possible to multiply the given matrices :::::::::" << endl;
        cout << "\n\t\t ::::::::::::: Columns of A not equal to rows of B :::::::::::::" << endl;
        cout << "\n\t\t :::::::::::::: Thus the can not multiply matrices :::::::::::::" << endl;
    }

    cout << endl
         << endl;

    //deallocation of the memories
    deallocate(matrixA, rowsA);

    return 0;
}

//function definitions
//for allocating and deallocating the memory
int **allocate(int **matrix, int r, int c)
{

    int i = 0;

    matrix = new int *[r];

    for (i = 0; i < r; i++)
    {
        *(matrix + i) = new int[c];
    }

    return matrix;
}

//will deallocate memory
void deallocate(int **matrix, int r)
{
    int i = 0;

    for (i = 0; i < r; i++)
    {
        delete[] * (matrix + i);
    }

    delete[] matrix;

    matrix = NULL;
}

//will take data from user
void enterValue(int **matrix, int r, int c)
{

    int i = 0, j = 0;

    cout << "\n\t\t :::::: Enter the values for the matrix :::::::: \n"
         << endl;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            cout << "\t Enter value for element at row (" << i + 1 << ") col (" << j + 1 << ") with indexes [" << i << "][" << j << "] : ";
            cin >> *(*(matrix + i) + j);
        }

        cout << endl;
    }
}

//will show the matrix
void showMatrix(int **matrix, int r, int c)
{

    int i = 0, j = 0;

    for (i = 0; i < r; i++)
    {

        cout << "\n\t\t\t ";

        for (j = 0; j < c; j++)
        {
            cout << setw(10) << *(*(matrix + i) + j);
        }

        cout << endl;
    }
}

bool mulCheck(int colsofA, int rowsofB)
{

    //condition for matrices to be applicable for multiplication
    if (colsofA == rowsofB)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//multiplying the two matrices and storing the result in resultant
void multiply(int **result, int **A, int **B, int ra, int ca, int rb, int cb)
{
    //for loops --- counting variables
    int i = 0, j = 0, k = 0;

    //for storing the sum in the process of multiplication
    int sum = 0;

    for (i = 0; i < ra; i++)
    {
        //will move for the columns of b , the row of will be multiplied by each column of B
        for (j = 0; j < cb; j++)
        {
            //each time will make sum equal to 0 to restore in the next element of rsultant matrix
            sum = 0;

            for (k = 0; k < ca; k++)
            {
                //the row of A multiplied by the column of B and sum stores
                sum += (*(*(A + i) + k)) * (*(*(B + k) + j));
            }

            *(*(result + i) + j) = sum;
        }
    }
}
