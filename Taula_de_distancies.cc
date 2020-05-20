#include "Taula_de_distancies.hh"
#include "Cjt_Especies.hh"
#include <iostream>
using namespace std;

Taula_de_distancies::Taula_de_distancies() {
    Taula = map<string,map<string,double>>();
}

double Taula_de_distancies::obtener_distancia(vector<string>& e1, vector<string>& e2) {
    double inter = 0, uni = 0, distancia = 0;
    int i = 0, j = 0;
    while (i < e1.size() and j < e2.size()) {
        if (e1[i] == e2[j]) {
            ++inter;
            ++i;
            ++j;
        }
        else if (e1[i] > e2[j]) {
            ++j;
        }
        else ++i;
    }
    uni = e1.size()+e2.size()-inter;
    distancia = (1-(inter/uni))*100;
    return distancia;
}


void Taula_de_distancies::afegeix_especie(string ID, Cjt_Especies& Mostra) {
    vector<string> e1_sub_gen = Mostra.obtener_sub_gen(ID);
    map<string,double> noves_distancies;
    for (map<string, map<string, double>>::iterator it1 = Taula.begin(); it1 != Taula.end(); ++it1) {
        vector<string> e2_sub_gen = Mostra.obtener_sub_gen(it1->first);
        double dist = obtener_distancia(e1_sub_gen, e2_sub_gen);
        it1->second.insert(make_pair(ID, dist));
        noves_distancies.insert(make_pair(it1->first,dist));
    }
    Taula.insert(make_pair(ID,noves_distancies));
}


//Pre:L'especie ha d'existir i s'ha d'eliminar
void Taula_de_distancies::eliminar_especie(string ID) {
    Taula.erase(ID);
    for (map<string,map<string,double>>::iterator it = Taula.begin(); it != Taula.end(); ++it) {
        it->second.erase(ID);
    }
}


double Taula_de_distancies::distancia(string ID1, string ID2) {
    map<string,map<string,double>>::iterator it1 = Taula.find(ID1);
    //if (it1 == Taula.end()) cout << "ID1" << ID1 << endl;
    map<string,double>::iterator it2 = it1->second.find(ID2);
    //if (it1->second.end() == it2) cout << "ID2 " << ID2 << endl;
    return it2->second;
}

void Taula_de_distancies::tabla_distancias() {
    for (map <string, map<string,double>>::const_iterator it1 = Taula.begin(); it1 != Taula.end(); ++it1) {
        cout << it1->first << ":";
        for (map<string,double>::const_iterator it2 = it1->second.begin(); it2 != it1->second.end(); ++it2) {
            if (it2->first > it1->first) {
                cout << ' ' << it2->first << " (" << it2->second << ")";
            }
        }
        cout << endl;
    }
}


void Taula_de_distancies::buidar_taula() {
    Taula.clear();
}



pair<string,string> Taula_de_distancies::dist_min() {
    double min = 101;
    pair<string, string> minim_noms;
    int numEspecies = Taula.size();
    map <string, map<string,double>>::const_iterator it1 = Taula.begin();
    for (int i = 0; i < numEspecies and it1 != Taula.end(); ++i) {
  		map<string,double>::const_iterator it2 = it1->second.begin();
  		for(int j = 0; j < i and it2 != it1->second.end(); ++j){
  			if (it2->second < min) {
                  min = it2->second;
                  if (it1->first < it2->first ){  
					minim_noms.first = it1->first;
					minim_noms.second = it2->first;
                  }
                  else {
					  minim_noms.first = it2->first;
					minim_noms.second = it1->first;
				  }
			}
              ++it2;
  		}
  		++it1;
    }
    return minim_noms;
}

void Taula_de_distancies::afegeix_especie_cluster(string nou_cluster, pair<string,string>& id_minims) {
    map<string,double> nou_clust;
    
   for (map <string, map<string,double>>::iterator it1 = Taula.begin(); it1 != Taula.end(); ++it1) {
       if (it1->first != id_minims.first and it1->first != id_minims.second) {
            double dist = ((distancia(id_minims.first,it1->first)+distancia(id_minims.second,it1->first))/2);
            it1->second.insert(make_pair(nou_cluster, dist));
            nou_clust.insert(make_pair(it1->first, dist));
       }
    }
    Taula.insert(make_pair(nou_cluster,nou_clust));
}
