TGraphErrors * HIN_15_008_Graph(string filename="/home/sanders/HIN-15-008/pt/pPbPtSPMid185HFp.dat", string name = "HIN_15_008_HM185_HFp",string typeError="stat", int marker=20, int color=kBlue, float size=0.14){
  FILE * fin;
  fin=fopen(filename.data(),"r");
  cout<<fin<<endl;
  char buf[100];
  int ncnt = 0;
  double x[20];
  double y[20];
  double ey[20];
  double sysy[20];
  while(fgets(buf,100,fin)!=NULL) {
    sscanf(buf,"%lf\t%lf\t%lf\t%lf",&x[ncnt],&y[ncnt],&ey[ncnt],&sysy[ncnt]);
    ++ncnt;
  }
  TGraphErrors * g = new TGraphErrors(ncnt,x,y,0,ey);
  g->SetName(name.data());
  g->SetTitle(name.data());
  g->SetMarkerStyle(marker);
  g->SetMarkerColor(color);
  g->SetMarkerSize(size);
  cout<<ncnt<<endl;
  return g;
}
