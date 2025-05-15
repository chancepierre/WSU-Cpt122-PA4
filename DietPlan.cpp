#include "DietPlan.h"
#include <iostream>

DietPlan::DietPlan(int calories, std::string name, std::string date)
    : calorieGoal(calories), planName(name), date(date) {}


DietPlan::DietPlan(const DietPlan& other)
    : calorieGoal(other.calorieGoal), planName(other.planName), date(other.date) {}


DietPlan::~DietPlan() {}


void DietPlan::setCalorieGoal(int calories) 
{ 
    calorieGoal = calories; 
}

void DietPlan::setPlanName(std::string name) 
{ 
    planName = name; 
}
void DietPlan::setDate(std::string date) 
{ 
    this->date = date; 
}

int DietPlan::getCalorieGoal() const 
{ 
    return calorieGoal; 
}

std::string DietPlan::getPlanName() const 
{ 
    return planName; 
}

std::string DietPlan::getDate() const 
{ 
    return date; 
}

void DietPlan::editGoal() 
{
    int newGoal;
    
    std::cout << "What's new the calorie goal twin: ";
    
    while (!(std::cin >> newGoal) || newGoal < 0) 
    {
        std::cout << "Nahhhh gotta be a positive number bro: ";
    
        std::cin.clear();
        
        std::cin.ignore(10000, '\n');
    }
    
    calorieGoal = newGoal;
    
    std::cout << *this;
}

std::ostream& operator<<(std::ostream& out, const DietPlan& plan) 
{
    out << "Plan Name: " << plan.planName << "\n"
   
        << "Goal Calories: " << plan.calorieGoal << "\n"
        
        << "Date: " << plan.date << "\n";
    
    return out;
}

std::istream& operator>>(std::istream& in, DietPlan& plan) 
{
    std::getline(in, plan.planName);

    if (!(in >> plan.calorieGoal)) return in;

    in.ignore();

    std::getline(in, plan.date);

    return in;
}
