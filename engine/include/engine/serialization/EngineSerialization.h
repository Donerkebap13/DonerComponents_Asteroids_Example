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

#pragma once

#include <donerserializer/DonerDeserialize.h>

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

namespace DonerSerializer
{
	template <>
	class CDeserializationResolver::CDeserializationResolverType<sf::Color>
	{
	public:
		static void Apply(sf::Color& value, const rapidjson::Value& att)
		{
			if (att.IsArray())
			{
				value = sf::Color(att[0].GetInt(), att[1].GetInt(), att[2].GetInt(), att[3].GetInt());
			}
		}
	};

	template <>
	class CDeserializationResolver::CDeserializationResolverType<sf::Vector2f>
	{
	public:
		static void Apply(sf::Vector2f& value, const rapidjson::Value& att)
		{
			if (att.IsArray())
			{
				value = sf::Vector2f(att[0].GetFloat(), att[1].GetFloat());
			}
		}
	};
}
