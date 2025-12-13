//
//  Texture.hpp
//  Smart Pointers Proof of Concept
//
//  Created by Alex Neville on 12/12/25.
//

#ifndef Texture_hpp
#define Texture_hpp

#include <stdio.h>
#include <iostream>

class Texture
{
public:
    Texture(std::string filePath);
    
private:
    std::string filePath;
};

#endif /* Texture_hpp */
