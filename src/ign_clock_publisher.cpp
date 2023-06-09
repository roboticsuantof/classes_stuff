/*
 * Copyright (C) 2020 Open Source Robotics Foundation
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
 
#include <iostream>
#include <string>
#include <ignition/msgs.hh>
#include <ignition/transport.hh>

ignition::transport::v11::Node::Publisher pub;

//////////////////////////////////////////////////
/// \brief Function called each time a topic update is received.
void cb(const ignition::msgs::WorldStatistics &_msg)
{
//   std::cout << "Msg: " << _msg.data() << std::endl << std::endl;
  ignition::msgs::Clock clock_msg;
  clock_msg.set_allocated_sim(new ignition::msgs::Time(_msg.sim_time()));
  clock_msg.set_allocated_real(new ignition::msgs::Time(_msg.real_time()));
  pub.Publish(clock_msg);
}

//////////////////////////////////////////////////
int main(int argc, char **argv)
{
  ignition::transport::Node node;
  std::string topic = "/stats";

  pub = node.Advertise<ignition::msgs::Clock>("/clock");

  // Subscribe to a topic by registering a callback.
  if (!node.Subscribe(topic, cb))
  {
    std::cerr << "Error subscribing to topic [" << topic << "]" << std::endl;
    return -1;
  }

  // Zzzzzz.
  ignition::transport::waitForShutdown();

  return 0;
}
