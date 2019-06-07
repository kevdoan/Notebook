#include "notebook.hpp"

Note* create_note() {
    string title, body;

    cout << "\nPlease enter the note's title: ";
    getline(cin, title);
    cout << "Please enter the note: ";
    getline(cin, body);
    //note->set_title(title);
    //note->set_body(body);
    //Note note(title,body);
    Note* note = new Note(title,body);
    //Note* note = &note;
    cout << "\nNote added!\n\n";

    return note;
}

//new encryptednote function
EncryptedNote* create_encrypted_note() { 
    string title, body, password;
    //Note* note;

    cout << "\nPlease enter the note's title: ";
    getline(cin, title);
    cout << "Please enter the note: ";
    getline(cin, body);
    //note->set_title(title);
    //note->set_body(body);
    cout << "\nPlease enter the password: ";
    getline(cin, password);
    //EncryptedNote note;
    EncryptedNote* note = new EncryptedNote(title,body,password);
    cout << "\nEncrypted note added!\n\n";

    return note;
}

void Notebook::list_notes() const {
    if (size_ == 0) {
        cout << "\nNo notes have been added.\n\n";
    }
    else {
        cout << "\nNotes\n";
        for (int i = 0; i < size_; i++){
	        cout << i+1 << ". " << (notes_+i)->title() << "\n";
        }
        cout << "\n";
    }
}

void Notebook::view_notes() const {
    int index;

    cout << "\nPlease input note index: ";
    cin >> index;
    if (index > size_ || index == 0)
        cout << "\n*Invalid note index.*\n\n";
    else {
        cout << "\n"; 
        notes_[index-1].display();
    }
}

void Notebook::save_notes(const string &name){
    ofstream out_file;
    int num = 0;

    out_file.open(name);
    for (int i = 0; i < size_; i++){
        num += 1;   
    }
    out_file << num; //stores number of notes on first line
    out_file << "\n";
    for (int i = 0; i < size_; i++) {
        out_file << notes_[i].serialize();
    }/*
    for (int i = 0; i < size_; i++){
        out_file << "[Note]\n";
        out_file << notes_[i].title() << "\n";
	    out_file << notes_[i].body() << "\n";
    }*/
    out_file.close();
    cout << "Notes saved!\n";
}

void Notebook::load_notes(const string &name){
    ifstream in_file;
    string header, title, body;
    
    in_file.open(name);
    if (in_file.fail())
        cout << "Error opening data file!\n";
    else {
        in_file >> size_; //obtains the number of note objects on the first line
        in_file.ignore();

        for (int i = 0; i < size_; i++){
            getline(in_file,header); //catch those annoying [Note] lines
            getline(in_file,title);
            notes_[i].set_title(title);
            getline(in_file,body);
            notes_[i].set_body(body);
        }
        in_file.close();
        cout << "Notes loaded!\n";
    }
}

//fix this
void Notebook::add(Note* new_note){
    *(notes_+size_) = *new_note;
    size_++;
}

Note* Notebook::get(int index) const {
    return (notes_+index);
}
