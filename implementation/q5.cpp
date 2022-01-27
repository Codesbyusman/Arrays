/*

   --------------- Muhammad Usman Shahid  ----------------
   --------------------  20i-1797 ------------------------
   ------------------- Question-05 -----------------------
   ------------------ Assignment-01 ----------------------

*/

#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

//functio prototypes
void assignRandom(char[][30], const int);
void showLifeboard(char[][30], const int);
void lifeConditions(char[][30], char[][30], const int, const int);

int main()
{

    const int size = 30;

    //for taking from user to run the iterartion aftera specific time
    int time = 0;

    //the bord of life containing the cells
    char life[size][size] = {};

    //for storing for temporary time
    char duplicateLife[size][size] = {};

    cout << "\n\n\t\t\t\t :::::::::::: Game of Life :::::::::::: \n\n"
         << endl;

    system("pause");

    cout << "\n\t Enter the number of Second you want stop after each chage occur in the cells" << endl;
    cout << "\t      suggested is 1 sec to observe more deeply try a number of your own " << endl;
    cout << "\n\t\t\t stop for seconds : ";
    cin >> time;

    //not validating time by default it will be 1 like if somone enters negative number it wll be 1 automatically
    if (time < 0)
    {
        cout << "\n\n\t\t\t\t Are You serious ? " << endl;
        cout << "\t\t     I can Understand 0 that not to stop But " << time << " doesn't make sense " << endl;
        cout << "\t\t I guess you don't want to see changes of life --- but you have too :) " << endl;

        time = 1;

        cout << "\n\n\t\t\t :::::::::::: Giving Pause of 1 sec ::::::::::::" << endl;
    }

    //making it in the thousands because sleep take miliseconds
    time *= 1000;

    cout << endl;

    //for making the pause
    system("pause");

    cout << endl
         << endl;

    //will assign ranomly the values with active * and dead ' '
    assignRandom(life, size);

    //to make it infite and will continue and will show how the cells evolved change
    while (1)
    {

        //each time when a change is made showing the change
        showLifeboard(life, size);

        //checking on each cell of bord what will be it's fate by seeing it's neighbours
        for (int i = 1; i < 29; i++)
        {
            for (int j = 1; j < 29; j++)
            {
                //will check neighbours and will decide according to the conditions
                lifeConditions(life, duplicateLife, i, j);
            }
        }

        //now assiginging the duplicatelife to the real life
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                life[i][j] = duplicateLife[i][j];
            }
        }

        cout << endl
             << endl
             << endl
             << endl
             << endl;

        Sleep(time);
    }

    return 0;
}

//will assign random dead or life cells
//* for alive and ' ' for dead
void assignRandom(char lifeCells[][30], const int s)
{

    int i = 0, j = 0;

    for (i = 0; i < s; i++)
    {
        for (j = 0; j < s; j++)
        {
            //if generated is less than 40 then make * alive
            if (rand() % 100 <= 60)
            {
                lifeCells[i][j] = '*';
            }
            else
            {
                lifeCells[i][j] = ' ';
            }
        }
    }
}

//will the life board
void showLifeboard(char lifeCells[][30], const int s)
{
    int i = 0, j = 0;

    for (i = 0; i < s; i++)
    {

        //to center align output
        cout << "\n\t\t\t\t";

        //printing each element
        for (j = 0; j < s; j++)
        {
            cout << lifeCells[i][j] << " ";
        }

        cout << endl;
    }
}

//will check conditions which decides the status of current cell
void lifeConditions(char lifeCells[][30], char duplicateLife[][30], const int row, const int col)
{

    //to count alive so that can check the main 4 conditions
    int countalive = 0;

    //to see wether the current is alive aur dead
    //initallay considering dead false
    bool active = false;

    //the cell is active then make true --- alive
    if (lifeCells[row][col] == '*')
    {
        active = true;
    }

    //the eight neighbouring check is as follow

    //consider if active was at position lifeCells[3][3] --- the following condition will be like
    //it will check lifecells[2][2]
    if (lifeCells[row - 1][col - 1] == '*')
    {
        countalive++;
    }

    //it will check lifecells[3][2]
    if (lifeCells[row][col - 1] == '*')
    {
        countalive++;
    }

    //it will check lifecells[4][2]
    if (lifeCells[row + 1][col - 1] == '*')
    {
        countalive++;
    }

    //it will check lifecells[4][3]
    if (lifeCells[row + 1][col] == '*')
    {
        countalive++;
    }

    //it will check lifecells[2][3]
    if (lifeCells[row - 1][col] == '*')
    {

        countalive++;
    }

    //it will check lifecells[2][4]
    if (lifeCells[row - 1][col + 1] == '*')
    {
        countalive++;
    }

    //it will check lifecells[3][4]
    if (lifeCells[row][col + 1] == '*')
    {
        countalive++;
    }

    //it will check lifecells[4][4]
    if (lifeCells[row + 1][col + 1] == '*')
    {
        countalive++;
    }

    //deciding the future of current cell on the basis of above cells and will assign to the duplicate life

    //Any live cell with 0 or 1 live neighbors becomes dead, because of underpopulation
    if (countalive == 0 || countalive == 1 && active == true)
    {
        duplicateLife[row][col] = ' ';
    }
    else if (countalive == 2 || countalive == 3 && active == true)
    {
        //Any live cell with 2 or 3 live neighbors stays alive, because its neighborhood is just right
        duplicateLife[row][col] = '*';
    }
    else if (countalive > 3 && active == true)
    {
        //Any live cell with more than 3 live neighbors becomes dead, because of overpopulation

        duplicateLife[row][col] = ' ';
    }
    else if (countalive == 3 && active == false)
    {
        //Any dead cell with exactly 3 live neighbors becomes alive, by reproduction

        duplicateLife[row][col] = '*';
    }
}
