#include <iostream>
#include <string>
using namespace std;

//my base class
class Sensor {
protected:
    string userName;
    string sensorModel;
    int sensorLife;
    int daysUsed;
    int bloodSugar;

public:
    Sensor(const string& name, const string& model, int life, int used, int sugar)
        : userName(name), sensorModel(model), sensorLife(life), daysUsed(used), bloodSugar(sugar) {}

    virtual void checkBloodSugarLevel() const = 0;

    virtual void displayRemainingUsage() const {
        int remainingDays = sensorLife - daysUsed;
        if (remainingDays > 0)
            cout << "Remaining usage days: " << remainingDays << " days" << endl;
        else
            cout << "Sensor usage has expired!" << endl;
    }

    virtual ~Sensor() {
        cout << "Sensor destructed for " << userName << endl;
    }
};


class Dexcom : public Sensor {
public:
    Dexcom(const string& name, const string& model, int life, int used, int sugar)
        : Sensor(name, model, life, used, sugar) {}

    void checkBloodSugarLevel() const override {
        cout << userName << "'s Blood Sugar Check:\n";
        cout << "Sensor Model: " << sensorModel << endl;
        cout << "Testing with blood sugar: " << bloodSugar << endl;

        if (bloodSugar < 60)
            cout << "Critical low blood sugar!" << endl;
        else if (bloodSugar <= 110)
            cout << "Normal blood sugar." << endl;
        else
            cout << "High blood sugar!" << endl;
    }

    void displayRemainingUsage() const override {
        int remainingDays = sensorLife - daysUsed + 10;
        if (remainingDays > 0)
            cout << "Remaining usage days: " << remainingDays << " days" << endl;
        else
            cout << "Sensor usage has expired!" << endl;
    }
};

// Derived class
class Abbott : public Sensor {
public:
    Abbott(const string& name, const string& model, int life, int used, int sugar)
        : Sensor(name, model, life, used, sugar) {}

    void checkBloodSugarLevel() const override {
        cout << userName << "'s Blood Sugar Check:\n";
        cout << "Sensor Model: " << sensorModel << endl;
        cout << "Testing with blood sugar: " << bloodSugar << endl;

        if (bloodSugar < 80)
            cout << "Critical low blood sugar!" << endl;
        else if (bloodSugar <= 130)
            cout << "Normal blood sugar." << endl;
        else
            cout << "High blood sugar!" << endl;
    }

    void displayRemainingUsage() const override {
        int remainingDays = sensorLife - daysUsed + 7;
        if (remainingDays > 0)
            cout << "Remaining usage days: " << remainingDays << " days" << endl;
        else
            cout << "Sensor usage has expired!" << endl;
    }
};

// Derived class Medtrum
class Medtrum : public Sensor {
public:
    Medtrum(const string& name, const string& model, int life, int used, int sugar)
        : Sensor(name, model, life, used, sugar) {}

    void checkBloodSugarLevel() const override {
        cout << userName << "'s Blood Sugar Check:\n";
        cout << "Sensor Model: " << sensorModel << endl;
        cout << "Testing with blood sugar: " << bloodSugar << endl;

        if (bloodSugar < 75)
            cout << "Critical low blood sugar!" << endl;
        else if (bloodSugar <= 120)
            cout << "Normal blood sugar." << endl;
        else
            cout << "High blood sugar!" << endl;
    }

    void displayRemainingUsage() const override {
        int remainingDays = sensorLife - daysUsed + 5;
        if (remainingDays > 0)
            cout << "Remaining usage days: " << remainingDays << " days" << endl;
        else
            cout << "Sensor usage has expired!" << endl;
    }
};

int main() {
    Sensor* sensors[3];

    sensors[0] = new Dexcom("Naz", "G7", 10, 5, 75);
    sensors[1] = new Abbott("Gizem", "Libre 2", 14, 7, 75);
    sensors[2] = new Medtrum("Yaren", "S7-960", 15, 10, 110);

    for (int i = 0; i < 3; ++i) {
        sensors[i]->checkBloodSugarLevel();
        sensors[i]->displayRemainingUsage();
        cout << endl;
    }

    for (int i = 0; i < 3; ++i) {
        delete sensors[i];
    }

    return 0;
}

