/**
 * @file Engine.h
 * @brief Declaración de la clase principal del motor gráfico[cite: 2].
 */
#pragma once
#include "Prerequisites.h"

 /**
  * @class Engine
  * @brief Clase principal encargada de administrar
           el ciclo de vida y renderizado del motor.
  *
  * Implementa el patrón de diseño Pimpl (Pointer to Implementation) para ocultar
  * los detalles de implementación de DirectX 11 y reducir tiempos de compilación.
  */
class
ENGINE_API Engine final {
public:
 /**
  * @brief Constructor por defecto de la clase Engine.
  */
 Engine() noexcept;

 /**
  * @brief Destructor de la clase Engine.
  */
 ~Engine() noexcept;

 /// Deshabilitada la copia de la clase Engine para evitar duplicación de recursos.
 Engine(const Engine&) = delete;
 /// Deshabilitada la asignación por movimiento.
 Engine& operator=(Engine&&) = delete;

 /**
  * @brief Inicializa el motor gráfico y sus subsistemas asociados.
  *
  * @param nativeWindow Puntero nativo a la ventana de la aplicación (ej. HWND).
  * @param width Ancho inicial del área de renderizado en píxeles.
  * @param height Alto inicial del área de renderizado en píxeles.
  * @return true si la inicialización fue exitosa, false en caso contrario.
  */
 bool
 Initialize(
  void* nativeWindow,
  std::uint32_t width,
  std::uint32_t height
  ) noexcept;

 /**
  * @brief Renderiza un fotograma en la pantalla.
  */
 void
 Render() noexcept;

 /**
  * @brief Libera los recursos y apaga el motor gráfico.
  */
 void
 Shutdown() noexcept;

private:
 /**
  * @brief Estructura interna para el patrón Pimpl.
  */
 struct Implementation;
 // Puntero a la implementación privada del motor.
 Implementation* m_implementation = nullptr;
};
