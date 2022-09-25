
#ifndef EL_ETERNO_DILEMA_DEL_LECTOR_MANEJO_DE_ARCHIVOS_H
#define EL_ETERNO_DILEMA_DEL_LECTOR_MANEJO_DE_ARCHIVOS_H
#include "Estructuras_y_Punteros.h"
//precondiciones:si el archivo de libros existe, debe tener una estructura correcta
// estructura: titulo,genero,puntaje
//postcondiciones: llena la biblioteca con los libros declarados en el archivo de libros
void llenar_biblioteca(Biblioteca &biblioteca);

//precondiciones: -
//postcondiciones: escribe los valores en memoria a un archivo de libros
void escribir_biblioteca_en_csv(Biblioteca biblioteca);

#endif //EL_ETERNO_DILEMA_DEL_LECTOR_MANEJO_DE_ARCHIVOS_H
