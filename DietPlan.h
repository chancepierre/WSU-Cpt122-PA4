#ifndef DIETPLAN_H
#define DIETPLAN_H

#include <iostream>
#include <string>

class DietPlan 
{
private:
    int calorieGoal;

    std::string planName;

    std::string date;

public:
    DietPlan(int calories = 0, std::string name = "", std::string date = "");

    DietPlan(const DietPlan& other);

    ~DietPlan();

    void setCalorieGoal(int calories);

    void setPlanName(std::string name);

    void setDate(std::string date);

    int getCalorieGoal() const;

    std::string getPlanName() const;

    std::string getDate() const;

    void editGoal();

    friend std::ostream& operator<<(std::ostream& out, const DietPlan& plan);

    friend std::istream& operator>>(std::istream& in, DietPlan& plan);
};

#endif
