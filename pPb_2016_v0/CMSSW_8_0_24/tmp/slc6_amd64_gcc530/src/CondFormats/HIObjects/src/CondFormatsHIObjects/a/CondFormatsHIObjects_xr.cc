// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME tmpdIslc6_amd64_gcc530dIsrcdICondFormatsdIHIObjectsdIsrcdICondFormatsHIObjectsdIadICondFormatsHIObjects_xr

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "src/CondFormats/HIObjects/src/classes.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *CentralityTable_Dictionary();
   static void CentralityTable_TClassManip(TClass*);
   static void *new_CentralityTable(void *p = 0);
   static void *newArray_CentralityTable(Long_t size, void *p);
   static void delete_CentralityTable(void *p);
   static void deleteArray_CentralityTable(void *p);
   static void destruct_CentralityTable(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CentralityTable*)
   {
      ::CentralityTable *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CentralityTable));
      static ::ROOT::TGenericClassInfo 
         instance("CentralityTable", "CondFormats/HIObjects/interface/CentralityTable.h", 7,
                  typeid(::CentralityTable), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CentralityTable_Dictionary, isa_proxy, 0,
                  sizeof(::CentralityTable) );
      instance.SetNew(&new_CentralityTable);
      instance.SetNewArray(&newArray_CentralityTable);
      instance.SetDelete(&delete_CentralityTable);
      instance.SetDeleteArray(&deleteArray_CentralityTable);
      instance.SetDestructor(&destruct_CentralityTable);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CentralityTable*)
   {
      return GenerateInitInstanceLocal((::CentralityTable*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::CentralityTable*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CentralityTable_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CentralityTable*)0x0)->GetClass();
      CentralityTable_TClassManip(theClass);
   return theClass;
   }

   static void CentralityTable_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CentralityTablecLcLBinValues_Dictionary();
   static void CentralityTablecLcLBinValues_TClassManip(TClass*);
   static void *new_CentralityTablecLcLBinValues(void *p = 0);
   static void *newArray_CentralityTablecLcLBinValues(Long_t size, void *p);
   static void delete_CentralityTablecLcLBinValues(void *p);
   static void deleteArray_CentralityTablecLcLBinValues(void *p);
   static void destruct_CentralityTablecLcLBinValues(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CentralityTable::BinValues*)
   {
      ::CentralityTable::BinValues *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CentralityTable::BinValues));
      static ::ROOT::TGenericClassInfo 
         instance("CentralityTable::BinValues", "CondFormats/HIObjects/interface/CentralityTable.h", 11,
                  typeid(::CentralityTable::BinValues), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CentralityTablecLcLBinValues_Dictionary, isa_proxy, 0,
                  sizeof(::CentralityTable::BinValues) );
      instance.SetNew(&new_CentralityTablecLcLBinValues);
      instance.SetNewArray(&newArray_CentralityTablecLcLBinValues);
      instance.SetDelete(&delete_CentralityTablecLcLBinValues);
      instance.SetDeleteArray(&deleteArray_CentralityTablecLcLBinValues);
      instance.SetDestructor(&destruct_CentralityTablecLcLBinValues);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CentralityTable::BinValues*)
   {
      return GenerateInitInstanceLocal((::CentralityTable::BinValues*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::CentralityTable::BinValues*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CentralityTablecLcLBinValues_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CentralityTable::BinValues*)0x0)->GetClass();
      CentralityTablecLcLBinValues_TClassManip(theClass);
   return theClass;
   }

   static void CentralityTablecLcLBinValues_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CentralityTablecLcLCBin_Dictionary();
   static void CentralityTablecLcLCBin_TClassManip(TClass*);
   static void *new_CentralityTablecLcLCBin(void *p = 0);
   static void *newArray_CentralityTablecLcLCBin(Long_t size, void *p);
   static void delete_CentralityTablecLcLCBin(void *p);
   static void deleteArray_CentralityTablecLcLCBin(void *p);
   static void destruct_CentralityTablecLcLCBin(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CentralityTable::CBin*)
   {
      ::CentralityTable::CBin *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CentralityTable::CBin));
      static ::ROOT::TGenericClassInfo 
         instance("CentralityTable::CBin", "CondFormats/HIObjects/interface/CentralityTable.h", 18,
                  typeid(::CentralityTable::CBin), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CentralityTablecLcLCBin_Dictionary, isa_proxy, 0,
                  sizeof(::CentralityTable::CBin) );
      instance.SetNew(&new_CentralityTablecLcLCBin);
      instance.SetNewArray(&newArray_CentralityTablecLcLCBin);
      instance.SetDelete(&delete_CentralityTablecLcLCBin);
      instance.SetDeleteArray(&deleteArray_CentralityTablecLcLCBin);
      instance.SetDestructor(&destruct_CentralityTablecLcLCBin);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CentralityTable::CBin*)
   {
      return GenerateInitInstanceLocal((::CentralityTable::CBin*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::CentralityTable::CBin*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CentralityTablecLcLCBin_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CentralityTable::CBin*)0x0)->GetClass();
      CentralityTablecLcLCBin_TClassManip(theClass);
   return theClass;
   }

   static void CentralityTablecLcLCBin_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RPFlatParams_Dictionary();
   static void RPFlatParams_TClassManip(TClass*);
   static void *new_RPFlatParams(void *p = 0);
   static void *newArray_RPFlatParams(Long_t size, void *p);
   static void delete_RPFlatParams(void *p);
   static void deleteArray_RPFlatParams(void *p);
   static void destruct_RPFlatParams(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RPFlatParams*)
   {
      ::RPFlatParams *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RPFlatParams));
      static ::ROOT::TGenericClassInfo 
         instance("RPFlatParams", "CondFormats/HIObjects/interface/RPFlatParams.h", 7,
                  typeid(::RPFlatParams), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RPFlatParams_Dictionary, isa_proxy, 0,
                  sizeof(::RPFlatParams) );
      instance.SetNew(&new_RPFlatParams);
      instance.SetNewArray(&newArray_RPFlatParams);
      instance.SetDelete(&delete_RPFlatParams);
      instance.SetDeleteArray(&deleteArray_RPFlatParams);
      instance.SetDestructor(&destruct_RPFlatParams);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RPFlatParams*)
   {
      return GenerateInitInstanceLocal((::RPFlatParams*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::RPFlatParams*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RPFlatParams_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RPFlatParams*)0x0)->GetClass();
      RPFlatParams_TClassManip(theClass);
   return theClass;
   }

   static void RPFlatParams_TClassManip(TClass* theClass){
      TDataMember* theMember_m_table = theClass->GetDataMember("m_table");
      theMember_m_table->CreateAttributeMap();
      TDictAttributeMap* memberAttrMap_m_table( theMember_m_table->GetAttributeMap() );
      memberAttrMap_m_table->AddProperty("mapping","blob");
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RPFlatParamscLcLEP_Dictionary();
   static void RPFlatParamscLcLEP_TClassManip(TClass*);
   static void *new_RPFlatParamscLcLEP(void *p = 0);
   static void *newArray_RPFlatParamscLcLEP(Long_t size, void *p);
   static void delete_RPFlatParamscLcLEP(void *p);
   static void deleteArray_RPFlatParamscLcLEP(void *p);
   static void destruct_RPFlatParamscLcLEP(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RPFlatParams::EP*)
   {
      ::RPFlatParams::EP *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RPFlatParams::EP));
      static ::ROOT::TGenericClassInfo 
         instance("RPFlatParams::EP", "CondFormats/HIObjects/interface/RPFlatParams.h", 9,
                  typeid(::RPFlatParams::EP), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RPFlatParamscLcLEP_Dictionary, isa_proxy, 0,
                  sizeof(::RPFlatParams::EP) );
      instance.SetNew(&new_RPFlatParamscLcLEP);
      instance.SetNewArray(&newArray_RPFlatParamscLcLEP);
      instance.SetDelete(&delete_RPFlatParamscLcLEP);
      instance.SetDeleteArray(&deleteArray_RPFlatParamscLcLEP);
      instance.SetDestructor(&destruct_RPFlatParamscLcLEP);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RPFlatParams::EP*)
   {
      return GenerateInitInstanceLocal((::RPFlatParams::EP*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::RPFlatParams::EP*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RPFlatParamscLcLEP_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RPFlatParams::EP*)0x0)->GetClass();
      RPFlatParamscLcLEP_TClassManip(theClass);
   return theClass;
   }

   static void RPFlatParamscLcLEP_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *UETable_Dictionary();
   static void UETable_TClassManip(TClass*);
   static void *new_UETable(void *p = 0);
   static void *newArray_UETable(Long_t size, void *p);
   static void delete_UETable(void *p);
   static void deleteArray_UETable(void *p);
   static void destruct_UETable(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::UETable*)
   {
      ::UETable *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::UETable));
      static ::ROOT::TGenericClassInfo 
         instance("UETable", "CondFormats/HIObjects/interface/UETable.h", 7,
                  typeid(::UETable), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &UETable_Dictionary, isa_proxy, 0,
                  sizeof(::UETable) );
      instance.SetNew(&new_UETable);
      instance.SetNewArray(&newArray_UETable);
      instance.SetDelete(&delete_UETable);
      instance.SetDeleteArray(&deleteArray_UETable);
      instance.SetDestructor(&destruct_UETable);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::UETable*)
   {
      return GenerateInitInstanceLocal((::UETable*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::UETable*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *UETable_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::UETable*)0x0)->GetClass();
      UETable_TClassManip(theClass);
   return theClass;
   }

   static void UETable_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_CentralityTable(void *p) {
      return  p ? new(p) ::CentralityTable : new ::CentralityTable;
   }
   static void *newArray_CentralityTable(Long_t nElements, void *p) {
      return p ? new(p) ::CentralityTable[nElements] : new ::CentralityTable[nElements];
   }
   // Wrapper around operator delete
   static void delete_CentralityTable(void *p) {
      delete ((::CentralityTable*)p);
   }
   static void deleteArray_CentralityTable(void *p) {
      delete [] ((::CentralityTable*)p);
   }
   static void destruct_CentralityTable(void *p) {
      typedef ::CentralityTable current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CentralityTable

namespace ROOT {
   // Wrappers around operator new
   static void *new_CentralityTablecLcLBinValues(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::CentralityTable::BinValues : new ::CentralityTable::BinValues;
   }
   static void *newArray_CentralityTablecLcLBinValues(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::CentralityTable::BinValues[nElements] : new ::CentralityTable::BinValues[nElements];
   }
   // Wrapper around operator delete
   static void delete_CentralityTablecLcLBinValues(void *p) {
      delete ((::CentralityTable::BinValues*)p);
   }
   static void deleteArray_CentralityTablecLcLBinValues(void *p) {
      delete [] ((::CentralityTable::BinValues*)p);
   }
   static void destruct_CentralityTablecLcLBinValues(void *p) {
      typedef ::CentralityTable::BinValues current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CentralityTable::BinValues

namespace ROOT {
   // Wrappers around operator new
   static void *new_CentralityTablecLcLCBin(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::CentralityTable::CBin : new ::CentralityTable::CBin;
   }
   static void *newArray_CentralityTablecLcLCBin(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::CentralityTable::CBin[nElements] : new ::CentralityTable::CBin[nElements];
   }
   // Wrapper around operator delete
   static void delete_CentralityTablecLcLCBin(void *p) {
      delete ((::CentralityTable::CBin*)p);
   }
   static void deleteArray_CentralityTablecLcLCBin(void *p) {
      delete [] ((::CentralityTable::CBin*)p);
   }
   static void destruct_CentralityTablecLcLCBin(void *p) {
      typedef ::CentralityTable::CBin current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CentralityTable::CBin

namespace ROOT {
   // Wrappers around operator new
   static void *new_RPFlatParams(void *p) {
      return  p ? new(p) ::RPFlatParams : new ::RPFlatParams;
   }
   static void *newArray_RPFlatParams(Long_t nElements, void *p) {
      return p ? new(p) ::RPFlatParams[nElements] : new ::RPFlatParams[nElements];
   }
   // Wrapper around operator delete
   static void delete_RPFlatParams(void *p) {
      delete ((::RPFlatParams*)p);
   }
   static void deleteArray_RPFlatParams(void *p) {
      delete [] ((::RPFlatParams*)p);
   }
   static void destruct_RPFlatParams(void *p) {
      typedef ::RPFlatParams current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RPFlatParams

namespace ROOT {
   // Wrappers around operator new
   static void *new_RPFlatParamscLcLEP(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RPFlatParams::EP : new ::RPFlatParams::EP;
   }
   static void *newArray_RPFlatParamscLcLEP(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RPFlatParams::EP[nElements] : new ::RPFlatParams::EP[nElements];
   }
   // Wrapper around operator delete
   static void delete_RPFlatParamscLcLEP(void *p) {
      delete ((::RPFlatParams::EP*)p);
   }
   static void deleteArray_RPFlatParamscLcLEP(void *p) {
      delete [] ((::RPFlatParams::EP*)p);
   }
   static void destruct_RPFlatParamscLcLEP(void *p) {
      typedef ::RPFlatParams::EP current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RPFlatParams::EP

namespace ROOT {
   // Wrappers around operator new
   static void *new_UETable(void *p) {
      return  p ? new(p) ::UETable : new ::UETable;
   }
   static void *newArray_UETable(Long_t nElements, void *p) {
      return p ? new(p) ::UETable[nElements] : new ::UETable[nElements];
   }
   // Wrapper around operator delete
   static void delete_UETable(void *p) {
      delete ((::UETable*)p);
   }
   static void deleteArray_UETable(void *p) {
      delete [] ((::UETable*)p);
   }
   static void destruct_UETable(void *p) {
      typedef ::UETable current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::UETable

namespace ROOT {
   static TClass *vectorlERPFlatParamscLcLEPgR_Dictionary();
   static void vectorlERPFlatParamscLcLEPgR_TClassManip(TClass*);
   static void *new_vectorlERPFlatParamscLcLEPgR(void *p = 0);
   static void *newArray_vectorlERPFlatParamscLcLEPgR(Long_t size, void *p);
   static void delete_vectorlERPFlatParamscLcLEPgR(void *p);
   static void deleteArray_vectorlERPFlatParamscLcLEPgR(void *p);
   static void destruct_vectorlERPFlatParamscLcLEPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<RPFlatParams::EP>*)
   {
      vector<RPFlatParams::EP> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<RPFlatParams::EP>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<RPFlatParams::EP>", -2, "vector", 214,
                  typeid(vector<RPFlatParams::EP>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlERPFlatParamscLcLEPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<RPFlatParams::EP>) );
      instance.SetNew(&new_vectorlERPFlatParamscLcLEPgR);
      instance.SetNewArray(&newArray_vectorlERPFlatParamscLcLEPgR);
      instance.SetDelete(&delete_vectorlERPFlatParamscLcLEPgR);
      instance.SetDeleteArray(&deleteArray_vectorlERPFlatParamscLcLEPgR);
      instance.SetDestructor(&destruct_vectorlERPFlatParamscLcLEPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<RPFlatParams::EP> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<RPFlatParams::EP>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlERPFlatParamscLcLEPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<RPFlatParams::EP>*)0x0)->GetClass();
      vectorlERPFlatParamscLcLEPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlERPFlatParamscLcLEPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlERPFlatParamscLcLEPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<RPFlatParams::EP> : new vector<RPFlatParams::EP>;
   }
   static void *newArray_vectorlERPFlatParamscLcLEPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<RPFlatParams::EP>[nElements] : new vector<RPFlatParams::EP>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlERPFlatParamscLcLEPgR(void *p) {
      delete ((vector<RPFlatParams::EP>*)p);
   }
   static void deleteArray_vectorlERPFlatParamscLcLEPgR(void *p) {
      delete [] ((vector<RPFlatParams::EP>*)p);
   }
   static void destruct_vectorlERPFlatParamscLcLEPgR(void *p) {
      typedef vector<RPFlatParams::EP> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<RPFlatParams::EP>

namespace ROOT {
   static TClass *vectorlECentralityTablecLcLCBingR_Dictionary();
   static void vectorlECentralityTablecLcLCBingR_TClassManip(TClass*);
   static void *new_vectorlECentralityTablecLcLCBingR(void *p = 0);
   static void *newArray_vectorlECentralityTablecLcLCBingR(Long_t size, void *p);
   static void delete_vectorlECentralityTablecLcLCBingR(void *p);
   static void deleteArray_vectorlECentralityTablecLcLCBingR(void *p);
   static void destruct_vectorlECentralityTablecLcLCBingR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<CentralityTable::CBin>*)
   {
      vector<CentralityTable::CBin> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<CentralityTable::CBin>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<CentralityTable::CBin>", -2, "vector", 214,
                  typeid(vector<CentralityTable::CBin>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlECentralityTablecLcLCBingR_Dictionary, isa_proxy, 4,
                  sizeof(vector<CentralityTable::CBin>) );
      instance.SetNew(&new_vectorlECentralityTablecLcLCBingR);
      instance.SetNewArray(&newArray_vectorlECentralityTablecLcLCBingR);
      instance.SetDelete(&delete_vectorlECentralityTablecLcLCBingR);
      instance.SetDeleteArray(&deleteArray_vectorlECentralityTablecLcLCBingR);
      instance.SetDestructor(&destruct_vectorlECentralityTablecLcLCBingR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<CentralityTable::CBin> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<CentralityTable::CBin>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlECentralityTablecLcLCBingR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<CentralityTable::CBin>*)0x0)->GetClass();
      vectorlECentralityTablecLcLCBingR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlECentralityTablecLcLCBingR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlECentralityTablecLcLCBingR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<CentralityTable::CBin> : new vector<CentralityTable::CBin>;
   }
   static void *newArray_vectorlECentralityTablecLcLCBingR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<CentralityTable::CBin>[nElements] : new vector<CentralityTable::CBin>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlECentralityTablecLcLCBingR(void *p) {
      delete ((vector<CentralityTable::CBin>*)p);
   }
   static void deleteArray_vectorlECentralityTablecLcLCBingR(void *p) {
      delete [] ((vector<CentralityTable::CBin>*)p);
   }
   static void destruct_vectorlECentralityTablecLcLCBingR(void *p) {
      typedef vector<CentralityTable::CBin> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<CentralityTable::CBin>

namespace {
  void TriggerDictionaryInitialization_CondFormatsHIObjects_xr_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"/home/sanders/pPb_2016_v0/CMSSW_8_0_24/src/CondFormats/HIObjects/src",
"/home/sanders/pPb_2016_v0/CMSSW_8_0_24/src",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc530/cms/cmssw/CMSSW_8_0_24/src",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc530/lcg/root/6.06.00-ikhhed5/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc530/external/boost/1.57.0-giojec2/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc530/external/pcre/8.37/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc530/external/bz2lib/1.0.6/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc530/external/libuuid/2.22.2/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc530/external/python/2.7.11-giojec2/include/python2.7",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc530/external/tbb/44_20151115oss/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc530/external/zlib/1.2.8/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc530/lcg/root/6.06.00-ikhhed5/include",
"/home/sanders/pPb_2016_v0/CMSSW_8_0_24/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "CondFormatsHIObjects_xr dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$CondFormats/HIObjects/src/headers.h")))  CentralityTable;
class __attribute__((annotate("$clingAutoload$CondFormats/HIObjects/src/headers.h")))  RPFlatParams;
class __attribute__((annotate("$clingAutoload$CondFormats/HIObjects/src/headers.h")))  UETable;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "CondFormatsHIObjects_xr dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif
#ifndef CMS_DICT_IMPL
  #define CMS_DICT_IMPL 1
#endif
#ifndef _REENTRANT
  #define _REENTRANT 1
#endif
#ifndef GNUSOURCE
  #define GNUSOURCE 1
#endif
#ifndef __STRICT_ANSI__
  #define __STRICT_ANSI__ 1
#endif
#ifndef GNU_GCC
  #define GNU_GCC 1
#endif
#ifndef _GNU_SOURCE
  #define _GNU_SOURCE 1
#endif
#ifndef CMSSW_GIT_HASH
  #define CMSSW_GIT_HASH "CMSSW_8_0_24"
#endif
#ifndef PROJECT_NAME
  #define PROJECT_NAME "CMSSW"
#endif
#ifndef PROJECT_VERSION
  #define PROJECT_VERSION "CMSSW_8_0_24"
#endif
#ifndef BOOST_SPIRIT_THREADSAFE
  #define BOOST_SPIRIT_THREADSAFE 1
#endif
#ifndef PHOENIX_THREADSAFE
  #define PHOENIX_THREADSAFE 1
#endif
#ifndef CMSSW_REFLEX_DICT
  #define CMSSW_REFLEX_DICT 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "CondFormats/HIObjects/src/headers.h"

namespace CondFormats_HIObjects {
  struct dictionary{
    std::vector<CentralityTable::CBin> dummy;
    std::vector<RPFlatParams::EP> yummy;
    UETable pred;
  };
}


#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"CentralityTable", payloadCode, "@",
"CentralityTable::BinValues", payloadCode, "@",
"CentralityTable::CBin", payloadCode, "@",
"RPFlatParams", payloadCode, "@",
"RPFlatParams::EP", payloadCode, "@",
"UETable", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("CondFormatsHIObjects_xr",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_CondFormatsHIObjects_xr_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_CondFormatsHIObjects_xr_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_CondFormatsHIObjects_xr() {
  TriggerDictionaryInitialization_CondFormatsHIObjects_xr_Impl();
}
