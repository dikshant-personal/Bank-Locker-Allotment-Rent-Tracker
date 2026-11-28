#include <iostream>
#include<fstream>
#include<string>
using namespace std;

const int small_rent=1000;
const int medium_rent=2000;
const int large_rent=3000;
const int total_lockers=9;

class Customer{
    public:
    string name;

    Customer(){
        name="";
    }
};
class Locker{
    public:
    int lockerno;
    string size;
    int rent;
    bool occupied;
    Customer customer;
    int lastPaidYear;

    Locker(){
        lockerno=0;
        size="";
        rent=0;
        occupied=false;
        lastPaidYear=0;
    }

    void setLocker(int no,string s,int r){
        lockerno=no;
        size=s;
        rent=r;
    }

};

class LockerRoom{
    Locker lockers[total_lockers];
    public:
    
    LockerRoom(){

        for(int i=0;i<3;i++){
            lockers[i].setLocker(i+1,"Small",small_rent);
        }
        for(int i=3;i<6;i++){
            lockers[i].setLocker(i+1,"Medium",medium_rent);
        }
        for(int i=6;i<9;i++){
            lockers[i].setLocker(i+1,"Large",large_rent);
        } 
    }

    void allotLocker(int no,string name,int year){
        if(no<1 || no>total_lockers){
            throw string("Invalid Locker Number!");
        }
        Locker &l=lockers[no-1];

        if(l.occupied){
            throw string("Locker is Already Occupied");
        }

        l.occupied=true;
        l.customer.name=name;
        l.lastPaidYear=year;

        ofstream file("lockers.txt",ios::app);
        file << "Allotment: Locker " << no
            << ", Customer: " << name
            << ", Size: " << l.size
            << ", Rent: " << l.rent
            << ", Year: " << year << endl;
        file.close();
        
        cout<<"Locker Added Successfully...";
    }

    void payRent(int no,int year){
        if(no<1 || no>total_lockers){
            throw string("Invalid Locker Number..");
        }

        Locker &l=lockers[no-1];

        if(!l.occupied){
            throw string("Locker is Not Occupied");
        }

        int yearsdue=year-l.lastPaidYear;
        if(yearsdue<=0){
            cout<<"Rent is already paid for this year..."<<endl;
            return;
        }

        int amount=yearsdue*l.rent;

        l.lastPaidYear=year;

        ofstream file("lockers.txt",ios::app);
        file << "Rent Payment: Locker " << no
             << ", Customer: " << l.customer.name
             << ", Amount: " << amount
             << ", Year: " << year << endl;
        file.close(); 
        
        cout<<"Rent Paid Successfully..\nAmount = "<< amount<<endl;
    }


    void lockerSurrender(int no){
        if(no<1 || no>total_lockers){
            throw string("Invalid Locker Number");
        }
        Locker &l=lockers[no-1];

        if(!l.occupied){
            throw string("Locker is not occupied");
        }

        ofstream file("lockers.txt",ios::app);
        file<<"Surrender : Locker"<<no
            <<", Customer : "<<l.customer.name<<endl;
        file.close();
        
        l.occupied=false;
        l.customer.name="";
        l.lastPaidYear=0;


        cout<<"locker Surrendered Successfully!.."<<endl;
        
    }

    
};

int main(){
    
    return 0;
}