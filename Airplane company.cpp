#include <iostream>
#include <string.h>
using namespace std ;

class Stuff {
    private : 
        string national_id ;
    public :
        int age ; 
        string first_name , last_name ;

        void set_stuff (string const n ,string f ,string l ,int a){
            national_id = n ;
            first_name = f ;
            last_name = l ;
            age = a ;
        }
};

class Pilots {
    private : 
        string national_id ; 
        string  work_experience ;
    public :
        int age ; 
        string first_name , last_name , degree ;

        void set_pilot (string const n  ,string w ,string d ,string f ,string l ,int a){
            national_id = n;
            work_experience = w ;
            degree = d ; 
            first_name = f ;
            last_name = l;
            age = a ;
        }
};

class Airplane {
    protected : 
        string id , series , company ;
    public : 
        int age , engine_number , length , seat_number ;
        
		virtual void set_basic(){}
        virtual void set_plane_info(){}       
};

class Boeing : public Airplane {
    public : 
    	void set_basic(){
    	company = "Boeing";
        seat_number = 250 ;

		}

        void set_plane_info(string i , string s , int a , int e , int l ){
            id=i;
            series=s;
            age=a;
            engine_number=e;
            length=l;
        }
};

class Airbus : public Airplane {
        public :
		void set_basic(){ 
        company = "Airbus";
        seat_number = 200 ;
		}
        
        void set_plane_info(string i , string s , int a , int e , int l ){
            id=i;
            series=s;
            age=a;
            engine_number=e;
            length=l;
        }
};

class Tupolev : public Airplane {
        public :
		void set_basic(){ 
        company = "Tupolev";
        seat_number = 210 ;
    	}
        void set_plane_info(string i , string s , int a , int e , int l ){
            id=i;
            series=s;
            age=a;
            engine_number=e;
            length=l;
        }
};

class TravelInfo {
    private : 
        string national_code ;
    public :
        string full_name , origin , destination , date , plane_company ;
        float pass_number , cost ;

        void set_info (string n , string f , string o ,string des ,string dat  , float p , string pc){
            national_code = n;
            full_name = f ;
            origin = o ;
            destination = des ;
            date = dat ;
            pass_number = p ;
            plane_company = pc ;
        }

        void calculate_cost (){
            if (plane_company=="boieng")
                cost = pass_number * 500000 ;
            
            else if (plane_company=="airbus")
                cost = pass_number * 480000 ;
            
            else 
                cost = pass_number * 450000 ;
            
        }
};

class Ticket : public TravelInfo {
    public : 
    Ticket(){
        cout << "name : " << full_name << endl ; 
        cout << "origin : " << origin <<endl ; 
        cout << "destination : " << destination <<endl ; 
        cout << "cost : " << cost ;
    }
};


int main (){
    //set a stuff 
    Stuff obj1;
    obj1.set_stuff("1273896838" , "Ali " , "Akbari" , 35);

    //set a pilot 
    Pilots obj2;
    obj2.set_pilot("1273896859" , "ten years" , "Master" , "Ahmad" , "Kazemi" , 41);

    // set a boieng airplane 
    Boeing obj3;
    obj3.set_plane_info("1285" , "k-950" , 21 , 4 , 50);

    // set a airbus airplane 
    Airbus obj4;
    obj4.set_plane_info("1325" , "z-150" , 18 , 4 , 42);

    // set a tupolev airplane 
    Tupolev obj5;
    obj5.set_plane_info("1481" , "h-650" , 28 , 2 , 44);

    // set a travel 
    TravelInfo obj6;
    obj6.set_info("1273896838" , "Mohammad Abbasi " , "Tehran" , "Tabriz" , "sunday" , 1 , "boieng");
    obj6.calculate_cost();

    return 0;
}