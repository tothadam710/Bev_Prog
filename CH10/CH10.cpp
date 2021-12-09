
#include "../std_lib_facilities.h"


struct Points {
    double x;
    double y;   
};





vector<Points> create_vektor() {

    vector<Points> ponts;
    double x_cord;
    double y_cord;


    for (int i = 0; i < 7; i++) {
        cin >> x_cord >> y_cord;
        ponts.push_back(Points{ x_cord,y_cord });


    }

    return ponts;

}


void output(string fajl, vector<Points> original_points) {

    
    ofstream ir{ fajl };

    if (!ir) {
        error("Nem sikerult megynitni a fajlt!");
    }


    

    for (int i = 0; i < original_points.size(); i++)
    {
        ir << original_points[i].x << ' ' << original_points[i].y << endl;
    }


    ir.close();

}


void fill_from_file(vector<Points>& points, const string& name)
{
    ifstream ist(name.c_str());
    if (!ist) error("can't open input file, ", name);
    Points pp;
    while (!ist.eof()) { points.push_back(pp); }

    

}







int main()
{

    try {

        string fajl = "mydata.txt";
        vector<Points> original_points;
        vector<Points> processed_points;

        
        
        cout << "Kerem irja be az x,y pontokat szokozzel elvalasztva:" << endl;

        original_points = create_vektor();

        
        cout << "Az altalad megadott pontok kiirva a TXT fajlba:" << endl;

        output(fajl, original_points);
       

       
        fill_from_file(processed_points, fajl);
        
        for (size_t i = 0; i < original_points.size(); i++)
        {
            original_points[i];
        }

        keep_window_open();

      

        
        
        

        return 0;
    }

    catch (runtime_error& e) {
        
        cerr << "Hiba:"<< e.what() << endl;


        return -1;
    
    }





}

