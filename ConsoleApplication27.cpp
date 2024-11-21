#include <iostream>
using namespace std;

class Engine {
private:
    float power;
    string type;

public:
    Engine() : power(0), type("Unknown") {}
    Engine(float p, string t) : power(p), type(t) {}

    void ShowInfo() const {
        cout << "Engine power: " << power << " horsepower: " << type << endl;
    }
};

class Driver {
private:
    string name;
    int age;

public:
    Driver() : name("Unknown"), age(0) {}
    Driver(string n, int a) : name(n), age(a) {}

    void ShowInfo() const {
        cout << "Driver: " << name << " Age: " << age << endl;
    }
};

class Car {
private:
    string brand;
    string model;
    int year;
    Engine engine;
    Driver* driver;

public:
    Car() : brand("Unknown"), model("Unknown"), year(0), engine(), driver(nullptr) {}
    Car(string b, string m, int y, float power, string type)
        : brand(b), model(m), year(y), engine(power, type), driver(nullptr) {}

    void ShowInfo() const {
        cout << "Car brand: " << brand << ", Model: " << model << ", Year: " << year << endl;
        engine.ShowInfo();
        if (driver) {
            driver->ShowInfo();
        }
        else {
            cout << "No driver assigned." << endl;
        }
    }

    void AssignDriver(Driver* d) {
        driver = d;
    }
};

int main() {
    Car car1("Toyota", "Camry", 2021, 150, "Gasoline");
    Car car2("Ford", "F-150", 2020, 200, "Diesel");
    Car car3("Tesla", "Model S", 2023, 300, "Electric");

    Driver driver1("Alice", 30);
    Driver driver2("Bob", 45);

    car1.AssignDriver(&driver1);
    car2.AssignDriver(&driver2);

    cout << "Car 1 Information:" << endl;
    car1.ShowInfo();
    cout << endl;

    cout << "Car 2 Information:" << endl;
    car2.ShowInfo();
    cout << endl;

    cout << "Car 3 Information:" << endl;
    car3.ShowInfo();
    cout << endl;
}
