#include <string>
#include <vector>
#ifndef USER_H
#define USER_H

class User {
 public:
 	User(int id, std::string name, int year, int zip,
 		std::vector<int> friends);
   ~User();
   void add_friend(int id);
   void delete_friend(int id);
   
   //getters
   int get_id();
   std::string get_name();
   int get_year();
   int get_zip();
   int get_totFriends();
   std::vector<int> get_friends();

   //setters
   void set_name(std::string name);
   void set_year(int year);
   void set_zip(int zip);
   void set_friends(std::vector<int> friends);

 private:
 	int _id;
 	std::string _name;
 	int _year;
 	int _zip;
 	std::vector<int> _friends;
   int _totFriends;
};


#endif
