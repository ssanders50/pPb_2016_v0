TFile * tf = new TFile("Ks.root");
void check(int minNtrk=250, int maxNtrk=500){
  TCanvas * c = new TCanvas("c","c",1100,800);
  c->Divide(2);
  TGraphErrors * pPb_pos = (TGraphErrors *) tf->Get(Form("pPb_%d_%d/vn_PosEta",minNtrk,maxNtrk));
  TGraphErrors * pPb_neg = (TGraphErrors *) tf->Get(Form("pPb_%d_%d/vn_NegEta",minNtrk,maxNtrk));
  TGraphErrors * Pbp_pos = (TGraphErrors *) tf->Get(Form("Pbp_%d_%d/vn_PosEta",minNtrk,maxNtrk));
  TGraphErrors * Pbp_neg = (TGraphErrors *) tf->Get(Form("Pbp_%d_%d/vn_NegEta",minNtrk,maxNtrk));
  TH1D * h = new TH1D("h","h",200,0.,12);
  h->SetMaximum(0.4);
  c->cd(1);
  h->Draw();
  pPb_pos->Draw("p");
  Pbp_neg->Draw("p");
  TLegend * leg1 = new TLegend(0.3,0.2,0.6,0.3);
  leg1->SetBorderSize(0);
  leg1->AddEntry(pPb_pos,"pPb +","lp");
  leg1->AddEntry(Pbp_neg,"Pbp -","lp");
  leg1->Draw();
  c->cd(2);
  h->Draw();
  pPb_neg->Draw("p");
  Pbp_pos->Draw("p");
  TLegend * leg2 = new TLegend(0.3,0.2,0.6,0.3);
  leg2->SetBorderSize(0);
  leg2->AddEntry(pPb_neg,"pPb -","lp");
  leg2->AddEntry(Pbp_pos,"Pbp +","lp");
  leg2->Draw();

}
