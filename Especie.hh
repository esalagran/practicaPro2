/** @file Especie.hh
    @brief Especificación de la clase Especie
*/

#ifndef ESPECIE_HH
#define ESPECIE_HH

#ifndef NO_DIAGRAM 
#include <string>
#include <vector>
#endif
using namespace std;

/** @class Especie
    @brief Representa una especie. 

    Contiene dos strings no vacios, el primero representa el identificador de la especie y el segundo es el gen
*/

class Especie {
    
    private:
        
        string id;
        string gen;
        vector<string> Sub_gen;
        
    public:
        
        //Constructores:
        
        /** @brief Creadora por defecto. 
            \pre <em>cierto</em>
            \post El resultado es una especie con id = id, gen = gen y con el Sub_gen         
        */  
        Especie();
    
        Especie(string id, string gen, int k);
        
        /** @brief Creadora de Sub_gen. 
            \pre <em>cierto</em>
            \post El resultado es el gen partido en particiones de k
        */  
        
        vector<string>partir_gen(int k);
        
        /** @brief Consultora del sub_gen

            \pre <em>cierto</em>
            \post retorna un vector con el subgen dividido en divisiones de k
        */
        
        vector<string>obtener_sub_gen();
        /** @brief Consultora del gen

            \pre <em>cierto</em>
            \post retorna un string que contiene el gen
        */
        
        string obtener_gen();
};
#endif
        
        
        
        
    
