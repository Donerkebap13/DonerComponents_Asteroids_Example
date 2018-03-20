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

#pragma once

struct SApplicationWindowParameters;
class CRenderer;

namespace DonerECS
{
	class CDonerECSSystems;
}

namespace Input
{
	class CKeyboard;
	class CMouse;
}

namespace sf
{
	class RenderWindow;
}

class CApplicationBase
{
public:
	CApplicationBase();
	virtual ~CApplicationBase();

	bool Init(const SApplicationWindowParameters& applicationWindowParameters);
	void Update();
	void Destroy();

protected:
	void RegisterComponents();

	virtual bool InitProject() = 0;
	virtual void UpdateProject(float dt) = 0;
	virtual void DestroyProject() = 0;

	virtual void RegisterComponentsProject() = 0;

	sf::RenderWindow* m_mainWindow;

	CRenderer* m_renderer;
	Input::CKeyboard* m_keyboard;
	Input::CMouse* m_mouse;

	DonerECS::CDonerECSSystems* m_donerECSSystems;
};
