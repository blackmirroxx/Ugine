#pragma once
#include <SDL.h>
#include <imgui.h>
#include "ugine/utils/keycode.h"
#include "ugine/utils/mouse_button.h"


namespace ugine::utils {
    constexpr ugine::utils::keycode sdl_keycode_to_keycode(SDL_Keycode key) {
        switch (key) {
            case SDLK_TAB: return keycode::Tab;
            case SDLK_LEFT: return keycode::Left;
            case SDLK_RIGHT: return keycode::Right;
            case SDLK_UP: return keycode::Up;
            case SDLK_DOWN: return keycode::Down;
            case SDLK_PAGEUP: return keycode::PageUp;
            case SDLK_PAGEDOWN: return keycode::PageDown;
            case SDLK_HOME: return keycode::Home;
            case SDLK_END: return keycode::End;
            case SDLK_INSERT: return keycode::Insert;
            case SDLK_DELETE: return keycode::Delete;
            case SDLK_BACKSPACE: return keycode::Backspace;
            case SDLK_SPACE: return keycode::Space;
            case SDLK_RETURN: return keycode::Enter;
            case SDLK_ESCAPE: return keycode::Escape;
            case SDLK_QUOTE: return keycode::Apostrophe;
            case SDLK_COMMA: return keycode::Comma;
            case SDLK_MINUS: return keycode::Minus;
            case SDLK_PERIOD: return keycode::Period;
            case SDLK_SLASH: return keycode::Slash;
            case SDLK_SEMICOLON: return keycode::Semicolon;
            case SDLK_EQUALS: return keycode::Equal;
            case SDLK_LEFTBRACKET: return keycode::LeftBracket;
            case SDLK_BACKSLASH: return keycode::Backslash;
            case SDLK_RIGHTBRACKET: return keycode::RightBracket;
            case SDLK_BACKQUOTE: return keycode::GraveAccent;
            case SDLK_CAPSLOCK: return keycode::CapsLock;
            case SDLK_SCROLLLOCK: return keycode::ScrollLock;
            case SDLK_NUMLOCKCLEAR: return keycode::NumLock;
            case SDLK_PRINTSCREEN: return keycode::PrintScreen;
            case SDLK_PAUSE: return keycode::Pause;
            case SDLK_KP_0: return keycode::KP0;
            case SDLK_KP_1: return keycode::KP1;
            case SDLK_KP_2: return keycode::KP2;
            case SDLK_KP_3: return keycode::KP3;
            case SDLK_KP_4: return keycode::KP4;
            case SDLK_KP_5: return keycode::KP5;
            case SDLK_KP_6: return keycode::KP6;
            case SDLK_KP_7: return keycode::KP7;
            case SDLK_KP_8: return keycode::KP8;
            case SDLK_KP_9: return keycode::KP9;
            case SDLK_KP_DECIMAL: return keycode::KPDecimal;
            case SDLK_KP_DIVIDE: return keycode::KPDivide;
            case SDLK_KP_MULTIPLY: return keycode::KPMultiply;
            case SDLK_KP_MINUS: return keycode::KPSubtract;
            case SDLK_KP_PLUS: return keycode::KPAdd;
            case SDLK_KP_ENTER: return keycode::KPEnter;
            case SDLK_KP_EQUALS: return keycode::KPEqual;
            case SDLK_LCTRL: return keycode::LeftControl;
            case SDLK_LSHIFT: return keycode::LeftShift;
            case SDLK_LALT: return keycode::LeftAlt;
            case SDLK_LGUI: return keycode::LeftSuper;
            case SDLK_RCTRL: return keycode::RightControl;
            case SDLK_RSHIFT: return keycode::RightShift;
            case SDLK_RALT: return keycode::RightAlt;
            case SDLK_RGUI: return keycode::RightSuper;
            case SDLK_MENU: return keycode::Menu;
            case SDLK_0: return keycode::D0;
            case SDLK_1: return keycode::D1;
            case SDLK_2: return keycode::D2;
            case SDLK_3: return keycode::D3;
            case SDLK_4: return keycode::D4;
            case SDLK_5: return keycode::D5;
            case SDLK_6: return keycode::D6;
            case SDLK_7: return keycode::D7;
            case SDLK_8: return keycode::D8;
            case SDLK_9: return keycode::D9;
            case SDLK_a: return keycode::A;
            case SDLK_b: return keycode::B;
            case SDLK_c: return keycode::C;
            case SDLK_d: return keycode::D;
            case SDLK_e: return keycode::E;
            case SDLK_f: return keycode::F;
            case SDLK_g: return keycode::G;
            case SDLK_h: return keycode::H;
            case SDLK_i: return keycode::I;
            case SDLK_j: return keycode::J;
            case SDLK_k: return keycode::K;
            case SDLK_l: return keycode::L;
            case SDLK_m: return keycode::M;
            case SDLK_n: return keycode::N;
            case SDLK_o: return keycode::O;
            case SDLK_p: return keycode::P;
            case SDLK_q: return keycode::Q;
            case SDLK_r: return keycode::R;
            case SDLK_s: return keycode::S;
            case SDLK_t: return keycode::T;
            case SDLK_u: return keycode::U;
            case SDLK_v: return keycode::V;
            case SDLK_w: return keycode::W;
            case SDLK_x: return keycode::X;
            case SDLK_y: return keycode::Y;
            case SDLK_z: return keycode::Z;
            case SDLK_F1: return keycode::F1;
            case SDLK_F2: return keycode::F2;
            case SDLK_F3: return keycode::F3;
            case SDLK_F4: return keycode::F4;
            case SDLK_F5: return keycode::F5;
            case SDLK_F6: return keycode::F6;
            case SDLK_F7: return keycode::F7;
            case SDLK_F8: return keycode::F8;
            case SDLK_F9: return keycode::F9;
            case SDLK_F10: return keycode::F10;
            case SDLK_F11: return keycode::F11;
            case SDLK_F12: return keycode::F12;
            case SDLK_F13: return keycode::F13;
            case SDLK_F14: return keycode::F14;
            case SDLK_F15: return keycode::F15;
            case SDLK_F16: return keycode::F16;
            case SDLK_F17: return keycode::F17;
            case SDLK_F18: return keycode::F18;
            case SDLK_F19: return keycode::F19;
            case SDLK_F20: return keycode::F20;
            case SDLK_F21: return keycode::F21;
            case SDLK_F22: return keycode::F22;
            case SDLK_F23: return keycode::F23;
            case SDLK_F24: return keycode::F24;
        }
        return  keycode::Unknown;
    }

    constexpr SDL_Keycode keycode_to_sdl_keycode(ugine::utils::keycode key) {
        switch (key) {
            case keycode::Tab: return SDLK_TAB;
            case keycode::Left: return SDLK_LEFT;
            case keycode::Right: return SDLK_RIGHT;
            case keycode::Up: return SDLK_UP;
            case keycode::Down: return SDLK_DOWN;
            case keycode::PageUp: return SDLK_PAGEUP;
            case keycode::PageDown: return SDLK_PAGEDOWN;
            case keycode::Home: return SDLK_HOME;
            case keycode::End: return SDLK_END;
            case keycode::Insert: return SDLK_INSERT;
            case keycode::Delete: return SDLK_DELETE;
            case keycode::Backspace: return SDLK_BACKSPACE;
            case keycode::Space: return SDLK_SPACE;
            case keycode::Enter: return SDLK_RETURN;
            case keycode::Escape: return SDLK_ESCAPE;
            case keycode::Apostrophe: return SDLK_QUOTE;
            case keycode::Comma: return SDLK_COMMA;
            case keycode::Minus: return SDLK_MINUS;
            case keycode::Period: return SDLK_PERIOD;
            case keycode::Slash: return SDLK_SLASH;
            case keycode::Semicolon: return SDLK_SEMICOLON;
            case keycode::Equal: return SDLK_EQUALS;
            case keycode::LeftBracket: return SDLK_LEFTBRACKET;
            case keycode::Backslash: return SDLK_BACKSLASH;
            case keycode::RightBracket: return SDLK_RIGHTBRACKET;
            case keycode::GraveAccent: return SDLK_BACKQUOTE;
            case keycode::CapsLock: return SDLK_CAPSLOCK;
            case keycode::ScrollLock: return SDLK_SCROLLLOCK;
            case keycode::NumLock: return SDLK_NUMLOCKCLEAR;
            case keycode::PrintScreen: return SDLK_PRINTSCREEN;
            case keycode::Pause: return SDLK_PAUSE;
            case keycode::KP0: return SDLK_KP_0;
            case keycode::KP1: return SDLK_KP_1;
            case keycode::KP2: return SDLK_KP_2;
            case keycode::KP3: return SDLK_KP_3;
            case keycode::KP4: return SDLK_KP_4;
            case keycode::KP5: return SDLK_KP_5;
            case keycode::KP6: return SDLK_KP_6;
            case keycode::KP7: return SDLK_KP_7;
            case keycode::KP8: return SDLK_KP_8;
            case keycode::KP9: return SDLK_KP_9;
            case keycode::KPDecimal: return SDLK_KP_DECIMAL;
            case keycode::KPDivide: return SDLK_KP_DIVIDE;
            case keycode::KPMultiply: return SDLK_KP_MULTIPLY;
            case keycode::KPSubtract: return SDLK_KP_MINUS;
            case keycode::KPAdd: return SDLK_KP_PLUS;
            case keycode::KPEnter: return SDLK_KP_ENTER;
            case keycode::KPEqual: return SDLK_KP_EQUALS;
            case keycode::LeftControl: return SDLK_LCTRL;
            case keycode::LeftShift: return SDLK_LSHIFT;
            case keycode::LeftAlt: return SDLK_LALT;
            case keycode::LeftSuper: return SDLK_LGUI;
            case keycode::RightControl: return SDLK_RCTRL;
            case keycode::RightShift: return SDLK_RSHIFT;
            case keycode::RightAlt: return SDLK_RALT;
            case keycode::RightSuper: return SDLK_RGUI;
            case keycode::Menu: return SDLK_MENU;
            case keycode::D0: return SDLK_0;
            case keycode::D1: return SDLK_1;
            case keycode::D2: return SDLK_2;
            case keycode::D3: return SDLK_3;
            case keycode::D4: return SDLK_4;
            case keycode::D5: return SDLK_5;
            case keycode::D6: return SDLK_6;
            case keycode::D7: return SDLK_7;
            case keycode::D8: return SDLK_8;
            case keycode::D9: return SDLK_9;
            case keycode::A: return SDLK_a;
            case keycode::B: return SDLK_b;
            case keycode::C: return SDLK_c;
            case keycode::D: return SDLK_d;
            case keycode::E: return SDLK_e;
            case keycode::F: return SDLK_f;
            case keycode::G: return SDLK_g;
            case keycode::H: return SDLK_h;
            case keycode::I: return SDLK_i;
            case keycode::J: return SDLK_j;
            case keycode::K: return SDLK_k;
            case keycode::L: return SDLK_l;
            case keycode::M: return SDLK_m;
            case keycode::N: return SDLK_n;
            case keycode::O: return SDLK_o;
            case keycode::P: return SDLK_p;
            case keycode::Q: return SDLK_q;
            case keycode::R: return SDLK_r;
            case keycode::S: return SDLK_s;
            case keycode::T: return SDLK_t;
            case keycode::U: return SDLK_u;
            case keycode::V: return SDLK_v;
            case keycode::W: return SDLK_w;
            case keycode::X: return SDLK_x;
            case keycode::Y: return SDLK_y;
            case keycode::Z: return SDLK_z;
            case keycode::F1: return SDLK_F1;
            case keycode::F2: return SDLK_F2;
            case keycode::F3: return SDLK_F3;
            case keycode::F4: return SDLK_F4;
            case keycode::F5: return SDLK_F5;
            case keycode::F6: return SDLK_F6;
            case keycode::F7: return SDLK_F7;
            case keycode::F8: return SDLK_F8;
            case keycode::F9: return SDLK_F9;
            case keycode::F10: return SDLK_F10;
            case keycode::F11: return SDLK_F11;
            case keycode::F12: return SDLK_F12;
            case keycode::F13: return SDLK_F13;
            case keycode::F14: return SDLK_F14;
            case keycode::F15: return SDLK_F15;
            case keycode::F16: return SDLK_F16;
            case keycode::F17: return SDLK_F17;
            case keycode::F18: return SDLK_F18;
            case keycode::F19: return SDLK_F19;
            case keycode::F20: return SDLK_F20;
            case keycode::F21: return SDLK_F21;
            case keycode::F22: return SDLK_F22;
            case keycode::F23: return SDLK_F23;
            case keycode::F24: return SDLK_F24;
        }
        return SDLK_UNKNOWN;
    }


    constexpr Uint8 mouse_button_to_sdl_button(ugine::utils::mouse_button button) {
        switch(button) {
            case ugine::utils::mouse_button::ButtonLeft: return SDL_BUTTON_LEFT;
            case ugine::utils::mouse_button::ButtonRight: return SDL_BUTTON_RIGHT;
            case ugine::utils::mouse_button::ButtonMiddle: return SDL_BUTTON_MIDDLE;
            case ugine::utils::mouse_button::Button3: return SDL_BUTTON_X1;
            case ugine::utils::mouse_button::Button4: return SDL_BUTTON_X2;
        }
        return 0;
    }

    constexpr mouse_button sdl_button_to_mouse_button(Uint8 button) {
        switch(button) {
            case SDL_BUTTON_LEFT: return mouse_button::ButtonLeft;
            case SDL_BUTTON_RIGHT: return mouse_button::ButtonRight;
            case SDL_BUTTON_MIDDLE: return mouse_button::ButtonMiddle;
            case SDL_BUTTON_X1: return mouse_button::Button3;
            case SDL_BUTTON_X2: return mouse_button::Button4;
        }
        return mouse_button::Button0;
    }
}