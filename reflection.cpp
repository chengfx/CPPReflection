#include "reflection.h"
#include <string>
#include <map>

using namespace std;

namespace reflection{
  
  void* CKClassFactory::getClassByName(string className)
  {
    auto iter = m_classMap.find(className);
    if(m_classMap.find(className) == m_classMap.end())
      return NULL;
    else
      return iter->second();
  }

  void CKClassFactory::registClass(string name, createClass method)
  {
    m_classMap.insert(pair<string, createClass>(name, method));
  }

  CKClassFactory& CKClassFactory::sharedClassFactory()
  {
    static CKClassFactory _sharedClassFactory;
    return _sharedClassFactory;
  }

}
