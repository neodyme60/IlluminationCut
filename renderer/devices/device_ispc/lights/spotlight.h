// ======================================================================== //
// Copyright 2009-2013 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#pragma once

#include "api/parms.h"
#include "spotlight_ispc.h"

namespace embree
{
  struct SpotLight
  {
    static void* create(const Parms& parms)
    {
      const Vector3f P = parms.getVector3f("P");
      const Vector3f D = parms.getVector3f("D");
      const Color I = parms.getColor("I");
      const float angleMin = parms.getFloat("angleMin");
      const float angleMax = parms.getFloat("angleMax");
      return ispc::SpotLight__new((ispc::vec3f&)P,(ispc::vec3f&)D,(ispc::vec3f&)I,angleMin,angleMax);
    }
  };
}

