#include <iostream>
#include <string.h>

using namespace std ;

// declaring  transportation class that include all the properties of vehicles  
class Transportation {
    private :
    string plaque ;
    protected :
        string color , model ;
    public : 
        void set_vehicle_informations(const string pl , string col , string mod ){
            plaque = pl ; 
            color = col ; 
            model = mod ;
        }

        void show_vehicle_informations(){
            cout << "The model of vehicle is : " << model << endl;
            cout << "The color of vehicle is : " << color << endl;
            cout << "The plaque of vehicle is : " << plaque << endl;
        }         
};

// declaring drivers properties 
class Drivers {
    private :
        string name , family , id ; 
        int age ;
    public : 
        void set_driver_informations(string n , string f , string i , int a){
            name = n ;
            family = f ;
            id = i ;
            age = a ; 
        }
        
        void show_driver_informations(){
            cout << "The name of driver is : " << name << endl;
            cout << "The family of driver is : " << family << endl;
            cout << "The id of driver is : " << id << endl;
        }       
};

// declaring a class to set travel properties
class Travel {
    protected : 
    	static int numberOfTravels;
        string origin , destination , time , type ; 
        float cost ;
    public :
        void set_Travel_informations (string org , string dest , string t , string tp ){
            origin = org ;
            destination = dest ; 
            time = t ;
            type = tp ;
        }
        // a pure virtual function to calculate cost 
        virtual void calculate_cost (){};
};
int Travel:: numberOfTravels=0;

// declaring two classes to define properties of Freightage and passenger service travels  
class Freightage { 
    protected :
        float freight_weight ; 
    public :
        void set_freight_weight (float x){
            freight_weight = x ; 
        } 
};

class Passenger : public Travel {
    private:
        string name, family, _id, mobile;
        unsigned int age;
    protected : 
        float passenger_number ;
    public : 
        void set_passenger_number (float x){
            passenger_number = x ;
        }
        void set_passenger_information(string n, string f, string id, string m, int a)
        {
            name = n;
            family = f;
            _id = id;
            mobile = m;
            age = a;
        }
        friend class Ticket;
        void showTicket()
        {
            if (age <=8)
            {
                cost/=2;
            }
            cout<<"Name: "<<name<<"\tFamily: "<<family<<"\n Age: "<<age<<"\t ID: "<<_id<<"\n Mobile: "<<mobile;
            cout << "\n Origin: "<<origin<<"\t Destinition: "<<destination<<"\n Date: "<<time<<"\t Type: "<<type<<endl;
            cout << "Cost: "<<cost<<endl;
        }
};

//defining all types of transportations and calculate cost of travel   
class Bus :public Passenger , public Freightage {
    public :
        Bus() {
        	calculate_cost();
		}
        void calculate_cost () {
            if (type == "Passenger"){
                 cost = passenger_number * 40000;
            }
            else {
                 cost = freight_weight * 10000 ;
            } 
        }

};

class Airplane : public Freightage ,public Passenger {
    public :
        Airplane() {calculate_cost();
		}
            void calculate_cost () {
                if (type == "Passenger"){
                    cost = passenger_number * 90000;
                }
                else {
                    cost = freight_weight *40000 ;
                }
            }  
};

class Taxi :public Freightage ,public Passenger{
    public :
        Taxi() {calculate_cost();}
        
            void calculate_cost () {
                if (type == "Passenger"){
                    cost = passenger_number * 60000;
                }
                else {
                    cost = freight_weight *30000 ;
                }
            }
};

class Train : public Freightage ,public Passenger {
    public :
        Train() {calculate_cost();}
            void calculate_cost () {
                if (type == "Passenger"){
                    cost = passenger_number * 30000;
                }
                else {
                    cost = freight_weight * 9000 ;
                }
            }
};

class Truck :public Freightage  , public Travel {
    public :
        Truck() {calculate_cost();}
        
            void calculate_cost () {
                cost = freight_weight *20000;
            }
};

class Ticket :public Passenger {
    public:
        Ticket()
        {
            numberOfTravels++;
        }
        void showTicket()
        {
            if (age <=8)
            {
                cost/=2;
            }
            cout<<"Name: "<<name<<"\tFamily: "<<family<<"\n Age: "<<age<<"\t ID: "<<_id<<"\n Mobile: "<<mobile;
            cout << "\n Origin: "<<origin<<"\t Destinition: "<<destination<<"\n Date: "<<time<<"\t Type: "<<type<<endl;
            cout << "Cost: "<<cost<<endl;
        }
};


int main (){
    // set a vehicle
    Transportation obj1 ;
    obj1.set_vehicle_informations("123p18/53","white","Benz");
    obj1.show_vehicle_informations();

    // set a driver
    Drivers obj2;
    obj2.set_driver_informations("Matin" , "Abri" , "1275555" , 35);
    obj2.show_driver_informations();

    // set a Travel 
    Travel obj3;
    obj3.set_Travel_informations("Esfahan" , "Tabriz" ,"15:30" , "Passenger");

    //set a passenger
    Passenger obj4;
    Passenger *p;
    p =&obj4;
    p -> set_passenger_number(1);
    p -> set_passenger_information("Ali" , "Alishani" , "12855442" , "091300000" , 7 );
    p-> showTicket();

    Bus obj5;
    obj5.calculate_cost();


    return 0;
}