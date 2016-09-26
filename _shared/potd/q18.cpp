#include <iostream>
#include <string>
using namespace std;

template <class T>
class BankAccount{
    public:
        BankAccount(T init);
        T getBalance();
        void add(T amount);
        void remove(T amount);
    private:
        T balance;
};

template <class T>
BankAccount<T>::BankAccount(T init){
    balance = init;
}
template <class T>
T BankAccount<T>::getBalance(){return balance;}
template <class T>
void BankAccount<T>::add(T amount){balance += amount;}
template <class T>
void BankAccount<T>::remove(T amount){balance += amount;}

int main(){
    BankAccount<double> a(2000.00);
    BankAccount<int> b(2000);
    a.add(.5);
    b.remove(50);
    return 0;
}   
