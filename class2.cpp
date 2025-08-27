#include <iostream>
#include <ctime>
using std::cin;
using std::cout;

typedef const char * string;

class automobile {
    public:
        automobile();
        automobile(string newManufacturer, string newModel, int newYear);
        string getAutoManufacturer();
        void setAutoManufacturer(string newManufacturer);
        string getAutoModel();
        void setAutoModel(string newModel);
        int getAutoYear();
        void setAutoYear(int newYear);
        int getAutoAge();
        string completedDescription();
    private: 
        string _manufacturer;
        string _model;
        int _year;
};



automobile::automobile() {
    setAutoManufacturer("");
    setAutoModel("");
    setAutoYear(0);
}

automobile::automobile(string newManufacturer, string newModel, int newYear) {
    setAutoManufacturer(newManufacturer);
    setAutoModel(newModel);
    setAutoYear(newYear);
}



string automobile::getAutoManufacturer() {
    return _manufacturer;
}

void automobile::setAutoManufacturer(string newManufactor) {
    _manufacturer = newManufactor;
}



string automobile::getAutoModel() {
    return _model;
}

void automobile::setAutoModel(string newModel) {
    _model = newModel;
}



int automobile::getAutoYear() {
    return _year;
}

void automobile::setAutoYear(int newYear) {
    if (newYear < 0) {
        _year = 0;
    } else {
        _year = newYear;
    }
}



int automobile::getAutoAge() {
    time_t now = time(NULL);
    tm *ptr = localtime(&now);
    int currentYear = 1900 + ptr->tm_year; 
    return currentYear - getAutoYear();
}



int lengthString(string s) {
    int count = 0;
    while (s[count] != 0){
        count++;
    }
    return count;
}

int lengthNumber(int n) {
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

int caretOperator(int n) {
    int careted = 1; 
    while (n != 1) {
        careted *= 10;
        n--;
    }
    return careted;
}

string numberConverter(int n) {
    int length = lengthNumber(n);

    char * s = new char[length + 1];
    for (int i = 0; i < length; i++) {
        s[i] = (n / caretOperator(length - i)) + '0';
        n = n % caretOperator(length - i);
    }
    s[length] = 0;

    return s;
}

string automobile::completedDescription() {
    string year = numberConverter(getAutoYear());
    string model = getAutoModel();
    string manufacturer = getAutoManufacturer();

    int lenModel = lengthString(model); 
    int lenManufacturer = lengthString(manufacturer);
    int lenYear = lengthString(year);
    char * description = new char[lenYear + lenModel + lenManufacturer + 3];

    for (int i = 0; i < lenYear; i++) {
        description[i] = year[i];
    }
    description[lenYear] = ' ';

    for (int i = 0; i < lenModel; i++) {
        description[lenYear + 1 + i] = model[i];
    }
    description[lenYear + lenModel + 1] = ' ';

    for (int i = 0; i < lenManufacturer; i++) {
        description[lenYear + lenModel + 2 + i] = manufacturer[i];
    }
    description[lenYear + lenModel + lenManufacturer + 2] = 0;

    return description;
}

int main() {
    automobile car;
    automobile car2("Toyota", "Ponom", 2024);
    automobile car3("Mitsubishi", "Yeah", 2011);
    //automobile car2();
    cout << car.completedDescription() << "\n";
    cout << car2.completedDescription() << "\n";
    cout << car3.completedDescription() << "\n";
    cout << car3.getAutoAge() << "\n";
}
