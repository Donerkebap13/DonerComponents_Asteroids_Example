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

#include <engine/components/CCompCollider.h>
#include <engine/messages/CommonMessages.h>
#include <engine/physics/CCollisionManager.h>

#include <donercomponents/gameObject/CGameObject.h>

CCompCollider::CCompCollider()
	: m_collisionManager(*CCollisionManager::Get())
{
}

void CCompCollider::RegisterMessages()
{
	RegisterMessage(&CCompCollider::OnAABBUpdated);
	RegisterMessage(&CCompCollider::OnCollision);
}

void CCompCollider::OnAABBUpdated(const CommonMessages::SAABBUpdated& message)
{
	m_collisionManager.AddCollisionBox(m_owner, message.m_AABB);
}
