#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#ifndef NOTEBOOK_HPP
#define NOTEBOOK_HPP

class Note{
protected:
  string title_, body_;
public:
  //mutators
  void set_title(string title) { title_ = title; }
  void set_body(string body) { body_ = body; }
  //accessors
  string title() { return title_; }
  string body() { return body_; }
  //default constructor
  Note(){
    title_ = "Untitled";
    body_ = "";
  }
  //nondefault constructor
  Note(string title, string body){
    title_ = title;
    body_ = body;
  }
  //new functions for milestone6
  virtual void display() const {
    cout << "[" << title_ << "]\n" << body_ << "\n\n";
  }
  virtual string serialize() {
    return "[Note]\n" + title_ + "\n" + body_ + "\n";
  }
};

class Notebook : public Note{
private: 
  int capacity_, size_;
  Note* notes_;
public:
  //default constructor
  Notebook(){
    capacity_ = 100;
    size_ = 0;
    notes_ = new Note[capacity_];
  }
  //nondefault constructor
  Notebook(int capacity){
    capacity_ = capacity;
    size_ = 0;
    notes_ = new Note[capacity_];
  }
  //destructor
  ~Notebook(){
    delete[] notes_;
    notes_ = nullptr;
  }
  //accessor
  int get_capacity() { return capacity_; }
  int get_size() { return size_; }
  //member functions
  void add(Note* new_note);
  Note* get(int index) const;
  void list_notes() const;
  void view_notes() const;
  void save_notes(const string &name);
  void load_notes(const string &name);
  //new functions for milestone6
  
};

//new class for milestone6
class EncryptedNote : public Note{
private:
  string password_;
public:
  //constructor
  EncryptedNote() {
    password_ = "";
  }
  EncryptedNote(string title, string body, string password) : Note(title, body) {
    title_ = title;
    body_ = body;
    password_ = password;
  }
  //member functions
  virtual void display() {
    string password;

    cout << "Please enter the password: ";
    getline(cin,password);

    if (password == password_)
      cout << "[" << title_ << "]\n" << body_ << "\n\n";
    else
      cout << "Incorrect password. \n";
  }
  virtual string serialize() {
    return "[Note]\n" + title_ + "\n" + body_ + "\n";
  }
};


Note* create_note();
EncryptedNote* create_encrypted_note();
/*
void list_notes(Note notes[], int size);
void view_notes(Note notes[], int size);
void save_notes(string name, Note notes[], int size);
void load_notes(string name, Note notes[], int *size);
*/

#endif