#include <iostream>

using namespace std;

class kutyak {
    public:
        string nev;
         int kor;
         bool chippelve;


        kutyak(string s, int k,bool ch) {
            nev = s;
            kor = k;
            chippelve = ch;



        }

        
         int kutyaev(int kora);
          void chippel(bool ch);
          void adatok();
      


      

       

};