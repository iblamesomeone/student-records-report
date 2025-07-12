#include<iostream>
#include<fstream>
using namespace std;

class Data {
    string inp_name;
    int score;
    string Grade;
public:
    void details () {
        cout<<"Enter Your Name : ";
        getline(cin, inp_name);

        cout<<"Marks (Out Of 100) : ";
        cin >> score;
        cin.ignore();

        if (score < 20) Grade = "F";
        else if (score <= 39) Grade = "D";
        else if (score <= 59) Grade = "C";
        else if (score <= 79) Grade = "B";
        else Grade = "A";
    }

    void printToConsole() {
        cout << inp_name << "\t" << score << "\t" << Grade << endl;
    }

    void printToFile(ofstream &file) {
        file << inp_name << "\t" << score << "\t" << Grade << endl;
    }
};

int main () {
    int x;
    cout<<"Enter Number Of Students: ";
    cin >> x;
    cin.ignore();

    Data a[100];

    for (int i = 0; i < x; i++) {
        cout << "\n--- Student " << i+1 << " ---\n";
        a[i].details();
    }

    cout << "\n----- Report Card (Console) -----\n";
    cout << "Name\tMarks\tGrade\n";

    for (int i = 0; i < x; i++) {
        a[i].printToConsole();
    }

    // Export to file
    ofstream file("report.txt");

    file << "----- Student Report Card -----\n";
    file << "Name\tMarks\tGrade\n";

    for (int i = 0; i < x; i++) {
        a[i].printToFile(file);
    }

    file.close();

    cout << "\n✅ Report exported successfully to 'report.txt'\n";

    return 0;
}
