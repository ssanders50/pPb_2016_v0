#include "../CMSSW_8_0_24/src/RecoHI/HiEvtPlaneAlgos/interface/HiEvtPlaneList.h"
TFile * tf = new TFile("../VNAnalysis_v0/vnanal.root");
using namespace hi;
void rescor(){
  for(int i = 0; i<NumEPNames; i++) {
    double ab = ((TH1D *) tf->Get(Form("vnanalyzer/%s/BA",EPNames[i].data())))->GetBinContent(1)/((TH1D *) tf->Get(Form("vnanalyzer/%s/BAcnt",EPNames[i].data())))->GetBinContent(1);
    double ac = ((TH1D *) tf->Get(Form("vnanalyzer/%s/CA",EPNames[i].data())))->GetBinContent(1)/((TH1D *) tf->Get(Form("vnanalyzer/%s/CAcnt",EPNames[i].data())))->GetBinContent(1);
    double bc = ((TH1D *) tf->Get(Form("vnanalyzer/%s/CB",EPNames[i].data())))->GetBinContent(1)/((TH1D *) tf->Get(Form("vnanalyzer/%s/CBcnt",EPNames[i].data())))->GetBinContent(1);
    double res = sqrt(ab*ac/bc);
    cout<<EPNames[i]<<"\t"<<res<<endl;
  }
}
