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

#include <engine/components/CCompTransform.h>
#include <engine/messages/CommonMessages.h>

#include <donerecs/json/json.h>
#include <donerecs/entity/CEntity.h>

#include <SFML/Graphics/Transformable.hpp>


DECS_COMPONENT_REFLECTION_IMPL(CCompTransform)

CCompTransform::CCompTransform()
	: m_position(0.f, 0.f)
	, m_rotation(0)
	, m_scale(0.f, 0.f)
	, m_dirty(false)
{
}

void CCompTransform::RegisterMessages()
{
	RegisterMessage(&CCompTransform::OnSetPosition);
	RegisterMessage(&CCompTransform::OnSetRotation);
	RegisterMessage(&CCompTransform::OnSetScale);
	RegisterMessage(&CCompTransform::OnGetTransform);
	RegisterMessage(&CCompTransform::OnParentTransformUpdated);
}

void CCompTransform::DoInit()
{
	UpdateWorldTransform();
}

void CCompTransform::DoUpdate(float dt)
{
	if (m_dirty)
	{
		CommonMessages::SUpdateTransformForRender message(m_worldTransform);
		m_owner.SendMessage(message);
		m_dirty = false;
	}
}

void CCompTransform::OnSetPosition(CommonMessages::SSetPosition& message)
{
	m_position = message.m_position;
	UpdateWorldTransform();
}

void CCompTransform::OnSetRotation(CommonMessages::SSetRotation& message)
{
	m_rotation = message.m_angle;
	UpdateWorldTransform();
}

void CCompTransform::OnSetScale(CommonMessages::SSetScale& message)
{
	m_scale = message.m_scale;
	UpdateWorldTransform();
}

void CCompTransform::OnGetTransform(CommonMessages::SGetTransform& message)
{
	*message.m_transform = &m_worldTransform;
}

void CCompTransform::OnParentTransformUpdated(CommonMessages::SParentTransformUpdated& message)
{
	UpdateWorldTransform();
}

void CCompTransform::UpdateWorldTransform()
{
	sf::Transformable localTransform;
	localTransform.setPosition(m_position);
	localTransform.setRotation(m_rotation);
	localTransform.setScale(m_scale);

	sf::Transform* parent_transform = nullptr;
	CommonMessages::SGetTransform getTransformMessage(&parent_transform);
	DonerECS::CHandle parent = static_cast<DonerECS::CEntity*>(m_owner)->GetParent();
	parent.SendMessage(getTransformMessage);
	if (parent_transform)
	{
		m_worldTransform = *parent_transform * localTransform.getTransform();
	}
	else
	{
		m_worldTransform = localTransform.getTransform();
	}
	
	CommonMessages::SParentTransformUpdated parentTransformUpdatedMessage(m_worldTransform);
	m_owner.SendMessageToChildren(parentTransformUpdatedMessage);
	m_dirty = true;
}
