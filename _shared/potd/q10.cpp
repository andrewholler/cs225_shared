#include <iostream>
#include <string>
using namespace std;

class Food{
    public:
        Food();
        void setName(string newName);
        void setQuantity(int newQuantity);
        string getName();
        int getQuantity();
    private:
        string name;
        int quantity;
};

Food::Food(){name = "food"; quantity = 0;}
void Food::setName(string newName){name = newName;}
void Food::setQuantity(int newQuantity){quantity = newQuantity;}
string Food::getName(){return name;}
int Food::getQuantity(){return quantity;}

void increaseQuantity(Food * food){
    (*food).setQuantity((*food).getQuantity() + 1);
}

int main(){
    Food apples;
    apples.setName("apples");
    apples.setQuantity(5);
    cout << "You have " << apples.getQuantity() << " apples." << endl;
    increaseQuantity(&apples);
    cout << "You have " << apples.getQuantity() << " apples." << endl;
    return 0;
}
