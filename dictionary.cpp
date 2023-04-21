#include<iostream>
#include<string.h>

using namespace std ;

// a class to set basics od dictionary 
class Dictionary{

    protected :
        static int entry_number ;
        const string name = "Madani dictionary";
		const string type_of_dictionary = "English to persian" ;
}; 

// a class to set an entry 
class Entry : public Dictionary {
    protected :
        string entry ; 
    public :

        virtual void set_entry_information(){};
        virtual void show_entry(){};
};

// two classes to set details of an entry 
class Word : public Entry {
    protected :
        string definition , type , pronunciation , synonym , antonym , example ;
    
	public :
        void set_entry_information(string en ,string  d , string  t , string  p , string  s ,string  a , string e ){
            entry = en ;
			definition = d;
            type = t ; 
            pronunciation = p;
            synonym = s ;
            antonym = a;
            example = e ;
        }

        void show_entry (){
            cout <<"the definition of "<< entry << " is : "  << definition <<endl;
            cout <<"the type of "<< entry << " is : "  << type <<endl;
            cout <<"the pronunciation of "<< entry << " is : "  << pronunciation <<endl;
            cout <<"the synonym of "<< entry << " is : "  << synonym <<endl;
            cout <<"the antonym of "<< entry << " is : "  << antonym <<endl;
            cout <<"the example of "<< entry << " is : "  << example <<endl;
        }
};

class Proverb : public Entry {
    protected :
        string meaning  ;
	public :
        void set_entry_information(string n ,string m ){
        	entry=n;
            meaning = m ;
        }

        void show_entry (){
            cout <<"the meaning of "<< entry << " is : "  << meaning <<endl;
        }
};

// sort by alfabet
class AlfabetOrder {
	public :
    string entry1[10];

    void set_entries(){
    	cout << "enter the entries"<< endl;
        for (int i=0 ; i<=10 ; i++ ) {
            getline(cin , entry1[i]);
        } 
    }

    void alfabet_order(){
        for (int i = 0 ; i <10 ; i++){
            for(int j = 1 ; j <=10 ; j++){
                if (entry1[i]>entry1[j]){
                    string temp = entry1[i];
                    entry1 [i] = entry1 [j];
                    entry1 [j] = temp;
                }
            }
        }
    }
    
    void show_entry1(){
        for (int i = 0 ; i <=10 ; i++){
            cout << entry1[i] << "\t";
        }
    }

};
int main (){

    Word ob1;
    ob1.set_entry_information("oppersive","ظالم" , "adj" , "/?'p??s.?v/" , "cruel" ,"kind" , "he is oppersive." );
    ob1.show_entry();

    Proverb ob2;
    Proverb *p;
    p=&ob2;
    p->set_entry_information("no pain no gain","نابرده رنج گنج میسر نمیشود");
	p->show_entry();
	
	AlfabetOrder ob3;
	ob3.set_entries();
	ob3.alfabet_order();
	ob3.show_entry1();
	
    return 0 ;
}