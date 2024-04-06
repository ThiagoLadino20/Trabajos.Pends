#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Data {
    int value;
    int priority;
};

void displayData(const queue<Data>& q) {
    queue<Data> temp = q;
    while (!temp.empty()) {
        cout << "Dato: " << temp.front().value << " | Prioridad: " << temp.front().priority << endl;
        temp.pop();
    }
}

int main() {
    queue<Data> queue_priority1;
    queue<Data> queue_priority2;
    queue<Data> queue_priority3;
    stack<Data> stack_data;

    int option;
    do {
        cout << "\n1. Insertar dato\n";
        cout << "2. Eliminar dato\n";
        cout << "3. Ver datos ingresados\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> option;

        switch (option) {
            case 1: {
                int value, priority;
                cout << "Ingrese el dato: ";
                cin >> value;
                cout << "Ingrese el nivel de prioridad (1, 2 o 3): ";
                cin >> priority;

                Data data;
                data.value = value;
                data.priority = priority;

                switch (priority) {
                    case 1:
                        queue_priority1.push(data);
                        break;
                    case 2:
                        queue_priority2.push(data);
                        break;
                    case 3:
                        queue_priority3.push(data);
                        break;
                    default:
                        cout << "Prioridad inválida. Intente nuevamente.\n";
                        break;
                }

                break;
            }
            case 2: {
                if (!queue_priority1.empty()) {
                    cout << "Dato eliminado con prioridad 1: " << queue_priority1.front().value << endl;
                    queue_priority1.pop();
                } else if (!queue_priority2.empty()) {
                    cout << "Dato eliminado con prioridad 2: " << queue_priority2.front().value << endl;
                    queue_priority2.pop();
                } else if (!queue_priority3.empty()) {
                    cout << "Dato eliminado con prioridad 3: " << queue_priority3.front().value << endl;
                    queue_priority3.pop();
                } else {
                    cout << "No hay datos para eliminar.\n";
                }

                break;
            }
            case 3: {
                cout << "\nDatos ingresados con prioridad 1:\n";
                displayData(queue_priority1);
                cout << "\nDatos ingresados con prioridad 2:\n";
                displayData(queue_priority2);
                cout << "\nDatos ingresados con prioridad 3:\n";
                displayData(queue_priority3);
                break;
            }
            case 4:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción inválida. Intente nuevamente.\n";
                break;
        }
    } while (option != 4);

    return 0;
}