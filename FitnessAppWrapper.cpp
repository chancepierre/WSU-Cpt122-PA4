#include "FitnessAppWrapper.h"
#include <iostream>
#include <fstream>


void FitnessAppWrapper::loadDailyPlan(std::ifstream& fileStream, DietPlan& plan) 
{
    fileStream >> plan;
}

void FitnessAppWrapper::loadDailyPlan(std::ifstream& fileStream, ExercisePlan& plan) 
{
    fileStream >> plan;
}


void FitnessAppWrapper::loadWeeklyPlan(std::ifstream& fileStream, std::vector<DietPlan>& weeklyPlan) 
{
    weeklyPlan.clear();

    for (int i = 0; i < 7; i++) 
    {
        DietPlan plan;
    
        loadDailyPlan(fileStream, plan);
        
        weeklyPlan.push_back(plan);
    }
}

void FitnessAppWrapper::loadWeeklyPlan(std::ifstream& fileStream, std::vector<ExercisePlan>& weeklyPlan) 
{
    weeklyPlan.clear();

    for (int i = 0; i < 7; i++) 
    {
        ExercisePlan plan;
    
        loadDailyPlan(fileStream, plan);
        
        weeklyPlan.push_back(plan);
    }
}


void FitnessAppWrapper::displayDailyPlan(const DietPlan& plan) 
{
    std::cout << plan << std::endl;
}

void FitnessAppWrapper::displayDailyPlan(const ExercisePlan& plan) 
{
    std::cout << plan << std::endl;
}

void FitnessAppWrapper::displayWeeklyPlan(const std::vector<DietPlan>& weeklyPlan) 
{
    for (const auto& plan : weeklyPlan) 
    
    {
        displayDailyPlan(plan);
    }
}

void FitnessAppWrapper::displayWeeklyPlan(const std::vector<ExercisePlan>& weeklyPlan) 
{
    for (const auto& plan : weeklyPlan) 
    
    {
        displayDailyPlan(plan);
    }
}

void FitnessAppWrapper::storeWeeklyPlan(std::ofstream& fileStream, const std::vector<DietPlan>& weeklyPlan) 
{
    for (const auto& plan : weeklyPlan) 
    {
        fileStream << plan << std::endl;
    }
}

void FitnessAppWrapper::storeWeeklyPlan(std::ofstream& fileStream, const std::vector<ExercisePlan>& weeklyPlan) 
{
    for (const auto& plan : weeklyPlan) 
    
    {
        fileStream << plan << std::endl;
    }
}

void FitnessAppWrapper::editDailyPlan(std::vector<DietPlan>& weeklyPlan) 
{
    int day;

    std::cout << "Which day would you like to edit 1-7: ";

    std::cin >> day;
    
    if (day < 1 || day > 7) 
    
    {
        std::cout << "okay be serious that's not even an option" << std::endl;
       
        return;
    }
    
    weeklyPlan[day - 1].editGoal();
}

void FitnessAppWrapper::editDailyPlan(std::vector<ExercisePlan>& weeklyPlan) 
{
    int day;

    std::cout << "Which day would you like to edit 1-7: ";

    std::cin >> day;

    if (day < 1 || day > 7) 
    {
        std::cout << "Come on gang that's not an option!" << std::endl;
    
        return;
    }
    weeklyPlan[day - 1].editGoal();
}


void FitnessAppWrapper::displayMenu() 
{
    std::cout << "\n Pierre fitness App Menu \n";

    std::cout << "1. Load weekly diet plan\n";

    std::cout << "2. Load weekly exercise plan\n";

    std::cout << "3. Store weekly diet plan\n";

    std::cout << "4. Store weekly exercise plan\n";

    std::cout << "5. Display weekly diet plan\n";

    std::cout << "6. Display weekly exercise plan\n";

    std::cout << "7. Edit daily diet plan\n";

    std::cout << "8. Edit daily exercise plan\n";

    std::cout << "9. Exit\n";

    std::cout << "Enter your choice: ";
}

void FitnessAppWrapper::runApp() 
{
    int choice;

    bool running = true;

    while (running) 
    {
        displayMenu();

        if (!(std::cin >> choice)) 
        {
            std::cout << "Invalid input! Please enter a number between 1-9.\n";
        
            std::cin.clear();
            
            std::cin.ignore(10000, '\n');
            
            continue;
        }

        switch (choice) 
        {
        case 1: 
        {
            std::ifstream inFile("dietPlans.txt");
           
            if (inFile.is_open())
            {
                loadWeeklyPlan(inFile, dietPlans);
            
                inFile.close();
                
                std::cout << "The diet plans loaded successfully.\n";
            }
            
            else 
            {
                std::cout << "Sorry can't open dietPlans.txt\n";
            }
            
            break;
        }
        
        case 2: 
        {
            std::ifstream inFile("exercisePlans.txt");
        
            if (inFile.is_open()) 
            {
                loadWeeklyPlan(inFile, exercisePlans);
            
                inFile.close();
                
                std::cout << "The exercise plans loaded successfully.\n";
            }
           
            else 
            {
                std::cout << "Sorry can't open exercisePlans.txt\n";
            }
           
            break;
        }
        
        case 3: 
        {
            std::ofstream outFile("dietPlans.txt");
        
            if (outFile.is_open()) 
            {
                storeWeeklyPlan(outFile, dietPlans);
            
                outFile.close();
                
                std::cout << "Alr we diet plans saved successfully.\n";
            }
            
            else 
            {
                std::cout << "Uhhhh can't save that gang\n";
            }
            break;
        }
        case 4: 
        {
            std::ofstream outFile("exercisePlans.txt");
        
            if (outFile.is_open()) 
            {
                storeWeeklyPlan(outFile, exercisePlans);
            
                outFile.close();
                
                std::cout << "Okayy exercise plans saved successfully.\n";
            }
            else 
            {
                std::cout << "umm error error can't savee\n";
            }
            break;
        }
        
        case 5:
            displayWeeklyPlan(dietPlans);
        
            break;
        
        case 6:
            displayWeeklyPlan(exercisePlans);
        
            break;
        
        case 7:
            editDailyPlan(dietPlans);
        
            break;
        
        case 8:
            editDailyPlan(exercisePlans);
        
            break;
        
        case 9:
            std::cout << "Aight gonna save and exit now\n";
        
            running = false;
            
            break;
        
        default:
           
            std::cout << "Bro it's a choice of 1-9 what u doin??\n";

        }
    }
}
