/**
 * @file Prerequisites.h
 * @brief Inclusión de dependencias globales y exportación de la API C nativa del motor.
 */

#pragma once
#include "API.h"
#include <cstdint>
#include <DirectXMath.h>
#include <Windows.h>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <sstream>
#include <cstddef>
#include <chrono>
#include <new>

 // MACROS
#define SAFE_RELEASE(x) if(x != nullptr) x->Release(); x = nullptr;

#define MESSAGE( classObj, method, state )   \
{                                            \
   std::wostringstream os_;                  \
   os_ << classObj << "::" << method << " : " << "[CREATION OF RESOURCE " << ": " << state << "] \n"; \
   OutputDebugStringW( os_.str().c_str() );  \
}

#define ERROR(classObj, method, errorMSG)                     \
{                                                             \
    try {                                                     \
        std::wostringstream os_;                              \
        os_ << L"ERROR : " << classObj << L"::" << method     \
            << L" : " << errorMSG << L"\n";                   \
        OutputDebugStringW(os_.str().c_str());                \
    } catch (...) {                                           \
        OutputDebugStringW(L"Failed to log error message.\n");\
    }                                                         \
}

template<typename T>
void
SafeRelease(T*& object) noexcept {
    if (object != nullptr) {
        object->Release();
        object = nullptr;
    }
}

extern
"C" {
 /**
  * @brief Inicializa el motor gráfico a través de la API en C.
  *
  * @param hand Manejador de la ventana de Windows (HWND).
  * @param width Ancho del área de renderizado en píxeles.
  * @param height Alto del área de renderizado en píxeles.
  * @return true si la inicialización fue exitosa, false en caso contrario.
  */
 ENGINE_API bool
 Engine_Initialize(HWND hand, int width, int height) noexcept;

 /**
  * @brief Actualiza la lógica del motor en la API en C.
  */
 ENGINE_API void
 Engine_Update() noexcept;

 /**
  * @brief Renderiza un cuadro en la API en C.
  */
 ENGINE_API void
 Engine_Render() noexcept;

 /**
  * @brief Finaliza y libera los recursos del motor en la API en C.
  */
 ENGINE_API void
 Engine_Shutdown() noexcept;
}
