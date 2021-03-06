#include "../std_lib_facilities.h"

//vector with months
vector<string> honapok = { "Januar","Februar", "Marcuis", "Aprilis",
    "Majus", "Junius", "Julius",
    "Augusztus", "Szeptember",
    "Oktober", "November", "December" };

//define the enum class
enum class Honap {
    jan, feb, mar,
    apr, may, jun, 
    jul, aug, szep,
    oct, nov, dec
};

//overloading
Honap operator++(Honap& ho) {

    ho = (ho == Honap::dec) ? Honap::jan :  Honap(int(ho) + 1);
    return ho;

}

ostream& operator<<(ostream& os, Honap ho)
{
    return os << honapok[int(ho)];
}


//define teh Date class
class Date {
    //fields
    int ev;
    Honap ho;
    int nap;
public:
    //error
    class Invalid {};
    Date(int e, Honap h, int n) : ev(e), ho(h), nap(n) { if (!is_valid()) throw Invalid{}; }
    
    bool is_valid();

    void add_day(int hozzaad);

    //get access to private variables
    int get_ev() {
        return ev;
    }

    Honap get_ho() {
        return ho;
    }

    int get_nap() {
        return nap;
    }

    void kiiras() {
        cout << get_ev() << '.' << get_ho() << '.' << get_nap() << '.' << endl;
    }


};

/*Date::Date(int y, Honap m, int d)
    
{
    if (y <= 0) {
        error("Hibas ev!");
    }

    else {
        ev = y;
    }
    if (m > 12 || m <= 0) {
        error("Hibas honap!");
    }

    else {
        ho = m;
    }

    if (d > 0 && d < 31) {
        if (m == 2 && d > 28) {
            error("A februar 28 napos!");
        }

        else {
            nap = d;
        }
    }

    else {
        error("Hibas honap!");
    }

}
*/

//define the is_valid function to handle bad values
bool Date::is_valid(){
    if (ev < 0 || nap < 1 || nap > 31) {
        return false;

        
    }

    return true;
}


//add a day
void Date::add_day(int hozzaad)
{
    nap = nap + hozzaad;

    if (nap > 31) {
        ++ho;
        nap = nap - 31;

        if (ho == Honap::jan) {
            ev++;


        }

    }

}

    int main() {
        try {

            //peldanyositas
            Date today(1978, Honap::jun, 25);

            // 9.7.2 - copy
            Date tomorrow = today;
            tomorrow.add_day(1);
           

            today.kiiras();
            tomorrow.kiiras();

            //error handling
        }
        catch (exception& e) {
            cerr << e.what() << '\n';
            return 1;
        }
        catch (Date::Invalid) {
            cerr << "Hibas adat" << '\n';
            return 2;
        }

    }
