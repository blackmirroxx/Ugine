#include "keyboard_mapping.h"

ImGuiKey ugine::utils::keycode_to_imguikey(ugine::utils::keycode key)
{
    using namespace ugine::utils;
    switch (key)
    {
        case keycode::Tab: return ImGuiKey_Tab;
        case keycode::Left: return ImGuiKey_LeftArrow;
        case keycode::Right: return ImGuiKey_RightArrow;
        case keycode::Up: return ImGuiKey_UpArrow;
        case keycode::Down: return ImGuiKey_DownArrow;
        case keycode::PageUp: return ImGuiKey_PageUp;
        case keycode::PageDown: return ImGuiKey_PageDown;
        case keycode::Home: return ImGuiKey_Home;
        case keycode::End: return ImGuiKey_End;
        case keycode::Insert: return ImGuiKey_Insert;
        case keycode::Delete: return ImGuiKey_Delete;
        case keycode::Backspace: return ImGuiKey_Backspace;
        case keycode::Space: return ImGuiKey_Space;
        case keycode::Enter: return ImGuiKey_Enter;
        case keycode::Escape: return ImGuiKey_Escape;
        case keycode::Apostrophe: return ImGuiKey_Apostrophe;
        case keycode::Comma: return ImGuiKey_Comma;
        case keycode::Minus: return ImGuiKey_Minus;
        case keycode::Period: return ImGuiKey_Period;
        case keycode::Slash: return ImGuiKey_Slash;
        case keycode::Semicolon: return ImGuiKey_Semicolon;
        case keycode::Equal: return ImGuiKey_Equal;
        case keycode::LeftBracket: return ImGuiKey_LeftBracket;
        case keycode::Backslash: return ImGuiKey_Backslash;
        case keycode::RightBracket: return ImGuiKey_RightBracket;
        case keycode::GraveAccent: return ImGuiKey_GraveAccent;
        case keycode::CapsLock: return ImGuiKey_CapsLock;
        case keycode::ScrollLock: return ImGuiKey_ScrollLock;
        case keycode::NumLock: return ImGuiKey_NumLock;
        case keycode::PrintScreen: return ImGuiKey_PrintScreen;
        case keycode::Pause: return ImGuiKey_Pause;
        case keycode::KP0: return ImGuiKey_Keypad0;
        case keycode::KP1: return ImGuiKey_Keypad1;
        case keycode::KP2: return ImGuiKey_Keypad2;
        case keycode::KP3: return ImGuiKey_Keypad3;
        case keycode::KP4: return ImGuiKey_Keypad4;
        case keycode::KP5: return ImGuiKey_Keypad5;
        case keycode::KP6: return ImGuiKey_Keypad6;
        case keycode::KP7: return ImGuiKey_Keypad7;
        case keycode::KP8: return ImGuiKey_Keypad8;
        case keycode::KP9: return ImGuiKey_Keypad9;
        case keycode::KPDecimal: return ImGuiKey_KeypadDecimal;
        case keycode::KPDivide: return ImGuiKey_KeypadDivide;
        case keycode::KPMultiply: return ImGuiKey_KeypadMultiply;
        case keycode::KPSubtract: return ImGuiKey_KeypadSubtract;
        case keycode::KPAdd: return ImGuiKey_KeypadAdd;
        case keycode::KPEnter: return ImGuiKey_KeypadEnter;
        case keycode::KPEqual: return ImGuiKey_KeypadEqual;
        case keycode::LeftControl: return ImGuiKey_LeftCtrl;
        case keycode::LeftShift: return ImGuiKey_LeftShift;
        case keycode::LeftAlt: return ImGuiKey_LeftAlt;
        case keycode::LeftSuper: return ImGuiKey_LeftSuper;
        case keycode::RightControl: return ImGuiKey_RightCtrl;
        case keycode::RightShift: return ImGuiKey_RightShift;
        case keycode::RightAlt: return ImGuiKey_RightAlt;
        case keycode::RightSuper: return ImGuiKey_RightSuper;
        case keycode::Menu: return ImGuiKey_Menu;
        case keycode::D0: return ImGuiKey_0;
        case keycode::D1: return ImGuiKey_1;
        case keycode::D2: return ImGuiKey_2;
        case keycode::D3: return ImGuiKey_3;
        case keycode::D4: return ImGuiKey_4;
        case keycode::D5: return ImGuiKey_5;
        case keycode::D6: return ImGuiKey_6;
        case keycode::D7: return ImGuiKey_7;
        case keycode::D8: return ImGuiKey_8;
        case keycode::D9: return ImGuiKey_9;
        case keycode::A: return ImGuiKey_A;
        case keycode::B: return ImGuiKey_B;
        case keycode::C: return ImGuiKey_C;
        case keycode::D: return ImGuiKey_D;
        case keycode::E: return ImGuiKey_E;
        case keycode::F: return ImGuiKey_F;
        case keycode::G: return ImGuiKey_G;
        case keycode::H: return ImGuiKey_H;
        case keycode::I: return ImGuiKey_I;
        case keycode::J: return ImGuiKey_J;
        case keycode::K: return ImGuiKey_K;
        case keycode::L: return ImGuiKey_L;
        case keycode::M: return ImGuiKey_M;
        case keycode::N: return ImGuiKey_N;
        case keycode::O: return ImGuiKey_O;
        case keycode::P: return ImGuiKey_P;
        case keycode::Q: return ImGuiKey_Q;
        case keycode::R: return ImGuiKey_R;
        case keycode::S: return ImGuiKey_S;
        case keycode::T: return ImGuiKey_T;
        case keycode::U: return ImGuiKey_U;
        case keycode::V: return ImGuiKey_V;
        case keycode::W: return ImGuiKey_W;
        case keycode::X: return ImGuiKey_X;
        case keycode::Y: return ImGuiKey_Y;
        case keycode::Z: return ImGuiKey_Z;
        case keycode::F1: return ImGuiKey_F1;
        case keycode::F2: return ImGuiKey_F2;
        case keycode::F3: return ImGuiKey_F3;
        case keycode::F4: return ImGuiKey_F4;
        case keycode::F5: return ImGuiKey_F5;
        case keycode::F6: return ImGuiKey_F6;
        case keycode::F7: return ImGuiKey_F7;
        case keycode::F8: return ImGuiKey_F8;
        case keycode::F9: return ImGuiKey_F9;
        case keycode::F10: return ImGuiKey_F10;
        case keycode::F11: return ImGuiKey_F11;
        case keycode::F12: return ImGuiKey_F12;
    }
    return ImGuiKey_None;
}

ugine::utils::keycode ugine::utils::sdl_keycode_to_keycode(SDL_Keycode key) {
    using namespace ugine::utils;
    switch (key) {

    }
   return  keycode::Unknown;
}

SDL_Scancode ugine::utils::keycode_to_sdl_scancode(ugine::utils::keycode key) {
    using namespace ugine::utils;
    switch (key) {

    }
    return SDL_SCANCODE_UNKNOWN;
}
