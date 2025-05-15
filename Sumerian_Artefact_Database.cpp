#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int Arte = 100;

string artefactID[Arte] = {
    "121201", "122701", "120840", "B17711", "B16691", "AN1919.65"
};
string name[Arte] = {
    "The Standard of Ur", "Ceremonial Dagger", "The Royal Game of Ur", 
    "Queen Puabi Wreath", "Adze", "Male Worshipper"
};
string date[Arte] = {
    "2500BC", "2600BC", "2600BC", "2450BC", "2450BC", "2350BC"
};
string material[Arte] = {
    "Lapis Lazuli", "Gold", "Stone", "Gold", "Electrum", "Limestone"
};
string location[Arte] = {
    "British Museum", "British Museum", "British Museum", 
    "Penn Museum", "Penn Museum", "Ashmolean Museum"
};
string type[Arte] = {
    "Box", "Dagger", "Board Game", "Crown", "Adze-head", "Sculpture"
};
string origin[Arte] = {
    "Iraq", "Iraq", "Iraq", "Iraq", "Iraq", "Iraq"
};
int currentCount = 6;

void AddElem();
int findArt(const string& targetID);
void showARt(int index);
void singRow(int index);
void deleteArt(int index);
void displayTable();
void mainMenu();
void findMenu();

int main() {
    mainMenu();
    return 0;
}

void AddElem() {
    if (currentCount >= Arte) {
        cout << "Too many artefacts, this is not the British Museum!\n";
        return;
    }
    
    cout << "\nAdd Artefact:\n";
    cout << "Artefact ID: "; getline(cin, artefactID[currentCount]);
    cout << "Name: "; getline(cin, name[currentCount]);
    cout << "Date: "; getline(cin, date[currentCount]);
    cout << "Material: "; getline(cin, material[currentCount]);
    cout << "Location: "; getline(cin, location[currentCount]);
    cout << "Type: "; getline(cin, type[currentCount]);
    cout << "Origin: "; getline(cin, origin[currentCount]);
    
    currentCount++;
    cout << "Artefact preserved!\n";
}

int findArt(const string& targetID) {
    for (int i = 0; i < currentCount; i++) {
        if (artefactID[i] == targetID) {
            return i;
        }
    }
    return -1;
}

void showARt(int index) {
    cout << "\nARTEFACT DETAILS:\n";
    cout << "ID: " << artefactID[index] << endl;
    cout << "Name: " << name[index] << endl;
    cout << "Date: " << date[index] << endl;
    cout << "Material: " << material[index] << endl;
    cout << "Location: " << location[index] << endl;
    cout << "Type: " << type[index] << endl;
    cout << "Origin: " << origin[index] << endl;
}

void singRow(int index) {
    while (true) {
        cout << "\nEDITING ARTEFACT (" << artefactID[index] << "):\n";
        showARt(index);
        
        cout << "\nWhat do you want to change?:\n"
             << "1. Name\n"
             << "2. Date\n"
             << "3. Material\n"
             << "4. Location\n"
             << "5. Type\n"
             << "6. Origin\n"
             << "7. Finish Editing\n"
             << "your selection: ";
        
        int choice;
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                cout << "Name: ";
                getline(cin, name[index]);
                break;
            case 2:
                cout << "Date: ";
                getline(cin, date[index]);
                break;
            case 3:
                cout << "Material: ";
                getline(cin, material[index]);
                break;
            case 4:
                cout << "Location: ";
                getline(cin, location[index]);
                break;
            case 5:
                cout << "Type: ";
                getline(cin, type[index]);
                break;
            case 6:
                cout << "Origin: ";
                getline(cin, origin[index]);
                break;
            case 7:
                cout << "Updated!\n";
                return;
            default:
                cout << "Wrong, try again.\n";
        }
    }
}

void deleteArt(int index) {
    for (int i = index; i < currentCount - 1; i++) {
        artefactID[i] = artefactID[i+1];
        name[i] = name[i+1];
        date[i] = date[i+1];
        material[i] = material[i+1];
        location[i] = location[i+1];
        type[i] = type[i+1];
        origin[i] = origin[i+1];
    }
    currentCount--;
    cout << "Artefact deleted!\n";
}

void displayTable() {
    if (currentCount == 0) {
        cout << "No artefacts in database.\n";
        return;
    }
    
    cout << "\nSUMERIAN ARTEFACT DATABASE (" << currentCount << " records)\n";
    cout << left 
         << setw(12) << "ID" 
         << setw(25) << "Name" 
         << setw(10) << "Date" 
         << setw(18) << "Material" 
         << setw(20) << "Location" 
         << setw(15) << "Type" 
         << setw(10) << "Origin" 
         << endl;
    cout << string(110, '-') << endl;
    
    for (int i = 0; i < currentCount; i++) {
        cout << left 
             << setw(12) << artefactID[i] 
             << setw(25) << name[i] 
             << setw(10) << date[i] 
             << setw(18) << material[i] 
             << setw(20) << location[i] 
             << setw(15) << type[i] 
             << setw(10) << origin[i] 
             << endl;
    }
    cout << endl;
}

void findMenu() {
    string targetID;
    cout << "Enter Artefact ID: ";
    getline(cin, targetID);
    
    int index = findArt(targetID);
    if (index == -1) {
        cout << "No such artefact\n";
        return;
    }
    
    showARt(index);
    
    while (true) {
        cout << "\nFIND MENU:\n"
             << "1. Edit\n"
             << "2. Delete\n"
             << "3. Back to Main Menu\n"
             << "selection: ";
        
        int choice;
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1: 
                singRow(index); 
                break;
            case 2: 
                deleteArt(index); 
                return;
            case 3: 
                return;
            default: 
                cout << "Wrong bruv\n";
        }
    }
}

void mainMenu() {
    while (true) {
        cout << "\nSUMERIAN ARTEFACT DATABASE\n"
             << "1. Add New Artefact\n"
             << "2. Find Artefact\n"
             << "3. List All Artefacts\n"
             << "4. Exit\n"
             << "operation choice: ";
        
        int choice;
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1: 
                AddElem(); 
                break;
            case 2: 
                findMenu(); 
                break;
            case 3: 
                displayTable(); 
                break;
            case 4: 
                return;
            default: 
                cout << "Nope fam\n";
        }
    }
}
