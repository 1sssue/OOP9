#include <iostream>
#include <Windows.h>
using namespace std;

class Base {
public:
    virtual void OOPmain() { cout << "�� ���� Base" << endl; }
    virtual ~Base() {}
};

class DerA : public virtual Base {
public:
    void OOPmain() override { cout << "�� ���� DerA" << endl; }
};

class DerB : public virtual Base {
public:
    void OOPmain() override { cout << "�� ���� DerB" << endl; }
};

class DerAB : public DerA, public DerB {
public:
    void OOPmain() override { cout << "�� ���� DerAB" << endl; }
};

void mymain(Base* obj) {
    obj->OOPmain();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    DerA objA;
    DerB objB;
    DerAB objAB;
    
    objA.OOPmain();
    objB.OOPmain();
    objAB.OOPmain();
    cout << endl;
    Base* arr[4];

    arr[0] = new Base();
    arr[1] = new DerA();
    arr[2] = new DerB();
    arr[3] = new DerAB();

    for (int i = 0; i < 4; ++i) {
        mymain(arr[i]);
    }

    // ��������� ���'��
    for (int i = 0; i < 4; ++i) {
        delete arr[i];
    }

    return 0;
}
