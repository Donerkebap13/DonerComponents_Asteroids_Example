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

#include <donerecs/json/json.h>

CCompTransform::CCompTransform()
{
}

CCompTransform::CCompTransform(CCompTransform& rhs)
{
	m_transform = rhs.m_transform;
}

void CCompTransform::ParseAtts(const DonerECS::Json::Value& atts)
{
	sf::Vector2f pos;
	const DonerECS::Json::Value& positionJson = atts["position"];
	if (!positionJson.isNull() && positionJson.isArray())
	{
		pos.x = positionJson[0].asFloat();
		pos.y = positionJson[1].asFloat();
	}
	m_transform.translate(pos);

	float rotation = 0.0f;
	const DonerECS::Json::Value& rotationJson = atts["rotation"];
	if (!positionJson.isNull() && positionJson.isInt())
	{
		rotation  = rotationJson.asFloat();
	}
	m_transform.rotate(rotation);

	sf::Vector2f scale;
	const DonerECS::Json::Value& scaleJson = atts["scale"];
	if (!scaleJson.isNull() && scaleJson.isArray())
	{
		scale.x = scaleJson[0].asFloat();
		scale.y = scaleJson[1].asFloat();
	}
	m_transform.scale(scale);
}
