#pragma once

#include <memory>


class PersonPrivate;

using private_t = std::shared_ptr<PersonPrivate>;



class Person {

protected:
	const private_t m_dptr;
	Person(const private_t &rhs);

public:
	Person();
	~Person();

public:
	int GetAge() const;
	void AddAge();
	void PrintAge();

};













class Student : public Person {



public:
	Student();
	~Student();

public:
	int GetId();

};
