#include<iostream>
using namespace std;


class Burger{
    public:
    virtual void prep()=0;  
    virtual ~Burger(){
        cout<<"destructor is called"<<endl;
    };
};

class BasicBurger : public Burger{
    public :

    void prep(){
        cout<<"your basic burger is in preparation"<<endl;
    }
};

class StandardBurger : public Burger{
    public :

    void prep(){
        cout<<"your standard burger is in preparation"<<endl;
    }
};

class Factory{
    public :

    Burger* createBurger(string type){

        if(type=="basic"){
            return new BasicBurger();
        }
        else {
            return new StandardBurger();
        }
    }
};

int main() {
    
    string type ="standard";

    Factory* product = new Factory();
    Burger* burger = product->createBurger(type);

    burger->prep();
    delete burger;

    return 0;
    
}