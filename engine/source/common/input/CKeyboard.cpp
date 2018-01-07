////////////////////////////////////////////////////////////
//
// MIT License
//
// DonerECS Asteroids Example
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

#include <engine/input/CKeyboard.h>

namespace Input
{
	CKeyboard::CKeyboard()
		: m_currentState()
		, m_previousState()
	{
	}

	void CKeyboard::Update(float /*dt*/)
	{
		for (int i = 0; i < sf::Keyboard::KeyCount; ++i)
		{
			m_previousState[i] = m_currentState[i];
			m_currentState[i] = sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i));
		}
	}

	bool CKeyboard::IsPressed(EKeyboardKey key)
	{
		return m_currentState[key];
	}

	bool CKeyboard::BecomesPressed(EKeyboardKey key)
	{
		return m_currentState[key] && !m_previousState[key];
	}

	bool CKeyboard::IsReleased(EKeyboardKey key)
	{
		return !m_currentState[key];
	}

	bool CKeyboard::BecomesReleased(EKeyboardKey key)
	{
		return !m_currentState[key] && m_previousState[key];
	}
}
