//
//  Garden.cpp
//  Smart Pointers Proof of Concept
//
//  Created by Alex Neville on 12/10/25.
//

#include "Garden.hpp"
#include <iostream>
#include <string>

Garden::Garden()
{
    std::cout << "Creating a Garden object with default gardener" << std::endl;
    gardenerName = "Elise";
}

Garden::Garden(std::string name)
{
    std::cout << "Creating a Garden object with a custom gardener, " << name << std::endl;
    gardenerName = name;
}

std::string Garden::get_gardener()
{
    return gardenerName;
}

void Garden::plant_flower()
{
    std::cout << "planting a flower" << std::endl;
    numFlowers++;
}

void Garden::display_info()
{
    std::cout << "Displaying Garden info: " << std::endl;
    std::cout << "Gardener: " << gardenerName << std::endl;
    std::cout << "We have " << numFlowers << " beautiful, allergy-inducing flowers" << std::endl;
}
