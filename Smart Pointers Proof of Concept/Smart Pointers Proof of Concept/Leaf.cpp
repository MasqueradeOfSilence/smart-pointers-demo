//
//  Leaf.cpp
//  Smart Pointers Proof of Concept
//
//  Created by Alex Neville on 12/12/25.
//

#include "Leaf.hpp"
#include <iostream>

Leaf::Leaf()
{
    std::cout << "Leaf created" << std::endl;
}

void Leaf::assign_texture(std::shared_ptr<Texture> texture)
{
    this->texture = texture;
}
