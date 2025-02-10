#include <iostream>
#include <vector>
#include <string>

class Employee {
public:
    Employee(std::string name, double hourlyRate, double hoursWorked)
        : name(name), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    double calculateSalary() const {
        return hourlyRate * hoursWorked;
    }

    std::string getName() const {
        return name;
    }

    double getHoursWorked() const {
        return hoursWorked;
    }

    void setHoursWorked(double hours) {
        hoursWorked = hours;
    }

private:
    std::string name;
    double hourlyRate;
    double hoursWorked;
};

class PayrollSystem {
public:
    void addEmployee(const Employee& employee) {
        employees.push_back(employee);
    }

    void generateReport() const {
        std::cout << "Payroll Report\n";
        std::cout << "--------------\n";
        for (const auto& employee : employees) {
            std::cout << "Employee: " << employee.getName() << "\n";
            std::cout << "Hours Worked: " << employee.getHoursWorked() << "\n";
            std::cout << "Salary: $" << employee.calculateSalary() << "\n\n";
        }
    }

private:
    std::vector<Employee> employees;
};

int main() {
    PayrollSystem payrollSystem;
    int numEmployees;

    std::cout << "Enter the number of employees: ";
    std::cin >> numEmployees;

    for (int i = 0; i < numEmployees; ++i) {
        std::string name;
        double hourlyRate;
        double hoursWorked;

        std::cout << "Enter details for employee " << i + 1 << ":\n";
        std::cout << "Name: ";
        std::cin.ignore(); // To ignore the newline character left in the buffer
        std::getline(std::cin, name);
        std::cout << "Hourly Rate: ";
        std::cin >> hourlyRate;
        std::cout << "Hours Worked: ";
        std::cin >> hoursWorked;

        Employee employee(name, hourlyRate, hoursWorked);
        payrollSystem.addEmployee(employee);
    }

    payrollSystem.generateReport();

    return 0;
}