#include <QCoreApplication>
#include <QDebug>
#include <thread>
#include <mutex>
#include <vector>
#include <cstdlib>
#include <ctime>

std::mutex listMutex;

struct Node {
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    void insert(int value) {
        std::lock_guard<std::mutex> guard(listMutex);
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        qDebug() << "Insertando:" << value;
    }

    void remove(int value) {
        std::lock_guard<std::mutex> guard(listMutex);
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->value == value) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }
                delete current;
                qDebug() << "Eliminando:" << value;
                return;
            }
            prev = current;
            current = current->next;
        }
        qDebug() << "No se eliminó:" << value;
    }

    bool search(int value) {
        std::lock_guard<std::mutex> guard(listMutex);
        Node* current = head;
        while (current != nullptr) {
            if (current->value == value) {
                qDebug() << "Buscado:" << value;
                return true;
            }
            current = current->next;
        }
        qDebug() << "No encontrado:" << value;
        return false;
    }

    void modify(int oldValue, int newValue) {
        std::lock_guard<std::mutex> guard(listMutex);
        Node* current = head;
        while (current != nullptr) {
            if (current->value == oldValue) {
                qDebug() << "Modificando" << oldValue << "a" << newValue;
                current->value = newValue;
                return;
            }
            current = current->next;
        }
        qDebug() << "No se encontró:" << oldValue;
    }

private:
    Node* head;
};

void threadRemove(LinkedList& list) {
    for (int i = 0; i < 10; ++i) {
        int value = rand() % 100;
        list.remove(value);
    }
}

void threadInsert(LinkedList& list) {
    for (int i = 0; i < 10; ++i) {
        int value = rand() % 100;
        list.insert(value);
    }
}

void threadSearch(LinkedList& list) {
    for (int i = 0; i < 10; ++i) {
        int value = rand() % 100;
        list.search(value);
    }
}

void threadModify(LinkedList& list) {
    for (int i = 0; i < 10; ++i) {
        int oldValue = rand() % 100;
        int newValue = oldValue + (rand() % 10 + 1);
        list.modify(oldValue, newValue);
    }
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    srand(static_cast<unsigned int>(time(0)));
    LinkedList list;

    std::thread t1(threadRemove, std::ref(list));
    std::thread t2(threadInsert, std::ref(list));
    std::thread t3(threadSearch, std::ref(list));
    std::thread t4(threadModify, std::ref(list));

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return a.exec();
}
