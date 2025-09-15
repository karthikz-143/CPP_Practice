#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

class Sensor {
protected:
    int id;
    float value, threshold;
    string status;
public:
    Sensor(int i, float v, float t) : id(i), value(v), threshold(t), status("OK") {}
    virtual ~Sensor() {}
    virtual void triggerFault() = 0;
    bool isFaulty() { return value > threshold; }
    int getId() { return id; }
    string getStatus() { return status; }
    void setThreshold(float t) { threshold = t; }
};

class TemperatureSensor : public Sensor {
public:
    using Sensor::Sensor;
    void triggerFault() override {
        value += 15;
        if (isFaulty()) status = "Overheat";
    }
};

class PressureSensor : public Sensor {
public:
    using Sensor::Sensor;
    void triggerFault() override {
        value += 10;
        if (isFaulty()) status = "HighPressure";
    }
};

class Actuator {
    int id, delay;
    string state;
public:
    Actuator(int i) : id(i), delay(1), state("Idle") {}
    void delayAct() {
        delay += rand() % 3;
        state = "Delayed";
    }
    void show() {
        cout << "Actuator[" << id << "] = " << state << " delay=" << delay << "\n";
    }
};

class ConfigManager {
public:
    void adjust(Sensor& s, float t) { s.setThreshold(t); }
};

class FaultLogger {
    ofstream log;
public:
    FaultLogger(string file) { log.open(file); }
    void record(Sensor& s) {
        log << "Sensor " << s.getId() << " -> " << s.getStatus() << "\n";
    }
};

class FaultInjector {
public:
    vector<Sensor*> sensors;
    vector<Actuator*> acts;

    void inject() {
        for (auto* s : sensors) s->triggerFault();
        for (auto* a : acts) a->delayAct();
    }

    void report() {
        for (auto* s : sensors)
            cout << "Sensor[" << s->getId() << "] = " << s->getStatus() << "\n";
        for (auto* a : acts) a->show();
    }
};

void check(Sensor* s, FaultLogger& log) {
    if (s->isFaulty()) log.record(*s);
}

void analyze(FaultInjector* fi) {
    cout << "System analysis: " << fi->sensors.size() << " sensors checked.\n";
}

class SimulationEngine {
    ConfigManager& cfg;
    FaultLogger& log;
    FaultInjector inj;
public:
    SimulationEngine(ConfigManager& c, FaultLogger& l) : cfg(c), log(l) {
        inj.sensors = { new TemperatureSensor(1, 95, 90),
                        new PressureSensor(2, 55, 50) };
        inj.acts = { new Actuator(1), new Actuator(2) };
    }

    ~SimulationEngine() {
        for (auto* s : inj.sensors) delete s;
        for (auto* a : inj.acts) delete a;
    }

    void run() {
        inj.inject();
        inj.report();
        for (auto* s : inj.sensors) check(s, log);
        analyze(&inj);
    }
};

int main() {
    ConfigManager cfg;
    FaultLogger log("events.txt");
    SimulationEngine engine(cfg, log);
    engine.run();
}
