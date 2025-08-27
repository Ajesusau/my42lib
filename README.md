# 📚 my42lib

**my42lib** es una librería en C que reúne varios proyectos desarrollados en [42 School](https://42.fr):  
- **libft** → funciones estándar y utilidades de cadenas, memoria y listas enlazadas.  
- **get_next_line** → lectura de archivos línea por línea.  
- **ft_printf** → impresión formateada al estilo de `printf`.  
- **extras** → funciones adicionales útiles para el desarrollo en C.  

Todo se compila con un **único Makefile**, lo que permite integrar la librería fácilmente en cualquier proyecto del cursus.

## 🧠 Objetivos del Proyecto

- Unificar los proyectos básicos del cursus en una sola librería.
- Facilitar la reutilización de código en futuros proyectos.
- Mejorar la organización y mantenimiento de funciones propias.
- Reforzar las buenas prácticas de modularidad y compilación en C.


## ✅ Funcionalidades Incluidas

- **libft** → funciones de memoria, cadenas, listas enlazadas y utilidades generales.  
- **get_next_line** → lectura de líneas desde descriptores de archivo con `BUFFER_SIZE`.  
- **ft_printf** → implementación de `printf` con soporte de conversores básicos.  
- **extras** → utilidades adicionales creadas para facilitar otros proyectos.  


## 🛠️ Compilación

Para compilar la librería, simplemente ejecuta:
```
make
```
Esto generará un archivo libmy42.a que puedes añadir a cualquier proyecto.

Para limpiar archivos objeto:
```
make clean
```
Para limpiar todo, incluyendo la librería:
```
make fclean
```
Para limpiar y recompilar:
```
make re
```
📌 Uso
Incluye los headers en tu proyecto:
```
#include "libft.h"
#include "get_next_line.h"
#include "ft_printf.h"
```
Compila junto a la librería:
```
cc main.c libmy42.a
```
Ejemplo:
```
#include "libft.h"
#include "get_next_line.h"
#include "ft_printf.h"

int main(void)
{
    ft_printf("Número: %d\n", ft_atoi("42"));
    return (0);
}
```
