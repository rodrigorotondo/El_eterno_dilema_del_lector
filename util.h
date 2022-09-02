
#ifndef EL_ETERNO_DILEMA_DEL_LECTOR_UTIL_H
#define EL_ETERNO_DILEMA_DEL_LECTOR_UTIL_H
const int ERROR = -1;
const int VALOR_MINIMO_ACEPTADO = 1;
const int VALOR_MAXIMO_ACEPTADO = 8;



void mostrar_menu();
void obtener_opcion(int &opcion_elegida);
void es_opcion_valida(int opcion_elegida,bool &opcion_valida);

#endif //EL_ETERNO_DILEMA_DEL_LECTOR_UTIL_H
