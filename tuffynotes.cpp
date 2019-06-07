/*This is a project by Kevin Doan for CPSC121 at CSUF

It is a note taking software that stores notes as objects
and saves them to a file.
*/
#include <iostream>
#include <string>
#include "notebook.hpp"
using namespace std;

int main() {
    char choice;
    Notebook notes;
    EncryptedNote* secretnote;
    Note* note;
    //int size = 0;
    string name;

    cout << "Welcome to TuffyNotes!\n";
  
    do {
        cout << "\n[C] Create a note\n";
        cout << "[N] Create an encrypted note\n";
        cout << "[L] List notes\n";
        cout << "[V] View note\n";
        cout << "[S] Save notes\n";
        cout << "[O] Load notes\n";
        cout << "[E] Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();
        switch (tolower(choice)) {
        case 'c':
            note = create_note();
            notes.add(note);
            break;
        case 'n':
            secretnote = create_encrypted_note();
            notes.add(secretnote);
            break;
        case 'l':
            notes.list_notes();
            break;
        case 'v':
            notes.view_notes();
            break;
        case 's':
            cout << "\nPlease enter filename: ";
            getline(cin,name);  
            notes.save_notes(name);
            break;
        case 'o':
            cout << "\nPlease enter filename: ";
            getline(cin,name);
            notes.load_notes(name);
            break;
        case 'e':
            cout << "\nThank you for using TuffyNotes!\n";
            break;
        default:
            cout << "\nInvalid choice. Please try again.\n\n";
        }
    } while (tolower(choice) != 'e');

    return 0;
}
