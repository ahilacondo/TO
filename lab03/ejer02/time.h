#ifndef TIME_H
#define TIME_H
#include <memory>
using namespace std;

class Time {
private:
    unique_ptr<int> hour;
    unique_ptr<int> minute;
    unique_ptr<int> second;

public:
    // Constructor con valores por defecto
    Time(const int h = 0, const int m = 0, const int s = 0);

    // Setter
    void setTime(const int h, const int m, const int s);

    // Imprime la descripción del objeto en formato hh:mm:ss
    void print() const; // readonly

    // Compara 2 objetos Time
    bool equals(const Time&);
};

#endif // TIME_H
