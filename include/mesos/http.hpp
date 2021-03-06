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

#ifndef __MESOS_HTTP_HPP__
#define __MESOS_HTTP_HPP__

#include <ostream>

#include <stout/unreachable.hpp>

namespace mesos {

const char APPLICATION_JSON[] = "application/json";
const char APPLICATION_PROTOBUF[] = "application/x-protobuf";

// Possible content-types that can be used as responses for
// the Mesos HTTP API.
enum class ContentType
{
  PROTOBUF,
  JSON
};


inline std::ostream& operator<<(std::ostream& stream, ContentType contentType)
{
  switch (contentType) {
    case ContentType::PROTOBUF: {
      return stream << APPLICATION_PROTOBUF;
    }
    case ContentType::JSON: {
      return stream << APPLICATION_JSON;
    }
  }

  UNREACHABLE();
}

} // namespace mesos {

#endif // __MESOS_HTTP_HPP__
