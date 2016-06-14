 #include "network.h"
#include <sstream>

using namespace std;

Network::Network(){}

Network::~Network(){}

int Network::read_friends(const char *filename){
  ifstream ifile(filename);
  if(ifile.fail()){
  	return -1;
  }
  int numUsers;
  ifile >> numUsers;
  for(int i = 0; i < numUsers; i++){
  	int id, year, zip;
  	string first, last, name;
  	vector<int> friends;

  	ifile >>id;
  	ifile >> first >> last;
  	ifile >> year;
  	ifile >> zip;
  	name = first + " " + last;
  	
  	string line;
  	getline(ifile, line);
  	getline(ifile, line);
  	stringstream ss;
  	ss >> line;
  	while(!ss.eof()){
  		int f;
  		ss >> f;
  		friends.push_back(f);
  	}
  	ss.clear();
  	User usr = User(id, name, year, zip, friends);
  	_users.push_back(usr);
  }
  return 0;
}

int Network::write_friends(const char *filename){
	ofstream ofile(filename);
	if(ofile.fail()){
		return -1;
	}
	int numUsers = _users.size();
	ofile << numUsers << endl;
	for(int i = 0; i < numUsers; i++){
		ofile << i << endl;
		
		User usr = _users[i];
		
		string name = usr.get_name();
		int year = usr.get_year();
		int zip = usr.get_zip();
		vector<int> friends = usr.get_friends();
		
		ofile << '\t' << name << endl;
		ofile << '\t' << year << endl;
		ofile << '\t' << zip << endl;
		ofile << '\t';

		for(unsigned int i = 0; i < friends.size(); i++){
			ofile << friends[i] << " ";
		}
		ofile << endl;
	}
	return 0;
}

void Network::add_user(string username, int yr, int zipcode){
	vector<int> friends;
	int id = _users.size() + 1;
	User usr = User(id, username, yr, zipcode, friends);
	_users.push_back(usr);	
}

int Network::add_connection(string name1, string name2){
	int id1, id2;

	for(unsigned int i=0; i < _users.size(); i++){
		if(_users[i].get_name() == name1){
			id1 = i;
		}
		else if(_users[i].get_name() == name2){
			id2 = i;
		}else{
			return -1;
		}
	}
	vector<int> fri1 = _users[id1].get_friends();
	vector<int> fri2 = _users[id2].get_friends();

	fri1.push_back(id2);
	fri2.push_back(id1);

	_users[id1].set_friends(fri1);
	_users[id2].set_friends(fri2);

	return 0;
}

int Network::remove_connection(string name1, string name2){
	int id1, id2;

	for(unsigned int i=0; i < _users.size(); i++){
		if(_users[i].get_name() == name1){
			id1 = i;
		}
		else if(_users[i].get_name() == name2){
			id2 = i;
		}
		else{
			return -1;
		}
	}
	vector<int> fri1 = _users[id1].get_friends();
	vector<int> fri2 = _users[id2].get_friends();

	for(unsigned int i =0; i < _users.size(); i++){
		if(fri1[i] == id2){
			fri1.erase(fri1.begin() + (id2 - 1));
		}
		else if(fri2[i] == id1){
			fri2.erase(fri2.begin() + (id1 - 1));
		}
		else{
			return -1;
		}
	}

	_users[id1].set_friends(fri1);
	_users[id2].set_friends(fri2);

	return 0;
}

int Network::get_id(string username){
	int id;
	for(unsigned int i = 0; i < _users.size(); i++){
		if(_users[i].get_name() == username){
			id = _users[i].get_id();
		}
		else{
			return -1;
		}
	}
	return id;
}