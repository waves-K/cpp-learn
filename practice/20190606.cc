#if 0
#include <iostream>
using namespace std;
int main() {
    double a = 5.2;
    int &b = a;         // 错误，引用的类型必须和其所绑定的变量的类型相同
    double &c = a;      // 正确
    cout << b << endl;
    return 0;
}
#include <iostream>
using namespace std;
int main() {
    int &a;             // 错误，声明引用的同时必须进行初始化
    return 0;
}
#include <iostream>
using namespace std;
int main() {
    int value = 5;
    int &new_value = value;
    cout << "value 在内存中的地址为: " << &value << endl;
    cout << "new_value 在内存中的地址为: " << &new_value << endl;
    return 0;
}
#include <iostream>
using namespace std;
int main() {
    int a[5] = {0, 1, 2, 3, 4};
    int (&b)[5] = a;          // 对数组的引用
    cout << &a[0] << " " << &b[0] << endl;
    cout << &a[1] << " " << &b[1] << endl;
    cout << &a[2] << " " << &b[2] << endl;
    cout << &a[3] << " " << &b[3] << endl;
    cout << &a[4] << " " << &b[4] << endl;
    return 0;
}
#include <iostream>
using namespace std;
int main() {
    int a = 5;
    int *ptr = &a;
    int *&new_ptr = ptr;
    cout << &ptr << endl;
    cout << &new_ptr << endl;
    return 0;
}
#endif
#include <iostream>
using namespace std;
int main() {
    int a = 5;
    const int &new_a = a;
    new_a = 6;      // 错误，不允许通过常引用对其绑定的变量或对象进行修改
    return 0;
}

