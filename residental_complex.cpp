#include <iostream>
#include <string.h>

using namespace std ;

class Complex {
    protected :
        string building_class , address ;
        unsigned int floor_number , unit_number , unit_area ;
        bool pool , jakuzzi , golf_field ;
        float cost , service_chrage ; 
    public :
        virtual void set_building_details(){}
        virtual void show_building_details(){}
        virtual void calc_cost(){}
};

class Apartment1 : public Complex {
    public :
        void set_building_details(string a , int f , int u ){
            building_class= "high class ";
            address=a ; 
            floor_number= f;
            unit_number= u ;
            unit_area= 200 ;
            pool= true;
            jakuzzi= true ;
            golf_field=true ;
            service_chrage=  150000 ; 
        }
        void calc_cost(){
            cost = unit_area * 20000000 ;
        }
        void show_building_details (){
            cout << "class : " << building_class << endl ;
            cout << "number of floors : " << floor_number << endl ;
            cout << "unit area : " << unit_area << endl ;
            cout << "does it have pool  : " << pool << endl ;
            cout << "does it have jakuzzi : " << jakuzzi << endl ;
            cout << "does it have golf field  : " << golf_field << endl ;
            cout << " service chrage : " << service_chrage << endl ;
            cout <<"cost : "<< cost << endl ;
        }
};

class Apartment2 : public Complex {
        public :
        void set_building_details(string a , int f , int u  ){
            building_class= "mid class ";
            address=a ; 
            floor_number= f;
            unit_number= u ;
            unit_area= 140 ;
            pool= true;
            jakuzzi= false ;
            golf_field=false ;
            service_chrage=  100000 ; 
        }
        void calc_cost(){
            cost = unit_area * 15000000 ;
        }
        void show_building_details (){
            cout << "class : " << building_class << endl ;
            cout << "number of floors : " << floor_number << endl ;
            cout << "unit area : " << unit_area << endl ;
            cout << "does it have pool  : " << pool << endl ;
            cout << "does it have jakuzzi : " << jakuzzi << endl ;
            cout << "does it have golf field  : " << golf_field << endl ;
            cout << " service chrage : " << service_chrage << endl ;
            cout <<"cost : "<< cost << endl ;
        }
};

class Apartment3 : public Complex {
        public :
        void set_building_details(string a , int f , int u  ){
            building_class= "low class ";
            address=a ; 
            floor_number= f;
            unit_number= u ;
            unit_area= 90 ;
            pool= false;
            jakuzzi= false ;
            golf_field= false ;
            service_chrage=  50000 ; 
        }
        void calc_cost(){
            cost = unit_area * 10000000 ;
        }
        void show_building_details (){
            cout << "class : " << building_class << endl ;
            cout << "number of floors : " << floor_number << endl ;
            cout << "unit area : " << unit_area << endl ;
            cout << "does it have pool  : " << pool << endl ;
            cout << "does it have jakuzzi : " << jakuzzi << endl ;
            cout << "does it have golf field  : " << golf_field << endl ;
            cout << " service chrage : " << service_chrage << endl ;
            cout <<"cost : "<< cost << endl ;
        }
};

int main (){ 
    Apartment1 ob1 ;
    Apartment2 ob2 ; 
    Apartment3 ob3 ;

    Apartment1 *p1 = &ob1 ;
    p1-> set_building_details ("a street , b alley " , 12 , 36 );
    p1 -> calc_cost (); 
    p1 -> show_building_details();

    Apartment2 *p2 = &ob2 ;
    p2 -> set_building_details ("c street , d alley " , 9 , 18 );
    p2 -> calc_cost (); 
    p2 -> show_building_details();

    Apartment3 *p3 = &ob3 ;
    p3 -> set_building_details ("j street , h alley " , 5 , 10 );
    p3 -> calc_cost (); 
    p3 -> show_building_details();

    return 0 ;
}