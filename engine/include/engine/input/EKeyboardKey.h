////////////////////////////////////////////////////////////
//
// MIT License
//
// DonerComponents Asteroids Example
// Copyright(c) 2018 Donerkebap13
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
////////////////////////////////////////////////////////////

#pragma once

#include <SFML/Window/Keyboard.hpp>

namespace Input
{
	enum EKeyboardKey
	{
		KK_INVALID = sf::Keyboard::Unknown,

		KK_A = sf::Keyboard::A,
		KK_B = sf::Keyboard::B,
		KK_C = sf::Keyboard::C,
		KK_D = sf::Keyboard::D,
		KK_E = sf::Keyboard::E,
		KK_F = sf::Keyboard::F,
		KK_G = sf::Keyboard::G,
		KK_H = sf::Keyboard::H,
		KK_I = sf::Keyboard::I,
		KK_J = sf::Keyboard::J,
		KK_K = sf::Keyboard::K,
		KK_L = sf::Keyboard::L,
		KK_M = sf::Keyboard::M,
		KK_N = sf::Keyboard::N,
		KK_O = sf::Keyboard::O,
		KK_P = sf::Keyboard::P,
		KK_Q = sf::Keyboard::Q,
		KK_R = sf::Keyboard::R,
		KK_S = sf::Keyboard::S,
		KK_T = sf::Keyboard::T,
		KK_U = sf::Keyboard::U,
		KK_V = sf::Keyboard::V,
		KK_W = sf::Keyboard::W,
		KK_X = sf::Keyboard::X,
		KK_Y = sf::Keyboard::Y,
		KK_Z = sf::Keyboard::Z,

		KK_1 = sf::Keyboard::Num1,
		KK_2 = sf::Keyboard::Num2,
		KK_3 = sf::Keyboard::Num3,
		KK_4 = sf::Keyboard::Num4,
		KK_5 = sf::Keyboard::Num5,
		KK_6 = sf::Keyboard::Num6,
		KK_7 = sf::Keyboard::Num7,
		KK_8 = sf::Keyboard::Num8,
		KK_9 = sf::Keyboard::Num9,
		KK_0 = sf::Keyboard::Num0,

		KK_RETURN = sf::Keyboard::Return,
		KK_SCAPE = sf::Keyboard::Escape,
		KK_BACKSPACE = sf::Keyboard::BackSpace,
		KK_TAB = sf::Keyboard::Tab,
		KK_SPACE = sf::Keyboard::Space,

		KK_F1 = sf::Keyboard::F1,
		KK_F2 = sf::Keyboard::F2,
		KK_F3 = sf::Keyboard::F3,
		KK_F4 = sf::Keyboard::F4,
		KK_F5 = sf::Keyboard::F5,
		KK_F6 = sf::Keyboard::F6,
		KK_F7 = sf::Keyboard::F7,
		KK_F8 = sf::Keyboard::F8,
		KK_F9 = sf::Keyboard::F9,
		KK_F10 = sf::Keyboard::F10,
		KK_F11 = sf::Keyboard::F11,
		KK_F12 = sf::Keyboard::F12,

		KK_RIGHT = sf::Keyboard::Right,
		KK_LEFT = sf::Keyboard::Left,
		KK_DOWN = sf::Keyboard::Down,
		KK_UP = sf::Keyboard::Up
	};
}
