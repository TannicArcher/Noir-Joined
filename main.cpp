#include <iostream>
#include <windows.h>

void blockInputAndDisplayMessage(const char* message) {
    // Блокируем управление пользователя
    BlockInput(TRUE);

    // Создаем окно поверх всех окон, в котором будет отображаться сообщение
    HWND hwnd = CreateWindowEx(
        WS_EX_TOPMOST,
        "STATIC",
        message,
        WS_POPUP | WS_VISIBLE,
        0, 0, 300, 100,
        NULL, NULL, NULL, NULL);

    // Устанавливаем цвет фона и переднего плана окна сообщения
    HDC hdc = GetDC(hwnd);
    SetBkColor(hdc, RGB(0, 0, 0));
    SetTextColor(hdc, RGB(255, 255, 255));
    ReleaseDC(hwnd, hdc);

    // Ждем, пока пользователь не закроет окно сообщения
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Разблокируем управление пользователя
    BlockInput(FALSE);
}

int main() {
    blockInputAndDisplayMessage("NOIR JOINED");

    return 0;
}
