/*
 * Copyright (C) 2015 Open Source Robotics Foundation
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
#ifndef _ISSUE1434PLUGINEXAMPLE_HH_
#define _ISSUE1434PLUGINEXAMPLE_HH_

#include <QObject>
#include <gazebo/common/Plugin.hh>
#include <gazebo/gui/GuiPlugin.hh>
#ifndef Q_MOC_RUN  // See: https://bugreports.qt-project.org/browse/QTBUG-22829
# include <gazebo/transport/transport.hh>
# include <gazebo/gui/gui.hh>
#endif

namespace gazebo
{
  class GAZEBO_VISIBLE Issue1434PluginExample : public GUIPlugin
  {
    Q_OBJECT

    /// \brief Constructor
    public: Issue1434PluginExample();

    /// \brief Destructor
    public: virtual ~Issue1434PluginExample() {}

    /// Documentation inherited
    public: void Load(sdf::ElementPtr /*_sdf*/);
  };
}

#endif
