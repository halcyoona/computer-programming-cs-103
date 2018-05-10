#include <iostream>
using namespace std;

struct student {
    string name;
    int roll_number;
    char section;
    int batch;
    string email;
    int Phone_number;
    struct date d1;
};

struct date {
    int day;
    int month;
    int year;
};






int main(){
    struct student st1;
    cout<<"enter roll number"<<endl;
    cin>>st1.roll_number;
    cout<<"enter section"<<endl;
    cin>>st1.section;
    cout<<"enter batch"<<endl;
    cin>>st1.batch;
    cout<<"enter name"<<endl;
    cin>>st1.name;
    cout<<"Name : "<<st1.name<<endl;
    cout<<"Roll Number : "<<st1.roll_number<<endl;
    cout<<"Section : "<<st1.section<<endl;
    cout<<"Batch : "<<st1.batch<<endl;
    
    return 0;
}


