// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef __LOCAL_FLAGS_HPP__
#define __LOCAL_FLAGS_HPP__

#include <stout/flags.hpp>

#include "logging/flags.hpp"

namespace mesos {
namespace internal {
namespace local {

class Flags : public logging::Flags
{
public:
  Flags()
  {
    add(&Flags::work_dir,
        "work_dir",
        "Path of the master/agent work directory. This is where the "
        "persistent\n"
        "information of the cluster will be stored. Note that locations like\n"
        "`/tmp` which are cleaned automatically are not suitable for the work\n"
        "directory when running in production, since long-running masters "
        "could\n"
        "lose data when cleanup occurs. (Example: `/var/lib/mesos/master`)",
        "/tmp/mesos/local");

    add(&Flags::num_slaves,
        "num_slaves",
        "Number of agents to launch for local cluster",
        1);
  }

  std::string work_dir;
  int num_slaves;
};

} // namespace local {
} // namespace internal {
} // namespace mesos {

#endif // __LOCAL_FLAGS_HPP__
