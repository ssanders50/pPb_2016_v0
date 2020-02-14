#include <ctime>

bool Framework::AddFile(){
  //clock_t start = clock();
  char buf[120];
  if(fgets(buf,120,flist)==NULL) return false;
  buf[strlen(buf)-1]=0;
  string infile = buf;
 
  
  std::unique_ptr<TFile> tf(new TFile(infile.data(),"read"));
  if(tf->IsZombie())                 {
   cout<<"ZOMBIE:    " <<infile.data()<<endl; 
   string remove = "rm "+infile;
   system(remove.data());
   return true;
  }

  int minNtrk = r[0].minNtrk;
  int maxNtrk = r[0].maxNtrk;
  string crnge = Form("%d_%d",minNtrk,maxNtrk);
  string spname = "vnanalyzer/Spectra/"+crnge+"/ptspecCnt";
  TH2D * ptcnt = (TH2D *) tf->Get(spname.data());

  double etamin1 = r[0].minEta[0];
  double etamax1 = r[0].maxEta[0];
  int ietamin1 = ptcnt->GetYaxis()->FindBin(etamin1+0.01);
  int ietamax1 = ptcnt->GetYaxis()->FindBin(etamax1-0.01);
  double etamin2 = r[0].minEta[1];
  double etamax2 = r[0].maxEta[1];
  int ietamin2 = ptcnt->GetYaxis()->FindBin(etamin2+0.01);
  int ietamax2 = ptcnt->GetYaxis()->FindBin(etamax2-0.01);
  if(r[0].spec_NegEta == 0) {
    r[0].spec_NegEta = (TH1D *) ptcnt->ProjectionX(Form("spec1d_%d_%d_NegEta",minNtrk,maxNtrk),ietamin1,ietamax1);
    r[0].spec_NegEta->SetDirectory(0);
    r[0].spec_NegEta->SetMarkerStyle(20);
    r[0].spec_NegEta->SetMarkerColor(kBlue);
  } else {
    r[0].spec_NegEta->Add((TH1D *) ptcnt->ProjectionX(Form("spec1d_%d_%d_NegEta",minNtrk,maxNtrk),ietamin1,ietamax1));
  }
  if(r[0].spec_PosEta == 0 ) {
    r[0].spec_PosEta = (TH1D *) ptcnt->ProjectionX(Form("spec1d_%d_%d_PosEta",minNtrk,maxNtrk),ietamin2,ietamax2);
    r[0].spec_PosEta->SetDirectory(0);
    r[0].spec_PosEta->SetMarkerStyle(25);
    r[0].spec_PosEta->SetMarkerColor(kRed);
  } else {
    r[0].spec_PosEta->Add((TH1D *) ptcnt->ProjectionX(Form("spec1d_%d_%d_PosEta",minNtrk,maxNtrk),ietamin2,ietamax2));
  }
  tf->RecursiveRemove(ptcnt);
  ptcnt->Delete("*/*");
  hntrk->Add((TH1D *) tf->Get("vnanalyzer/Ntrk"));
  TH2F * ptspec=0;
  TH2F * ptspecCnt=0;
  TH1D * ntrk=0;
  TH2F * qA[11]={0};
  TH2F * qB[11]={0};
  TH2F * wnA[11]={0};
  TH2F * wnB[11]={0};
  TH1D * qBA[11]={0};
  TH1D * qCA[11]={0};
  TH1D * qCB[11]={0};
  TH1D * qBAcnt[11]={0};
  TH1D * qCAcnt[11]={0};
  TH1D * qCBcnt[11]={0};
  int i = 0;
  ptspec = (TH2F *) tf->Get(Form("vnanalyzer/Spectra/%d_%d/ptspec",r[i].minNtrk,r[i].maxNtrk));
  ptspec->SetDirectory(0);
  ptspecCnt = (TH2F *) tf->Get(Form("vnanalyzer/Spectra/%d_%d/ptspecCnt",r[i].minNtrk,r[i].maxNtrk));
  ptspecCnt->SetDirectory(0);
  qA[0] = (TH2F *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/qA",r[i].minNtrk,r[i].maxNtrk,r[i].order));
  qA[0]->SetDirectory(0);
  qB[0] = (TH2F *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/qB",r[i].minNtrk,r[i].maxNtrk,r[i].order));
  qB[0]->SetDirectory(0);
  wnA[0] = (TH2F *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/wnA",r[i].minNtrk,r[i].maxNtrk,r[i].order));
  wnA[0]->SetDirectory(0);
  wnB[0] = (TH2F *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/wnB",r[i].minNtrk,r[i].maxNtrk,r[i].order));
  wnB[0]->SetDirectory(0);
  qBA[0] = (TH1D *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/qBA",r[i].minNtrk,r[i].maxNtrk,r[i].order));
  qBA[0]->SetDirectory(0);
  qCA[0] = (TH1D *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/qCA",r[i].minNtrk,r[i].maxNtrk,r[i].order));
  qCA[0]->SetDirectory(0);
  qCB[0] = (TH1D *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/qCB",r[i].minNtrk,r[i].maxNtrk,r[i].order));
  qCB[0]->SetDirectory(0);
  qBAcnt[0] = (TH1D *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/qBAcnt",r[i].minNtrk,r[i].maxNtrk,r[i].order));
  qBAcnt[0]->SetDirectory(0);
  qCAcnt[0] = (TH1D *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/qCAcnt",r[i].minNtrk,r[i].maxNtrk,r[i].order));
  qCAcnt[0]->SetDirectory(0);
  qCBcnt[0] = (TH1D *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/qCBcnt",r[i].minNtrk,r[i].maxNtrk,r[i].order));
  qCBcnt[0]->SetDirectory(0);
  for(int isub = 1; isub<=10; isub++) {
    qA[isub] = (TH2F *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/SubEvents/qA_%d",r[i].minNtrk,r[i].maxNtrk,r[i].order,isub));
    qA[isub]->SetDirectory(0);
    qB[isub] = (TH2F *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/SubEvents/qB_%d",r[i].minNtrk,r[i].maxNtrk,r[i].order,isub));
    qB[isub]->SetDirectory(0);
    wnA[isub] = (TH2F *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/SubEvents/wnA_%d",r[i].minNtrk,r[i].maxNtrk,r[i].order,isub));
    wnA[isub]->SetDirectory(0);
    wnB[isub] = (TH2F *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/SubEvents/wnB_%d",r[i].minNtrk,r[i].maxNtrk,r[i].order,isub));
    wnB[isub]->SetDirectory(0);
    qBA[isub] = (TH1D *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/SubEvents/qBA_%d",r[i].minNtrk,r[i].maxNtrk,r[i].order,isub));
    qBA[isub]->SetDirectory(0);
    qCA[isub] = (TH1D *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/SubEvents/qCA_%d",r[i].minNtrk,r[i].maxNtrk,r[i].order,isub));
    qCA[isub]->SetDirectory(0);
    qCB[isub] = (TH1D *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/SubEvents/qCB_%d",r[i].minNtrk,r[i].maxNtrk,r[i].order,isub));
    qCB[isub]->SetDirectory(0);
    qBAcnt[isub] = (TH1D *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/SubEvents/qBAcnt_%d",r[i].minNtrk,r[i].maxNtrk,r[i].order,isub));
    qBAcnt[isub]->SetDirectory(0);
    qCAcnt[isub] = (TH1D *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/SubEvents/qCAcnt_%d",r[i].minNtrk,r[i].maxNtrk,r[i].order,isub));
    qCAcnt[isub]->SetDirectory(0);
    qCBcnt[isub] = (TH1D *) tf->Get(Form("vnanalyzer/Harmonics/%d_%d/N%d/SubEvents/qCBcnt_%d",r[i].minNtrk,r[i].maxNtrk,r[i].order,isub));
    qCBcnt[isub]->SetDirectory(0);
  }
   tf->Close();
  
  for(int i = 0; i<nrange; i++) {
    for(int j = r[i].minEtaBin[0]; j<= r[i].maxEtaBin[0]; j++) {
      for(int k = r[i].minPtBin; k<=r[i].maxPtBin; k++) {
  	r[i].qn[0]+=qA[0]->GetBinContent(k,j);
  	r[i].qne[0]+=pow(qA[0]->GetBinError(k,j),2);
  	r[i].wnA[0] += wnA[0]->GetBinContent(k,j);
  	r[i].qAB[0] += qBA[0]->GetBinContent(1);
  	r[i].qAC[0] += qCA[0]->GetBinContent(1);
  	r[i].qBC[0] += qCB[0]->GetBinContent(1);
  	r[i].wAB[0] += qBAcnt[0]->GetBinContent(1);
  	r[i].wAC[0] += qCAcnt[0]->GetBinContent(1);
  	r[i].wBC[0] += qCBcnt[0]->GetBinContent(1);
	
  	r[i].pt[0] += ptspec->GetBinContent(k,j);
  	r[i].ptcnt[0] += ptspecCnt->GetBinContent(k,j);
	
  	for(int m = 1; m<11; m++) {  
  	  r[i].qnSub[0][m-1]+=qA[m]->GetBinContent(k,j);
  	  r[i].wnASub[0][m-1] += wnA[m]->GetBinContent(k,j);
  	}
      }
    }
    //////////////////
    for(int j = r[i].minEtaBin[1]; j<= r[i].maxEtaBin[1]; j++) {
      for(int k = r[i].minPtBin; k<=r[i].maxPtBin; k++) {
  	r[i].qn[1]+=qB[0]->GetBinContent(k,j);
  	r[i].qne[1]+=pow(qB[0]->GetBinError(k,j),2);
  	r[i].wnA[1] += wnB[0]->GetBinContent(k,j);
  	r[i].qAB[1] += qBA[0]->GetBinContent(1);
  	r[i].qAC[1] += qCB[0]->GetBinContent(1);
  	r[i].qBC[1] += qCA[0]->GetBinContent(1);
  	r[i].wAB[1] += qBAcnt[0]->GetBinContent(1);
  	r[i].wAC[1] += qCBcnt[0]->GetBinContent(1);
  	r[i].wBC[1] += qCAcnt[0]->GetBinContent(1);
	
  	r[i].pt[1] += ptspec->GetBinContent(k,j);
  	r[i].ptcnt[1] += ptspecCnt->GetBinContent(k,j);
	
  	for(int m = 1; m<11; m++) {  
  	  r[i].qnSub[1][m-1]+=qB[m]->GetBinContent(k,j);
  	  r[i].wnASub[1][m-1] += wnB[m]->GetBinContent(k,j);
  	}
      }
    }
  }
  if(ptspec) ptspec->Delete("*/*");
  if(ptspecCnt) ptspecCnt->Delete("*/*");
  if(ntrk) ntrk->Delete("*/*");
  for(int k = 0; k<11; k++) {
    if(qA[k]) {
      qA[k]->Delete("*/*");
      qA[k] = 0;
    }
    if(qB[k]) {
      qB[k]->Delete("*/*");
      qB[k] = 0;
    }
    if(wnA[k]) {
      wnA[k]->Delete("*/*");
      wnA[k] = 0;
    }
    if(wnB[k]) {
      wnB[k]->Delete("*/*");
      wnB[k] = 0;
    }
    if(qBA[k]) {
      qBA[k]->Delete("*/*");
      qBA[k] = 0;
    }
    if(qCA[k]) {
      qCA[k]->Delete("*/*");
      qCA[k] = 0;
    }
    if(qCB[k]) {
      qCB[k]->Delete("*/*");
      qCB[k] = 0;
    }
    if(qBAcnt[k]) {
      qBAcnt[k]->Delete("*/*");
      qBAcnt[k] = 0;
    }
    if(qCAcnt[k]) {
      qCAcnt[k]->Delete("*/*");
      qCAcnt[k]=0;
    }
    if(qCBcnt[i]) {
      qCBcnt[k]->Delete("*/*");
      qCBcnt[i] = 0;
    }
  }
  //clock_t end = clock();
  //double elapsed_secs = double(end-start)/CLOCKS_PER_SEC;
  //cout<<"elapsed time with file (s) = "<<elapsed_secs<<endl;
  
  return true;
}
