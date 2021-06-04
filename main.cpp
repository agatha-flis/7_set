#include "set.h"

int main()
{
    Set<int> a;
    a.insert(3);
    a.insert(4);
    a.insert(5);
    a.insert(6);
    a.insert(3);
    std::cout << a.isFull() << std::endl;
    std::cout << a.size() << std::endl;
    a.show();
    //a.clear();
    std::cout << a.isFull() << std::endl;

    Set<char> b;
    b.insert('a');
    b.insert('b');
    b.insert('a');
    b.insert('r');
    b.insert('r');
    std::cout << b.isFull() << std::endl;
    std::cout << b.size() << std::endl;
    b.show();
    b.clear();
    std::cout << b.isFull() << std::endl;

    Set<int> c(a);
    c.show();

    return 0;
}