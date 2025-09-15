#include <iostream>
#include <string>
using namespace std;

class Sensor {
public:
    int id, priority;
    float value;
    string status;

    Sensor(int i, float v, int p) {
        id = i; value = v; priority = p;
        status = "OK";
    }

    void updateValue(float v) {
        value = v;
        status = (v > 80 ? "ALERT" : "OK");
    }
};

class Diagnostics {
public:
    string check(Sensor& s) {
        return "Sensor " + to_string(s.id) + " Value=" + to_string(s.value) + " Status=" + s.status;
    }
};

void rebind(Sensor*& ref, Sensor* arr[], int n) {
    Sensor* best = arr[0];
    for(int i=1;i<n;i++)
        if(arr[i]->priority > best->priority) best = arr[i];
    ref = best;
    cout << "Critical now: Sensor " << ref->id << "\n";
}

void printMap(Sensor* arr[], int n) {
    cout << "---- Grid ----\n";
    for(int i=0;i<n;i++)
        cout << "ID="<<arr[i]->id<<" Val="<<arr[i]->value<<" Pri="<<arr[i]->priority<<" Status="<<arr[i]->status<<"\n";
}

class Controller {
public:
    Sensor* arr[10];
    Sensor* critical;

    Controller(Sensor* a[], int n) {
        for(int i=0;i<n;i++) arr[i]=a[i];
        critical = arr[0];
        rebind(critical, arr, n);
    }

    void updateCritical() {
        critical->updateValue(critical->value + 15);
    }

    void show() {
        cout << "Controller bound to Sensor " << critical->id << " (" << critical->status << ")\n";
    }
};

int main() {
    Sensor* s1 = new Sensor(1, 75, 3);
    Sensor* s2 = new Sensor(2, 60, 5);
    Sensor* s3 = new Sensor(3, 90, 2);
    Sensor* arr[3] = {s1, s2, s3};

    Controller ctrl(arr, 3);
    Diagnostics d;

    cout << d.check(*ctrl.critical) << "\n";
    printMap(arr, 3);

    ctrl.updateCritical();
    ctrl.show();

    rebind(ctrl.critical, arr, 3);
    ctrl.show();

    for(int i=0;i<3;i++) delete arr[i];
}
