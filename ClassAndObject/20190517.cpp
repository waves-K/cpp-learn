/* 赋值运算符重载
 */
#include <iostream>
using namespace std;

class Date{
    public:
        // 构造函数
        // 把参数赋值给当前的成员变量
        Date(int year = 1900, int month = 1, int day = 1) {
            _year = year;
            _month = month;
            _day = day;
        }

        // 重载运算符
        // 重载哪个运算符 operator 后边直接跟着要重载的运算符就可以
        // 不需要空格，要重载这个运算符，这个赋值运算符有两个参数
        // 既然已经给成累的成员函数了，那么当前对象就不需要你给了
        // 当前对象是哪一个对象呢，就是赋值运算符的做操作数，就不需要提供了
        // 你只需要把赋值运算符的右操作数提供出来即可。这种情况下要用日期来赋值
        // 此时只需要把这个参数传过来即可，当然传这个参数一般情况下自定义类型的对象
        // 在里边都给的是引用，一般情况下，对于这种赋值，赋值不需要改变参数里边的内容
        // 如果不需要改变，就把 const 加上，如果需要改变就不用加 const
        // 有些场景下可能需要改变，但是大部分情况下都不需要改变
        // 赋值必须要有返回值，为什么要有返回值呢？目的是为了完成连续赋值
        // 将来在里边就是要返回一个对象出去，在这个位置返回对象，对象是自定义类型的
        // 能返回引用尽量返回引用
        // 要返回引用，当前这个函数体里边的必须要有生命周期比这个函数长的
        // 这个函数里边的当前对象和这个d生命周期都比这个函数的生命周期长
        // 既然都比函数的生命周期长，那么按道理来说返回d和返回*this 都是可以的
        // 但是这个位置他在里边只能返回 *this 
        // 为什么只能返回 *this 呢？就是因为连续赋值 a = b = c，是 c 给 b 赋值 b 给 a 赋值
        // 所以只能把赋值运算符的左操作数返回，而左操作数就是当前 this 
        // 在这个函数体中并不是什么情况下都要进行赋值
        // 如果是自己给自己赋值就不需要操作了，因为赋值完了之后还是他自己。
        Date& operator= (Date& d) {
            if (this != &d) {
                _year = d._year;
                _month = d._month;
                _day = d._day;
            }
            return *this;
        }

        // 判断两个日期类是否相等
        bool operator== (const Date& d) {
            return _year == d._year &&
                _month == d._month &&
                _day == d._day;
        }

        bool operator!= (const Date& d) {
            return !(*this == d);
        }

        bool operator< (const Date& d) {
            if (_year < d._year || 
                    (_year == d._year && _month < d._month) || 
                    (_year == d._year && _month == d._month && _day < d._day)) {
                return true;
            }
            return false;
        }

        // 重载 ++
        //    前置 ++   后置 ++
        //    ++ 运算符只有一个操作数
        Date& operator++ () {
            // 考虑如期 ++ 之后的合法性
            _day += 1;
            return *this;
        }

        // 后置++ 先用在加
        Date& operator++ (int) {
            Date temp(*this);
            _day += 1;
            return temp;
        }

        Date& operator-- () {
            _day -= 1;
            return *this;
        }

        Date& operator-- (int) {
            Date temp(*this);
            -- *this;   // day -= 1;
            return temp;
        }

        Date operator+ (int days);

        Date operator- (int days);

        int operator- (const Date& d);

        bool operator> (const Date& d);

        bool operator>= (const Date& d);

        bool operator<= (const Date& d);

        // const Date* const this
        void PrintDate() const {
            this->_day = 1;
            // _year += 1;
            // _month -= 1;
            cout << _year << "-" << _month << "-" << _day << endl;
        }
    private:
        int _year;
        int _month;
        mutable int _day;
};


int main() {
    // 默认的赋值运算符重载
    // Date d1(2019, 5, 17);
    // Date d2(2019, 5, 18);
    // d1 = d2;
    
    Date d1(2019, 5, 17);
    Date d2(2019, 5, 18);

    Date d3(2019, 5, 17);
    d1.PrintDate();

    const Date d4(d3); 
    d4.PrintDate();

    d1 = ++d2; // d1.operator=(d2.operator++());
    d1 = d2++;

    d1 = --d2;
    d1 = d2--;
    return 0;
}
