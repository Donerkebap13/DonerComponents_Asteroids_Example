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

#include <application/CApplication.h>
#include <components/CCompMoveStraightLine.h>
#include <components/CCompShoot.h>
#include <components/CCompShipMovement.h>

#include <donerecs/entity/CEntityParser.h>

CApplication::CApplication()
{
}

CApplication::~CApplication()
{
}

bool CApplication::InitProject() 
{
	DonerECS::CEntityParser parser;
	
	// Prefabs
	parser.ParseSceneFromFile("res/common/prefabs/bullet.json");
	
	parser.ParseSceneFromFile("res/common/scenes/test_player.json");

	return true; 
}

void CApplication::RegisterComponentsProject()
{
	ADD_COMPONENT_FACTORY("move_straight_line", CCompMoveStraightLine, 4096);
	ADD_COMPONENT_FACTORY("shoot", CCompShoot, 1);
	ADD_COMPONENT_FACTORY("ship_movement", CCompShipMovement, 1);
}
