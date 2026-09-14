#include <stdio.h>

struct Proceso {
    int pid;
    char nombre[20];
    int prioridad; // 1 (alta) a 5 (baja)
};

int main() {
    struct Proceso procesos[5];

    printf("=== Registro de Procesos (Hasta 5) ===\n\n");

    for (int i = 0; i < 5; i++) {
        printf("--- Proceso %d ---\n", i + 1);
        
        printf("Ingrese PID: ");
        scanf("%d", &procesos[i].pid);

        printf("Ingrese Nombre: ");
        scanf("%19s", procesos[i].nombre);

        printf("Ingrese Prioridad (1-5): ");
        scanf("%d", &procesos[i].prioridad);

        printf("\n");
    }

    // Mostrar resumen de los procesos registrados
    printf("\n=== Resumen de Procesos Registrados ===\n");
    for (int i = 0; i < 5; i++) {
        printf("[%d] PID: %d | Nombre: %s | Prioridad: %d\n", 
               i + 1, procesos[i].pid, procesos[i].nombre, procesos[i].prioridad);
    }

    return 0;
}
