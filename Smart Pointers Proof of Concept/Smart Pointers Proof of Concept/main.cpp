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
    std::cout << std::endl;
    
    /*
        Now, let's define the HEAP.
     
        We use the heap if we need more room. It's slower, but more spacious.
     
        The heap is DYNAMICALLY ALLOCATED memory, meaning we get to choose when to use it, and when to release it.
     
        But that means that if we forget to release it, that's going to cause an issue. The memory will just be happily sitting there, set aside for our program, hogging resources that the rest of our computer could be using.
     
        In order to put things on the heap, we need to use pointers. Pointers are objects placed on the stack that simply reference a heap location by its hex address. They're how we work with the heap.
     
        Pointers can point to any location though, including stack locations.
        
     */
    
    // To illustrate what a pointer is, we will create a pointer to a string that's on the stack.
    std::string dinner = "Red Robin Clucks and Fries";
    std::string* pointerToDinner = &dinner;
    // Did we need to do this? Of course not! But let's print it anyway:
    std::cout << "Dinner: " << *pointerToDinner << std::endl;
    std::cout << "Stack address of dinner: " << pointerToDinner << std::endl;
    // And yeah, we can even see the address of a pointer:
    std::cout << "stack address of the pointer TO dinner: " << &pointerToDinner << std::endl;
    
    // Here's a raw pointer that actually points to a heap location. You have to take care of all the memory yourself.
    int* heapInt = new int(42);
    std::cout << "Value: " << *heapInt << std::endl;
    std::cout << "Address: " << heapInt << std::endl;
    delete heapInt;
    heapInt = nullptr;
    
    // Exhibit 2:
    int* ohLookARawArray = new int[100];
    // put some random crap in the array
    ohLookARawArray[0] = 67;
    ohLookARawArray[10] = 666;
    ohLookARawArray[87] = 69;
    ohLookARawArray[99] = 621;
    std::cout << "Item: " << ohLookARawArray[0] << std::endl;
    std::cout << "Item: " << ohLookARawArray[10] << std::endl;
    std::cout << "Item: " << ohLookARawArray[87] << std::endl;
    std::cout << "Item: " << ohLookARawArray[99] << std::endl;
    delete[] ohLookARawArray;
    ohLookARawArray = nullptr;
    
    // Here's a raw pointer to a class on the heap:
    Garden* pointerToMyGarden = new Garden();
    // We access the variables in this manner:
    std::cout << "Owner of the garden I just made: " << pointerToMyGarden->get_gardener() << std::endl;
    delete pointerToMyGarden;
    pointerToMyGarden = nullptr;
    // Fine to do it this way here, but it gets trickier in large programs.
    
    /*
        In order to eliminate some responsibility from ourselves to avoid double-deletion or forgetting to delete something, we now use smart pointers in modern C++. 
     */
    
    return EXIT_SUCCESS;
}
