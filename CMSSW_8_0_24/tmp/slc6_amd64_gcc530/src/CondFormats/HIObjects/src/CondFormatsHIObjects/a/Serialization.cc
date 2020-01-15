
#include "CondFormats/HIObjects/src/headers.h"

#include <boost/serialization/base_object.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/export.hpp>

#include "CondFormats/Serialization/interface/Equal.h"
#include "CondFormats/Serialization/interface/Instantiate.h"

template <class Archive>
void CentralityTable::serialize(Archive & ar, const unsigned int)
{
    ar & boost::serialization::make_nvp("m-table", m_table);
}
COND_SERIALIZATION_INSTANTIATE(CentralityTable);

template <class Archive>
void CentralityTable::BinValues::serialize(Archive & ar, const unsigned int)
{
    ar & boost::serialization::make_nvp("mean", mean);
    ar & boost::serialization::make_nvp("var", var);
}
COND_SERIALIZATION_INSTANTIATE(CentralityTable::BinValues);

template <class Archive>
void CentralityTable::CBin::serialize(Archive & ar, const unsigned int)
{
    ar & boost::serialization::make_nvp("bin-edge", bin_edge);
    ar & boost::serialization::make_nvp("n-part", n_part);
    ar & boost::serialization::make_nvp("n-coll", n_coll);
    ar & boost::serialization::make_nvp("n-hard", n_hard);
    ar & boost::serialization::make_nvp("b", b);
    ar & boost::serialization::make_nvp("eccRP", eccRP);
    ar & boost::serialization::make_nvp("ecc2", ecc2);
    ar & boost::serialization::make_nvp("ecc3", ecc3);
    ar & boost::serialization::make_nvp("ecc4", ecc4);
    ar & boost::serialization::make_nvp("ecc5", ecc5);
    ar & boost::serialization::make_nvp("S", S);
    ar & boost::serialization::make_nvp("var0", var0);
    ar & boost::serialization::make_nvp("var1", var1);
    ar & boost::serialization::make_nvp("var2", var2);
}
COND_SERIALIZATION_INSTANTIATE(CentralityTable::CBin);

template <class Archive>
void RPFlatParams::serialize(Archive & ar, const unsigned int)
{
    ar & boost::serialization::make_nvp("m-table", m_table);
}
COND_SERIALIZATION_INSTANTIATE(RPFlatParams);

template <class Archive>
void RPFlatParams::EP::serialize(Archive & ar, const unsigned int)
{
    ar & boost::serialization::make_nvp("x", x);
    ar & boost::serialization::make_nvp("y", y);
    ar & boost::serialization::make_nvp("xSub1", xSub1);
    ar & boost::serialization::make_nvp("ySub1", ySub1);
    ar & boost::serialization::make_nvp("xSub2", xSub2);
    ar & boost::serialization::make_nvp("ySub2", ySub2);
    ar & boost::serialization::make_nvp("RPNameIndx", RPNameIndx);
}
COND_SERIALIZATION_INSTANTIATE(RPFlatParams::EP);

template <class Archive>
void UETable::serialize(Archive & ar, const unsigned int)
{
    ar & boost::serialization::make_nvp("values", values);
    ar & boost::serialization::make_nvp("np", np);
    ar & boost::serialization::make_nvp("ni0", ni0);
    ar & boost::serialization::make_nvp("ni1", ni1);
    ar & boost::serialization::make_nvp("ni2", ni2);
    ar & boost::serialization::make_nvp("edgeEta", edgeEta);
}
COND_SERIALIZATION_INSTANTIATE(UETable);

