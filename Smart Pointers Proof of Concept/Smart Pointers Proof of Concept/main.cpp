//
//  main.cpp
//  Smart Pointers Proof of Concept
//
//  Created by Alex Neville on 12/10/25.
//

#include <iostream>
#include <string>
#include "Garden.hpp"

int main(int argc, const char * argv[])
{
    std::cout << "Hello, Smart Pointers Proof of Concept!\n";
    
    /*
        First, to understand smart pointers, we must understand normal (raw) pointers.
     
        And THAT requires and understanding of the STACK and the HEAP.
        
        Objects by default in C++ are placed on the STACK. The STACK is:
            - LIFO
            - Quick
            - Doesn't have a lot of storage space
     
        Its memory is also managed automatically. You don't have to do anything.
     */
    
    std::cout << std::endl;
    
    std::cout << "Basic Stack Variables: " << std::endl;
    
    // This is on the stack
    int yourMomsWeightInLbs = 480;
    // So are these
    bool yourMomLikesCarlsJrDoubleWesternBacon = true;
    bool isSheALady = yourMomsWeightInLbs >= 280;
    // We don't use using namespace std; anymore because of name collisions when using different libraries.
    std::string whereYourMomGotBaptized = "Sea World";
    
    std::cout << "your mom weighs " << yourMomsWeightInLbs << " lbs " << std::endl;
    if (yourMomLikesCarlsJrDoubleWesternBacon)
    {
        std::cout << "her favorite food is the Carl's Jr. Double Western Bacon Cheeseburger" << std::endl;
    }
    if (isSheALady)
    {
        std::cout << "and yeah she's definitely a lady" << std::endl;
    }
    
    // See? No new needed. Just standard variables.
    
    std::cout << "and she got baptized at " << whereYourMomGotBaptized << std::endl;
    std::cout << std::endl;
    
    /*
        Coming from an academic background, you might have been taught that classes always need to be put on the heap and dynamically allocated with new.
     
        But in reality, a standard nonused class can just be placed on the stack.
     
     */
    
    std::cout << "Classes placed on the stack: " << std::endl;
    
    // Default constructor (on stack)
    Garden myGarden;
    myGarden.display_info();
    // Constructor overloading (yep...still on stack)
    Garden someoneElsesGarden("Josie");
    someoneElsesGarden.display_info();
    // In Java, this would be put on the heap and there would be nothing you could do about it.
    // It just goes there. Not so here in C++.
    
    /*
        Now, let's define the HEAP.
     
        We use the heap if we need more room. It's slower, but more spacious.
     
        The heap is DYNAMICALLY ALLOCATED memory, meaning we get to choose when to use it, and when to release it.
     
        But that means that if we forget to release it, that's going to cause an issue. The memory will just be happily sitting there, set aside for our program, hogging resources that the rest of our computer could be using. 
        
     */
    
    return EXIT_SUCCESS;
}
