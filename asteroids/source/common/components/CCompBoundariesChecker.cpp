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

#include <components/CCompBoundariesChecker.h>
#include <engine/graphics/CRenderer.h>
#include <engine/messages/CommonMessages.h>

#include <donerecs/entity/CEntity.h>

CCompBoundariesChecker::CCompBoundariesChecker()
	: m_screenBoundaries(CRenderer::Get()->GetScreenBoundaries())
{
}

void CCompBoundariesChecker::RegisterMessages()
{
	RegisterMessage(&CCompBoundariesChecker::OnAABBUpdated);
	RegisterMessage(&CCompBoundariesChecker::OnDestroyEntity);
}

void CCompBoundariesChecker::OnAABBUpdated(const CommonMessages::SAABBUpdated& message)
{
	if (!m_screenBoundaries.intersects(message.m_AABB))
	{
		m_owner.PostMessage(CommonMessages::SDestroyEntity(message.m_entity));
	}
}

void CCompBoundariesChecker::OnDestroyEntity(CommonMessages::SDestroyEntity& message)
{
	bool success = DonerECS::CEntityManager::Get()->DestroyEntity(message.m_entity);
	if (success)
	{
		printf("Entity destroyed!\n");
	}
	else
	{
		printf("Entity NOT destroyed!\n");
	}
}
