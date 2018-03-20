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

#include <components/CCompShipMovement.h>
#include <engine/messages/CommonMessages.h>
#include <engine/Defines.h>
#include <engine/input/CKeyboard.h>
#include <engine/input/CMouse.h>

#include <donerecs/entity/CEntity.h>

#include <cmath>

DECS_COMPONENT_REFLECTION_IMPL(CCompShipMovement)

CCompShipMovement::CCompShipMovement()
	: m_velocity(0.f)
{}

void CCompShipMovement::DoUpdate(float dt)
{
	sf::Vector2i mousePos = Input::CMouse::Get()->GetMouseScreenPosition();

	CommonMessages::SLookAt lookAtMessage(sf::Vector2f(static_cast<float>(mousePos.x),
													   static_cast<float>(mousePos.y)));
	m_owner.SendMessage(lookAtMessage);

	float dist = m_velocity * dt;
	if (Input::CKeyboard::Get()->IsPressed(Input::KK_S))
	{
		m_owner.SendMessage(CommonMessages::SMoveTransform(-dist));
	}
	else
	{
		m_owner.SendMessage(CommonMessages::SMoveTransform(dist));
	}
}
