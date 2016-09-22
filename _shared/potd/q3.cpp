#include <string>
using namespace std;

class Pet{
    public:             // access functions should be public so client code can change the private variables in allowed ways
        void setName(string newName);
        void setBirthYear(int newBY);
        void setType(string newType);
        void setOwnerName(string newName);
        string getName();
        int getBirthYear();
        string getType();
        string getOwnerName();
    private:            // class member variables should be private to ensure data is protected and only manipulated in allowed ways
        string name;
        int birth_year;
        string type;
        string owner_name;
};

// the scope resolution operator would be necessary if we had two classes that both had functions called "setName", "getName", etc.
void Pet::setName(string newName){name = newName;}
void Pet::setBirthYear(int newBY){birth_year = newBY;}
void Pet::setType(string newType){type = newType;}
void Pet::setOwnerName(string newName){owner_name = newName;}
string Pet::getName(){return name;}
int Pet::getBirthYear(){return birth_year;}
string Pet::getType(){return type;}
string Pet::getOwnerName(){return owner_name;}

int main(){
    Pet Mia, Trinity, Tiberius;
    Mia.setName("Mia");
    Mia.setBirthYear(2002);
    Mia.setType("cat");
    Mia.setOwnerName("Kelly");
    Trinity.setName("Trinity");
    Trinity.setBirthYear(2006);
    Trinity.setType("cat");
    Trinity.setOwnerName("Kelly");
    Tiberius.setName("Tiberius");
    Tiberius.setBirthYear(2011);
    Tiberius.setType("dog");
    Tiberius.setOwnerName("Kelly");
    return 0;
}
