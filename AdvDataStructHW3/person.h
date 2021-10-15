#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Person{
    Person();
    private:
    int phoneNum;
    string Lname;
    string Fname;

    public:
    //setter functions
    void setPhoneNum(int phoneNum){
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