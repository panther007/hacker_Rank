#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
    public:
        string name;
        int age;
        virtual void getdata() = 0;
        virtual void putdata() = 0;

};

class Professor : public Person{
    private:
        int publications;
        int cur_id;
        static int idCtr;
    public:
        Professor(){
            name="";
            age=0;
            publications=0;
            idCtr++;
            cur_id=idCtr;
        }
        virtual void getdata(){
            std::cin>>this->name
                    >>this->age
                    >>this->publications;
        }
        virtual void putdata(){
            std::cout<<this->name<<" "
                     <<this->age<<" "
                     <<this->publications<<" "
                     <<this->cur_id<<"\n";
        }
};

class Student : public Person{
    private:
        std::vector<int> marks;
        int cur_id;
        static int idCtr;
    public:
        Student(){
            name="";
            age=0;
            marks={0,0,0,0,0,0};
            idCtr++;
            cur_id=idCtr;
        }
        virtual void getdata(){
            std::cin>>this->name
                    >>this->age;
            for(int i=0;i<6;i++){
                std::cin>>this->marks[i];    
            }
        }
        virtual void putdata(){
            std::cout<<this->name<<" "
                     <<this->age<<" "
                     <<marks[0]+marks[1]+marks[2]+marks[3]+marks[4]+marks[5]<<" "
                     <<this->cur_id<<"\n";
        }
};


int Professor::idCtr = 0;
int Student::idCtr = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
