#include "delist.h"
#include <cstdlib>

using namespace std;

DEList::DEList(){
	_head = NULL;
	_tail = NULL;;
}

DEList::~DEList(){
	delete[] _head;
	delete[] _tail;
}

bool DEList::empty(){
	if(_head == NULL){
		return true;
	}
	else{
		return false;
	}
}

int DEList::size(){
	if(_head == NULL){
		return -1;
	}
	else{
		int count = 0;
		DEItem* item = _head;
		while(item != NULL){
			count++;
			item = item ->next;
		}
		return count;
	}
}

int DEList::front(){
	if(_head == NULL){
		return -1;
	}
	else{
		return _head->val;
		}
	}
}

int DEList::back(){
	if(_tail == NULL){
		return -1;
	}
	else{
		return _tail->val;
	}
}

void DEList::push_front(int new_val){
	DEItem* tmp = new DEItem();
	tmp->val = new_val;

	if(_head == NULL){
		tmp->prev = NULL;
		tmp->next = NULL;
		_head = tmp;
		_tail = tmp;
	}
	else{
		tmp->prev = NULL;
		tmp-> next = _head;
		_head->prev = tmp;
		_head = tmp;
	}
}

void DEList::push_back(){
	DEItem* tmp = new DEItem();
	tmp->val = new_val;

	if(_tail == NULL){
		tmp->prev =NULL;
		tmp-> next = NULL;
		_head = tmp;
		_tail= tmp;
	}
	else{
		tmp->prev = _tail;
		tmp -> next = NULL;
		_tail->next = tmp;
		_tail = tmp;
	}
}

void DEList::pop_front(){
	if(_head != NULL){
		if(size() = 1){
			
		}

	}
}