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

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Transform.hpp>

class CSpriteInfo;

namespace DonerECS
{
	namespace Json
	{
		class Value;
	}
}

namespace CommonMessages
{
	struct STransformUpdated;
}

namespace sf
{
	class RenderWindow;
	class Transform;
}

class CCompSprite : public DonerECS::CComponent
{
	DECS_DECLARE_COMPONENT_AS_REFLECTABLE(CCompSprite)
public:
	CCompSprite();
	CCompSprite(CCompSprite& rhs);

	void RegisterMessages() override;

	void OnUpdateTransform(const CommonMessages::STransformUpdated& message);

private:
	void DoInit() override;
	void DoDestroy() override;
	std::string m_texturePath;
	sf::Color m_tintColor;
	sf::Vector2f m_origin;
	sf::Texture m_texture;
	CSpriteInfo* m_spriteInfo;
	bool m_smooth;
};

DECS_REFLECT_CLASS_DATA(CCompSprite,
	DECS_REFLECT_VAR(CCompSprite, std::string, m_texturePath, "texture"),
	DECS_REFLECT_VAR(CCompSprite, sf::Color, m_tintColor, "tint"),
	DECS_REFLECT_VAR(CCompSprite, sf::Vector2f, m_origin, "origin"),
	DECS_REFLECT_VAR(CCompSprite, bool, m_smooth, "smooth")
);
