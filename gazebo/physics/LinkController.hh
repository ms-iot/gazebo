/*
 * Copyright (C) 2012-2014 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef _LINKCONTROLLER_HH_
#define _LINKCONTROLLER_HH_

#include <map>
#include <string>
#include <vector>

#include "gazebo/common/PID.hh"
#include "gazebo/common/Time.hh"
#include "gazebo/physics/PhysicsTypes.hh"
#include "gazebo/transport/TransportTypes.hh"
#include "gazebo/msgs/msgs.hh"

namespace gazebo
{
  namespace physics
  {
    /// \addtogroup gazebo_physics
    /// \{

    /// \class LinkController LinkController.hh physics/physics.hh
    /// \brief A class for manipulating physics::Link
    class LinkController
    {
      /// \brief Constructor
      /// \param[in] _model Model that uses this link controller.
      public: explicit LinkController(ModelPtr _model);

      /// \brief Add a link to control.
      /// \param[in] _link Link to control.
      /// \param[in] _pose Target pose for the link
      public: void AddLink(LinkPtr _link, math::Pose _pose);

      /// \brief Set a link to control.
      /// \param[in] _link Link to control.
      /// \param[in] _pose Target pose for the link
      public: void SetLink(LinkPtr _link, math::Pose _pose);

      /// \brief Update the link control forces.
      public: void Update();

      /// \brief Reset all commands
      public: void Reset();

      /// \brief Callback when a link command message is received.
      /// \param[in] _msg The received message.
      private: void OnLinkCmd(ConstLinkCmdPtr &_msg);

      /// \brief Model to control.
      private: ModelPtr model;

      /// \brief Map of link names to the link pointer.
      private: std::map<std::string, LinkPtr> links;

      /// \brief Position PID controllers, one for each axis.
      private: std::map<std::string, std::vector<common::PID> > posPids;

      /// \brief Orientation PID controllers, one for each axis.
      private: std::map<std::string, std::vector<common::PID> > rotPids;

      /// \brief Wrenches applied to links.
      private: std::map<std::string, physics::Wrench> wrenches;

      /// \brief target link poses
      private: std::map<std::string, math::Pose> targetPoses;

      /// \brief Node for communication.
      private: transport::NodePtr node;

      /// \brief Subscribe to link command.
      private: transport::SubscriberPtr linkCmdSub;

      /// \brief Last time the controller was updated.
      private: common::Time prevUpdateTime;
    };
    /// \}
  }
}
#endif
