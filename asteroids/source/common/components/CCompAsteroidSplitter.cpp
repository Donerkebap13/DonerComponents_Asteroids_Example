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

#include <components/CCompAsteroidSplitter.h>
#include <engine/messages/CommonMessages.h>
#include <engine/utils/CRandomGenerator.h>

#include <donercomponents/CDonerComponentsSystems.h>
#include <donercomponents/gameObject/CGameObject.h>
#include <donercomponents/gameObject/CPrefabManager.h>

DONER_SERIALIZABLE_COMPONENT_IMPL(CCompAsteroidSplitter)

CCompAsteroidSplitter::CCompAsteroidSplitter()
	: m_prefabManager(DonerComponents::CDonerComponentsSystems::Get()->GetPrefabManager())
	, m_maxAsteroids(4)
{
}

void CCompAsteroidSplitter::RegisterMessages()
{
	RegisterMessage(&CCompAsteroidSplitter::OnSplitAsteroid);
}

void CCompAsteroidSplitter::OnSplitAsteroid(const AsteroidsMessages::SSplitAsteroid& message)
{
	float anglePerAsteroid = 360.f / m_maxAsteroids;
	float randomInitialAngle = CRandomGenerator::Get()->NextFloat(360.f);
	for (int i = 0; i < m_maxAsteroids; ++i)
	{
		float angle = (i * anglePerAsteroid) + randomInitialAngle;
		SpawnSingleAsteroid(angle);
	}
}

void CCompAsteroidSplitter::SpawnSingleAsteroid(float angle)
{
	DonerComponents::CGameObject* asteroidGameObject = m_prefabManager->ClonePrefab(DonerComponents::CStrID(m_prefabName.c_str()));
	if (asteroidGameObject)
	{
		sf::Vector2f position;
		m_owner.SendMessage(CommonMessages::SGetPosition(position));

		asteroidGameObject->SendMessage(CommonMessages::SSetPosition(position));
		asteroidGameObject->SendMessage(CommonMessages::SSetRotation(angle));
	}
}
