#ifndef FITNESSAPPWRAPPER_H
#define FITNESSAPPWRAPPER_H

#include "DietPlan.h"
#include "ExercisePlan.h"
#include <vector>
#include <fstream>

class FitnessAppWrapper 
{
private:
    std::vector<DietPlan> dietPlans;

    std::vector<ExercisePlan> exercisePlans;

    void loadDailyPlan(std::ifstream& fileStream, DietPlan& plan);

    void loadDailyPlan(std::ifstream& fileStream, ExercisePlan& plan);

    void loadWeeklyPlan(std::ifstream& fileStream, std::vector<DietPlan>& weeklyPlan);

    void loadWeeklyPlan(std::ifstream& fileStream, std::vector<ExercisePlan>& weeklyPlan);

    void displayDailyPlan(const DietPlan& plan);

    void displayDailyPlan(const ExercisePlan& plan);

    void displayWeeklyPlan(const std::vector<DietPlan>& weeklyPlan);

    void displayWeeklyPlan(const std::vector<ExercisePlan>& weeklyPlan);
    
    void storeWeeklyPlan(std::ofstream& fileStream, const std::vector<DietPlan>& weeklyPlan);
    
    void storeWeeklyPlan(std::ofstream& fileStream, const std::vector<ExercisePlan>& weeklyPlan);

    void editDailyPlan(std::vector<DietPlan>& weeklyPlan);

    void editDailyPlan(std::vector<ExercisePlan>& weeklyPlan);

    void displayMenu();

public:
    void runApp();

};

#endif
