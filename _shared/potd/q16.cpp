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

Animal::Animal(){animal_type = "cat"; food_type = "fish";}
Animal::Animal(string newType, string newFood){animal_type = newType; food_type = newFood;}
void Animal::setType(string newType){animal_type = newType;}
void Animal::setFood(string newFood){food_type = newFood;}
string Animal::getType(){return animal_type;}
string Animal::getFood(){return food_type;}
void Animal::print(){cout << "I am a " << animal_type << "." << endl;}
