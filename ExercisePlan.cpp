#include "ExercisePlan.h"
#include <iostream>


ExercisePlan::ExercisePlan(int steps, std::string name, std::string date)
    : goalSteps(steps), planName(name), date(date) {}


ExercisePlan::ExercisePlan(const ExercisePlan& other)
    : goalSteps(other.goalSteps), planName(other.planName), date(other.date) {}


ExercisePlan::~ExercisePlan() {}


void ExercisePlan::setGoalSteps(int steps) 
{ 
    goalSteps = steps; 
}

void ExercisePlan::setPlanName(std::string name) 
{ 
    planName = name; 
}

void ExercisePlan::setDate(std::string date) 
{ 
    this->date = date; 
}

int ExercisePlan::getGoalSteps() const 
{ 
    return goalSteps; 
}

std::string ExercisePlan::getPlanName() const 
{ 
    return planName; 
}

std::string ExercisePlan::getDate() const 
{ 
    return date; 
}

void ExercisePlan::editGoal() 
{
    int newGoal;

    std::cout << "What's the new step goal: ";

    while (!(std::cin >> newGoal) || newGoal < 0) 
    {
        std::cout << "Nahhhh gotta be a positive number: ";
    
        std::cin.clear();
        
        std::cin.ignore(10000, '\n');
    }
    goalSteps = newGoal;
    
    std::cout << *this;
}


std::ostream& operator<<(std::ostream& out, const ExercisePlan& plan) 
{
    out << "Plan Name: " << plan.planName << "\n"

        << "Goal Steps: " << plan.goalSteps << "\n"

        << "Date: " << plan.date << "\n";

    return out;
}

std::istream& operator>>(std::istream& in, ExercisePlan& plan) 
{
    std::getline(in, plan.planName);

    if (!(in >> plan.goalSteps)) return in;

    in.ignore();

    std::getline(in, plan.date);

    return in;
}
