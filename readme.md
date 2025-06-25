# Proyecto Final C++ — Conversor de Unidades

¡Hola gente!

Este proyecto ya tiene toda la **estructura base implementada**: el menú se abre correctamente, pero aún no hace nada más.  
Todos los métodos que tienen que implementar **ya están escritos como stubs** (vacíos con comentarios), así que su tarea será completarlos. Yo ya lo hice para asegurarme que funciona y no los pondré a cazar fantasmas.

> 💡 **El profesor no ha cubierto mucho de lo necesario** para este proyecto. Hemos pasado más tiempo hablando del método de evaluación que practicando cómo pedir dos números, validar datos, manejar entradas o crear un menú. Así que sí, hay un saltico… pero sobrevivimos 💪




## 📦 ¿Cómo descargo el proyecto?

Si ya tienen acceso al GitHub, simplemente ejecuten este comando:

```bash
git clone --branch development --single-branch git@github.com:Ing-jdum/PFinalCPP.git
```

## 🚀 Cómo compilar y ejecutar el proyecto

-- Paso 1: Limpia archivos compilados previos (opcional pero recomendado)
``` bash
make clean
```
-- Paso 2: Compila el proyecto completo
``` bash
make 
```

-- Paso 3: Ejecuta el programa
``` bash
./main
```

-- 💡 Si estás en una subcarpeta distinta, asegúrate de estar en la raíz del proyecto antes de ejecutar estos comandos.

-- 📍 Si estás en la carpeta tests y quieres correr los tests:
cd tests
make run

## 🧭 Orden sugerido para implementar los métodos
Con base en cómo están organizadas las clases y su dependencia entre ellas, este es el orden recomendado para implementar el código:

``` bash
1. Unit — la base de todo
Unit::Unit()

Unit::getName()

Unit::getConversionFactor()

Unit::toBase()

Unit::fromBase()

2. Validation — para manejar la entrada del usuario
Validation::isValidDouble()

Validation::isValidInt()

Validation::isValidUnitName()

Validation::trim()

Validation::toLowerCase()

3. UnitCategory — agrupa unidades
UnitCategory::UnitCategory()

UnitCategory::getName()

UnitCategory::getBaseUnitName()

UnitCategory::addUnit()

UnitCategory::findUnit()

UnitCategory::getUnitNames()

UnitCategory::getUnitCount()

4. UnitRegistry — controla el sistema
UnitRegistry::UnitRegistry()

UnitRegistry::initializeDefaultCategories()

UnitRegistry::findCategory()

UnitRegistry::getCategoryNames()

UnitRegistry::canAddUnitsToCategory()

UnitRegistry::addUnitToCategory()

5. Converter — usa todo lo anterior
Converter::convert()

Temperatura:

Converter::celsiusToFahrenheit()

Converter::fahrenheitToCelsius()

Converter::celsiusToKelvin()

Converter::kelvinToCelsius()

Converter::fahrenheitToKelvin()

Converter::kelvinToFahrenheit()

Converter::convertTemperature()

Converter::convertInCategory()
```

## Estructura

```

+-----------------+
|     Unit        | <--------------------+
+-----------------+                      |
| - name: string  |                      |
| - factor: double|                      |
+-----------------+                      |
| +getName()      |                      |
| +getConversionFactor()                |
| +toBase(value)                         |
| +fromBase(value)                       |
+-----------------+                      |
                                         |
+-------------------------+              |
|     UnitCategory        |              |
+-------------------------+              |
| - name: string          |              |
| - baseUnitName: string  |              |
| - units: vector<Unit*>  |              |
+-------------------------+              |
| +addUnit(name, factor)  |              |
| +findUnit(name)         |              |
| +getUnitNames()         |              |
| +getUnitCount()         |              |
+-------------------------+              |
        ▲                                |
        | contains                       |
        |                                |
+-------------------------+              |
|     UnitRegistry        |              |
+-------------------------+              |
| - categories: vector<UnitCategory*>   |
+-------------------------+              |
| +findCategory(name)     |              |
| +getCategoryNames()     |              |
| +addUnitToCategory(...) |              |
+-------------------------+              |
                                         |
+-------------------------+              |
|      Converter          |              |
+-------------------------+              |
| +convert(value, from, to)              |
| +convertInCategory(...)                |
| +convertTemperature(...)               |
| +temp-specific methods                 |
+-------------------------+              |

+-------------------------+              |
|     Validation          |              |
+-------------------------+              |
| +isValidDouble()        |              |
| +isValidInt()           |              |
| +isValidUnitName()      |
| +trim()                 |
| +toLowerCase()          |
+-------------------------+

+-------------------------+
|        Menu            |
+-------------------------+
| - registry: UnitRegistry& |
| +run()                   |
| +performConversion()     |
| +addNewUnit()            |
+-------------------------+

+-------------------------+
|     InputHandler        |
+-------------------------+
| +getString(prompt)      |
| +getDouble(prompt)      |
| +getInt(prompt)         |
| +getYesNo(prompt)       |
+-------------------------+
```
📝 Explicación rápida para estudiantes:
Unit representa una unidad individual (como "metro" o "kilómetro").

UnitCategory agrupa unidades similares, y define cuál es la unidad base (por ejemplo, categoría "Distancia" con base "metro").

UnitRegistry es como una base de datos en memoria: guarda todas las categorías y permite buscarlas.

Converter usa todo lo anterior para realizar conversiones.

Validation y InputHandler ayudan con entrada y validación del usuario.

Menu muestra el menú principal y llama al resto de la lógica.

## 🤖 ¿Puedo usar la AI?
Claro que sí, pero úsala con cabeza. Podrías hacer todo esto en 10 minutos con ChatGPT, pero si no entiendes lo que hace, nos vas a quemar en la exposición.

Aquí un buen prompt para que te ayude mientras aprendes:

Prompt recomendado
Ayúdame a codificar pero a aprender mientras lo hago. Explica cada decisión de estructura de datos que tomes y descríbemela como si fuera nuevo en programación. + estructura en texto plano del proyecto.

Esta es la estructura del proyecto: Entran aqui y le pegan el contenido a gpt, es una versión en texto plano del proyecto:
https://github.com/Ing-jdum/PFinalCPP/tree/development
Pídele que comente bien su código. Pregunta todo lo que no entiendas.

## 📦: Cómo hacer commit y push en GitHub

-- Paso 1: Verifica los archivos modificados
``` bash 
git status
```

-- Paso 2: Añade los archivos al área de preparación (staging)
``` bash 
git add .
```

-- Paso 3: Crea un commit con un mensaje descriptivo
``` bash 
git commit -m "Implementé la clase Unit con sus métodos"
```

-- Paso 4: Envía tus cambios al repositorio remoto (GitHub)
``` bash 
git push origin development
```

## 📣 Dudas
Me pueden escribir si tienen preguntas. No prometo responder de una vez, pero siempre respondo. Échenle ganas.