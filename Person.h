//
// Created by krucisatorul on 06.01.2018.
//

#ifndef UNTITLED_PERSON_H
#define UNTITLED_PERSON_H

#include "Utility.h"

class Person {
private:
    string name;
    int age;
public:
    Person();

    Person(string name, int age);

    Person(const Person &person);

    friend ostream &operator <<(ostream &os, const Person &person);

    friend istream &operator >>(istream &is, Person &person);

    Person &operator =(const Person &person);

    const string &getName() const;

    void setName(const string &name);

    int getAge() const;

    void setAge(int age);
};


#endif //UNTITLED_PERSON_H
