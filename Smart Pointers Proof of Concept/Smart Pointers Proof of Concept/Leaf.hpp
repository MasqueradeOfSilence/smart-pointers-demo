//
//  Leaf.hpp
//  Smart Pointers Proof of Concept
//
//  Created by Alex Neville on 12/12/25.
//

#ifndef Leaf_hpp
#define Leaf_hpp

#include <stdio.h>
#include <iostream>
#include "Texture.hpp"

class Leaf
{
public:
    Leaf();
    void assign_texture(std::shared_ptr<Texture> texture);
    
private:
    std::shared_ptr<Texture> texture;
};

#endif /* Leaf_hpp */
