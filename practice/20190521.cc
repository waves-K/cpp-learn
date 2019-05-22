#if 0
#include <iostream>
using namespace std;

void test(int a = 1) {
    cout << a << endl;
}

int main() {
    test();
    test(5);
    return 0;
}
#endif

#include <iostream>
using namespace std;

#if 0
void test(int a = 1, int b = 2, int c = 3) {
    cout << a << " " << b << " " << c << endl;
}

int main() {
    test();
    test(10);
    test(10, 20);
    test(10, 20, 30);
    return 0;
}
#endif

void test(int a, int b = 3, int c = 4) {
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
}

int main() {
    test(10);
    return 0;
}
