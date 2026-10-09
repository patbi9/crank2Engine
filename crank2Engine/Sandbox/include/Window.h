#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef NOMINMAX
#define NOMINMAX
#endif

#include <Windows.h>

class Window final {
public:
	Window() = default;
	~Window();

	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	bool
	Create(HINSTANCE instance, const wchar_t* title,
		   UINT clientWidth, UINT clientHeight) noexcept;

	void
	Show(int showComand) noexcept;

	void
	Destroy() noexcept;

	// Devuelve false cuando se recibe WM_QUIT
	bool
	ProcessMessages() noexcept;

	HWND
	GetHandle() const noexcept { return m_handle; }

	bool
	IsMinimized() const noexcept;

private:
	static LRESULT CALLBACK
	WindowProcedure(HWND handle, UINT message,
		WPARAM wParam, LPARAM lParam);

	static constexpr const wchar_t* ClassName =
		L"crank2EngineWindow";

	HINSTANCE m_instance = nullptr;
	HWND m_handle = nullptr;
	bool m_classRegistered = false;
};