//
//  main.cpp
//  Task3
//
// 12. Реализовать очередь с приоритетами на С++
//
//  Created by Сергей Павленок on 3/14/20.
//  Copyright © 2020 just_terror. All rights reserved.
//

#include <iostream>
#include "PriorityQueue.hpp"

int main(int argc, const char * argv[]) {
    PriorityQueue<int> queue;
    PriorityQueue<int> queue2;
    queue.add(5, 21321);
    queue.add(6, 32131);
    queue.add(1,321321);
    queue.add(6, 321);
    
    queue2.add(3,32131);
    queue2.add(2,321321);
    std::cout << "queue1:";
    queue.output();
    std::cout << "queue2:";
    queue2.output();
    queue.joinBQ(queue2);
    std::cout << "Getting max priority element: ";
    std::cout << queue.getMax() << "\n";
    std::cout << "queue1:";
    queue.output();
    std::cout << "queue2:";
    queue2.output();
    
    
    return 0;
}
