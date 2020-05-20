/** @file Taula_de_distancies.hh
    @brief Especificación de la clase Taula_de_distancies
*/

#ifndef TAULA_DE_DISTANCIES_HH
#define TAULA_DE_DISTANCIES_HH

#include "Cjt_Especies.hh"

#ifndef NO_DIAGRAM 
#include <map>
#include <string>
#endif
using namespace std;

/** @class Taula_de_distancies
    @brief Representa una Taula_de_distancies 


    Contiene un map con clave string i valor map. el segundo map tiene clave string i valor double que sirve para anotar la distancia entre especies
*/

class Taula_de_distancies {
    
    private:
        
    map <string, map <string, double>> Taula;
        
    public:
        
        //Constructores:
        
        /** @brief Creadora por defecto. 
            \pre <em>cierto</em>
            \post El resultado es una tabla de distancias vacía
        */  
        
        Taula_de_distancies();
        /* Pre: cert */
        /* Post: el resultado es un conjunto de especies vacío */
        
        //Destructores:
        
        //~Taula_de_distancies();
        
        //Modificadoras:
        
        /** @brief Modificadora de añadir una especie.
            \pre <em>cierto</em>
            \post El parámetro implícito pasa a contener una especie mas y mas distancias 
        */
        
        void afegeix_especie(string id, Cjt_Especies& Mostra);
        
        /** @brief Modificadora de eliminar una especie.
            \pre <em>L'especie ha d'existir</em>
            \post El parámetro implícito pasa a contener una especie menos y menos distancias
        */
        
        void eliminar_especie(string ID);
        
        //Consultores:
        
        /** @brief Consultora de distancia entre dos especies 
            \pre <em>cierto</em>
            \post El resultado es la distancia entre la primera especie y la segunda
        */
        
        double distancia(string ID1, string ID2);
        
        //Escribir:
        
        /** @brief Operación de escritura

            \pre <em>cierto</em>
            \post Escribe el contenido del parámetro implícito por el canal estándar de salida

        */
        
        void tabla_distancias();
        
         /** @brief Consultora de distancia entre los subgenes de dos especies 
            \pre <em>cierto</em>
            \post El resultado es la distancia entre la primera especie y la segunda

        */
        double obtener_distancia(vector<string>& e1, vector<string>& e2);
        
         /** @brief Modificadora de la taula.
            \pre <em>L'especie ha d'existir</em>
            \post El parámetro implícito pasa a estar vacío
        */
        
        void buidar_taula();
        
         /** @brief Consultora de las especies con menor distancia
            \pre <em>cierto</em>
            \post El resultado es un pair formado de dos strings que representan los id de las especies de menor distancia

        */
        pair<string,string> dist_min();
        
        /** @brief Modificadora de la taula.
            \pre <em>cierto</em>
            \post El parámetro implícito pasa tener una especie mas
        */
        void afegeix_especie_cluster(string id, pair<string,string>& id_minims);
        
};
#endif
        
