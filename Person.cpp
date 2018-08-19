#include <iostream>

#include "Person.h"
#include "Person_p.h"




PersonPrivate::PersonPrivate() : q_ptr{ nullptr }, m_age{} {

}



PersonPrivate::~PersonPrivate() {

}












Person::Person() : m_dptr{ new PersonPrivate{} } {
	m_dptr->q_ptr = this;
}



Person::Person(const private_t &rhs) : m_dptr{ rhs } {
	std::cout << "Person::Person(const private_t &rhs) this: " << this << std::endl;
	m_dptr->q_ptr = this;
}


Person::~Person() {

}


int Person::GetAge() const {
	return m_dptr->m_age;
}


void Person::AddAge() {
	++m_dptr->m_age;
}

void Person::PrintAge() {
	std::cout << "age: " << m_dptr->m_age << std::endl;
}





















StudentPrivate::StudentPrivate() : PersonPrivate{}, m_id{}{

}



StudentPrivate::~StudentPrivate() {

}


void StudentPrivate::Test() {

	if (q_ptr) {
		if (Student *ss = reinterpret_cast<Student*>(q_ptr)) {
			ss->GetId();
		}
	}
}










Student::Student() : Person{std::make_shared<StudentPrivate>()} {
	std::cout << "Student::Student() this: " << this << std::endl;
	std::cout << "Student::Student() m_dptr->q_ptr: " << m_dptr->q_ptr << std::endl;

}


Student::~Student() {

}


int Student::GetId() {



	{
		if (auto *ptr = dynamic_cast<StudentPrivate*>(&*m_dptr)) {

			return ptr->m_id;
		}
		else {
			std::cout << "translate fail....." << std::endl;
			return 0;
		}
	}


	{
		try
		{
			auto &ptr = dynamic_cast<StudentPrivate&>(*m_dptr);
			return ptr.m_id;

		}
		catch (const std::bad_cast &cast)
		{
			std::cout << "translate fail11....." << cast.what() << std::endl;
			return 0;
		}

	}
	


}

