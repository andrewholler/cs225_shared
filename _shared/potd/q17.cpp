#include <iostream>
#include <string>
using namespace std;

class Animal{
    public:
        Animal();
        Animal(string newType, string newFood);
        void setType(string newType);
        void setFood(string newFood);
        string getType();
        string getFood();
        virtual void print();
    protected:
        string food_type; 
    private:
        string animal_type;
};

class Pet : public Animal{
    private:
        string name;
        string owner_name;
    public:
        Pet();
        Pet(string newName, string newOwnerName, string type, string food);
        void setName(string newName);
        void setOwnerName(string newName);
        string getName();
        string getOwnerName();
        virtual void print();
};

Animal::Animal(){
    animal_type = "cat";
    food_type = "fish";
}
Animal::Animal(string newType, string newFood){
    animal_type = newType;
    food_type = newFood;
}
void Animal::setType(string newType){animal_type = newType;}
void Animal::setFood(string newFood){food_type = newFood;}
string Animal::getType(){return animal_type;}
string Animal::getFood(){return food_type;}
void Animal::print(){cout << "I am a " << animal_type << "." << endl;}

Pet::Pet() : Animal(){
    name = "Fluffy";
    owner_name = "Cinda";
}
Pet::Pet(string newName, string newOwnerName, string type, string food): Animal(type, food){
    name = newName;
    owner_name = newOwnerName;
}
void Pet::setName(string newName){name = newName;}
void Pet::setOwnerName(string newName){owner_name = newName;}
string Pet::getName(){return name;}
string Pet::getOwnerName(){return owner_name;}
void Pet::print(){cout << "My name is " << name << "." << endl;}

int main(){
    Animal a;
    Pet b;
    b.setName("Garfield");
    a.print();
    b.print();

    return 0;
}
