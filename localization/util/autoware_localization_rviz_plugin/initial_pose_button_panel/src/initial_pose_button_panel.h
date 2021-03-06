/*
 * Copyright (c) 2018, TierIV Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#pragma once

#include <string>

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSettings>
#ifndef Q_MOC_RUN
#include <ros/ros.h>
#include <rviz/panel.h>
#include <rviz/properties/ros_topic_property.h>
#endif
#include <geometry_msgs/PoseWithCovarianceStamped.h>

#include "autoware_localization_srvs/PoseWithCovarianceStamped.h"

namespace autoware_localization_rviz_plugin
{
class InitialPoseButtonPanel : public rviz::Panel
{
  Q_OBJECT
public:
  InitialPoseButtonPanel(QWidget * parent = 0);
  void callbackPoseCov(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr & msg);

public Q_SLOTS:
  void editTopic();
  void pushInitialzeButton();

protected:
  ros::NodeHandle nh_;
  ros::Subscriber pose_cov_sub_;

  ros::ServiceClient client_;

  QLabel * topic_label_;
  QLineEdit * topic_edit_;
  QPushButton * initialize_button_;
  QLabel * status_label_;

  rviz::RosTopicProperty * property_topic_;

  geometry_msgs::PoseWithCovarianceStamped pose_cov_msg_;
};

}  // end namespace autoware_localization_rviz_plugin
