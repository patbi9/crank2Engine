/**
 * @file API.h
 * @brief Definición de macros para la exportación e importación de la DLL del motor.
 */
#pragma once

#if defined(_WIN32)

#if defined(ENGINE_BUILD_DLL)

 /**
  * @def ENGINE_API
  * @brief Macro utilizada para exportar o importar símbolos de la API de la librería.
  *
  * Si se define ENGINE_BUILD_DLL,
    exporta las funciones y clases (__declspec(dllexport)).
  * De lo contrario, las importa (__declspec(dllimport)).
  */
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif

#else

 /**
  * @def ENGINE_API
  * @brief Definición vacía de la macro para plataformas distintas a Windows.
  */
#define ENGINE_API
#endif
