#include "Cjt_Especies.hh"
#include "Cjt_Clusters.hh"
#include <iostream>
using namespace std;

Cjt_Especies::Cjt_Especies() {
     Mostra = map<string,Especie>();
}

void Cjt_Especies::crea_especie (string id, string gen, int k) {
    Especie esp(id,gen,k);
    Mostra.insert(make_pair(id, esp));
}

void Cjt_Especies::elimina_especie(string id) {
    Mostra.erase(id);
}

bool Cjt_Especies::existe_especie(string id) {
    map <string, Especie>::iterator it = Mostra.find(id);
    if (it == Mostra.end()) {
        Mostra.erase(id);
        return false;
    }
    else {
        return true;
    }
}
        
string Cjt_Especies::obtener_gen(string id) {
     map <string, Especie>::iterator it = Mostra.find(id);
     return it->second.obtener_gen();
}
    
//pre:l'especie ha d'existir
vector<string> Cjt_Especies::obtener_sub_gen(string id) {
    return Mostra[id].obtener_sub_gen();
}

void Cjt_Especies::eliminar_totes() {
    Mostra.clear();
}

void Cjt_Especies::imprime_cjt_especies() {
    for (map <string, Especie>::iterator it = Mostra.begin(); it != Mostra.end(); ++it) {
        cout << it->first << ' ' << it->second.obtener_gen() << endl;
    }
}
    
vector<string> Cjt_Especies::retorna_especies() {
    vector<string>  vec;
    for (map <string, Especie>::iterator it = Mostra.begin(); it != Mostra.end(); ++it) {
        vec.push_back(it->first);
    }
    return vec;
}
        
        

        
    
    
    
    
