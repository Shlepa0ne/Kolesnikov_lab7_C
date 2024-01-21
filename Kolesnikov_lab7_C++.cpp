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
            return "Бензиновый";
        case diesel:
            return "Дизельный";
        case electric:
            return "Электрический";
        default:
            return "Неизвестен";
        }
    }

    string GetWheelDriveType() const {
        switch (wd) {
        case fwd:
            return "Передний";
        case rwd:
            return "Задний";
        case awd:
            return "Полный";
        default:
            return "Неизвестен";
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
            return "Алюминий";
        case steel:
            return "Сталь";
        case carbon_fiber:
            return "Углеволокно";
        default:
            return "Неизвестен";
        }
    }

    void DisplayCarInfo() const {
        cout << "Имя: " << cust_data.GetName() << "\n";
        cout << "Фамилия: " << cust_data.GetSurname() << "\n";
        cout << "Телефонный номер: " << cust_data.GetPhoneNumber() << "\n";
        cout << "Марка автомобиля: " << car_data.GetCarBrand() << "\n";
        cout << "Год выпуска автомобиля: " << car_data.GetYearOfRelease() << "\n";
        cout << "Госномер автомобиля: " << car_data.GetStateNumber() << "\n";
        cout << "Тип двигателя: " << GetEngineType() << "\n";
        cout << "Тип привода: " << GetWheelDriveType() << "\n";
        cout << "Цвет кузова: " << car_body.GetColor() << "\n";
        cout << "Материал кузова: " << GetMaterialType() << "\n";
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
        cout << "Создание записи об автомобиле.\n\n";

        string name, surname, phone_number;
        cout << "Введите имя: ";
        cin >> name;
        cout << "Введите фамилию: ";
        cin >> surname;
        cout << "Введите телефонный номер: ";
        cin >> phone_number;
        CustomerData customer(name, surname, phone_number);

        string car_brand, year_of_release, state_number;
        cout << "Введите марку автомобиля: ";
        cin >> car_brand;
        cout << "Введите год выпуска автомобиля: ";
        cin >> year_of_release;
        cout << "Введите госномер автомобиля: ";
        cin >> state_number;
        CarData car(car_brand, year_of_release, state_number);

        int option;
        cout << "Выберите тип двигателя (1. бензиновый; 2. дизельный; 3. электрический): ";
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

        cout << "Выберите тип привода (1. передний; 2. задний; 3. полный): ";
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
        cout << "Введите цвет кузова: ";
        cin >> color;

        cout << "Выберите материал кузова (1. алюминий; 2. сталь; 3. углеволокно): ";
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
            cout << "Вывод всех записей.\n\n";
            for (int counter = 0; counter < num_cars; counter++) {
                cout << "Заказ №" << counter + 1 << "\n";
                cars[counter].DisplayCarInfo();
                cout << "-----------------------------------\n\n";
            }
        }
        else {
            cout << "Записи не найдены!\n\n";
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
            throw std::runtime_error("Автомобиль с указанным госномером не найден.\n");
        }
    }
};

int CarDatabase::totalCars = 0;

void DisplayCarDatabaseInfo(const CarDatabase& database) {
    cout << "Общее количество записей в базе данных: " << database.GetNumCars() << "\n";
}

int main() {
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    CarDatabase car_db;
    int quit = 0;
    int option;

    try {
        while (!quit) {
            cout << "Выберите действие:\n";
            cout << " 1. Создать запись об автомобиле\n";
            cout << " 2. Редактировать конкретную запись\n";
            cout << " 3. Вывести все существующие записи\n";
            cout << " 4. Вывести конкретную запись\n";
            cout << " 5. Удалить конкретную запись\n";
            cout << " 6. Отсортировать по году выпуска\n";
            cout << " 7. Поиск по госномеру\n";
            cout << " 0. Выйти\n > ";

            if (cin >> option) {
                system("cls");
                switch (option) {
                case 1:
                    car_db.Input();
                    break;
                case 2:
                    cout << "Редактирование находится в разработке!\n\n";
                    break;
                case 3:
                    car_db.Output();
                    break;
                case 4:
                    cout << "Вывод конкретной записи находится в разработке!\n\n";
                    break;
                case 5:
                    cout << "Удаление находится в разработке!\n\n";
                    break;
                case 6:
                    car_db.SortByYear();
                    cout << "Записи отсортированы по году выпуска.\n\n";
                    break;
                case 7:
                {
                    string stateNumber;
                    cout << "Введите госномер автомобиля для поиска: \n > ";
                    cin >> stateNumber;
                    try {
                        Car foundCar = car_db.FindByStateNumber(stateNumber);
                        cout << "\nАвтомобиль найден:\n";
                        foundCar.DisplayCarInfo();
                        cout << "\n";
                    }
                    catch (const std::exception& e) {
                        cerr << e.what() << endl;
                    }
                }
                break;
                case 0:
                    cout << "Выход.\n";
                    quit = 1;
                    break;
                default:
                    cout << "Некорректный ввод. Попробуйте еще раз\n\n";
                    break;
                }
            }
            else {
                system("cls");
                throw runtime_error("Некорректный ввод. Пожалуйста, введите числовое значение.");
            }
        }
    }
    catch (const exception& e) {
        cerr << "Поймано исключение: " << e.what() << endl;
    }

    return 0;
}
