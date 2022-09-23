

#ifndef EL_ETERNO_DILEMA_DEL_LECTOR_CONSTANTES_H
#define EL_ETERNO_DILEMA_DEL_LECTOR_CONSTANTES_H
#include <string>

using namespace std;
const int CANTIDAD_MAXIMA_DE_LIBROS_INICIAL = 10;

const int ERROR = -1;
const int EL_LIBRO_NO_EXISTE = -1;

const int VALOR_MINIMO_ACEPTADO = 1;
const int VALOR_MAXIMO_ACEPTADO = 8;

const char GENERO_AVENTURA = 'A';
const char GENERO_CIENCIA_FICCION = 'C';
const char GENERO_DIDACTICA = 'D';
const char GENERO_POLICIACA = 'P';
const char GENERO_ROMANCE = 'R';
const char GENERO_TERROR = 'T';
const int CANTIDAD_DE_GENEROS = 6;
const int PUNTAJE_MINIMO = 0;
const int PUNTAJE_MAXIMO = 100;
const char ERROR_GENERO = 'E';

const int INDICE_AVENTURA = 0;
const int INDICE_CIENCIA_FICCION = 1;
const int INDICE_DIDACTICA = 2;
const int INDICE_POLICIACA = 3;
const int INDICE_ROMANCE = 4;
const int INDICE_TERROR = 5;


const int LISTAR_LIBROS = 1;
const int AGREGAR_LIBRO = 2;
const int EDITAR_PUNTAJE = 3;
const int MOSTRAR_LIBRO_FAVORITO = 4;
const int MOSTRAR_LIBROS_CON_MENOR_PUNTAJE = 5;
const int MOSTRAR_GENERO_MAS_LEIDO = 6;
const int MOSTRAR_GENERO_FAVORITO = 7;
const int GUARDAR_Y_SALIR = 8;

const string PATH = "libros.csv";

#endif //EL_ETERNO_DILEMA_DEL_LECTOR_CONSTANTES_H
