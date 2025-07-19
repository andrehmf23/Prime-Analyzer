
#ifndef PRIME_ANALYZER_H
#define PRIME_ANALYZER_H

#include <vector>
#include <iostream>

using namespace std;

class prime_analyzer
{
private:
    vector<int> data = {};
    string name;
public:
    prime_analyzer(int initial = 2, int last = __INT_MAX__);
    prime_analyzer(vector<int> v, string name = "Primes");
    ~prime_analyzer();
    void search_set(int initial, int last);
    prime_analyzer diference(string name);
    bool is_inside(int value);
    void show();
    void total(int max = 0);
    void show_jump(int max, int var = 0);
    prime_analyzer collect_jump(int max, int var = 0);

};

#endif
