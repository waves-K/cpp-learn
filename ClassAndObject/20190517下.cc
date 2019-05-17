/* 类和对象下
 */
#include <iostream>
using namespace std;

class Time {
    public:
        // 初始化列表中没有明确规定成员初始化出现的先后次序
        // 初始化列表有其自己的初始化次序
        // 初始化列表的初始化次序与成员在类中的声明次序保持一致
        // 与成员变量在初始化列表中出现的先后次序无关
        // 建议：
        //    1. 初始化列表中成员变量的先后次序最好和其再类中的声明次序保持一致
        //    2. 尽量避免使用成原来初始化成员
        Time(int hour, int minute, int second) {
            _hour = hour;
            _minute = minute;
            _second = second;
        }
    private:
        int _hour;
        int _minute;
        int _second;
};

// 特殊：初始化列表
class Date {
    public:
        Date(int year = 1900, int month = 1, int day = 1)
            : _year(year)
            , _month(month)
            , _day(day) {
            // _year = year;
            // _month = month;
            // _day = day;
            // _day = day;
        }

         Date (const Date& d)
         : _year(d._year)
         , _month(d._month)
         , _day(d._day){

         }
        Date& operator=(const Date& d) {
            if (this != &d) {
                _year = d._year;
                _month = d._month;
                _day = d._day;
            }
            return *this;
        }
        void PrintDate() {
            cout << _year << "-" << _month << "-" << _day << endl;
        }
    private:
        int _year;
        int _month;
        int _day;
        // Time _t;
};
int main() {
    Date d(2019, 5, 17);
    return 0;
}
