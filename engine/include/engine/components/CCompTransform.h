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

#include <engine/reflection/EngineReflection.h>

#include <donerecs/component/CComponent.h>

#include <SFML/Graphics/Transform.hpp>

namespace sf
{
	class Transformable;
}

namespace CommonMessages
{
	struct SGetTransform;
	struct SGetTransformable;
	struct SSetTransformable;
	struct SSetPosition;
	struct SSetRotation;
	struct SSetScale;
	struct SParentTransformUpdated;
	struct SMoveTransform;
	struct SLookAt;
}

class CCompTransform : public DonerECS::CComponent
{
	DECS_DECLARE_COMPONENT_AS_REFLECTABLE(CCompTransform)
public:
	CCompTransform();
	CCompTransform(CCompTransform& rhs) = default;
	CCompTransform(CCompTransform&& rhs) = default;
	CCompTransform& operator=(CCompTransform& rhs) = default;

	void RegisterMessages() override;

	bool IsDirty() const { return m_dirty; }

	void OnSetPosition(CommonMessages::SSetPosition& message);
	void OnSetRotation(CommonMessages::SSetRotation& message);
	void OnSetScale(CommonMessages::SSetScale& message);
	void OnGetTransform(CommonMessages::SGetTransform& message);
	void OnGetTransformable(CommonMessages::SGetTransformable& message);
	void OnSetTransformable(CommonMessages::SSetTransformable& message);
	void OnMoveTransform(CommonMessages::SMoveTransform& message);
	void OnParentTransformUpdated(CommonMessages::SParentTransformUpdated& message);
	void OnLookAt(CommonMessages::SLookAt& message);

private:
	void DoInit() override;
	void DoUpdate(float dt) override;

	void UpdateWorldTransform();
	void UpdateWorldTransform(const sf::Transformable& localTransform);

	sf::Vector2f m_position;
	float m_rotation;
	sf::Vector2f m_scale;

	sf::Transform m_worldTransform;

	bool m_dirty;
};

DECS_DEFINE_REFLECTION_DATA(CCompTransform,
	DECS_ADD_VAR_INFO(m_position, "position"),
	DECS_ADD_VAR_INFO(m_rotation, "rotation"),
	DECS_ADD_VAR_INFO(m_scale, "scale")
);
