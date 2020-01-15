#ifndef __RPFlatParams_h__
#define __RPFlatParams_h__

#include "CondFormats/Serialization/interface/Serializable.h"

#include <vector>
class RPFlatParams{
 public:
  struct EP {
    float x[200];
    float y[200];
    float xSub1[200];
    float ySub1[200];
    float xSub2[200];
    float ySub2[200];
    int RPNameIndx[200];
  
  COND_SERIALIZABLE;
};
  RPFlatParams(){}
  virtual ~RPFlatParams(){}
  std::vector<EP> m_table;

 COND_SERIALIZABLE;
};

#endif

