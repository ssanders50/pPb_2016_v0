double Framework::GetVnSubEvt(int roi, int sub){
  double vnav=0;
  for(int i = 0; i<10; i++) {
    vnav+=GetVnSub(roi,i,sub);
  }

  vnav/=10.;
  return vnav;
}
