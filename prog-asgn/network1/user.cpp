#include <string>
#include "user.h"
#include <vector>

using namespace std;

User::User(int id, string name, int year,int zip, vector<int> friends){
   _id = id;
   _name = name;
   _year = year;
   _zip = zip;
   vector<int> _friends;
   _totFriends = 0;
}

User::~User(){}

void User::add_friend(int id){
   _friends.push_back(id);
}

void User::delete_friend(int id){
   for(unsigned int i = 0; i < _friends.size(); i++){
      if(_friends[i] == id){
         _friends.erase(_friends.begin() + i);
         return;
      }
}}
   
   //getters
int User::get_id(){
   return _id;
}

string User::get_name(){
   return _name;
}

int User::get_year(){
   return _year;
}

int User::get_zip(){
   return _zip;
}


vector<int> User::get_friends(){
   return _friends;
}

//setters
void User::set_name(string name){
   _name = name;
}

void User::set_year(int year){
   _year = year;
}

void User::set_zip(int zip){
   _zip = zip;
}

void User::set_friends(std::vector<int> friends){
   _friends = friends;
}
