// Copyright (c) 2021 Mikayla Barthelette All rights reserved
//
// Created by: Mikayla Barthelette
// Created on: Oct 2021
// This program creates the best number guessing game

#include <iostream>
#include <random>
#include <string>


int main() {
    // this function creates the game

    int numberGuessed;
    int someRandomNumber;
    std::string userInput;

    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0 , 9);  // [0 , 9]
    someRandomNumber = idist(rgen);

    // input & process & output
    while (true) {
        std::cout << "Enter the number between 0 - 9 : ";
        std::cin >> userInput;
        try {
            numberGuessed = std::stoi(userInput);
            if (numberGuessed == someRandomNumber) {
                std::cout << "Correct! The number was " <<
                someRandomNumber << ".";
                std::cout << std::endl;
                std::cout << "Done.";
                break;
            } else if (numberGuessed > someRandomNumber) {
                std::cout << numberGuessed << " is too high.";
                std::cout << std::endl;
                std::cout << std::endl;
            } else {
                std::cout << numberGuessed << " is too low.";
                std::cout << std::endl;
                std::cout << std::endl;
            }
        } catch (std::invalid_argument) {
            std::cout << "Invalid input";
            std::cout << std::endl;
            std::cout << std::endl;
        }
    }
}
