#include "Person.h"
#include <string.h>
#include <iostream>
using namespace std;

void Person::SetPersonInfo(char *name, char *gender, int age) {
    strcpy(_name, name);
    strcpy(_gender, gender);
    _age = age;
}

void Person::PrintPersonInfo() {
    cout << _name << " " << _gender << " " << _age << endl;
}
