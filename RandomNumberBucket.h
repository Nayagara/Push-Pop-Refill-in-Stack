#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <vector>
using namespace std;

class RandomNumberBucket {
public:
    RandomNumberBucket();
    RandomNumberBucket(int range);
    int pop(); // return -1 if empty
    void refill();
    int size(); // Number of elements left
    bool empty(); // whether empty or not
    int popWithRefill();
    vector<int> picked_numbers;
private:
    vector<int> bucket; 
    int current_max;
    
};


