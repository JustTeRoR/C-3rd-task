//
//  PriorityQueue.hpp
//  Task3
//
//  Created by Сергей Павленок on 3/14/20.
//  Copyright © 2020 just_terror. All rights reserved.
//

#ifndef PriorityQueue_hpp
#define PriorityQueue_hpp

#include <iostream>

const int SIZE = 31;

template<class T>
class Node
{
public:
    T data_;
    int priority_;
    Node<T> *left;
    Node<T> *right;
    Node(){}
    Node(int priority, T value)
    {
        priority_ = priority;
        data_ = value;
        left = 0;
        right = 0;
    }
    Node(const Node<T> &n)
    {
        priority_ = n.priority_;
        data_ = n.data_;
        Node<T> *l = 0, *r = 0;
        if (n.left) l = new Node<T>(*n.left);
        if (n.right) r = new Node<T>(*n.right);
        left = l;
        right = r;
    }
    ~Node() {
        if (left)
        {
            delete left;
            left = 0;
        }
        if (right)
        {
            delete right;
            right = 0;
        }
    }
};

template<class T>
class PriorityQueue
{
public:
    Node<T> *arr[SIZE];
    int size;
    PriorityQueue() { memset(arr,0,sizeof(arr)); size = 0; }
    PriorityQueue(const PriorityQueue &pq)
    {
        memset(arr,0,sizeof(arr));
        size = pq.size;
        for (int i=0;i<SIZE;i++) {
            if (pq.arr[i]) {
                Node<T> *deepCopy = new Node<T>(*pq.arr[i]);
                arr[i] = deepCopy;
            }
        }
    }
    ~PriorityQueue() {
        for (int i=0;i<SIZE;++i)
        {
            if (arr[i])
                delete arr[i];
        }
    }
    void clear()
    {
        memset( arr, 0, sizeof(arr));
        size = 0;
    }
    void read() {
        int n,val;
        scanf("%d",&n);
        for (int i=0;i<n;i++) {
            scanf("%d", &val);
            add(val);
        }
    }
    void output() {
        PriorityQueue pq = *this;
        while (!pq.empty())
            std::cout << " " << pq.getMax() << " ";
        std::cout << "\n";
    }
    bool empty()
    {
        return size == 0;
    }
    Node<T>* join(Node<T>* f, Node<T> *s)
    {
        if (f->priority_ > s->priority_)
        {
            s->right = f->left; f->left = s; return f;
        }
        else
        {
            f->right = s->left; s->left = f; return s;
        }
    }
    int num(int c, int b, int a)
    {
        return 4*c + 2*b + a;
    }
    void joinBQ(Node<T>* a[], Node<T>* b[])
    {
        Node<T>* c = 0;
        for (int i=0;i<SIZE;i++) {
            switch(num(c!=0,b[i]!=0,a[i]!=0)) {
                case 2: a[i] = b[i]; break;
                case 3: c = join(a[i],b[i]); a[i] = 0; break;
                case 4: a[i] = c; c = 0; break;
                case 5: c = join(a[i],c); a[i] = 0; break;
                case 6:
                case 7: c = join(b[i],c); break;
            }
        }
    }
    
    void joinBQ(PriorityQueue &pq)
    {
        joinBQ(arr, pq.arr);
        size += pq.size;
        pq.clear();
    }
    
    void add(int priority, T nodeValue)
    {
        Node<T>* newNode = new Node<T>(priority, nodeValue);
        Node<T>* curNode = newNode;
        for (int i=0; i<SIZE; i++)
        {
            if (arr[i] == NULL)
            {
                arr[i] = curNode;
                break;
            }
            else
            {
                curNode = join(curNode,arr[i]);
                arr[i] = NULL;
            }
        }
        size++;
    }

    //TODO:: Вообще тут должно быть нормальное возвращаемое значения тк это ключевой метод структуры данных, но для теста сделана строка
    std::string getMax() {
        int res = 0;
        Node<T> *resultNode = nullptr;
        int resPos = -1;
        for (int i=0;i<SIZE;i++) {
            if (arr[i] && arr[i]->priority_ > res)
            {
                resultNode = arr[i];
                resPos = i;
            }
        }
        Node<T>** tmp = new Node<T>*[SIZE];
        memset(tmp,0,sizeof(tmp)*SIZE);
        Node<T>* cur = arr[resPos]->left;
        for (int i=resPos-1;i>=0;i--)
        {
            tmp[i] = new Node<T>(*cur);
            cur = cur->right;
            tmp[i]->right = 0;
        }
        delete arr[resPos];
        arr[resPos] = 0;

        joinBQ(arr, tmp);
        delete[] tmp;
        size--;
        std::string result = std::to_string(resultNode->data_) + "(" + std::to_string(resultNode->priority_) + ")";
    
        return  result;
    }
};
#endif /* PriorityQueue_hpp */
