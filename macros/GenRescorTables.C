#include "/home/sanders/pPb_2016_v0/CMSSW_8_0_24/src/RecoHI/HiEvtPlaneAlgos/interface/HiEvtPlaneList.h"
using namespace hi;
static const int ntrkbins = 25;
static const  double trkBins[]={0, 10, 20, 30, 40, 50, 60, 70, 80, 100, 120, 135, 150, 160, 185, 210, 230, 250, 270, 300, 330, 350, 370, 390, 420, 500};
double rescor[ntrkbins];
double erescor[ntrkbins];
FILE * fout;
TH1I * htrk;
void GenRescorTable(string reac, string name){
  FILE * fin;
  string pPb[5];
  for(int i = 0; i<ntrkbins; i++) {
    rescor[i] = 100;
    erescor[i] = 100;
  }
  pPb[0]= "RescorTables_pPb2016_pPb_MB";
  pPb[1] = "RescorTables_pPb2016_pPb_HM120";
  pPb[2] = "RescorTables_pPb2016_pPb_HM150";
  pPb[3] = "RescorTables_pPb2016_pPb_HM185";
  pPb[4] = "RescorTables_pPb2016_pPb_HM250";
  if(reac.find("Pbp")!=std::string::npos) {
    pPb[0] = "RescorTables_pPb2016_Pbp_MB";
    pPb[1] = "RescorTables_pPb2016_Pbp_HM120";
    pPb[2] = "RescorTables_pPb2016_Pbp_HM150";
    pPb[3] = "RescorTables_pPb2016_Pbp_HM185";
    pPb[4] = "RescorTables_pPb2016_Pbp_HM250";
  }
  for(int i = 0; i<5; i++) {
    string fullName = "/home/sanders/pPb_2016/MoveFlatParamsToDB/RescorSave/"+pPb[i]+"/"+name+".dat";
    cout<<fullName<<endl;
    fin = fopen(fullName.data(),"r");
    cout<<"fin"<<fin<<endl;
    char buf[100];
    while(fgets(buf,100,fin)!=NULL) {
      int cmin,cmax;
      float r,er;
      sscanf(buf,"%d\t%d\t%f\t%f",&cmin,&cmax,&r,&er);
      int ibin = htrk->FindBin((double)(cmin+cmax)/2.);
      for(int j = 0; j<ntrkbins; j++) {
	if(er<erescor[ibin] && er > 0 && r < 0.9) {
	  rescor[ibin] = r;
	  erescor[ibin] = er;
	}
      }
    }
  fclose(fin);
  }
  fprintf(fout,"{\n");
  for(int j = 0; j<ntrkbins; j++) {
    fprintf(fout,"%7.5f,\t",rescor[j]);
    if(j==9||j==19||j==24) fprintf(fout,"\n");
  }

  for(int j = 0; j<ntrkbins; j++) {
    fprintf(fout,"%7.5f,\t",erescor[j]);
    if(j==9||j==19||j==24) fprintf(fout,"\n");
  }
  fprintf(fout,"},\n");
}
void GenRescorTables(){
  htrk = new TH1I("htrk","htrk",ntrkbins,trkBins);
  fout = fopen("rescor.h","w");
  fprintf(fout,"double rescor_pPb[%d][50]={\n",NumEPNames);
  for(int i = 0; i<NumEPNames; i++){
    GenRescorTable("pPb",EPNames[i]);
  }
  fprintf(fout,"};\n");

  fprintf(fout,"double rescor_Pbp[%d][50]={\n",NumEPNames);
  for(int i = 0; i<NumEPNames; i++){
    GenRescorTable("Pbp",EPNames[i]);
  }
  fprintf(fout,"};\n");
  fclose(fout);
}
