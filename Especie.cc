#include "Especie.hh"
#include <vector>
#include <algorithm>
using namespace std;

Especie::Especie(string id, string gen, int k) {
    this->id = id;
    this->gen = gen;
    Sub_gen = partir_gen(k);
}

Especie::Especie(){}

vector<string> Especie::partir_gen(int k) {
    string copiargen = gen;
    vector<string> v(copiargen.size()+1-k);
        for (int i = 0; i <v.size(); ++i) {
            for (int j = 0; j < k; ++j) {
                v[i]+=copiargen[j];
            }
            copiargen.erase(copiargen.begin());
        }
        sort(v.begin(), v.end());
        return v;
}

vector<string> Especie::obtener_sub_gen() {
    return Sub_gen;
}

string Especie::obtener_gen() {
    return gen;
}
        
