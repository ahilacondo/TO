# Laboratorio 03 - C++

Este repositorio contiene los ejercicios del Laboratorio 03 de C++.

## Contenido del repositorio

- **ejer01.cpp**: Modificar el ejercicio 01 (Rectángulo) para que utilice memoria dinámica.
- **ejer02.cpp**: Modificar el ejercicio 02 (Tiempo) para que funcione en memoria dinámica.
- **ejer03.cpp**: Modificar el ejercicio 03 para implementar una lista doblemente enlazada con funciones de búsqueda e impresión.
- **ejer04.cpp**: Implementar un árbol de expresión binaria para resolver operaciones matemáticas.

## Cómo ejecutar los archivos

### Para el ejercicio 01 (Rectángulo):

1. Clona este repositorio en tu máquina local:
   ```
   git clone https://github.com/ahilacondo/TO.git
   ```
2. Navega a la carpeta donde están los archivos:
   ```
   cd lab03/ejer01
   ```
3. Para compilar los archivos:
   ```
   g++ -o rectangulo main.cpp rectangulo.cpp
   ```
4. Y lo ejecutamos con:
   ```
   ./rectangulo
   ```

### Para el ejercicio 02 (Tiempo):

1. Clona este repositorio en tu máquina local:
   ```
   git clone https://github.com/ahilacondo/TO.git
   ```
2. Navega a la carpeta donde están los archivos:
   ```
   cd lab03/ejer02
   ```
3. Para compilar los archivos:
   ```
   g++ -o programa main.cpp time.cpp
   ```
4. Y lo ejecutamos con:
   ```
   ./programa
   ```

### Para el ejercicio 03 (Lista doblemente enlazada):

1. Clona este repositorio en tu máquina local:
   ```
   git clone https://github.com/ahilacondo/TO.git
   ```
2. Navega a la carpeta donde están los archivos:
   ```
   cd lab03/ejer03
   ```
3. Para compilar los archivos:
   ```
   g++ main.cpp lista.cpp -o lista
   ```
4. Y lo ejecutamos con:
   ```
   ./lista.exe
   ```

### Para el ejercicio 04 (Árbol de expresión binaria):

1. Clona este repositorio en tu máquina local:
   ```
   git clone https://github.com/ahilacondo/TO.git
   ```
2. Navega a la carpeta donde están los archivos:
   ```
   cd lab03/ejer04
   ```
3. Para compilar los archivos:
   ```
   g++ -c Nodo.cpp -o Nodo.o
   g++ -c Funciones.cpp -o Funciones.o
   g++ -c main.cpp -o main.o
   g++ Nodo.o Funciones.o main.o -o programa
   ```
4. Y lo ejecutamos con:
   ```
   ./programa
   ```

## Requerimientos

- **Compilador C++**: Asegúrate de tener un compilador instalado (como `g++`).
- **Git**: Para clonar el repositorio.