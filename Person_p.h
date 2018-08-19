#pragma once

#include <memory>

class Person;

class PersonPrivate {
public:
	Person *q_ptr;

public:

	int m_age;

public:
	PersonPrivate();
	~PersonPrivate();

public:
	virtual void test() {

	}

};













class StudentPrivate : public PersonPrivate {
public:
	int m_id;


public:
	StudentPrivate();
	~StudentPrivate();

public:
	void Test();
};
