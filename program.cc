/**
 * @mainpage Práctica PRO2
 */

/** @file program.cc
    @brief Programa principal para el ejercicio <em>Practica PRO2.Primavera 2020</em>.
*/


#include "Cjt_Clusters.hh"
                
#ifndef NO_DIAGRAM
#include <iostream>
#endif

using namespace std;

void crea_especie (int k, Cjt_Especies& Mostra,Taula_de_distancies& Taula, string ID, string gen) {
    bool creado = Mostra.existe_especie(ID);
    if (creado) {
        cout << "ERROR: La especie " << ID << " ya existe." << endl;
    }
    else {
        Mostra.crea_especie(ID, gen, k);
        Taula.afegeix_especie(ID, Mostra);
    }
}

int main () {
    int k;
    cin >> k;
    Cjt_Especies Mostra;
    Cjt_Clusters Arbre;
    Taula_de_distancies Taula;
    string ordre;
    cin >> ordre;
    while (ordre != "fin") {
        if (ordre == "crea_especie") {
            string ID, gen;
            cin >> ID >> gen;
            cout << "# " << ordre <<" " << ID << " " << gen << endl;
            crea_especie(k, Mostra, Taula, ID, gen);
        }
        else if (ordre == "obtener_gen") {
            string ID;
            cin >> ID;
            cout << "# " << ordre << " " << ID << endl;
            bool existe = Mostra.existe_especie(ID);
            if (existe) {
                string gen;
                gen = Mostra.obtener_gen(ID);
                cout << gen << endl;
            }
            else cout << "ERROR: La especie " << ID << " no existe." << endl;
        }
        else if (ordre == "distancia") {
            string ID1, ID2;
            cin >> ID1 >> ID2;
            cout << "# " << ordre << " " << ID1 << " " << ID2 << endl;
            bool e1_existe = Mostra.existe_especie(ID1);
            bool e2_existe = Mostra.existe_especie(ID2);
            if (e1_existe and e2_existe) {
                double dist;
                dist = Taula.distancia(ID1,ID2); 
                cout << dist << endl;
            }
            else if (not e1_existe and e2_existe) {
                cout << "ERROR: La especie " << ID1 << " no existe." << endl;
            }
            else if (e1_existe and not e2_existe) cout << "ERROR: La especie " << ID2 << " no existe." << endl;
            else cout << "ERROR: La especie " << ID1 << " y la especie " << ID2 << " no existen." << endl;
        }
        
        else if (ordre == "elimina_especie") {
            string ID;
            cin >> ID;
            cout << "# " << ordre << " " << ID << endl;
            bool eliminado = Mostra.existe_especie(ID);
            if (eliminado) {
                Taula.eliminar_especie(ID);
                Mostra.elimina_especie(ID);
            }
            else cout << "ERROR: La especie " << ID << " no existe." << endl;
        }
        else if (ordre == "existe_especie") {
            string ID;
            cin >> ID;
            cout << "# " << ordre << ' ' << ID << endl;
            bool exist = Mostra.existe_especie(ID);
            if (exist) {
                cout << "SI" << endl;
            }
            else cout << "NO" << endl;
        }
        else if (ordre == "lee_cjt_especies") {
            int n;
            cin >> n;
            cout << "# " << ordre << endl;
            Mostra.eliminar_totes();
            Taula.buidar_taula();
            for (int i = 0; i < n; ++i) {
                string ID, gen;
                cin >> ID >> gen;
                crea_especie(k, Mostra, Taula, ID, gen);
            }
        }
        else if (ordre == "imprime_cjt_especies") {
            cout << "# " << ordre << endl;
            Mostra.imprime_cjt_especies();
        }
        else if (ordre == "tabla_distancias") {
            cout << "# " << ordre << endl;
            Taula_de_distancies taula_aux = Taula;
            taula_aux.tabla_distancias();
        }
        else if (ordre == "inicializa_clusters") {
            cout << "# " << ordre << endl;
            Taula_de_distancies taula_aux = Taula;
            Arbre.inicializa_clusters(Mostra, Taula);
            taula_aux.tabla_distancias();
        }
        else if (ordre == "ejecuta_paso_wpgma") {
            cout << "# " << ordre << endl;
            int num_c = Arbre.numero_clusters();
            if (num_c > 2) {
                Arbre.ejecutar_paso_wpgma();
                Arbre.taula_clusters_imprime();
            }
            else cout << "ERROR: num_clusters <= 1" << endl;
        }
        else if (ordre == "imprime_cluster") {
            string id;
            cin >> id;
            cout << "# " << ordre << " " << id << endl;
            if (Arbre.existe_cluster(id)) {
                BinTree<pair<string,double>> aux = Arbre.retorna_subarb(id);
                Arbre.imprime_cluster_aux(aux);
            }
            else cout << "ERROR: El cluster " << id << " no existe." << endl;
        }
        else if (ordre == "imprime_arbol_filogenetico") {
            cout << "# " << ordre << endl;
            Arbre.inicializa_clusters(Mostra, Taula);
            int num_c = Arbre.numero_clusters();
            if (num_c > 0) {
                while (num_c > 1) {
                    Arbre.ejecutar_paso_wpgma();
                    num_c = Arbre.numero_clusters();
                }
                Arbre.imprime_arbol_filogenetico();
            }
            else cout << "ERROR: El conjunto de clusters es vacio." << endl;
        }
        cin >> ordre;
        cout << endl;
    }
}
