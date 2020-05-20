/** @file Cjt_Clusters.hh
    @brief Especificación de la clase Cjt_Clusters
*/

#ifndef CJT_CLUSTERS_HH
#define CJT_CLUSTERS_HH

#include "Taula_de_distancies.hh"
#include "Cjt_Especies.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <map>
#endif

/** @class Cjt_Clusters
    @brief Representa una Cjt_Clusters 

    Contiene un BinTree formado por el Cjt_Especies
*/

class Cjt_Clusters {
    
    private:
        
        map<string, BinTree< pair<string, double>>> Arbre;
        Taula_de_distancies Taula_Clusters;
        
    public:
        
        //Constructores:
        
        /** @brief Creadora por defecto.
            \pre <em>cierto</em>
            \post El resultado es un conjunto de clusters vacío
        */  
        
        Cjt_Clusters();
        
        //Modificadores:
        
        /** @brief Modificadora de inicializa el clúster. 
            \pre <em>cierto</em>
            \post Inicializa el conjunto de clúsers con el conjunto de especies end el estado en el que esté en ese momento e imprime los clústers resultantes, así como la tabla de distancias
        */  
        void inicializa_clusters(Cjt_Especies& Mostra, Taula_de_distancies& Taula);
        
        /** @brief Modificadora de ejecutar paso wpgma.
            \pre <em>cierto</em>
            \post El resultado es la creación de un nuevo cluster con las distancias calculadas y la eliminación de los clusters con distancia mas pequeña
        */ 
        
        void ejecutar_paso_wpgma ();
        
        
        //Escriure:
        
        /** @brief Operación de escritura

            \pre <em>cierto</em>
            \post Escribe el contenido del parámetro implícito por el canal estándar de salida
        */
    
        void imprime_cluster(BinTree<pair<string,double>> arbre);
        
        /** @brief Operación de escritura
            \pre <em>cierto</em>
            \post llama a la función imprime_cluster y hace un salto de linea
        */ 
        
        void imprime_cluster_aux (BinTree<pair<string,double>>& arbre);
        
        /** @brief Operación de escritura

            \pre <em>cierto</em>
            \post Escribe el contenido del parámetro implícito por el canal estándar de salida
        */
    
        
        void imprime_arbol_filogenetico();
        
        /** @brief Operación de escritura

            \pre <em>cierto</em>
            \post Escribe el contenido del parámetro implícito por el canal estándar de salida
        */
        void taula_clusters_imprime();
        
        /** @brief Consultora existencia de cluster

            \pre <em>cierto</em>
            \post retorna true si existe y false si no
        */
        
        
        
        bool existe_cluster(string id);
        
        /** @brief Consultora del tamaño del conjunto de clusters

            \pre <em>cierto</em>
            \post retorna un int con el tamaño del conjunto de clusters
        */
        
        int numero_clusters();
        
         /** @brief Consultora del clusters

            \pre <em>cierto</em>
            \post retorna el BinTree donde se encuentra el string que entra
        */
        
        BinTree<pair<string,double>> retorna_subarb(string id);
};
#endif
        
    
