#include "RandomNumberBucket.h"

RandomNumberBucket::RandomNumberBucket(){
    for(int i = 1; i < 40; ++i){
        bucket.push_back(i);
    }
}
RandomNumberBucket::RandomNumberBucket(int N){
    for(int i = 1; i < N; ++i){
        bucket.push_back(i);
    }
}
int RandomNumberBucket::pop(){
    srandom (time (0));

    if (bucket.size() == 0) {
        return -1;
    } else {
        int random_index = random() % bucket.size();
        int random_number = bucket[random_index];
        bucket.erase (bucket.begin() + random_index);
        picked_numbers.push_back(random_number);
        return random_number;
    }
}
void RandomNumberBucket::refill(){
    for(int i = 0; i < picked_numbers.size(); ++i){
        bucket.push_back(picked_numbers[i]);
    }
    picked_numbers.clear();
}
int RandomNumberBucket::size(){
    return bucket.size();
}
bool RandomNumberBucket::empty(){
    return (bucket.size() == 0);
}

int RandomNumberBucket::popWithRefill(){
    if(empty()){
        refill();
    }
    return pop();
}

// ======================= TEST CODE =================================

/*void test(RandomNumberBucket & rb){
    int test_num = 100;
    bool test_array[test_num];
    for(int i = 0; i < test_num; ++i){
        test_array[i] = false;
    }
    for(int i = 0; i < test_num; i++){
        int random_number = rb.pop();
        if(test_array[random_number] == true){
            cout << "error" << endl;
            return;
        }
        cout << "random number chosen = " << random_number << endl;
        test_array[random_number] = true;
    }
    cout << "after gen bucket size = " << rb.size() << endl;
    cout << "after gen picked_numbers size " << rb.picked_numbers.size() << endl;
    rb.popWithRefill();
    cout << "after refill bucket size = " << rb.size() << endl;
    cout << "after refill picked_numbers size " << rb.picked_numbers.size() << endl;   
    
    cout << " *******************************************" << endl;
}
int main()
{
    srandom (time (0));

    RandomNumberBucket rb(100);
    
        test(rb);
    

    return 0;
}*/
