void statistics(){
  TF1 * g = new TF1("g","gaus(0)",0,10);
  g->SetParameters(10,5,1);
  TH1D * h = new TH1D("h","h",100,0,10);
  h->Sumw2();
  TH1D * hsub[10];
  for(int i = 0; i<10; i++) hsub[i]=new TH1D(Form("h%d",i),Form("h%d",i),100,0,10);
  int isub = 0;
  for(int i = 0; i<1000;i++) {
    double v = g->GetRandom(0,10);
    h->Fill(v);
    hsub[isub]->Fill(v);
    isub++;
    if(isub==10) isub=0;
  }
  h->Draw();

  cout<<"mean: "<<h->GetMean()<<"\t"<<h->GetMeanError()<<"\t"<<h->GetStdDev()<<endl;
  double s = 0;
  double es2 = 0;
  double sum = 0;
  for(int i = 1; i<=100; i++) {
    //cout<<i<<"\t"<<h->GetBinContent(i)<<"\t"<<h->GetBinError(i)<<"\t"<<hsub[0]->GetBinContent(i)<<"\t"<<hsub[0]->GetBinError(i)<<endl;
    s+=h->GetBinContent(i)*h->GetBinCenter(i);
    sum+=h->GetBinContent(i);
    es2+=pow(h->GetBinError(i)*h->GetBinCenter(i),2);
  }
  double var = es2/sum-pow(s/sum,2);
  cout<<"mean: "<<s/sum<<"\t"<<sqrt(var)<<endl;
  double subm = 0;
  for(int i = 0; i<10; i++) {
    subm+=hsub[i]->GetMean();
  }
  double smean = subm/10.;
  double varm=0;
  for(int i = 0; i<10; i++) {
    varm+=pow(hsub[i]->GetMean()-smean,2);
  }
  double sigsubm = sqrt(varm)/9; 
  cout<<"sub mean: "<<smean<<"\t"<<sigsubm<<endl;

}
