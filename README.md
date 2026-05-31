# GadgetXpress_Final
Proyecto final en C++ para la gestión de inventario y simulación de ventas de GadgetXpress.
# GadgetXpress - Sistema de Gestion de Inventario

## Descripcion del proyecto

GadgetXpress es un sistema desarrollado en C++ para gestionar el inventario de una tienda de productos tecnologicos.

El proyecto permite registrar productos, consultar el inventario, actualizar cantidades disponibles, generar reportes de bajo inventario y simular ventas en tiempo real.

## Objetivo

El objetivo del sistema es ayudar a GadgetXpress a mejorar el control de sus productos, evitando errores en el manejo manual del inventario y permitiendo observar como cambian las cantidades disponibles despues de una venta.

## Funcionalidades

- Agregar producto.
- Listar inventario.
- Actualizar cantidad de un producto.
- Generar reporte de bajo inventario.
- Simular venta.
- Validar entradas incorrectas.

## Lenguaje utilizado

C++

## Estructura principal del codigo

El programa utiliza una estructura llamada Producto, que almacena:

- Nombre del producto.
- Codigo del producto.
- Cantidad en inventario.
- Precio.

Tambien utiliza un vector para guardar la lista de productos registrados.

## Funcion nueva: simulacion de venta

La funcion simularVenta permite ingresar el codigo de un producto y la cantidad que se desea vender.

El sistema valida que:

1. El producto exista en el inventario.
2. La cantidad solicitada sea menor o igual a la cantidad disponible.
3. La cantidad a vender sea mayor que cero.

Si las validaciones se cumplen, el sistema descuenta la cantidad vendida del inventario y muestra el total de la venta.

## Como ejecutar el programa

1. S2. Tarea. Simulación del compartimiento del inventario.cpp.
2. Compilar el programa en un entorno compatible con C++.
3. Ejecutar el programa.
4. Usar el menu principal para probar las funcionalidades.

## Video de sustentacion

https://docs.google.com/videos/d/1G_ZygDpLFBsag65oNPR5KGuB5du5dLD5d1e6LGpsvu4/edit?usp=sharing.

## Autor

Sebastian Zapata Alvarez
