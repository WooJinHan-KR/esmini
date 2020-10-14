/* 
 * esmini - Environment Simulator Minimalistic 
 * https://github.com/esmini/esmini
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 * 
 * Copyright (c) partners of Simulation Scenarios
 * https://sites.google.com/view/simulationscenarios
 */

#pragma once

#include <string>
#include "Controller.hpp"
#include "pugixml.hpp"
#include "Parameters.hpp"
#include "Entities.hpp"
#include "vehicle.hpp"

#define CONTROLLER_FOLLOW_GHOST_NAME "FollowGhostController"

namespace scenarioengine
{
	class ScenarioPlayer;

	// base class for controllers
	class ControllerFollowGhost: public Controller
	{
	public:
		ControllerFollowGhost(std::string name, Entities* entities, ScenarioGateway* gateway,
			Parameters* parameters, OSCProperties* properties);

		static const char* GetTypeNameStatic() { return CONTROLLER_FOLLOW_GHOST_NAME; }
		virtual const char* GetTypeName() { return GetTypeNameStatic(); }
		static const int GetTypeStatic() { return CONTROLLER_TYPE_FOLLOW_GHOST; }
		virtual int GetType() { return GetTypeStatic(); }

		void Init();
		void Step(double timeStep);
		void PostFrame();
		void Activate(int domainMask);
		void ReportKeyEvent(int key, bool down);

	private:
		vehicle::Vehicle vehicle_;
	};

	Controller* InstantiateControllerFollowGhost(std::string name, Entities* entities, ScenarioGateway* gateway,
		Parameters* parameters, OSCProperties* properties);
}