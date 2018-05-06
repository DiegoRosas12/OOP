#include <iostream>
#include <string>

using namespace std;

class Animal {
    public:
    Animal() { cout << "ANIMAL: constructor" << endl; }
    virtual ~Animal() {cout << "ANIMAL: destructor" << endl; }
    virtual string sound() {
        return "???";
    }
    virtual string name() {
        return "animal";
    }
    void speak() { 
        cout << "El " << name() << " dice \"" << sound() << "\"." << endl;
    }
};

class Dog : public Animal {
    public:
    Dog() {cout << "DOG: constructor" << endl;}
    ~Dog() {cout << "DOG: destructor" << endl;}

    string sound() {
        return "guau";
    }

    string name() {
        return "Perro";
    }
};

class Pug : public Dog {
    public:
    Pug() {cout << "PUG: constructor" << endl;}
    ~Pug() {cout << "PUG: destructor" << endl;}

    string name() {
        return "pug";
    }
    string sound() {
        return "oink";
    }
};

int main() {
    //Animal* obj = new Dog;
    //obj->speak();
    // (*obj).speak();
    Animal** vec = new Animal*[5];
    vec[0] = new Dog;
    vec[1] = new Pug;
    vec[2] = new Animal;

    for (int i=0; i<3; i++) {
        vec[i]->speak();
    }
    for (int i=0; i<3; i++) {
        delete vec[i];
    }
    delete [] vec;
    //delete obj;
    return 0;
}