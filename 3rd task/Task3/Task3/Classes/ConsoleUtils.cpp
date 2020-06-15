//
//  ConsoleUtils.cpp
//  Task3
//
//  Created by Сергей Павленок on 4/4/20.
//  Copyright © 2020 just_terror. All rights reserved.
//

#include "ConsoleUtils.hpp"

PriorityQueue<int> CreateIntPriorityQueue()
{
    PriorityQueue<int> *newPriorityQueue = new PriorityQueue<int>();
    std::cout << "Целочисленная очередь с приоритетами создана";
    return *newPriorityQueue;
}

PriorityQueue<std::string> CreateStringPriorityQueue()
{
    PriorityQueue<std::string> *newPriorityQueue = new PriorityQueue<std::string>();
    std::cout << "Строковая очередь с приоритетами создана";
    return *newPriorityQueue;
}

