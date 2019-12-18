#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

enum RISK_LEVEL { RISK_A = 30, RISK_B = 20, RISK_C = 10 };
using namespace std;


class Employee {
	string name;
public:
	Employee() {

	}
	Employee(string name);
	virtual void Printname();
	virtual void ShowInfo() = 0;
	virtual int getPay() = 0;
};
Employee::Employee(string name) {
	this->name = name;
}
void Employee::Printname() {
	cout << "name : " << name << endl;
}


class PermanentWorker : public Employee {
	int salary; // 월급
public:
	PermanentWorker(string name, int salary);
	int getPay();
	void ShowInfo();
};
PermanentWorker::PermanentWorker(string name, int slary) :Employee(name) {
	this->salary = slary;
}
int PermanentWorker::getPay() {
	return salary;
}
void PermanentWorker::ShowInfo() {
	Printname();
	cout << "salary : " << salary << endl;
}


class TemporaryWorker : public Employee {
	int workTime = 0;
	int payPerHour;
public:
	TemporaryWorker() :Employee() {

	}
	TemporaryWorker(string name, int pay);
	void AddWorkTime(int workTime);
	int getPay();
	void ShowInfo();
};
TemporaryWorker::TemporaryWorker(string name, int pay) : Employee(name) {
	this->payPerHour = pay;
}
void TemporaryWorker::AddWorkTime(int workTime) {
	this->workTime += workTime;
}
int TemporaryWorker::getPay() {
	return this->payPerHour * workTime;
}
void TemporaryWorker::ShowInfo() {
	Printname();
	cout << "Pay : " << getPay();
}


class SalesWorker : public PermanentWorker {
	int salesResult = 0;
	double bonusRatio = 0;
public:
	SalesWorker(string name, int salay, double bonusRatio);
	void AddSalesResult(int salesResult);
	int getPay();
	void ShowInfo();

};
SalesWorker::SalesWorker(string name, int salary, double bonusRatio)
	: PermanentWorker(name, salary) {
	this->bonusRatio = bonusRatio;
}
void SalesWorker::AddSalesResult(int salesResult) {
	this->salesResult += salesResult;
}
int SalesWorker::getPay() {
	return PermanentWorker::getPay() + (salesResult * bonusRatio);
}
void SalesWorker::ShowInfo() {
	Printname();
	cout << "salesResult : " << getPay() << endl;
	cout << "bonusRatio : " << bonusRatio << endl;
}


class ForeinSalesWorker : public SalesWorker {
	int riskLevel;
public:
	ForeinSalesWorker(string name, int salary, double bonusRatio, int riskLevel);
	int GetRiskPay(); //return 위험수당
	int getPay(); // return salary + 위험수당
	void ShowInfo(); // 이름 월급 위험수당 페이 출력
};
ForeinSalesWorker::ForeinSalesWorker(string name, int salary, double bonusRatio, int riskLevel)
	:SalesWorker(name, salary, bonusRatio) {
	this->riskLevel = riskLevel;
}
int ForeinSalesWorker::GetRiskPay() {
	return (SalesWorker::getPay() * riskLevel / 100);
}
int ForeinSalesWorker::getPay() {
	return SalesWorker::getPay() + GetRiskPay();
}
void ForeinSalesWorker::ShowInfo() {
	Printname();
	cout << "Pay : " << getPay() << endl;
	cout << "RiskPay : " << GetRiskPay() << endl;
}

class EmployeeHandler {
public:
	Employee* Empl[100];
	int count = 0;
	void AddEmployee(Employee* emp);
	void ShowAllSalaryInfo();
	void ShowTotalSalary();
};
void EmployeeHandler::AddEmployee(Employee* emp) {
	Empl[count++] = emp;
}
void EmployeeHandler::ShowAllSalaryInfo() {

	for (int i = 0; i < count; i++) {
		Empl[i]->ShowInfo();
	}
}
void EmployeeHandler::ShowTotalSalary() {
	int total = 0;
	for (int i = 0; i < count; i++) {
		total = total + Empl[i]->getPay();
	}
	cout << "Totla : " << total;
}

void main() {
	EmployeeHandler handler;

	PermanentWorker* per1 = new PermanentWorker("Kim", 1000);
	handler.AddEmployee(per1);
	PermanentWorker* per2 = new PermanentWorker("Lee", 1500);
	handler.AddEmployee(per2);

	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	ForeinSalesWorker* fseller = new ForeinSalesWorker("Park", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller->AddSalesResult(7000);
	handler.AddEmployee(fseller);

	handler.ShowAllSalaryInfo();
	handler.ShowTotalSalary();

	system("pause");
}