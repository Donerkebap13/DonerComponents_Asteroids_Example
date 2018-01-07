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

#include <engine/application/SApplicationWindowParameters.h>
#include <engine/graphics/CRenderer.h>

#include <SFML/Graphics/RenderWindow.hpp>

CRenderer::CRenderer()
	: m_mainWindow(nullptr)
{
}

CRenderer::~CRenderer()
{
}

bool CRenderer::Init(sf::RenderWindow* mainWindow, const SApplicationWindowParameters& applicationWindowParameters)
{
	m_mainWindow = mainWindow;

	if (applicationWindowParameters.m_hasVerticalSync)
	{
		m_mainWindow->setVerticalSyncEnabled(true);
	}
	else
	{
		m_mainWindow->setFramerateLimit(applicationWindowParameters.m_frameRateLimit);
	}
	return true;
}

void CRenderer::Destroy()
{

}

void CRenderer::Render()
{
	m_mainWindow->clear(sf::Color::Black);
	// m_mainWindow->draw(...);
	m_mainWindow->display();
}
