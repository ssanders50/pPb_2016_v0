#include <iostream>
#include "TFile.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TLatex.h"
#include "TLegend.h"

TFile * fKs = NULL;
void plotKs_(string particle="Ks", int ntrkmin = 120, int ntrkmax = 150){
  f = new TFile(Form("%s.root",particle.data()),"read");
  TCanvas * c = new TCanvas("c","c",1400,900);
  c->Divide(2);
  TH1D * h = new TH1D("h","h",200,0,8);
  h->SetMinimum(-0.02);
  h->SetMaximum(0.3);
  h->SetXTitle("p_{T} (GeV/c)");
  h->SetYTitle("v_{2}");
  c->cd(1);
  h->Draw();
  TGraphErrors * g_pside_pPb = (TGraphErrors *) f->Get(Form("pPb_%d_%d/vn_PosEta",ntrkmin,ntrkmax));
  g_pside_pPb->Draw("p");
  TGraphErrors * g_pside_Pbp = (TGraphErrors *) f->Get(Form("Pbp_%d_%d/vn_NegEta",ntrkmin,ntrkmax));
  g_pside_Pbp->Draw("p");
  TLatex * lspec = new TLatex(1,0.27,particle.data());
  lspec->Draw();
  TLatex * lntrk = new TLatex(1,0.25,Form("%d #leq N_{trk}^{off} < %d",ntrkmin,ntrkmax));
  lntrk->Draw();
  TLegend * leg1 = new TLegend(0.5,0.3,0.8,0.4);
  leg1->SetBorderSize(0);
  leg1->AddEntry(g_pside_pPb,"pPb (p-side)","lp");
  leg1->AddEntry(g_pside_Pbp,"Pbp (p-side)","lp");
  leg1->Draw();
  c->cd(2);
  h->Draw();
  TGraphErrors * g_Pbside_pPb = (TGraphErrors *) f->Get(Form("pPb_%d_%d/vn_NegEta",ntrkmin,ntrkmax));
  g_Pbside_pPb->Draw("p");
  TGraphErrors * g_Pbside_Pbp = (TGraphErrors *) f->Get(Form("Pbp_%d_%d/vn_PosEta",ntrkmin,ntrkmax));
  g_Pbside_Pbp->Draw("p");
  TLegend * leg2 = new TLegend(0.5,0.3,0.8,0.4);
  leg2->SetBorderSize(0);
  leg2->AddEntry(g_pside_pPb,"pPb (Pb-side)","lp");
  leg2->AddEntry(g_pside_Pbp,"Pbp (Pb-side)","lp");
  leg2->Draw();
  c->Print(Form("figures/%s_%d_%d.pdf",particle.data(),ntrkmin,ntrkmax),"pdf");
}
void plotKs(){
  plotKs_("Ks",120,150);
  plotKs_("Ks",150,185);
  plotKs_("Ks",185,250);
  plotKs_("Ks",250,500);
}
