#include<iostream>
#include<vecetor>
#include<string>
using namespace std;

class Person{
    person();
    private:
    int phoneNum;
    string LName;
    string FName;

    public:
    //setter functions
    void setPhoneNum(phoneNum){
        this->phoneNum = phoneNum;
    }
    void setLastName(string Lname){
        this->Lname=Lname;
    }
    void setFirstName(string Fname){
        this->Fname=Fname;
    }
    //getter functions
    int getPhoneNum(){
        return phoneNum;
    }
    string getLName(){
        return Lname;
    }
    string getFName(){
        return Fname;
    }

};