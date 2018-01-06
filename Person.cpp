//
// Created by krucisatorul on 06.01.2018.
//

#include "Person.h"
#include "Utility.h"

ostream &operator<<(std::ostream &os, const Person &person) {
    os << "name: " << person.name << " age: " << person.age;
    return os;
}

Person::Person() {
    age = 0;
    name = "0";
}

Person::Person(string name, int age): name(name), age(age){}

Person::Person(const Person &person) {
    name = person.name;
    age = person.age;
}

istream &operator >>(istream &is, Person &person) {
    cout << "Person name: ";
    is >> person.name;
    cout << "Person age: ";
    is >> person.age;
    return is;
}

Person &Person::operator =(const Person &person) {
    name = person.name;
    age = person.age;
    return (*this);
}

const string &Person::getName() const {
    return name;
}

void Person::setName(const string &name) {
    Person::name = name;
}

int Person::getAge() const {
    return age;
}

void Person::setAge(int age) {
    Person::age = age;
}
