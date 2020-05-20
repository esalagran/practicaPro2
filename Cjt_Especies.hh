/** @file Cjt_Especies.hh
    @brief Especificación de la clase Cjt_Especies
*/


#ifndef CJT_ESPECIES_HH
#define CJT_ESPECIES_HH

#include "Especie.hh"

#ifndef NO_DIAGRAM
#include <map>
#endif

/** @class Cjt_Especies
    @brief Representa una Cjt_Especies 

    Contiene un map formado por dos strings
*/

class Cjt_Especies {
    
    private:
        
        map <string, Especie> Mostra;
        
    public:
        
        //Constructores:
        
        /** @brief Creadora por defecto. 
            \pre <em>cierto</em>
            \post El resultado es un conjunto de especies vacío
        */ 
        
        Cjt_Especies();
        
        
        //Destructora

        //~Cjt_Especies();
        
        //Modificadores:
        
        /** @brief Modificadora de creación de especie 
            \pre <em>cierto</em>
            \post El resultado es una nueva especie en el map
        */  
        
        void crea_especie (string id, string gen, int k);
        /** @brief Modificadora de eliminación de especie 

            \pre <em>cierto</em>
            \post El resultado es la eliminación de una especie del conjunto de especies
        */  
       
        
         void elimina_especie (string id);
        
        
        //Consultores:
        
        /** @brief Consultora del especie
            \pre <em>cierto</em>
            \post El resultado es true si existe i false i no
        */
        
        bool existe_especie(string id);
        
         /** @brief Consultora del gen
            \pre <em>cierto</em>
            \post El resultado es el gen correspondiente al identificador dado
        */
        
        string obtener_gen(string id);
        
        /** @brief Consultora del sub_gen
            \pre <em>cierto</em>
            \post El resultado es el gen correspondiente al identificador dado
        */
        
        
        vector<string> obtener_sub_gen(string id);
        
        //Lectura i escriptura:
        
        /** @brief Operación de lectura

            \pre <em>cierto</em>
            \post Lee el contenido del parámetro implícito por el canal estándar de entrada
        */
        
        void eliminar_totes();
        
        /** @brief Operación de escriptura

            \pre <em>cierto</em>
            \post  Escribe el contenido del parámetro implícito por el canal estándar de salida

        */
        void imprime_cjt_especies();
        
        /** @brief Consultora del id del cjt_especies
            \pre <em>cierto</em>
            \post El resultado es un vector con los id de las especies
        */
        
        vector<string> retorna_especies();
};
#endif
        
        
        
        
    


