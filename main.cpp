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
};

int main(){
    
    return 0;
}