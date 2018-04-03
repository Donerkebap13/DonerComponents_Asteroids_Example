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

#include <components/CCompSpin.h>
#include <engine/messages/CommonMessages.h>
#include <engine/Defines.h>
#include <engine/input/CKeyboard.h>
#include <engine/input/CMouse.h>
#include <engine/utils/CRandomGenerator.h>

#include <donerecs/entity/CEntity.h>

#include <cmath>

DECS_COMPONENT_REFLECTION_IMPL(CCompSpin)

CCompSpin::CCompSpin()
	: m_velocity(0.f)
	, m_accRotation(0.f)
	, m_direction(0.f)
{
}

void CCompSpin::DoInit()
{
	m_velocity *= CRandomGenerator::Get()->NextFloat(80.f, 120.f) / 100.f;
	m_direction = CRandomGenerator::Get()->Next(0, 1) > 0 ? 1.f : -1.f;
}

void CCompSpin::DoUpdate(float dt)
{
	m_accRotation += (m_velocity * dt) * m_direction;

	CommonMessages::SSetRotation message(m_accRotation);
	m_owner.SendMessage(message);
}
