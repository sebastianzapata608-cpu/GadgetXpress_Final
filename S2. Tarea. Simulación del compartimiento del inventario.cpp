#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

// Estructura que representa un producto dentro del inventario.
struct Producto {
    string nombre;
    int codigo;
    int cantidadEnInventario;
    double precio;
};

// Limpia errores de entrada cuando el usuario escribe un dato invalido.
void limpiarEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Busca un producto dentro del inventario usando su codigo.
// Retorna la posicion del producto si lo encuentra.
// Retorna -1 si el producto no existe.
int buscarProductoPorCodigo(const vector<Producto>& inventario, int codigoBuscado) {
    for (int i = 0; i < inventario.size(); i++) {
        if (inventario[i].codigo == codigoBuscado) {
            return i;
        }
    }

    return -1;
}

// Solicita un numero entero positivo al usuario.
// Esta funcion evita que el programa falle si el usuario escribe letras.
int solicitarEnteroPositivo(string mensaje) {
    int valor;

    while (true) {
        cout << mensaje;
        cin >> valor;

        if (cin.fail() || valor < 0) {
            cout << "Error: ingrese un numero entero valido y mayor o igual a cero.\n";
            limpiarEntrada();
        }
        else {
            limpiarEntrada();
            return valor;
        }
    }
}

// Solicita un numero decimal positivo al usuario.
// Se usa para validar correctamente el precio del producto.
double solicitarDecimalPositivo(string mensaje) {
    double valor;

    while (true) {
        cout << mensaje;
        cin >> valor;

        if (cin.fail() || valor < 0) {
            cout << "Error: ingrese un valor numerico valido y mayor o igual a cero.\n";
            limpiarEntrada();
        }
        else {
            limpiarEntrada();
            return valor;
        }
    }
}

// Permite registrar un nuevo producto en el inventario.
// Valida que el codigo no este repetido.
void agregarProducto(vector<Producto>& inventario) {
    Producto nuevoProducto;

    cout << "\n========== AGREGAR PRODUCTO ==========\n";

    cout << "Ingrese el nombre del producto: ";
    getline(cin, nuevoProducto.nombre);

    nuevoProducto.codigo = solicitarEnteroPositivo("Ingrese el codigo del producto: ");

    int posicionProducto = buscarProductoPorCodigo(inventario, nuevoProducto.codigo);

    if (posicionProducto != -1) {
        cout << "Error: ya existe un producto registrado con ese codigo.\n";
        return;
    }

    nuevoProducto.cantidadEnInventario = solicitarEnteroPositivo("Ingrese la cantidad en inventario: ");
    nuevoProducto.precio = solicitarDecimalPositivo("Ingrese el precio del producto: ");

    inventario.push_back(nuevoProducto);

    cout << "Producto agregado correctamente.\n";
}

// Muestra todos los productos registrados en el inventario.
// Si no existen productos, informa al usuario.
void listarInventario(const vector<Producto>& inventario) {
    cout << "\n========== INVENTARIO ACTUAL ==========\n";

    if (inventario.empty()) {
        cout << "No hay productos registrados en el inventario.\n";
        return;
    }

    cout << left << setw(15) << "Codigo"
        << setw(25) << "Nombre"
        << setw(15) << "Cantidad"
        << setw(15) << "Precio" << endl;

    cout << string(70, '-') << endl;

    for (const Producto& producto : inventario) {
        cout << left << setw(15) << producto.codigo
            << setw(25) << producto.nombre
            << setw(15) << producto.cantidadEnInventario
            << "$" << fixed << setprecision(2) << producto.precio << endl;
    }
}

// Permite modificar la cantidad disponible de un producto.
// Primero valida que el producto exista en el inventario.
void actualizarCantidad(vector<Producto>& inventario) {
    cout << "\n========== ACTUALIZAR CANTIDAD ==========\n";

    if (inventario.empty()) {
        cout << "Error: no hay productos registrados para actualizar.\n";
        return;
    }

    int codigoBuscado = solicitarEnteroPositivo("Ingrese el codigo del producto: ");

    int posicionProducto = buscarProductoPorCodigo(inventario, codigoBuscado);

    if (posicionProducto == -1) {
        cout << "Error: el producto no existe en el inventario.\n";
        return;
    }

    cout << "Producto encontrado: " << inventario[posicionProducto].nombre << endl;
    cout << "Cantidad actual: " << inventario[posicionProducto].cantidadEnInventario << endl;

    int nuevaCantidad = solicitarEnteroPositivo("Ingrese la nueva cantidad: ");

    inventario[posicionProducto].cantidadEnInventario = nuevaCantidad;

    cout << "Cantidad actualizada correctamente.\n";
}

// Genera un reporte con los productos que tienen bajo inventario.
// El limite usado es de 5 unidades o menos.
void generarReporteBajoInventario(const vector<Producto>& inventario) {
    const int limiteBajoInventario = 5;
    bool hayProductosBajos = false;

    cout << "\n========== REPORTE DE BAJO INVENTARIO ==========\n";

    if (inventario.empty()) {
        cout << "No hay productos registrados en el inventario.\n";
        return;
    }

    cout << "Productos con cantidad menor o igual a "
        << limiteBajoInventario << " unidades:\n\n";

    cout << left << setw(15) << "Codigo"
        << setw(25) << "Nombre"
        << setw(15) << "Cantidad" << endl;

    cout << string(55, '-') << endl;

    for (const Producto& producto : inventario) {
        if (producto.cantidadEnInventario <= limiteBajoInventario) {
            cout << left << setw(15) << producto.codigo
                << setw(25) << producto.nombre
                << setw(15) << producto.cantidadEnInventario << endl;

            hayProductosBajos = true;
        }
    }

    if (!hayProductosBajos) {
        cout << "No hay productos con bajo inventario.\n";
    }
}

// Simula la venta de un producto.
// Valida que el producto exista y que haya suficiente cantidad disponible.
// Si la venta es valida, descuenta la cantidad vendida del inventario.
void simularVenta(vector<Producto>& inventario) {
    cout << "\n========== SIMULACION DE VENTA ==========\n";

    if (inventario.empty()) {
        cout << "Error: no hay productos registrados para vender.\n";
        return;
    }

    int codigoBuscado = solicitarEnteroPositivo("Ingrese el codigo del producto que desea vender: ");

    int posicionProducto = buscarProductoPorCodigo(inventario, codigoBuscado);

    if (posicionProducto == -1) {
        cout << "Error: el producto no existe en el inventario.\n";
        return;
    }

    cout << "Producto encontrado: " << inventario[posicionProducto].nombre << endl;
    cout << "Cantidad disponible: " << inventario[posicionProducto].cantidadEnInventario << endl;
    cout << "Precio unitario: $" << fixed << setprecision(2)
        << inventario[posicionProducto].precio << endl;

    int cantidadAVender = solicitarEnteroPositivo("Ingrese la cantidad que desea vender: ");

    if (cantidadAVender == 0) {
        cout << "Error: la cantidad a vender debe ser mayor que cero.\n";
        return;
    }

    if (cantidadAVender > inventario[posicionProducto].cantidadEnInventario) {
        cout << "Error: no hay suficiente inventario para realizar la venta.\n";
        return;
    }

    inventario[posicionProducto].cantidadEnInventario -= cantidadAVender;

    double totalVenta = cantidadAVender * inventario[posicionProducto].precio;

    cout << "\nVenta realizada con exito.\n";
    cout << "Producto vendido: " << inventario[posicionProducto].nombre << endl;
    cout << "Cantidad vendida: " << cantidadAVender << endl;
    cout << "Total de la venta: $" << fixed << setprecision(2) << totalVenta << endl;
    cout << "Cantidad restante en inventario: "
        << inventario[posicionProducto].cantidadEnInventario << endl;
}

// Muestra el menu principal del sistema.
void mostrarMenu() {
    cout << "\n========================================\n";
    cout << "        SISTEMA GADGETXPRESS\n";
    cout << "========================================\n";
    cout << "1. Agregar producto\n";
    cout << "2. Listar inventario\n";
    cout << "3. Actualizar cantidad\n";
    cout << "4. Generar reporte de bajo inventario\n";
    cout << "5. Simular venta\n";
    cout << "6. Salir\n";
    cout << "Seleccione una opcion: ";
}

// Solicita la opcion del menu y valida que sea un numero correcto.
int solicitarOpcionMenu() {
    int opcion;

    while (true) {
        mostrarMenu();
        cin >> opcion;

        if (cin.fail()) {
            cout << "\nError: debe ingresar un numero valido.\n";
            limpiarEntrada();
        }
        else {
            limpiarEntrada();
            return opcion;
        }
    }
}

int main() {
    vector<Producto> inventario;
    int opcion;

    do {
        opcion = solicitarOpcionMenu();

        switch (opcion) {
        case 1:
            agregarProducto(inventario);
            break;

        case 2:
            listarInventario(inventario);
            break;

        case 3:
            actualizarCantidad(inventario);
            break;

        case 4:
            generarReporteBajoInventario(inventario);
            break;

        case 5:
            simularVenta(inventario);
            break;

        case 6:
            cout << "\nGracias por utilizar el sistema GadgetXpress.\n";
            break;

        default:
            cout << "\nError: opcion no valida. Intente nuevamente.\n";
            break;
        }

    } while (opcion != 6);

    return 0;
}