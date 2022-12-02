#include <iostream>
#include <fstream>
#include "FullName.pb.h"
#include "Student.pb.h"
#include "StudentsGroup.pb.h"
#include "IMethods.h"
#include "IRepository.h"
#include <google/protobuf/descriptor.pb.h>
using namespace std;

class StudentsGroup: private IRepository, private IMethods
{
private:

public:
	Students::StudentsGroup instance;

	StudentsGroup()
	{

	}

	StudentsGroup(Students::StudentsGroup instance)
	{
		this->instance = instance;
	}

	const int FindByFullName(const Students::FullName& name)
	{
		for (int i = 0; i < instance.students_size(); i++)
		{
			if (instance.students(i).name().firstname() == name.firstname()
					&& instance.students(i).name().lastname() == name.lastname()
					&& instance.students(i).name().patronymic() == name.patronymic())
			{
				return i;
			}
		};
		return -1;
	}

	double GetAverageScore(const Students::FullName& name) override
	{
		int sum = 0;
		int index = FindByFullName(name);
		if (index != -1)
		{
			auto marks = instance.students(index).marks();
			for (int i = 0; i < marks.size(); i++)
			{
				sum += marks.Get(i);
			}
			return (double)sum / marks.size();
		}
		return 0;
	}

	string GetAllInfo(const Students::FullName& name) override
	{
		int index = FindByFullName(name);
		if (index != -1)
		{
			auto student = instance.students(index);
			string result = "";
			result = "Student: " + student.name().lastname() + " " + student.name().firstname() + " " + student.name().patronymic();
			string marksString = "";
			auto marks = student.marks();
			for (int i = 0; i < marks.size(); i++)
			{
				marksString += to_string(marks.Get(i)) + " ";
			}
			result += " Student Marks: " + marksString;
			string studentAvg = " Student Avg: " + to_string(GetAverageScore(name));
			result += studentAvg;
			return result;
		}
		return "";
	}

	string GetAllInfo() override
	{
		string result = "";
		for (auto student: instance.students())
		{
			result += GetAllInfo(student.name()) + ";    ";
		}
		return result;
	}

	void Open() override
	{
		ifstream in("students.bin", std::ios_base::binary);
		Students::StudentsGroup group;
		if (group.ParseFromIstream(&in))
		{
			instance = group;
			cout << GetAllInfo() << endl;
		}
		else
		{
			cout << "Parse Failed" << endl;
		}
		in.close();
	}

	void Save() override
	{
		ofstream out("students.bin", std::ios_base::binary);
		instance.SerializePartialToOstream(&out);
		out.close();
	}
};




int main()
{
    Students::FullName name;
    name.set_lastname("Mishenko1");
    name.set_firstname("Kirill1");
    name.set_patronymic("Alexandrovich1");
    Students::FullName name2;
    name2.set_lastname("Mishenko2");
    name2.set_firstname("Kirill2");
    name2.set_patronymic("Alexandrovich2");
    Students::Student student1;
    student1.set_allocated_name(&name);
    Students::Student student2;
    student2.set_allocated_name(&name2);
    Students::StudentsGroup group;
	Students::Student* s1 = group.add_students();
	s1->set_allocated_name(&name);
	s1->add_marks(3);
	s1->add_marks(4);
	s1->add_marks(4);
	s1->add_marks(5);
	s1->add_marks(3);
	Students::Student* s2 = group.add_students();
	s2->set_allocated_name(&name2);
	s2->add_marks(4);
	s2->add_marks(4);
	s2->add_marks(4);
	s2->add_marks(5);
	s2->add_marks(5);
	StudentsGroup sg(group);


	cout << sg.GetAverageScore(name) << endl;
	cout << sg.GetAllInfo(name) << endl;
	cout << sg.GetAllInfo() << endl;


	sg.Save();


	cout << "THIS IS OBJECT OPENED FROM FILE:" << endl;
	StudentsGroup sgFromFile;
	sgFromFile.Open();
}
