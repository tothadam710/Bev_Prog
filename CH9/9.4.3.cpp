#include "../std_lib_facilities.h"

class Date {
private:
	int ev;
	int ho;
	int nap;

public:
    Date(int e, int h, int n);
    void add_day(int hozzaad);

    int get_ev() {
        return ev;
    }

    int get_ho() {
        return ho;
    }

    int get_nap(){
        return nap;
    }

    void kiiras() {
        cout << get_ev() << '.' << get_ho() << '.' << get_nap() << '.' << endl;
    }

    
    

};


Date::Date(int e, int h, int n) {

    if (e <= 0) {
        error("Hibas ev!");
    }

    else {
        ev = e;
    }
    if (h > 12 || h <= 0) {
        error("Hibas honap!");
    }

    else {
        ho = h;
    }

    if (n > 0 && n < 31) {
        if (h == 2 && n > 28) {
            error("A februar 28 napos!");
        }

        else {
            nap = n;
        }
    }

    else {
        error("Hibas honap!");
    }


}

void Date::add_day(int hozzaad) {
    nap = nap + hozzaad;

    if (nap > 31) {
        ho++;
        nap = nap - 31;
      
        if (ho > 12) {
            ev++;
            ho = ho - 12;
                    
        }

      
        
        

    }

}



int main() {


    try {

        Date today( 1978, 6, 25 );

        cout << "today: ";
        today.kiiras();

        today.add_day(1);

        cout << "tomorrow: ";
        today.kiiras();


        return 0;
    }
    catch (exception& e) {
        cout << e.what() << endl;
        return 1;
    }


	
}
