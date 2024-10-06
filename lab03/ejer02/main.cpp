#include <iostream>
#include <memory>
#include "time.h"

using namespace std;

int main() {
    unique_ptr<Time> t1 = make_unique<Time>(10, 50, 59);
    t1->print(); // 10:50:59

    unique_ptr<Time> t2 = make_unique<Time>();
    t2->print(); // 00:00:00

    t2->setTime(6, 39, 9);
    t2->print(); // 06:39:09

    if (t1->equals(*t2)) {
        cout << "Dos objetos son IGUALES\n";
    } else {
        cout << "Dos objetos NO son IGUALES\n";
    }

    return 0;
}
