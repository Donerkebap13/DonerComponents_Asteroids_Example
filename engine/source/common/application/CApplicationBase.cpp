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

#include <engine/application/CApplicationBase.h>
#include <engine/application/SApplicationWindowParameters.h>
#include <engine/input/CKeyboard.h>
#include <engine/input/CMouse.h>
#include <engine/graphics/CRenderer.h>

#include <donerecs/DonerECSSystems.h>

#include <engine/components/CCompTransform.h>
#include <engine/components/CCompSprite.h>

#include <SFML/Config.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>

CApplicationBase::CApplicationBase()
	: m_entityManager(nullptr)
	, m_componentFactoryManager(nullptr)
{
}

CApplicationBase::~CApplicationBase()
{
	delete m_mainWindow;
}

bool CApplicationBase::Init(const SApplicationWindowParameters& applicationWindowParameters)
{
	m_keyboard = Input::CKeyboard::CreateInstance();

	sf::Uint32 windowStyle = applicationWindowParameters.m_hasTitleBar ? sf::Style::Titlebar : sf::Style::None;
	windowStyle |= applicationWindowParameters.m_hasCloseButton ? sf::Style::Close : sf::Style::None;
	windowStyle |= applicationWindowParameters.m_hasResizeButton ? sf::Style::Resize : sf::Style::None;
	windowStyle |= applicationWindowParameters.m_isFullScreen ? sf::Style::Fullscreen : sf::Style::None;

	m_mainWindow = new sf::RenderWindow(sf::VideoMode(applicationWindowParameters.m_xRes, applicationWindowParameters.m_yRes)
								  , applicationWindowParameters.m_windowTitle
								  , windowStyle
								  );

	m_renderer = CRenderer::CreateInstance();
	if (!m_renderer->Init(m_mainWindow, applicationWindowParameters))
	{
		return false;
	}

	m_mouse = Input::CMouse::CreateInstance();
	if (!m_mouse->Init(m_mainWindow))
	{
		return false;
	}

	DonerECS::InitializeDonerECSSystems();
	m_componentFactoryManager = DonerECS::CComponentFactoryManager::Get();
	m_entityManager = DonerECS::CEntityManager::Get();

	RegisterComponents();

	return InitProject();
}

void CApplicationBase::Update() 
{
	sf::Clock clock;
	while (m_mainWindow->isOpen())
	{
		float elapsed = clock.restart().asSeconds();
		sf::Event event;
		while (m_mainWindow->pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					m_mainWindow->close();
				break;
				case sf::Event::Resized:
				break;
				case sf::Event::GainedFocus:
				break;
				case sf::Event::LostFocus:
				break;
				default:
				break;
			}
			if (event.type == sf::Event::Closed)
			{
				m_mainWindow->close();
				break;
			}
		}
		m_keyboard->Update(elapsed);
		m_mouse->Update(elapsed);

		m_componentFactoryManager->Update(elapsed);
		m_entityManager->SendPostMsgs();

		UpdateProject(elapsed);

		m_renderer->Render();
	}
}

void CApplicationBase::Destroy() 
{
	DestroyProject( );

	DonerECS::DestroyDonerECSSystems();
	m_componentFactoryManager = nullptr;

	CRenderer::DestroyInstance();
	Input::CKeyboard::DestroyInstance();
	Input::CMouse::DestroyInstance();
}

void CApplicationBase::RegisterComponents()
{
	ADD_COMPONENT_FACTORY("transform", CCompTransform, 2048);
	ADD_COMPONENT_FACTORY("sprite", CCompSprite, 2048);
	
	RegisterComponentsProject();
}
