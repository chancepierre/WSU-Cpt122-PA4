#ifndef EXERCISEPLAN_H
#define EXERCISEPLAN_H

#include <iostream>
#include <string>

class ExercisePlan 
{
private:
    int goalSteps;

    std::string planName;

    std::string date;

public:
    ExercisePlan(int steps = 0, std::string name = "", std::string date = "");
    
    ExercisePlan(const ExercisePlan& other);
    
    ~ExercisePlan();

    
    void setGoalSteps(int steps);
    
    void setPlanName(std::string name);
    
    void setDate(std::string date);

    int getGoalSteps() const;

    std::string getPlanName() const;

    std::string getDate() const;

    void editGoal();
    
    friend std::ostream& operator<<(std::ostream& out, const ExercisePlan& plan);
    
    friend std::istream& operator>>(std::istream& in, ExercisePlan& plan);
};

#endif
#pragma once
