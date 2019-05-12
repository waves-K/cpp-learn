#include <string.h>
#include <iostream>
using namespace std;

struct Student{
    void SetStudentInfo(char *name, char *gender, int age){
        strcpy(_name, name);
        strcpy(_gender, gender);
        _age = age;

    }
    void PrintStudentInfo(){
        cout << _name << " " << _gender << " " << _age << endl;

    }
    char _name[20];
    char _gender[3];
    int _age;

};
int main() {
    Student s1, s2, s3;
    s1.SetStudentInfo("Peter", "男", 18);
    s2.SetStudentInfo("jing jing", "女", 17);
    s3.SetStudentInfo("summer", "男", 2);

    s1.PrintStudentInfo();
    s2.PrintStudentInfo();
    s3.PrintStudentInfo();
    return 0;
}
