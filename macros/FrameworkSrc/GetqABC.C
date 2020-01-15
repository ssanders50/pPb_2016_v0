double Framework::GetqABC(int roi, int sub) {
  double AB = r[roi].qAB[sub]/r[roi].wAB[sub];
  double AC = r[roi].qAC[sub]/r[roi].wAC[sub];
  double BC = r[roi].qBC[sub]/r[roi].wBC[sub];
  return sqrt(AB*AC/BC);
}
