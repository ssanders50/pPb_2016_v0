double Framework::GetVnErrSubEvt(int roi, int isub){
  double vnav=0;
  for(int i = 0; i<10; i++) vnav+=GetVnSub(roi,i,isub);
  vnav/=10.;
  double sig = 0;
  for(int i = 0; i<10; i++) sig+=pow(GetVnSub(roi,i,isub)-vnav,2);
  sig = sqrt(sig)/9.;
  return sig;
}
