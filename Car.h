#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

enum Engine {
    petrol,
    diesel,
    electric,
    unknown_engine
};
enum WheelDrive {
    fwd,
    rwd,
    awd,
    unknown_wd
};
enum Material {
    aluminum,
    steel,
    carbon_fiber,
    unknown_material
};

class CustomerData {
private:
    string name;
    string surname;
    string phone_number;

public:
    CustomerData(const string& n, const string& s, const string& phone)
        : name(n), surname(s), phone_number(phone) {}

    string GetName() const { return name; }
    string GetSurname() const { return surname; }
    string GetPhoneNumber() const { return phone_number; }
};
class CarData {
private:
    string car_brand;
    string year_of_release;
    string state_number;

public:
    CarData(const string& brand, const string& year, const string& state)
        : car_brand(brand), year_of_release(year), state_number(state) {}

    string GetCarBrand() const { return car_brand; }
    string GetYearOfRelease() const { return year_of_release; }
    string GetStateNumber() const { return state_number; }
};
class CarBody {
private:
    string color;
    Material material;

public:
    CarBody(const string& clr, Material mat)
        : color(clr), material(mat) {}

    string GetColor() const { return color; }
    Material GetMaterial() const { return material; }
};
class Car {
private:
    CustomerData cust_data;
    CarData car_data;
    Engine engine;
    WheelDrive wd;
    CarBody car_body;

public:
    Car(const CustomerData& customer, const CarData& car, Engine eng, WheelDrive drive, const CarBody& body)
        : cust_data(customer), car_data(car), engine(eng), wd(drive), car_body(body) {}

    string GetEngineType() const {
        switch (engine) {
        case petrol:
            return "����������";
        case diesel:
            return "���������";
        case electric:
            return "�������������";
        default:
            return "����������";
        }
    }

    string GetWheelDriveType() const {
        switch (wd) {
        case fwd:
            return "��������";
        case rwd:
            return "������";
        case awd:
            return "������";
        default:
            return "����������";
        }
    }

    string GetYearOfRelease() const {
        return car_data.GetYearOfRelease();
    }

    string GetStateNumber() const {
        return car_data.GetStateNumber();
    }

    string GetMaterialType() const {
        switch (car_body.GetMaterial()) {
        case aluminum:
            return "��������";
        case steel:
            return "�����";
        case carbon_fiber:
            return "�����������";
        default:
            return "����������";
        }
    }

    void DisplayCarInfo() const {
        cout << "���: " << cust_data.GetName() << "\n";
        cout << "�������: " << cust_data.GetSurname() << "\n";
        cout << "���������� �����: " << cust_data.GetPhoneNumber() << "\n";
        cout << "����� ����������: " << car_data.GetCarBrand() << "\n";
        cout << "��� ������� ����������: " << car_data.GetYearOfRelease() << "\n";
        cout << "�������� ����������: " << car_data.GetStateNumber() << "\n";
        cout << "��� ���������: " << GetEngineType() << "\n";
        cout << "��� �������: " << GetWheelDriveType() << "\n";
        cout << "���� ������: " << car_body.GetColor() << "\n";
        cout << "�������� ������: " << GetMaterialType() << "\n";
    }
};
class CarDatabase {
private:
    static int totalCars;
    int num_cars;
    vector<Car> cars;

public:
    CarDatabase() {
        num_cars = 0;
        totalCars++;
    }

    static int GetTotalCars() {
        return totalCars;
    }

    int GetNumCars() const {
        return num_cars;
    }

    void Input() {
        cout << "�������� ������ �� ����������.\n\n";

        string name, surname, phone_number;
        cout << "������� ���: ";
        cin >> name;
        cout << "������� �������: ";
        cin >> surname;
        cout << "������� ���������� �����: ";
        cin >> phone_number;
        CustomerData customer(name, surname, phone_number);

        string car_brand, year_of_release, state_number;
        cout << "������� ����� ����������: ";
        cin >> car_brand;
        cout << "������� ��� ������� ����������: ";
        cin >> year_of_release;
        cout << "������� �������� ����������: ";
        cin >> state_number;
        CarData car(car_brand, year_of_release, state_number);

        int option;
        cout << "�������� ��� ��������� (1. ����������; 2. ���������; 3. �������������): ";
        Engine eng = unknown_engine;
        if (cin >> option) {
            switch (option) {
            case 1:
                eng = petrol;
                break;
            case 2:
                eng = diesel;
                break;
            case 3:
                eng = electric;
                break;
            default:
                break;
            }
        }

        cout << "�������� ��� ������� (1. ��������; 2. ������; 3. ������): ";
        WheelDrive drive = unknown_wd;
        if (cin >> option) {
            switch (option) {
            case 1:
                drive = fwd;
                break;
            case 2:
                drive = rwd;
                break;
            case 3:
                drive = awd;
                break;
            default:
                break;
            }
        }

        string color;
        cout << "������� ���� ������: ";
        cin >> color;

        cout << "�������� �������� ������ (1. ��������; 2. �����; 3. �����������): ";
        Material mat = unknown_material;
        if (cin >> option) {
            switch (option) {
            case 1:
                mat = aluminum;
                break;
            case 2:
                mat = steel;
                break;
            case 3:
                mat = carbon_fiber;
                break;
            default:
                break;
            }
        }

        CarBody body(color, mat);
        Car car_obj(customer, car, eng, drive, body);

        cars.push_back(car_obj);
        num_cars++;
        system("cls");
    }

    void Output() {
        if (num_cars > 0) {
            cout << "����� ���� �������.\n\n";
            for (int counter = 0; counter < num_cars; counter++) {
                cout << "����� �" << counter + 1 << "\n";
                cars[counter].DisplayCarInfo();
                cout << "-----------------------------------\n\n";
            }
        }
        else {
            cout << "������ �� �������!\n\n";
        }
    }

    void SortByYear() {
        std::sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return std::stoi(a.GetYearOfRelease()) < std::stoi(b.GetYearOfRelease());
            });
    }

    Car FindByStateNumber(const std::string& stateNumber) const {
        auto it = std::find_if(cars.begin(), cars.end(), [&](const Car& car) {
            return car.GetStateNumber() == stateNumber;
            });

        if (it != cars.end()) {
            return *it;
        }
        else {
            system("cls");
            throw std::runtime_error("���������� � ��������� ���������� �� ������.\n");
        }
    }
};

int CarDatabase::totalCars = 0;

void DisplayCarDatabaseInfo(const CarDatabase& database) {
    cout << "����� ���������� ������� � ���� ������: " << database.GetNumCars() << "\n";
}

