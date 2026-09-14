#include <stdio.h>

#define MAX_PROCESOS 5
struct Proceso {
    int pid;
    char nombre[20];
    int prioridad; // 1 (alta) a 5 (baja)
};

// Parte C: Función que recibe el arreglo mediante puntero
// Retorna el índice del proceso de mayor prioridad (valor numérico más bajo)
int buscarMayorPrioridad(struct Proceso *procesos, int n) {
    int idx_mayor_prioridad = 0;

    for (int i = 1; i < n; i++) {
        // Acceso usando punteros: (procesos + i)->prioridad o procesos[i].prioridad
        if ((procesos + i)->prioridad < (procesos + idx_mayor_prioridad)->prioridad) {
            idx_mayor_prioridad = i;
        }
    }

    return idx_mayor_prioridad;
}

printf("=========================================\n");
printf("  SISTEMA PLANIFICADOR DE PROCESOS (SO)  \n");
printf("=========================================\n\n");
int main() {
    struct Proceso procesos[MAX_PROCESOS];
    int n = 5;

    // Parte B: Registro de procesos
    for (int i = 0; i < n; i++) {
        printf("--- Proceso %d ---\n", i + 1);
        printf("PID: ");
        scanf("%d", &procesos[i].pid);

        printf("Nombre: ");
        scanf("%19s", procesos[i].nombre);

        printf("Prioridad (1-5): ");
        scanf("%d", &procesos[i].prioridad);
        while (getchar() != '\n');
        printf("\n");
    }

    // Parte C: Búsqueda del proceso de mayor prioridad
    int idx = buscarMayorPrioridad(procesos, n);

    // Parte D: Presentación de resultados
    printf("-----------------------------------------\n");
    printf("   PROCESO SELECCIONADO (MAYOR PRIORIDAD) \n");
    printf("-----------------------------------------\n");
    printf("PID       : %d\n", procesos[idx].pid);
    printf("Nombre    : %s\n", procesos[idx].nombre);
    printf("Prioridad : %d\n", procesos[idx].prioridad);
    printf("-----------------------------------------\n");

    return 0;
}
