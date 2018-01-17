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

#include <engine/reflection/EngineReflection.h>

namespace DonerECS
{
	namespace Reflection
	{
		Optional<sf::Color> SDataReflector<sf::Color>::ReflectData(const DonerECS::Json::Value& att)
		{
			if (!att.isNull() && att.isArray())
			{
				return Optional<sf::Color>(sf::Color(att[0].asInt(), att[1].asInt(), att[2].asInt(), att[3].asInt()));
			}
			return Optional<sf::Color>();
		}

		Optional<sf::Vector2f> SDataReflector<sf::Vector2f>::ReflectData(const DonerECS::Json::Value& att)
		{
			if (!att.isNull() && att.isArray())
			{
				return Optional<sf::Vector2f>(sf::Vector2f(att[0].asFloat(), att[1].asFloat()));
			}
			return Optional<sf::Vector2f>();
		}
	}
}
