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

#include <components/CCompAsteroidSpawner.h>
#include <engine/graphics/CRenderer.h>
#include <engine/messages/CommonMessages.h>
#include <engine/input/CKeyboard.h>
#include <engine/utils/CRandomGenerator.h>

#include <donerecs/CDonerECSSystems.h>
#include <donerecs/entity/CEntity.h>
#include <donerecs/entity/CPrefabManager.h>

#include <algorithm>

DECS_COMPONENT_REFLECTION_IMPL(CCompAsteroidSpawner)

CCompAsteroidSpawner::CCompAsteroidSpawner()
	: m_prefabManager(DonerECS::CDonerECSSystems::Get()->GetPrefabManager())
	, m_checkCadence(1.f)
	, m_maxAsteroids(10)
	, m_spawnArea(0.5f, 0.5f)
	, m_screenBoundaries(CRenderer::Get()->GetScreenBoundaries())
	, m_accTime(0.f)
{
	m_spawnAreaInPixels.x = m_screenBoundaries.width * m_spawnArea.x;
	m_spawnAreaInPixels.y = m_screenBoundaries.height * m_spawnArea.y;
}

void CCompAsteroidSpawner::DoActivate()
{
	SpawnAsteroids();
}

void CCompAsteroidSpawner::DoUpdate(float dt)
{
	m_accTime -= dt;
	if (m_accTime <= 0.f)
	{
		m_accTime = m_checkCadence;
		SpawnAsteroids();
	}
}

void CCompAsteroidSpawner::SpawnAsteroids()
{
	DeleteDestroyedAsteroids();

	int asteroidsLeft = m_maxAsteroids - m_activeAsteroids.size();

	for (int i = 0; i < asteroidsLeft; ++i)
	{
		SpawnSingleAsteroid();
	}
}

void CCompAsteroidSpawner::SpawnSingleAsteroid()
{
	static constexpr float dummySpawnSize = 5.f;
	static constexpr float dummySpawnMargin = 20.f;

	sf::FloatRect spawn;
	spawn.left = CRandomGenerator::Get()->NextFloat(-dummySpawnMargin, m_screenBoundaries.width + dummySpawnMargin);
	spawn.top = CRandomGenerator::Get()->NextFloat(-dummySpawnMargin, m_screenBoundaries.height + dummySpawnMargin);
	spawn.width = dummySpawnSize;
	spawn.height = dummySpawnSize;

	while (m_screenBoundaries.intersects(spawn))
	{
		spawn.left = CRandomGenerator::Get()->NextFloat(-dummySpawnMargin, m_screenBoundaries.width + dummySpawnMargin);
		spawn.top = CRandomGenerator::Get()->NextFloat(-dummySpawnMargin, m_screenBoundaries.height + dummySpawnMargin);
	}

	DonerECS::CEntity* asteroidEntity = m_prefabManager->ClonePrefab(DonerECS::CStrID(m_prefabName.c_str()));
	if (asteroidEntity)
	{
		sf::Vector2f lookAt;
		lookAt.x = CRandomGenerator::Get()->NextFloat(m_screenBoundaries.width * 0.5f - m_spawnAreaInPixels.x, m_screenBoundaries.width * 0.5f + m_spawnAreaInPixels.x);
		lookAt.y = CRandomGenerator::Get()->NextFloat(m_screenBoundaries.height * 0.5f - m_spawnAreaInPixels.y, m_screenBoundaries.height * 0.5f + m_spawnAreaInPixels.y);

		asteroidEntity->SendMessage(CommonMessages::SSetPosition(sf::Vector2f(spawn.left, spawn.top)));
		asteroidEntity->SendMessage(CommonMessages::SLookAt(lookAt));
		
		m_activeAsteroids.emplace_back(asteroidEntity);
	}
}

void CCompAsteroidSpawner::DeleteDestroyedAsteroids()
{
	m_activeAsteroids.erase(std::remove_if(
		m_activeAsteroids.begin(), m_activeAsteroids.end()
		, [](DonerECS::CHandle& handle) { return !static_cast<bool>(handle); })
		, m_activeAsteroids.end()
	);
}
