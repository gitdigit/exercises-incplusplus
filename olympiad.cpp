//JENNIFER KOUASSI 
//12/05/2024

#include <iostream>
#include <string>
using namespace std;

class CParticipant {
public:
    virtual void insertData() = 0;
    virtual void displayData() = 0;
    virtual int getAge() = 0;
    virtual int getGender() = 0;
    virtual string getSchool() = 0;
    virtual string getUniversity() = 0;
    virtual ~CParticipant() {}
};

class CStudents : public CParticipant {
private:
    string name;
    string idN;
    string university;
    string faculty;
    string speciality;
    int points = 0;

public:
    void insertData() override;
    void displayData() override;
    int getGender() override;
    string getUniversity() override;
    int getAge() override;
    string getSchool() override;
};

void CStudents::insertData() {
    cin.ignore();
    cout << "Enter the student name: "; getline(cin, name);
    cout << "Enter the student ID: "; getline(cin, idN); //syyyymmdd the format the ID
    cout << "Enter the student university: "; getline(cin, university);
    cout << "Enter the student faculty: "; getline(cin, faculty);
    cout << "Enter the student speciality: "; getline(cin, speciality);
    cout << "Enter the student points: "; cin >> points;
}

void CStudents::displayData() {
    cin.ignore();
    cout << "Student Name: " << name << endl;
    cout << "Student ID: " << idN << endl;
    cout << "Student University: " << university << endl;
    cout << "Student Faculty: " << faculty << endl;
    cout << "Student Speciality: " << speciality << endl;
    cout << "Student Points: " << points << endl;
}

string CStudents::getUniversity() {
    return university;
}

int CStudents::getAge() {
    int year = stoi(idN.substr(1, 4));
    int age = 2024 - year;
    return year;
}
int CStudents::getGender() {
    int gender = stoi(idN.substr(0, 1)); // 1 FOR MALE 2 FOR FEMALE
    return gender;
}
string CStudents::getSchool() {
    // Students don't have a school
    return "";
}

class CPupils : public CParticipant {
private:
    string name;
    string idN;
    string school;
    string puClass;
    int points = 0;

public:
    void insertData() override;
    void displayData() override;
    int getGender() override;
    string getSchool() override;
    string getUniversity() override;
    int getAge() override;

};

void CPupils::insertData() {
    cin.ignore();
    cout << "Enter the pupil name: "; getline(cin, name);
    cout << "Enter the pupil ID: "; getline(cin, idN);
    cout << "Enter the pupil school: "; getline(cin, school);
    cout << "Enter the pupil class: "; getline(cin, puClass);
    cout << "Enter the pupil points: "; cin >> points;
}

void CPupils::displayData() {
    cin.ignore();
    cout << "Pupil Name: " << name << endl;
    cout << "Pupil ID: " << idN << endl;
    cout << "Pupil School: " << school << endl;
    cout << "Pupil Class: " << puClass << endl;
    cout << "Pupil Points: " << points << endl;
}

string CPupils::getSchool() {
    return school;
}

string CPupils::getUniversity() {
    return "";
}

int CPupils::getAge() {

    return 0;
}
int CPupils::getGender() {

    return 0;
}



//adds to the array data of a participant;
int main() {
    int i = 0;
    int maxParticipants = 5; ///NUMBER MAX OF PARTICIPANTS
    int numParticipants = 0; /// 
    char participantType;
    char add;
    int choice;
    string uniToSearch;
    string schoolToSearch;

    CParticipant** participantTab = nullptr;
    do {
        cout << "\nMENU\n";
        cout << "1 - Add information for the student or pupil\n";
        cout << "2 - Display information of all the participants\n";
        cout << "3 - Display male students over 20 years old from a given university\n";
        cout << "4 - Create an array of data for all students from a given school\n";
        cout << "Choose an operation or press 0: ";
        cin >> choice;

        switch (choice) {
        case 1:
            do {
                //ASK FOR THE PARTICIPANT TYPE
                cout << "Are you adding information for a student (s) or a pupil (p)";
                cin >> participantType;

                if (numParticipants == 0) {
                    participantTab = new CParticipant * [maxParticipants];
                }
                if (participantType == 's') {
                    participantTab[numParticipants] = new CStudents();
                }
                else if (participantType == 'p') {
                    participantTab[numParticipants] = new CPupils();
                }

                //INSERT THE DATA
                participantTab[numParticipants]->insertData();
                numParticipants++;

                //ADD PARTICIPANT AGAIN ?
                cout << "Add another participant? (y/n): ";
                cin >> add;
            } while (add == 'y');
            break;

        case 2:
            //cin.ignore(); 
                //DISPLAY ALL ENTERED DATA
            for (i = 0; i < numParticipants; i++) {
                participantTab[i]->displayData();
            }
            break;
        case 3:
            cout << "Enter the university to search: "; //SEARCH UNIVERSITY 
            cin.ignore();
            getline(cin, uniToSearch);
            //CALL THE getUniversity and getAge FUNCTIONS
            cout << "\nMale students over 20 years old from " << uniToSearch << ":\n";
            for (i = 0; i < numParticipants; i++) {
                if (participantTab[i]->getUniversity() == uniToSearch && participantTab[i]->getAge() > 20 && participantTab[i]->getGender() == 1) {
                    participantTab[i]->displayData();

                }
            }
            break;
        case 4:
            cout << "Enter the school to search: ";
            cin.ignore();
            getline(cin, schoolToSearch);
            cout << "\nStudents from " << schoolToSearch << ":\n";
            for (i = 0; i < numParticipants; i++) {
                if (participantTab[i]->getSchool() == schoolToSearch) {
                    participantTab[i]->displayData();
                    cout << endl;

                }
            }
            break;
        default:
            cout << "Wrong code of operation.\n";
        }
    } while (choice != 0);
    // cin.ignore();
    //FREE THE MEMORY
    for (int i = 0; i < numParticipants; i++) {
        delete participantTab[i]; 
    }


    return 0;
}
