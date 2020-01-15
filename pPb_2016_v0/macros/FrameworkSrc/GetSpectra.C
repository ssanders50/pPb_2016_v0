TH1D * Framework::GetSpectra() {
  debug = false;
  TDirectory * dirsave = gDirectory;
  TH2D * spec;
  int minNtrk = r[0].minNtrk;
  int maxNtrk = r[0].maxNtrk;
  string crnge = Form("%d_%d",minNtrk,maxNtrk);
  string spname = "vnanalyzer/Spectra/"+crnge+"/ptspecCnt";
  TH2D * ptcnt = (TH2D *) tf->Get(spname.data());
  ptcnt->SetDirectory(0);
  spec = (TH2D *) ptcnt->Clone(Form("spec_%s",crnge.data()));
  spec->SetDirectory(0);
  double etamin1 = r[0].minEta[0];
  double etamax1 = r[0].maxEta[0];
  int ietamin1 = spec->GetYaxis()->FindBin(etamin1+0.01);
  int ietamax1 = spec->GetYaxis()->FindBin(etamax1-0.01);
  double etamin2 = r[0].minEta[1];
  double etamax2 = r[0].maxEta[1];
  int ietamin2 = spec->GetYaxis()->FindBin(etamin2+0.01);
  int ietamax2 = spec->GetYaxis()->FindBin(etamax2-0.01);
  r[0].spec_NegEta = (TH1D *) spec->ProjectionX(Form("spec1d_%d_%d_NegEta",minNtrk,maxNtrk),ietamin1,ietamax1);
  r[0].spec_PosEta = (TH1D *) spec->ProjectionX(Form("spec1d_%d_%d_PosEta",minNtrk,maxNtrk),ietamin2,ietamax2);
  TH1D * spec1d = (TH1D *) r[0].spec_NegEta->Clone(Form("spec1d_%d_%d",minNtrk,maxNtrk));
  spec1d->SetDirectory(0);
  spec1d->Add(r[0].spec_PosEta);
  double bineta = 0.199;
  for(int i = 0; i<spec1d->GetNbinsX(); i++) {
    double deta = etamax1-etamin1+etamax2-etamin2;
    double dpt = spec1d->GetBinWidth(i+1);
    double binpt = spec1d->GetXaxis()->GetBinCenter(i+1);
    double eff = 1;
    spec1d->SetBinContent(i+1,spec1d->GetBinContent(i+1)/deta/dpt);
    spec1d->SetBinError(i+1,spec1d->GetBinError(i+1)/deta/dpt);

  }
  spec1d->SetXTitle("p_{T} (GeV/c)");
  spec1d->SetYTitle("dN/(d#eta dp_{T})");
  spec1d->SetMarkerStyle(20);
  spec1d->SetMarkerColor(kBlue);
  spec1d->SetLineColor(kBlue);
  spec->Delete();
  ptcnt->Delete();
  debug = false;
  dirsave->cd();
  spec1d->Scale(1./hntrk->Integral(hntrk->FindBin(minNtrk),hntrk->FindBin(maxNtrk)));
  return spec1d;
}
