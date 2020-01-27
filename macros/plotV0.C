#include <iostream>
#include "TFile.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TLatex.h"
#include "TLegend.h"

TFile * fKs = NULL;
void plotV0_(string particle="Ks", int ntrkmin = 120, int ntrkmax = 150){
  f = new TFile("v0.root","read");
  TCanvas * c = new TCanvas("c","c",1600,900);
  c->Divide(2);
  TH1D * h = new TH1D("h","h",200,0,8);
  h->SetMinimum(-0.02);
  h->SetMaximum(0.3);
  h->SetXTitle("p_{T} (GeV/c)");
  h->SetYTitle("v_{2}");
  c->cd(1);
  h->Draw();
  TGraphErrors * g_pside_pPb = (TGraphErrors *) f->Get(Form("%s_pPb_%d_%d/vn_PosEta_NegEtaEP",particle.data(),ntrkmin,ntrkmax));
  g_pside_pPb->Draw("p");
  TGraphErrors * g_pside_Pbp = (TGraphErrors *) f->Get(Form("%s_Pbp_%d_%d/vn_NegEta_PosEtaEP",particle.data(),ntrkmin,ntrkmax));
  g_pside_Pbp->Draw("p");
  TGraphErrors * g_full_psideEP_pPb = (TGraphErrors *) f->Get(Form("%s_pPb_%d_%d/vn_Full_NegEtaEP",particle.data(),ntrkmin,ntrkmax));
  g_full_psideEP_pPb->SetMarkerColor(kGreen);
  g_full_psideEP_pPb->Draw("p");
  TGraphErrors * g_full_psideEP_Pbp = (TGraphErrors *) f->Get(Form("%s_Pbp_%d_%d/vn_Full_PosEtaEP",particle.data(),ntrkmin,ntrkmax));
  g_full_psideEP_Pbp->SetMarkerColor(kMagenta);
  g_full_psideEP_Pbp->Draw("p");
  TLatex * lspec = new TLatex(1,0.27,particle.data());
  lspec->Draw();
  TLatex * lntrk = new TLatex(1,0.25,Form("%d #leq N_{trk}^{off} < %d",ntrkmin,ntrkmax));
  lntrk->Draw();
  TLegend * leg1 = new TLegend(0.5,0.2,0.9,0.45);
  leg1->SetBorderSize(0);
  leg1->AddEntry(g_pside_pPb,"pPb (0 < #eta < 1, HF-)","lp");
  leg1->AddEntry(g_pside_Pbp,"Pbp (-1 < #eta < -, HF+)","lp");
  leg1->AddEntry(g_full_psideEP_pPb,"pPb(-1 < #eta < 1, HF-)","lp");
  leg1->AddEntry(g_full_psideEP_Pbp,"Pbp(-1 < #eta < 1, HF+)","lp");
  leg1->Draw();
  c->cd(2);
  h->Draw();
  TGraphErrors * g_Pbside_pPb = (TGraphErrors *) f->Get(Form("%s_pPb_%d_%d/vn_NegEta_PosEtaEP",particle.data(),ntrkmin,ntrkmax));
  g_Pbside_pPb->SetMarkerColor(kBlue);
  g_Pbside_pPb->Draw("p");
  TGraphErrors * g_Pbside_Pbp = (TGraphErrors *) f->Get(Form("%s_Pbp_%d_%d/vn_PosEta_NegEtaEP",particle.data(),ntrkmin,ntrkmax));
  g_Pbside_Pbp->SetMarkerColor(kBlue);
  g_Pbside_Pbp->Draw("p");
  TGraphErrors * g_full_nsideEP_pPb = (TGraphErrors *) f->Get(Form("%s_pPb_%d_%d/vn_Full_PosEtaEP",particle.data(),ntrkmin,ntrkmax));
  g_full_nsideEP_pPb->SetMarkerColor(kGreen);
  g_full_nsideEP_pPb->Draw("p");
  TGraphErrors * g_full_nsideEP_Pbp = (TGraphErrors *) f->Get(Form("%s_Pbp_%d_%d/vn_Full_NegEtaEP",particle.data(),ntrkmin,ntrkmax));
  g_full_nsideEP_Pbp->SetMarkerColor(kMagenta);
  g_full_nsideEP_Pbp->Draw("p");
  TLegend * leg2 = new TLegend(0.5,0.2,0.9,0.45);
  leg2->SetBorderSize(0);
  leg2->AddEntry(g_Pbside_pPb,"pPb (-1 < #eta < 0, HF+)","lp");
  leg2->AddEntry(g_Pbside_Pbp,"Pbp (0 < #eta < 1, HF-)","lp");
  leg2->AddEntry(g_full_nsideEP_pPb,"pPb (-1 < #eta < 1, HF+)","lp");
  leg2->AddEntry(g_full_nsideEP_Pbp,"Pbp (-1 < #eta < 1, HF-)","lp");
  leg2->Draw();
  c->Print(Form("figures/%s_%d_%d.pdf",particle.data(),ntrkmin,ntrkmax),"pdf");
}
void plotV0(){
  // plotV0_("Ks",120,150);
  //plotV0_("Ks",150,185);
  plotV0_("Ks",185,250);
  //plotV0_("Ks",250,500);
  //plotV0_("Lambda",120,150);
  //plotV0_("Lambda",150,185);
  //plotV0_("Lambda",185,250);
  //plotV0_("Lambda",250,500);
  //plotV0_("ch",150,185);
  //plotV0_("ch",185,250);
}
