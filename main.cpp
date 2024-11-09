#include "Exercises.h"
#include <iostream> 
#include <string> 
#include <vector> 

int main()
{
    int numExercise; // Variable for number of exercises the user chooses
    Exercises a; // First class overload 
    std::cout << "Enter the amount of exercises in your routine: "; // Asking user how many exercises they want 
    std::cin >> numExercise; // Storing value 
    std::cin.ignore(); // Avoids new line issues 

    Exercises * exerciseList  = new Exercises[numExercise]; // Creating an array for exercises with dynamic memory allocation

    for (int i = 0; i < numExercise; ++i) // For loop for input on each each exercise wanted by user 
    {
        std::string nameExercise; // String varaible for exercise name defined 
        int numSets, numReps; // Variables for reps and sets defined 

        std::cout << "Enter the name of the exercise: "; // Asking user to input name of exercise 
        std::getline(std::cin, nameExercise); // Storing user input into variable. std::getline allows for a space between words

        std::cout << "Enter number of sets: "; // Asking user to input number of sets 
        std::cin >> numSets; // Storing variable 

        std::cout << "Enter number of reps: "; // Asking user to input number of reps 
        std::cin >> numReps; // Storing variable 
        std::cin.ignore(); // Avoid new line issues 

        exerciseList[i]= Exercises(nameExercise, numSets, numReps, numExercise); // Assigning Exercises object to the i-th element in the array
    }

   std::cout << "Your exercise routine:\n"; // Displaying exercise routine to user 
   for (int i = 0; i < numExercise; ++i)
   {
    std::cout << "\n"; 
    std::cout << "Exercise name: " << exerciseList[i].getExcercises() << "\n";
    std::cout << "Sets: " << exerciseList[i].getSets() << "\n";
    std::cout << "Reps: " << exerciseList[i].getReps() << "\n\n";
   }

    return 0; 

    
    
}