/* 完成一个日期类 */
#include <iostream>
using namespace std;

class Date{
    public:
        // 构造函数
        Date(int year = 1900, int month = 1, int day = 1)
            : _year(year)
            , _month(month)
            , _day(day) {
            // 对日期进行合法性检测
            // 1. 对参数说明
            // 2. 如果用户所给的参数非法---提示用户日期非法，Set函数进行调整 
            // 3. 如果日期非法---调整
            if (!(year > 0 &&
                month > 0 && month < 13 &&
                day > 0 && day <= _GetDaysOfMonth(year, month))) {
                _year = 1900;
                _month = 1;
                _day = 1;
            }
        }

        // 拷贝构造
        // 系统默认的是：浅拷贝
        Date(const Date& d)
            : _year(d._year)
            , _month(d._month)
            , _day(d._day) {}

        // 赋值运算符的重载
        // 系统默认的是：浅拷贝
        Date& operator = (const Date& d) {
            if (this != &d) {
                _year = d._year;
                _month = d._month;
                _day = d._day;
            }
            return *this;
        }

        void SetYear(int year) {
            _year = year;
        }

        void SetMonth(int month) {
            _month = month;
        }

        void SetDay(int day) {
            _day = day;
        }

        bool IsLeapYear()const {
            return _IsLeapYear(_year);
        }

        Date operator+(int days) {
            if (days < 0) {
                return *this - (0 - days);
            }
            Date temp(*this);
            temp._day += days;

            int daysOofMonth = 0;
            while (temp._day > (daysOofMonth = _GetDaysOfMonth(temp._year, temp._month))) {
                temp._day -= daysOofMonth;
                temp._month += 1;

                if (temp._month > 12) {
                    temp._year += 1;
                    temp._month = 1;
                }
            }
            return temp;
        }

        Date operator-(int days) {
            if (days < 0) {
                return *this + (0 - days);
            }

            Date temp(*this);
            temp._day -= days;

            if (temp._day <= 0) {
                temp._month -= 1;
                if ( 0 == temp._month) {
                    temp._year -= 1;
                    temp._month = 12;
                }

                temp._day += _GetDaysOfMonth(temp._year, temp._month);
            }
            return temp;
        }

        Date& operator++() {
            *this = *this + 1;
            return *this;
        }

        Date operator++(int) {
            Date temp(*this);
            *this = *this + 1;
            return temp;
        }

        Date& operator--() {
            *this = *this - 1;
            return *this;
        }

        Date operator--(int) {
            Date temp(*this);
            *this = *this - 1;
            return temp;
        }

        int operator-(const Date& d) {
            Date minDate(*this);
            Date maxDate(d);

            if (maxDate < minDate) {
                swap(minDate, maxDate);
            }

            int count = 0;
            while (minDate != maxDate) {
                count += 1;
                ++minDate;
            }
            return count;
        }

        bool operator==(const Date& d)const {
            return _year == d._year &&
                   _month == d._month &&
                   _day == d._day;
        }

        bool operator!=(const Date& d)const {
            return !(*this == d);
        }

        bool operator<(const Date& d)const {
            if ((_year < d._year) ||
                (_year == d._year && _month < d._month) ||
                (_year == d._year && _month == d._month && _day < d._day)) {
                return true;
            }
            return false;
        }

    private:
        bool _IsLeapYear(int year)const {
            if ((0 == year % 4 && 0 != year % 100) ||
                (0 == year % 400)) {
                    return true;
                }
            return false;
        }

        int _GetDaysOfMonth(int year, int month) {
            int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            if (2 == month && _IsLeapYear(year)) {
                days[2] += 1;
            }

            return days[month];
        }
        // 输出运算符的重载
        friend ostream& operator << (ostream& _cout, const Date& d) {
            _cout << d._year << "-" << d._month << "-" << d._day;
            return _cout;
        }

        friend istream& operator >> (istream& _cin, Date& d) {
            _cin >> d._year >> d._month >> d._day;
            return _cin;
        }
    private:
        int _year;
        int _month;
        int _day;
};

int main() {
    Date d1(2019, 06, 05);
    Date d2(2018, 06, 100);
    cout << d1 << endl;
    cout << d2 << endl;
    cout << d1 + 999 << endl;
    cout << d1 - 999 << endl;
    cout << d1 - d2 << endl;
    return 0;
}
