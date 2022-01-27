/*

   --------------- Muhammad Usman Shahid  ----------------
   --------------------  20i-1797 ------------------------
   ------------------- Question-04 -----------------------
   ----------------------- Class -------------------------
   ------------------ Assignment-01 ----------------------

*/


#include <string>
using namespace std;

//class of Customer support representative to hold informartion about CSRs
class customerSR
{

private:
    string csrID;
    string csrName;
    int hours;
    int complaintsResolved;
    double payRate;
    double wages;

    static int assignID; //will assign each CSR with a number in ID

public:
    //default constructur
    customerSR();

    //set the data
    void setName(string);
    void setHours(int);
    void set_compResol(int);
    void set_payRate(double);
    void setWages(double);

    //to access the data
    string getID() const;
    string getName() const;
    int getHour() const;
    int get_compResolv() const;
    double get_payRate() const;
    double getWages() const;

    //tocalculate the wages
    void calWages();

    //to display the data
    void display();
};

