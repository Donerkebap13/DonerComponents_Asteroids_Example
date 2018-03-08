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

#include <engine/Defines.h>

#include <SFML/System/Vector2.hpp>

#include <cmath>

class CVectorUtils
{
public:
	static float Length(const sf::Vector2f& v)
	{
		return std::sqrtf((v.x * v.x) + (v.y * v.y));
	}

	static void Normalize(sf::Vector2f& v)
	{
		float length = Length(v);
		v.x /= length;
		v.y /= length;
	}

	static sf::Vector2f Normalized(const sf::Vector2f& v)
	{
		float length = Length(v);
		return sf::Vector2f(v.x / length, v.y / length);
	}

	static float Dot(const sf::Vector2f& v1, const sf::Vector2f& v2)
	{
		return (v1.x * v2.x) + (v1.y * v2.y);
	}

	static float GetAngleInRadians(const sf::Vector2f& v)
	{
		return atan2f(v.x, -v.y);
	}

	static float GetAngleInDegrees(const sf::Vector2f& v)
	{
		return ENGINE_RAD_TO_DEG(GetAngleInRadians(v));
	}
};
