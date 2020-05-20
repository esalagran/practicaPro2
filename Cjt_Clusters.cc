#include "Cjt_Clusters.hh"
#include "Taula_de_distancies.hh"
#include <iostream>
using namespace std;

Cjt_Clusters::Cjt_Clusters() {
    Arbre =  map<string, BinTree< pair<string, double>>>();
}

void Cjt_Clusters::ejecutar_paso_wpgma() {
    pair<string,string> id_minims = Taula_Clusters.dist_min();
    string nou_cluster = id_minims.first + id_minims.second;
    Taula_Clusters.afegeix_especie_cluster(nou_cluster, id_minims);
    
    
    double distancia_cluster = Taula_Clusters.distancia(id_minims.first,id_minims.second)/2;
    Taula_Clusters.eliminar_especie(id_minims.first);
    Taula_Clusters.eliminar_especie(id_minims.second);
    
    pair<string, double> nou_clu;
    nou_clu.first = nou_cluster;
    nou_clu.second = distancia_cluster;
    
    map<string, BinTree< pair<string, double>>>::iterator it1 = Arbre.find(id_minims.first);
    BinTree<pair<string,double>> clu_left = it1->second;
    map<string, BinTree< pair<string, double>>>::iterator it2 = Arbre.find(id_minims.second);
    BinTree<pair<string,double>> clu_righ = it2->second;
    BinTree<pair<string,double>> arbre_nou(nou_clu,clu_left,clu_righ);
    
    Arbre.insert(make_pair(nou_cluster,arbre_nou));
    Arbre.erase(id_minims.first);
    Arbre.erase(id_minims.second);
}

void Cjt_Clusters::imprime_cluster(BinTree<pair<string,double>> arbre) {
    if (not arbre.empty()) {
        cout <<"[";
        if (arbre.value().second != 0) {
            cout << "(" << arbre.value().first << ", " << arbre.value().second << ") ";
            imprime_cluster(arbre.left());
            imprime_cluster(arbre.right());
        }
        else {
            cout << arbre.value().first;
        }
        cout << "]";
    }
}

void Cjt_Clusters::imprime_cluster_aux(BinTree<pair<string,double>>& arb) {
    imprime_cluster(arb);
    cout << endl;
}

bool Cjt_Clusters::existe_cluster(string id) {
    map <string, BinTree<pair<string,double>>>::iterator it = Arbre.find(id);
    if (it == Arbre.end()) {
        Arbre.erase(id);
        return false;
    }
    else {
        return true;
    }
}

int Cjt_Clusters::numero_clusters() {
    return Arbre.size();
}


void Cjt_Clusters::imprime_arbol_filogenetico() {
    for (map <string, BinTree<pair<string,double>>>::const_iterator it = Arbre.begin(); it != Arbre.end(); ++it) {
        imprime_cluster(it->second);
    }
    cout << endl;
}

void Cjt_Clusters::inicializa_clusters(Cjt_Especies& Mostra, Taula_de_distancies& Taula) {
    Arbre.clear();
    vector<string> vec = Mostra.retorna_especies();
    Taula_Clusters = Taula;
    for (int i = 0; i < vec.size(); ++i) {
        pair<string, double> p;
        p.first = vec[i];
        p.second = 0;
        BinTree<pair<string, double>> arb(p);
        Arbre.insert(make_pair(vec[i], arb));
    }
}

void Cjt_Clusters::taula_clusters_imprime() {
    Taula_Clusters.tabla_distancias();
}

BinTree<pair<string,double>> Cjt_Clusters::retorna_subarb(string id) {
    map<string,BinTree<pair<string,double>>>::const_iterator it = Arbre.find(id);
    return it->second;
}
    
    
    
    
