#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Record {
public:
    string name;
    string surname;
    string birthDate;
    string phoneNumber;


};

bool operator==(const Record& lhs, const Record& rhs) {
    return lhs.name == rhs.name &&
        lhs.surname == rhs.surname &&
        lhs.birthDate == rhs.birthDate &&
        lhs.phoneNumber == rhs.phoneNumber;
}

class Notebook {
private:
    svector<Record> records;

public:
    Notebook() {}

    Notebook(const vector<Record>& initialRecords) {
        records = initialRecords;
    }

    void addRecord(const Record& record) {
        records.push_back(record);
    }

    void deleteRecord(const Record& record) {
        records.erase(remove(records.begin(), records.end(), record), records.end());
    }

    vector<Record> searchBySurname(const string& surname) {
        vector<Record> foundRecords;

        for (const auto& record : records) {
            if (record.surname == surname) {
                foundRecords.push_back(record);
            }
        }

        return foundRecords;
    }

    vector<Record> searchByBirthDate(const string& birthDate) {
        vector<Record> foundRecords;

        for (const auto& record : records) {
            if (record.birthDate == birthDate) {
                foundRecords.push_back(record);
            }
        }

        return foundRecords;
    }

    vector<Record> searchByPhoneNumber(const string& phoneNumber) {
        vector<Record> foundRecords;

        for (const auto& record : records) {
            if (record.phoneNumber == phoneNumber) {
                foundRecords.push_back(record);
            }
        }

        return foundRecords;
    }

    void sortByName() {
        sort(records.begin(), records.end(), [](const Record& a, const Record& b) {
            return a.name < b.name;
            });
    }

    void sortBySurname() {
        sort(records.begin(), records.end(), [](const Record& a, const Record& b) {
            return a.surname < b.surname;
            });
    }

    void sortByBirthDate() {
        sort(records.begin(), records.end(), [](const Record& a, const Record& b) {
            return a.birthDate < b.birthDate;
            });
    }

    void sortByPhoneNumber() {
        sort(records.begin(), records.end(), [](const Record& a, const Record& b) {
            return a.phoneNumber < b.phoneNumber;
            });
    }

    void printAllRecords() {
        for (const auto& record : records) {
            cout << "Name: " << record.name << endl;
            cout << "Surname: " << record.surname << endl;
            cout << "Birth Date: " << record.birthDate << endl;
            cout << "Phone Number: " << record.phoneNumber << endl;
            cout << endl;
        }
    }
};

int main() {
    setlocale(0,"Ru");
    Notebook notebook;

    Record record1;
    record1.name = "Антон";
    record1.surname = "Айрапетян";
    record1.birthDate = "01.01.1990";
    record1.phoneNumber = "123456789";

    Record record2;
    record2.name = "Роман";
    record2.surname = "Поздняк";
    record2.birthDate = "10.05.1985";
    record2.phoneNumber = "987654321";

    notebook.addRecord(record1);
    notebook.addRecord(record2);


    vector<Record> foundRecords = notebook.searchBySurname("Айрапетян");

    cout << "найдено по фамилии 'Айрапетян':" << endl;
    for (const auto& record : foundRecords) {
        cout << "Name: " << record.name << endl;
        cout << "Surname: " << record.surname << endl;
        cout << "Birth Date: " << record.birthDate << endl;
        cout << "Phone Number: " << record.phoneNumber << endl;
        cout << endl;
    }

    notebook.sortByName();
    cout << "Сортировано по имени:" << endl;
    notebook.printAllRecords();

    return 0;
}
