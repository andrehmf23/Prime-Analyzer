#include "prime_analyzer.h"
#include <iomanip>
#include <sstream>

prime_analyzer::prime_analyzer(int initial, int last)
{
    search_set(initial, last);
    name = "Primes";
}

prime_analyzer::prime_analyzer(vector<int> data, string name)
{
    this->data = data;
    this->name = name;
}

prime_analyzer::~prime_analyzer()
{
}

// Encontra os números primos
void prime_analyzer::search_set(int initial, int last){
    bool is_prime;
    data.push_back(initial);
    for (size_t i = initial+1; i <= last; i++)
    {
        is_prime = true;
        for (size_t j = 0; j < data.size() && data[j] * data[j] <= i; j++)
        {
            if (i%data.at(j) == 0)
            {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            data.push_back(i);
        }
    }
}

// Mostra os números primos encontrados
void prime_analyzer::show(){
    cout << name << " : { ";
    for (size_t i = 0; i < data.size(); i++)
    {
        cout << data.at(i) << ' ';
    }
    cout << '}' << endl;
}

// Faz a soma de todo vetor, mostrando o número enquanto soma da esquerda para direita
void prime_analyzer::total(int max){
    if (!(0 < max && max < data.size())) max = data.size();
    int result = 0;
    cout << "Variacao total da soma dos " << name << " : { ";
    for (size_t i = 0; i < data.size(); i++)
    {
        result += data.at(i);
        if (i > 0) cout << " > ";
        cout << result;
    }
    cout << " }" << endl;
}

// Tira variação do número anterior eo próximo
prime_analyzer prime_analyzer::diference(string name){
    vector<int> v = data;
    for (size_t i = 0; i < v.size() - 1; i++)
    {
        v[i] = v[i+1] - v[i];
    }
    v.pop_back();
    return prime_analyzer(v, name);
}

// Verifica se o valor esta no primes
bool prime_analyzer::is_inside(int value){

    for (size_t i = 0; i < data.size(); i++)
    {
        if (data[i] == value) return true;
    }
    return false;
    
}

// Mostra os pulos assim como a aparição de cada primo em todos números
void prime_analyzer::show_jump(int max, int var){

    int analitic = 0; // Analiza o pulo
    bool select;

    cout << "_____Prime Number Appearance Frequency Analyzer_____" << endl;

    // Conta 10 vezes o número primo mais alto
    for (size_t i = data.front(); i <= max; i++)
    {
        select = false;
        // Analiza toda lista de números primos
        for (size_t j = 0; j < data.size(); j++)
        {
            if (i >= data[j]) {
                if (i == data[j]) {
                    ostringstream ss;
                    ss << "[" << i << "]";
                    cout << setw(5) << ss.str() << "<-";
                    analitic = 0;
                }
                else if (i%data[j] == 0) {
                    ostringstream ss;
                    ss << "[" << i << "]";
                    cout << setw(5) << ss.str();
                    select = true;
                }
                else {
                    cout << setw(4) << i << " ";
                }
            }
            else cout << setw(5) << " ";
        }
        if (select) analitic++;
        else if (i > data.back())
        {
            cout << "{" << analitic + var << "}";
            analitic = 0;
        }
        cout << endl;
    }
    cout << "____________________________________________________" << endl;
}

// Mostra os pulos assim como a aparição de cada primo em todos números
prime_analyzer prime_analyzer::collect_jump(int max, int var){

    int analitic = 0; // Analiza o pulo
    bool select;
    vector<int> v = {};

    // Conta 10 vezes o número primo mais alto
    for (size_t i = data.front(); i <= max; i++)
    {
        select = false;
        // Analiza toda lista de números primos
        for (size_t j = 0; j < data.size(); j++)
        {
            if (i >= data[j]) {
                if (i == data[j]) {
                    analitic = 0;
                }
                else if (i%data[j] == 0) {
                    select = true;
                }
            }
        }
        if (select) analitic++;
        else if (i > data.back())
        {
            v.push_back(analitic + var);
            analitic = 0;
        }
    }
    
    return prime_analyzer(v);
}