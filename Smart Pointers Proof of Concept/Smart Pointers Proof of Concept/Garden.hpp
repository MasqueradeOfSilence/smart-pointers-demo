//
//  Garden.hpp
//  Smart Pointers Proof of Concept
//
//  Created by Alex Neville on 12/10/25.
//

#ifndef Garden_hpp
#define Garden_hpp

#include <stdio.h>
#include <string>

class Garden
{
public:
    
    Garden();
    Garden(std::string name);
    void display_info();
    
private:
    std::string gardenerName;
};

#endif /* Garden_hpp */
