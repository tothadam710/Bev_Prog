#include "../std_lib_facilities.h"



struct Date {

    int ev;
    int honap;
    int nap;


   

};

void init_day(Date& dd,int e,int h,int n) {

    if (e <= 0) {
        error("Hibas ev!");
    }

    else {
        dd.ev = e;
    }
    if (h > 12 || h <= 0) {
        error("Hibas honap!");
    }

    else {
        dd.honap = h;
    }

    if (n > 0 && n < 31) {
        if (h==2 && n > 28) {
            error("A februar 28 napos!");
        }

        else {
            dd.nap = n;
        }
    }

    else {
        error("Hibas honap!");
    }


}

void add_day(Date& dd, int hozzaad) {
    
    dd.nap = dd.nap + hozzaad;

    if (dd.nap > 31) {
        dd.honap++;
        dd.nap = dd.nap - 31;
        if (dd.honap > 12) {
            dd.ev++;
            dd.honap = dd.honap - 12;
        }
    }


}


int main()
{
    try {
        

       

      
        Date tomorrow;
        init_day(tomorrow, 1978, 6, 25);

        cout << "today:" << tomorrow.ev << '.' << tomorrow.honap << '.' << tomorrow.nap << ".\n";

        
        
        cout << "tomorrow:";
        add_day(tomorrow,1);

       
        cout << tomorrow.ev << '.' << tomorrow.honap << '.' << tomorrow.nap << ".\n";

        return 0;
    }
    catch (exception& e) {
        cout << e.what() << endl;
        return 1;
    }
}

