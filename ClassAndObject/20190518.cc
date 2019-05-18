/* 类和对象下
 */ 

#if 0
#include <iostream>
using namespace std;

class Date {
    public:
        Date(int year = 1900, int month = 1, int day = 1)
            : _year(year)
            , _month(month)
            , _day(day) {}
    private:
        int _year;
        int _month;
        int _day;
};

int main() {
    return 0;
}
#endif


#if 0
// 想要知道当前类定义了多少个对象？ 需要计数 --- int 
class Test {
    public:
        Test()
            : _count(0) {
                _count++;
            }
        Test (Test& t)
            : _count(++t._count) {}

        ~Test () {
            --_count;
        }

    private:
        int _t;
        int _count;
};

void TestFunc() {
    Test t1, t2, t3;
}

int main () {
    Test t1;
    TestFunc();
    return 0;
}
#endif

#if 0
// 全局变量 -- 可以用来统计对象的个数，但是不安全

#include <iostream>
using namespace std;

int g_count = 0;

class Test {
    public:
        Test() {
            ++g_count;
            }
        Test (Test& t) {
            ++g_count;
        }

        ~Test () {
            --g_count;
        }

    private:
        int _t;
};

void TestFunc() {
    Test t1, t2, t3;
    cout << g_count << endl;

    Test t4(t3);
    cout << g_count << endl;
}

int main () {
    Test t1;
    g_count = 0;

    TestFunc();
    cout << g_count << endl;
    return 0;
}
#endif

#if 0
// static 修饰的类成员：静态的成员
// static 修饰成员变量，静态的成员变量
// static 修饰成员函数，静态的成员函数

#include <iostream>
using namespace std;

// 静态成员函数中：只能直接访问静态的成员变量
//                 不能直接访问非静态的成员变量
//    在静态成员函数中不能打印 this：
//    静态成员函数中没有 this 指针，没有影藏的参数，此时就说明静态成员函数不需要通过对象来调
//    静态成员函数不能使用 const 来修饰
//    在静态的成员函数中调用非静态的成员函数
class Test {
    public:
        Test() {
            ++_count;
            }
        Test (Test& t) {
            ++_count;
        }

        ~Test () {
            --_count;
        }

        int GetCount() {
            return _count;
        }

    private:
        int _t;
        static int _count;
};

int Test::_count = 0;

void TestFunc() {
    Test t1, t2, t3;
    // cout << _count << endl;

    Test t4(t3);
    // cout << _count << endl;
}

// 静态成员变量：是类的属性不属于某个具体的对象，因此不影响 sizeof 的结果
//    访问形式： 类名:: =静态成员变量
//               对象.静态成员变量
//    所有对象共享
//    必须在类外进行初始化
//    静态的成员变量在程序运行前
int main () {
    int a = 10;
    a = Test::_count;
    cout << Test::_count << endl;

    Test t1;
    a = t1._count;  // Test::_count
    cout << t1._count << endl;

    Test t2;
    cout << t2._count << endl;

    cout << &t1._count << "=" << &t2._count << endl;

    Test::_count;
    cout << sizeof(Test) << endl;
    return 0;
}
#endif
