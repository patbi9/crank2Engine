#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef NOMINMAX
#define NOMINMAX
#endif

#include <Windows.h>

/**
 * @class Window
 * @brief Gestiona la creación, ciclo de vida y eventos de una ventana.
 *
 * Se declara como 'final' para deshabilitar los constructores de copia y
 * asignación y garantizar que cada instancia maneje de forma única una ventana.
 */
class
Window final {
public:
 /**
  * @brief Constructor por defecto.
  */
 Window() = default;

 /**
  * @brief Destructor. Destruye los recursos nativos
           de la ventana si aún no han sido liberados.
  */
 ~Window();

 // Deshabilitar la copia y la asignación
 Window(const Window&) = delete;
 Window& operator=(const Window&) = delete;

 /**
  * @brief Registra la clase de ventana y crea la ventana.
  *
  * @param instance Identificador de la instancia actual del ejecutable (HINSTANCE).
  * @param title Título que se mostrará en la barra superior de la ventana.
  * @param clientWidth Ancho deseado para el área en píxeles.
  * @param clientHeight Alto deseado para el área en píxeles.
  * @return true Si la ventana se creó correctamente.
  * @return false Si ocurrió un error durante el registro o la creación.
  */
 bool
 Create(
  HINSTANCE instance,
  const wchar_t* title,
  UINT clientWidth,
  UINT clientHeight
 ) noexcept;

 /**
  * @brief Define el estado de visualización de la ventana.
  *
  * @param showComand Comando de visualización de Win32.
  */
 void
 Show(int showComand) noexcept;

 /**
  * @brief Destruye la ventana nativa y desregistra
           la clase de ventana si corresponde.
  */
 void
 Destroy() noexcept;

 /**
  * @brief Procesa y despacha los mensajes pendientes de la cola de eventos de Windows.
  *
  * @return true Si la aplicación debe continuar procesando bucles de render.
  * @return false Si se ha recibido el mensaje WM_QUIT.
  */
 bool
 ProcessMessages() noexcept;

 /**
  * @brief Obtiene el manejador nativo (HWND) de la ventana.
  *
  * @return HWND Handle a la ventana de Win32.
  */
 HWND
 GetHandle() const noexcept { return m_handle; }
	
 /**
  * @brief Consulta si la ventana se encuentra actualmente minimizada.
  *
  * @return true Si la ventana está minimizada.
  * @return false Si la ventana se encuentra visible o restaurada.
  */
 bool
 IsMinimized() const noexcept;

 private:
 /**
  * @brief Función de procedimiento de ventana
           (Callback) que procesa los mensajes de Win32.
  *
  * @param handle Handle de la ventana que recibe el mensaje.
  * @param message Código del mensaje de evento.
  * @param wParam Parámetro adicional del mensaje.
  * @param lParam Parámetro adicional del mensaje.
  * @return LRESULT Resultado del procesamiento del mensaje.
  */
 static LRESULT CALLBACK WindowProcedure(
  HWND handle,
  UINT message,
  WPARAM wParam,
  LPARAM lParam
 );

 /// Nombre de la clase de ventana de Windows registrada por el motor.
 static constexpr const wchar_t* ClassName =
  L"crank2EngineWindow";

 HINSTANCE m_instance = nullptr;		///< Instancia de la aplicación Win32.
 HWND m_handle = nullptr;			///< Handle nativo de la ventana (HWND).
 bool m_classRegistered = false;		///< Estado que indica si la clase WNDCLASSEX ya fue registrada.
};
