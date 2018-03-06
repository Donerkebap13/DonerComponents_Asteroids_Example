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

#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/Transformable.hpp>

namespace CommonMessages
{
	struct SUpdateTransformForRender
	{
		SUpdateTransformForRender(const sf::Transform& transform)
			: m_transform(transform)
		{}
		const sf::Transform& m_transform;
	};

	struct SParentTransformUpdated
	{
		SParentTransformUpdated(const sf::Transform& transform)
			: m_transform(transform)
		{}
		const sf::Transform& m_transform;
	};

	struct SGetTransform
	{
		SGetTransform(sf::Transform** transform)
			: m_transform(transform)
		{}
		sf::Transform** m_transform;
	};

	struct SSetTransformable
	{
		SSetTransformable(sf::Transformable& transformable)
			: m_transformable(transformable)
		{}
		sf::Transformable& m_transformable;
	};

	struct SGetTransformable
	{
		SGetTransformable(sf::Transformable& transformable)
			: m_transformable(transformable)
		{}
		sf::Transformable& m_transformable;
	};

	struct SSetPosition
	{
		SSetPosition(const sf::Vector2f& position)
			: m_position(position)
		{}
		sf::Vector2f m_position;
	};

	struct SSetRotation
	{
		SSetRotation(float angle)
			: m_angle(angle)
		{}
		float m_angle;
	};

	struct SSetScale
	{
		SSetScale(const sf::Vector2f& scale)
			: m_scale(scale)
		{}
		sf::Vector2f m_scale;
	};

	struct SMoveTransform
	{
		SMoveTransform(const sf::Vector2f& offset)
			: m_offset(offset)
		{}
		sf::Vector2f m_offset;
	};
}
