#include <iostream>

// Global game variables
double Money = 1000;          // Starting money set to $1000
double TotalProfit = 0;       // Total profit earned
int UsedCar = 0;              // Number of used cars owned
int ModifiedCar = 0;          // Number of modified cars owned
int Vote;                     // User menu selection

// Displays player statistics
void StatisticsMenu(){
    std::cout << "----------------------" << std::endl;
    std::cout << "Money: $" << Money << std::endl;
    std::cout << "My Total Profit: $" << TotalProfit << std::endl;
    std::cout << "My Used Cars: " << UsedCar << std::endl;
    std::cout << "My Modified Cars: " << ModifiedCar << std::endl;
    std::cout << "----------------------" << std::endl << std::endl;
}

// Displays main menu options
void MainMenu(){
    std::cout << "[1] - Buy Used Car [$500]" << std::endl;
    std::cout << "[2] - Sell Modified Car [Offers]" << std::endl;
    std::cout << "[3] - Modify The Car [$100]" << std::endl;
}

// Displays buyer offers for modified cars
void ModifiedCarSaled(){
    std::cout << "[1] - Albert [$750 Offer]" << std::endl;
    std::cout << "[2] - Alex [$730 Offer]" << std::endl;
}

// Gets user input
void VoteFunction(){
    std::cout << "Vote: ";
    std::cin >> Vote;
}

int main(){

    // Infinite game loop
    while(true){

        // Show statistics and menu every loop
        StatisticsMenu();
        MainMenu();
        VoteFunction();

        switch(Vote){

        // Buy used car
        case 1:
            if(Money >= 500){
                Money -= 500;
                UsedCar++;
                std::cout << "Used car purchased." << std::endl;
            }
            else{
                std::cout << "Insufficient money." << std::endl;
            }
            break;

        // Sell modified car
        case 2:
            ModifiedCarSaled();
            VoteFunction();

            switch(Vote){

            case 1:
                if(ModifiedCar >= 1){
                    ModifiedCar--;
                    Money += 750;
                    TotalProfit += 250;
                    std::cout << "Car sold to Albert!" << std::endl;
                }
                else{
                    std::cout << "No modified cars available." << std::endl;
                }
                break;

            case 2:
                if(ModifiedCar >= 1){
                    ModifiedCar--;
                    Money += 730;
                    TotalProfit += 230;
                    std::cout << "Car sold to Alex!" << std::endl;
                }
                else{
                    std::cout << "No modified cars available." << std::endl;
                }
                break;

            default:
                std::cout << "Invalid selection!" << std::endl;
                break;
            }
            break; // Prevent fall-through to case 3

        // Modify used car
        case 3:
            if(UsedCar >= 1 && Money >= 100){
                UsedCar--;
                ModifiedCar++;
                Money -= 100;
                std::cout << "The car has been modified." << std::endl;
            }
            else{
                std::cout << "Insufficient resources to modify the car." << std::endl;
            }
            break;

        default:
            std::cout << "Invalid selection!" << std::endl;
            break;
        }
    }

    return 0;
}
