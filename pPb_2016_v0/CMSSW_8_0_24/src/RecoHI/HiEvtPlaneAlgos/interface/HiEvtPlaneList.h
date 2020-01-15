#ifndef __HiEvtPlaneList__
#define __HiEvtPlaneList__
/*
Index     Name   Detector Order hmin1 hmax1 hmin2 hmax2 minpt maxpt nsub mcw    rmate1    rmate2
    0      HFm1        HF     1 -5.00 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp1 trackmid1
    1      HFp1        HF     1  3.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm1 trackmid1
    2 trackmid1   Tracker     1 -0.80  0.80  0.00  0.00  0.30  3.00 3sub  no      HFm1      HFp1
    3   trackm1   Tracker     1 -0.50  0.00  0.00  0.00  0.30  3.00 3sub  no      HFp1      HFm1
    4   trackp1   Tracker     1  0.00  0.50  0.00  0.00  0.30  3.00 3sub  no      HFp1      HFm1
    5 trackm122   Tracker     1 -2.40 -2.00  0.00  0.00  0.30  3.00 3sub  no      HFm1      HFp1
    6 trackm118   Tracker     1 -2.00 -1.60  0.00  0.00  0.30  3.00 3sub  no      HFm1      HFp1
    7 trackm114   Tracker     1 -1.60 -1.20  0.00  0.00  0.30  3.00 3sub  no      HFm1      HFp1
    8 trackm110   Tracker     1 -1.20 -0.80  0.00  0.00  0.30  3.00 3sub  no      HFm1      HFp1
    9 trackm106   Tracker     1 -0.80 -0.40  0.00  0.00  0.30  3.00 3sub  no      HFm1      HFp1
   10 trackm102   Tracker     1 -0.40  0.00  0.00  0.00  0.30  3.00 3sub  no      HFm1      HFp1
   11 trackp102   Tracker     1  0.00  0.40  0.00  0.00  0.30  3.00 3sub  no      HFm1      HFp1
   12 trackp106   Tracker     1  0.40  0.80  0.00  0.00  0.30  3.00 3sub  no      HFm1      HFp1
   13 trackp110   Tracker     1  0.80  1.20  0.00  0.00  0.30  3.00 3sub  no      HFm1      HFp1
   14 trackp114   Tracker     1  1.20  1.60  0.00  0.00  0.30  3.00 3sub  no      HFm1      HFp1
   15 trackp118   Tracker     1  1.60  2.00  0.00  0.00  0.30  3.00 3sub  no      HFm1      HFp1
   16 trackp122   Tracker     1  2.00  2.40  0.00  0.00  0.30  3.00 3sub  no      HFm1      HFp1
   17trackmid1mc   Tracker     1 -0.80  0.80  0.00  0.00  0.30  3.00 3sub yestrackm122mctrackp122mc
   18 trackm1mc   Tracker     1 -0.50  0.00  0.00  0.00  0.30  3.00 3sub yestrackm122mctrackp122mc
   19 trackp1mc   Tracker     1  0.00  0.50  0.00  0.00  0.30  3.00 3sub yestrackm122mctrackp122mc
   20trackm122mc   Tracker     1 -2.40 -2.00  0.00  0.00  0.30  3.00 3sub yes trackp1mctrackp122mc
   21trackm118mc   Tracker     1 -2.00 -1.60  0.00  0.00  0.30  3.00 3sub yes trackp1mctrackp122mc
   22trackm114mc   Tracker     1 -1.60 -1.20  0.00  0.00  0.30  3.00 3sub yes trackp1mctrackp122mc
   23trackm110mc   Tracker     1 -1.20 -0.80  0.00  0.00  0.30  3.00 3sub yes trackp1mctrackp122mc
   24trackm106mc   Tracker     1 -0.80 -0.40  0.00  0.00  0.30  3.00 3sub yestrackp110mctrackp122mc
   25trackm102mc   Tracker     1 -0.40  0.00  0.00  0.00  0.30  3.00 3sub yestrackp110mctrackp122mc
   26trackp102mc   Tracker     1  0.00  0.40  0.00  0.00  0.30  3.00 3sub yestrackm110mctrackm122mc
   27trackp106mc   Tracker     1  0.40  0.80  0.00  0.00  0.30  3.00 3sub yestrackm110mctrackm122mc
   28trackp110mc   Tracker     1  0.80  1.20  0.00  0.00  0.30  3.00 3sub yes trackm1mctrackm122mc
   29trackp114mc   Tracker     1  1.20  1.60  0.00  0.00  0.30  3.00 3sub yes trackm1mctrackm122mc
   30trackp118mc   Tracker     1  1.60  2.00  0.00  0.00  0.30  3.00 3sub yes trackm1mctrackm122mc
   31trackp122mc   Tracker     1  2.00  2.40  0.00  0.00  0.30  3.00 3sub yes trackm1mctrackm122mc
   32     HFm1a        HF     1 -2.50 -2.00  0.00  0.00  0.01 30.00 3sub  no      HFp1   trackp1
   33     HFm1b        HF     1 -3.00 -2.50  0.00  0.00  0.01 30.00 3sub  no      HFp1   trackp1
   34     HFm1c        HF     1 -3.50 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp1   trackp1
   35     HFm1d        HF     1 -4.00 -3.50  0.00  0.00  0.01 30.00 3sub  no      HFp1   trackp1
   36     HFm1e        HF     1 -4.50 -4.00  0.00  0.00  0.01 30.00 3sub  no      HFp1   trackp1
   37     HFm1f        HF     1 -5.00 -4.50  0.00  0.00  0.01 30.00 3sub  no      HFp1   trackp1
   38     HFp1a        HF     1  2.00  2.50  0.00  0.00  0.01 30.00 3sub  no      HFm1   trackm1
   39     HFp1b        HF     1  2.50  3.00  0.00  0.00  0.01 30.00 3sub  no      HFm1   trackm1
   40     HFp1c        HF     1  3.00  3.50  0.00  0.00  0.01 30.00 3sub  no      HFm1   trackm1
   41     HFp1d        HF     1  3.50  4.00  0.00  0.00  0.01 30.00 3sub  no      HFm1   trackm1
   42     HFp1e        HF     1  4.00  4.50  0.00  0.00  0.01 30.00 3sub  no      HFm1   trackm1
   43     HFp1f        HF     1  4.50  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm1   trackm1
   44      HFm2        HF     2 -5.00 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp2 trackmid2
   45      HFp2        HF     2  3.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm2 trackmid2
   46 trackmid2   Tracker     2 -0.80  0.80  0.00  0.00  0.30  3.00 3sub  no      HFm2      HFp2
   47   trackm2   Tracker     2 -0.50  0.00  0.00  0.00  0.30  3.00 3sub  no      HFp2      HFm2
   48   trackp2   Tracker     2  0.00  0.50  0.00  0.00  0.30  3.00 3sub  no      HFp2      HFm2
   49 trackm222   Tracker     2 -2.40 -2.00  0.00  0.00  0.30  3.00 3sub  no      HFm2      HFp2
   50 trackm218   Tracker     2 -2.00 -1.60  0.00  0.00  0.30  3.00 3sub  no      HFm2      HFp2
   51 trackm214   Tracker     2 -1.60 -1.20  0.00  0.00  0.30  3.00 3sub  no      HFm2      HFp2
   52 trackm210   Tracker     2 -1.20 -0.80  0.00  0.00  0.30  3.00 3sub  no      HFm2      HFp2
   53 trackm206   Tracker     2 -0.80 -0.40  0.00  0.00  0.30  3.00 3sub  no      HFm2      HFp2
   54 trackm202   Tracker     2 -0.40  0.00  0.00  0.00  0.30  3.00 3sub  no      HFm2      HFp2
   55 trackp202   Tracker     2  0.00  0.40  0.00  0.00  0.30  3.00 3sub  no      HFm2      HFp2
   56 trackp206   Tracker     2  0.40  0.80  0.00  0.00  0.30  3.00 3sub  no      HFm2      HFp2
   57 trackp210   Tracker     2  0.80  1.20  0.00  0.00  0.30  3.00 3sub  no      HFm2      HFp2
   58 trackp214   Tracker     2  1.20  1.60  0.00  0.00  0.30  3.00 3sub  no      HFm2      HFp2
   59 trackp218   Tracker     2  1.60  2.00  0.00  0.00  0.30  3.00 3sub  no      HFm2      HFp2
   60 trackp222   Tracker     2  2.00  2.40  0.00  0.00  0.30  3.00 3sub  no      HFm2      HFp2
   61     HFm2a        HF     2 -2.50 -2.00  0.00  0.00  0.01 30.00 3sub  no      HFp2   trackp2
   62     HFm2b        HF     2 -3.00 -2.50  0.00  0.00  0.01 30.00 3sub  no      HFp2   trackp2
   63     HFm2c        HF     2 -3.50 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp2   trackp2
   64     HFm2d        HF     2 -4.00 -3.50  0.00  0.00  0.01 30.00 3sub  no      HFp2   trackp2
   65     HFm2e        HF     2 -4.50 -4.00  0.00  0.00  0.01 30.00 3sub  no      HFp2   trackp2
   66     HFm2f        HF     2 -5.00 -4.50  0.00  0.00  0.01 30.00 3sub  no      HFp2   trackp2
   67     HFp2a        HF     2  2.00  2.50  0.00  0.00  0.01 30.00 3sub  no      HFm2   trackm2
   68     HFp2b        HF     2  2.50  3.00  0.00  0.00  0.01 30.00 3sub  no      HFm2   trackm2
   69     HFp2c        HF     2  3.00  3.50  0.00  0.00  0.01 30.00 3sub  no      HFm2   trackm2
   70     HFp2d        HF     2  3.50  4.00  0.00  0.00  0.01 30.00 3sub  no      HFm2   trackm2
   71     HFp2e        HF     2  4.00  4.50  0.00  0.00  0.01 30.00 3sub  no      HFm2   trackm2
   72     HFp2f        HF     2  4.50  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm2   trackm2
   73      HFm3        HF     3 -5.00 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp3 trackmid3
   74      HFp3        HF     3  3.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm3 trackmid3
   75 trackmid3   Tracker     3 -0.80  0.80  0.00  0.00  0.30  3.00 3sub  no      HFm3      HFp3
   76   trackm3   Tracker     3 -0.50  0.00  0.00  0.00  0.30  3.00 3sub  no      HFp3      HFm3
   77   trackp3   Tracker     3  0.00  0.50  0.00  0.00  0.30  3.00 3sub  no      HFp3      HFm3
   78 trackm322   Tracker     3 -2.40 -2.00  0.00  0.00  0.30  3.00 3sub  no      HFm3      HFp3
   79 trackm318   Tracker     3 -2.00 -1.60  0.00  0.00  0.30  3.00 3sub  no      HFm3      HFp3
   80 trackm314   Tracker     3 -1.60 -1.20  0.00  0.00  0.30  3.00 3sub  no      HFm3      HFp3
   81 trackm310   Tracker     3 -1.20 -0.80  0.00  0.00  0.30  3.00 3sub  no      HFm3      HFp3
   82 trackm306   Tracker     3 -0.80 -0.40  0.00  0.00  0.30  3.00 3sub  no      HFm3      HFp3
   83 trackm302   Tracker     3 -0.40  0.00  0.00  0.00  0.30  3.00 3sub  no      HFm3      HFp3
   84 trackp302   Tracker     3  0.00  0.40  0.00  0.00  0.30  3.00 3sub  no      HFm3      HFp3
   85 trackp306   Tracker     3  0.40  0.80  0.00  0.00  0.30  3.00 3sub  no      HFm3      HFp3
   86 trackp310   Tracker     3  0.80  1.20  0.00  0.00  0.30  3.00 3sub  no      HFm3      HFp3
   87 trackp314   Tracker     3  1.20  1.60  0.00  0.00  0.30  3.00 3sub  no      HFm3      HFp3
   88 trackp318   Tracker     3  1.60  2.00  0.00  0.00  0.30  3.00 3sub  no      HFm3      HFp3
   89 trackp322   Tracker     3  2.00  2.40  0.00  0.00  0.30  3.00 3sub  no      HFm3      HFp3
   90     HFm3a        HF     3 -5.00 -2.00  0.00  0.00  0.01 30.00 3sub  no      HFp3   trackp3
   91     HFm3b        HF     3 -5.00 -2.50  0.00  0.00  0.01 30.00 3sub  no      HFp3   trackp3
   92     HFm3c        HF     3 -5.00 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp3   trackp3
   93     HFm3d        HF     3 -5.00 -3.50  0.00  0.00  0.01 30.00 3sub  no      HFp3   trackp3
   94     HFm3e        HF     3 -5.00 -4.00  0.00  0.00  0.01 30.00 3sub  no      HFp3   trackp3
   95     HFm3f        HF     3 -5.00 -4.50  0.00  0.00  0.01 30.00 3sub  no      HFp3   trackp3
   96     HFp3a        HF     3  2.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm3   trackm3
   97     HFp3b        HF     3  2.50  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm3   trackm3
   98     HFp3c        HF     3  3.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm3   trackm3
   99     HFp3d        HF     3  3.50  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm3   trackm3
  100     HFp3e        HF     3  4.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm3   trackm3
  101     HFp3f        HF     3  4.50  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm3   trackm3
  102      HFm4        HF     4 -5.00 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp4 trackmid4
  103      HFp4        HF     4  3.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm4 trackmid4
  104 trackmid4   Tracker     4 -0.80  0.80  0.00  0.00  0.30  3.00 3sub  no      HFm4      HFp4
  105   trackm4   Tracker     4 -0.50  0.00  0.00  0.00  0.30  3.00 3sub  no      HFp4      HFm4
  106   trackp4   Tracker     4  0.00  0.50  0.00  0.00  0.30  3.00 3sub  no      HFp4      HFm4
  107 trackm422   Tracker     4 -2.40 -2.00  0.00  0.00  0.30  3.00 3sub  no      HFm4      HFp4
  108 trackm418   Tracker     4 -2.00 -1.60  0.00  0.00  0.30  3.00 3sub  no      HFm4      HFp4
  109 trackm414   Tracker     4 -1.60 -1.20  0.00  0.00  0.30  3.00 3sub  no      HFm4      HFp4
  110 trackm410   Tracker     4 -1.20 -0.80  0.00  0.00  0.30  3.00 3sub  no      HFm4      HFp4
  111 trackm406   Tracker     4 -0.80 -0.40  0.00  0.00  0.30  3.00 3sub  no      HFm4      HFp4
  112 trackm402   Tracker     4 -0.40  0.00  0.00  0.00  0.30  3.00 3sub  no      HFm4      HFp4
  113 trackp402   Tracker     4  0.00  0.40  0.00  0.00  0.30  3.00 3sub  no      HFm4      HFp4
  114 trackp406   Tracker     4  0.40  0.80  0.00  0.00  0.30  3.00 3sub  no      HFm4      HFp4
  115 trackp410   Tracker     4  0.80  1.20  0.00  0.00  0.30  3.00 3sub  no      HFm4      HFp4
  116 trackp414   Tracker     4  1.20  1.60  0.00  0.00  0.30  3.00 3sub  no      HFm4      HFp4
  117 trackp418   Tracker     4  1.60  2.00  0.00  0.00  0.30  3.00 3sub  no      HFm4      HFp4
  118 trackp422   Tracker     4  2.00  2.40  0.00  0.00  0.30  3.00 3sub  no      HFm4      HFp4
  119     HFm4a        HF     4 -5.00 -2.00  0.00  0.00  0.01 30.00 3sub  no      HFp4   trackp4
  120     HFm4b        HF     4 -5.00 -2.50  0.00  0.00  0.01 30.00 3sub  no      HFp4   trackp4
  121     HFm4c        HF     4 -5.00 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp4   trackp4
  122    HFm43d        HF     4 -5.00 -3.50  0.00  0.00  0.01 30.00 3sub  no      HFp4   trackp4
  123     HFm4e        HF     4 -5.00 -4.00  0.00  0.00  0.01 30.00 3sub  no      HFp4   trackp4
  124     HFm4f        HF     4 -5.00 -4.50  0.00  0.00  0.01 30.00 3sub  no      HFp4   trackp4
  125     HFp4a        HF     4  2.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm4   trackm4
  126     HFp4b        HF     4  2.50  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm4   trackm4
  127     HFp4c        HF     4  3.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm4   trackm4
  128     HFp4d        HF     4  3.50  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm4   trackm4
  129     HFp4e        HF     4  4.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm4   trackm4
  130     HFp4f        HF     4  4.50  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm4   trackm4
  131      HFm5        HF     5 -5.00 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp5 trackmid5
  132      HFp5        HF     5  3.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm5 trackmid5
  133 trackmid5   Tracker     5 -0.80  0.80  0.00  0.00  0.30  3.00 3sub  no      HFm5      HFp5
  134   trackm5   Tracker     5 -0.50  0.00  0.00  0.00  0.30  3.00 3sub  no      HFp5      HFm5
  135   trackp5   Tracker     5  0.00  0.50  0.00  0.00  0.30  3.00 3sub  no      HFp5      HFm5
  136 trackm522   Tracker     5 -2.40 -2.00  0.00  0.00  0.30  3.00 3sub  no      HFm5      HFp5
  137 trackm518   Tracker     5 -2.00 -1.60  0.00  0.00  0.30  3.00 3sub  no      HFm5      HFp5
  138 trackm514   Tracker     5 -1.60 -1.20  0.00  0.00  0.30  3.00 3sub  no      HFm5      HFp5
  139 trackm510   Tracker     5 -1.20 -0.80  0.00  0.00  0.30  3.00 3sub  no      HFm5      HFp5
  140 trackm506   Tracker     5 -0.80 -0.40  0.00  0.00  0.30  3.00 3sub  no      HFm5      HFp5
  141 trackm502   Tracker     5 -0.40  0.00  0.00  0.00  0.30  3.00 3sub  no      HFm5      HFp5
  142 trackp502   Tracker     5  0.00  0.40  0.00  0.00  0.30  3.00 3sub  no      HFm5      HFp5
  143 trackp506   Tracker     5  0.40  0.80  0.00  0.00  0.30  3.00 3sub  no      HFm5      HFp5
  144 trackp510   Tracker     5  0.80  1.20  0.00  0.00  0.30  3.00 3sub  no      HFm5      HFp5
  145 trackp514   Tracker     5  1.20  1.60  0.00  0.00  0.30  3.00 3sub  no      HFm5      HFp5
  146 trackp518   Tracker     5  1.60  2.00  0.00  0.00  0.30  3.00 3sub  no      HFm5      HFp5
  147 trackp522   Tracker     5  2.00  2.40  0.00  0.00  0.30  3.00 3sub  no      HFm5      HFp5
  148      HFm6        HF     6 -5.00 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp6 trackmid6
  149      HFp6        HF     6  3.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm6 trackmid6
  150 trackmid6   Tracker     6 -0.80  0.80  0.00  0.00  0.30  3.00 3sub  no      HFm6      HFp6
  151   trackm6   Tracker     6 -0.50  0.00  0.00  0.00  0.30  3.00 3sub  no      HFp6      HFm6
  152   trackp6   Tracker     6  0.00  0.50  0.00  0.00  0.30  3.00 3sub  no      HFp6      HFm6
  153 trackm622   Tracker     6 -2.40 -2.00  0.00  0.00  0.30  3.00 3sub  no      HFm6      HFp6
  154 trackm618   Tracker     6 -2.00 -1.60  0.00  0.00  0.30  3.00 3sub  no      HFm6      HFp6
  155 trackm614   Tracker     6 -1.60 -1.20  0.00  0.00  0.30  3.00 3sub  no      HFm6      HFp6
  156 trackm610   Tracker     6 -1.20 -0.80  0.00  0.00  0.30  3.00 3sub  no      HFm6      HFp6
  157 trackm606   Tracker     6 -0.80 -0.40  0.00  0.00  0.30  3.00 3sub  no      HFm6      HFp6
  158 trackm602   Tracker     6 -0.40  0.00  0.00  0.00  0.30  3.00 3sub  no      HFm6      HFp6
  159 trackp602   Tracker     6  0.00  0.40  0.00  0.00  0.30  3.00 3sub  no      HFm6      HFp6
  160 trackp606   Tracker     6  0.40  0.80  0.00  0.00  0.30  3.00 3sub  no      HFm6      HFp6
  161 trackp610   Tracker     6  0.80  1.20  0.00  0.00  0.30  3.00 3sub  no      HFm6      HFp6
  162 trackp614   Tracker     6  1.20  1.60  0.00  0.00  0.30  3.00 3sub  no      HFm6      HFp6
  163 trackp618   Tracker     6  1.60  2.00  0.00  0.00  0.30  3.00 3sub  no      HFm6      HFp6
  164 trackp622   Tracker     6  2.00  2.40  0.00  0.00  0.30  3.00 3sub  no      HFm6      HFp6
  165      HFm7        HF     7 -5.00 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp7 trackmid7
  166      HFp7        HF     7  3.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm7 trackmid7
  167 trackmid7   Tracker     7 -0.80  0.80  0.00  0.00  0.30  3.00 3sub  no      HFm7      HFp7
  168   trackm7   Tracker     7 -0.50  0.00  0.00  0.00  0.30  3.00 3sub  no      HFp7      HFm7
  169   trackp7   Tracker     7  0.00  0.50  0.00  0.00  0.30  3.00 3sub  no      HFp7      HFm7
  170 trackm722   Tracker     7 -2.40 -2.00  0.00  0.00  0.30  3.00 3sub  no      HFm7      HFp7
  171 trackm718   Tracker     7 -2.00 -1.60  0.00  0.00  0.30  3.00 3sub  no      HFm7      HFp7
  172 trackm714   Tracker     7 -1.60 -1.20  0.00  0.00  0.30  3.00 3sub  no      HFm7      HFp7
  173 trackm710   Tracker     7 -1.20 -0.80  0.00  0.00  0.30  3.00 3sub  no      HFm7      HFp7
  174 trackm706   Tracker     7 -0.80 -0.40  0.00  0.00  0.30  3.00 3sub  no      HFm7      HFp7
  175 trackm702   Tracker     7 -0.40  0.00  0.00  0.00  0.30  3.00 3sub  no      HFm7      HFp7
  176 trackp702   Tracker     7  0.00  0.40  0.00  0.00  0.30  3.00 3sub  no      HFm7      HFp7
  177 trackp706   Tracker     7  0.40  0.80  0.00  0.00  0.30  3.00 3sub  no      HFm7      HFp7
  178 trackp710   Tracker     7  0.80  1.20  0.00  0.00  0.30  3.00 3sub  no      HFm7      HFp7
  179 trackp714   Tracker     7  1.20  1.60  0.00  0.00  0.30  3.00 3sub  no      HFm7      HFp7
  180 trackp718   Tracker     7  1.60  2.00  0.00  0.00  0.30  3.00 3sub  no      HFm7      HFp7
  181 trackp722   Tracker     7  2.00  2.40  0.00  0.00  0.30  3.00 3sub  no      HFm7      HFp7
*/
#include <string>
using namespace std;
namespace hi{

  enum EPNamesInd {
          HFm1,        HFp1,   trackmid1,     trackm1,     trackp1,
     trackm122,   trackm118,   trackm114,   trackm110,   trackm106,
     trackm102,   trackp102,   trackp106,   trackp110,   trackp114,
     trackp118,   trackp122, trackmid1mc,   trackm1mc,   trackp1mc,
   trackm122mc, trackm118mc, trackm114mc, trackm110mc, trackm106mc,
   trackm102mc, trackp102mc, trackp106mc, trackp110mc, trackp114mc,
   trackp118mc, trackp122mc,       HFm1a,       HFm1b,       HFm1c,
         HFm1d,       HFm1e,       HFm1f,       HFp1a,       HFp1b,
         HFp1c,       HFp1d,       HFp1e,       HFp1f,        HFm2,
          HFp2,   trackmid2,     trackm2,     trackp2,   trackm222,
     trackm218,   trackm214,   trackm210,   trackm206,   trackm202,
     trackp202,   trackp206,   trackp210,   trackp214,   trackp218,
     trackp222,       HFm2a,       HFm2b,       HFm2c,       HFm2d,
         HFm2e,       HFm2f,       HFp2a,       HFp2b,       HFp2c,
         HFp2d,       HFp2e,       HFp2f,        HFm3,        HFp3,
     trackmid3,     trackm3,     trackp3,   trackm322,   trackm318,
     trackm314,   trackm310,   trackm306,   trackm302,   trackp302,
     trackp306,   trackp310,   trackp314,   trackp318,   trackp322,
         HFm3a,       HFm3b,       HFm3c,       HFm3d,       HFm3e,
         HFm3f,       HFp3a,       HFp3b,       HFp3c,       HFp3d,
         HFp3e,       HFp3f,        HFm4,        HFp4,   trackmid4,
       trackm4,     trackp4,   trackm422,   trackm418,   trackm414,
     trackm410,   trackm406,   trackm402,   trackp402,   trackp406,
     trackp410,   trackp414,   trackp418,   trackp422,       HFm4a,
         HFm4b,       HFm4c,      HFm43d,       HFm4e,       HFm4f,
         HFp4a,       HFp4b,       HFp4c,       HFp4d,       HFp4e,
         HFp4f,        HFm5,        HFp5,   trackmid5,     trackm5,
       trackp5,   trackm522,   trackm518,   trackm514,   trackm510,
     trackm506,   trackm502,   trackp502,   trackp506,   trackp510,
     trackp514,   trackp518,   trackp522,        HFm6,        HFp6,
     trackmid6,     trackm6,     trackp6,   trackm622,   trackm618,
     trackm614,   trackm610,   trackm606,   trackm602,   trackp602,
     trackp606,   trackp610,   trackp614,   trackp618,   trackp622,
          HFm7,        HFp7,   trackmid7,     trackm7,     trackp7,
     trackm722,   trackm718,   trackm714,   trackm710,   trackm706,
     trackm702,   trackp702,   trackp706,   trackp710,   trackp714,
     trackp718,   trackp722,   EPBLANK
  };

  const std::string  EPNames[]  = {
        "HFm1",      "HFp1", "trackmid1",   "trackm1",   "trackp1",
   "trackm122", "trackm118", "trackm114", "trackm110", "trackm106",
   "trackm102", "trackp102", "trackp106", "trackp110", "trackp114",
   "trackp118", "trackp122","trackmid1mc", "trackm1mc", "trackp1mc",
  "trackm122mc","trackm118mc","trackm114mc","trackm110mc","trackm106mc",
  "trackm102mc","trackp102mc","trackp106mc","trackp110mc","trackp114mc",
  "trackp118mc","trackp122mc",     "HFm1a",     "HFm1b",     "HFm1c",
       "HFm1d",     "HFm1e",     "HFm1f",     "HFp1a",     "HFp1b",
       "HFp1c",     "HFp1d",     "HFp1e",     "HFp1f",      "HFm2",
        "HFp2", "trackmid2",   "trackm2",   "trackp2", "trackm222",
   "trackm218", "trackm214", "trackm210", "trackm206", "trackm202",
   "trackp202", "trackp206", "trackp210", "trackp214", "trackp218",
   "trackp222",     "HFm2a",     "HFm2b",     "HFm2c",     "HFm2d",
       "HFm2e",     "HFm2f",     "HFp2a",     "HFp2b",     "HFp2c",
       "HFp2d",     "HFp2e",     "HFp2f",      "HFm3",      "HFp3",
   "trackmid3",   "trackm3",   "trackp3", "trackm322", "trackm318",
   "trackm314", "trackm310", "trackm306", "trackm302", "trackp302",
   "trackp306", "trackp310", "trackp314", "trackp318", "trackp322",
       "HFm3a",     "HFm3b",     "HFm3c",     "HFm3d",     "HFm3e",
       "HFm3f",     "HFp3a",     "HFp3b",     "HFp3c",     "HFp3d",
       "HFp3e",     "HFp3f",      "HFm4",      "HFp4", "trackmid4",
     "trackm4",   "trackp4", "trackm422", "trackm418", "trackm414",
   "trackm410", "trackm406", "trackm402", "trackp402", "trackp406",
   "trackp410", "trackp414", "trackp418", "trackp422",     "HFm4a",
       "HFm4b",     "HFm4c",    "HFm43d",     "HFm4e",     "HFm4f",
       "HFp4a",     "HFp4b",     "HFp4c",     "HFp4d",     "HFp4e",
       "HFp4f",      "HFm5",      "HFp5", "trackmid5",   "trackm5",
     "trackp5", "trackm522", "trackm518", "trackm514", "trackm510",
   "trackm506", "trackm502", "trackp502", "trackp506", "trackp510",
   "trackp514", "trackp518", "trackp522",      "HFm6",      "HFp6",
   "trackmid6",   "trackm6",   "trackp6", "trackm622", "trackm618",
   "trackm614", "trackm610", "trackm606", "trackm602", "trackp602",
   "trackp606", "trackp610", "trackp614", "trackp618", "trackp622",
        "HFm7",      "HFp7", "trackmid7",   "trackm7",   "trackp7",
   "trackm722", "trackm718", "trackm714", "trackm710", "trackm706",
   "trackm702", "trackp702", "trackp706", "trackp710", "trackp714",
   "trackp718", "trackp722" 
  };

  enum Detectors {Tracker, HF, Castor};

  const int  EPDet[]  = {
          HF,        HF,   Tracker,   Tracker,   Tracker,
     Tracker,   Tracker,   Tracker,   Tracker,   Tracker,
     Tracker,   Tracker,   Tracker,   Tracker,   Tracker,
     Tracker,   Tracker,   Tracker,   Tracker,   Tracker,
     Tracker,   Tracker,   Tracker,   Tracker,   Tracker,
     Tracker,   Tracker,   Tracker,   Tracker,   Tracker,
     Tracker,   Tracker,        HF,        HF,        HF,
          HF,        HF,        HF,        HF,        HF,
          HF,        HF,        HF,        HF,        HF,
          HF,   Tracker,   Tracker,   Tracker,   Tracker,
     Tracker,   Tracker,   Tracker,   Tracker,   Tracker,
     Tracker,   Tracker,   Tracker,   Tracker,   Tracker,
     Tracker,        HF,        HF,        HF,        HF,
          HF,        HF,        HF,        HF,        HF,
          HF,        HF,        HF,        HF,        HF,
     Tracker,   Tracker,   Tracker,   Tracker,   Tracker,
     Tracker,   Tracker,   Tracker,   Tracker,   Tracker,
     Tracker,   Tracker,   Tracker,   Tracker,   Tracker,
          HF,        HF,        HF,        HF,        HF,
          HF,        HF,        HF,        HF,        HF,
          HF,        HF,        HF,        HF,   Tracker,
     Tracker,   Tracker,   Tracker,   Tracker,   Tracker,
     Tracker,   Tracker,   Tracker,   Tracker,   Tracker,
     Tracker,   Tracker,   Tracker,   Tracker,        HF,
          HF,        HF,        HF,        HF,        HF,
          HF,        HF,        HF,        HF,        HF,
          HF,        HF,        HF,   Tracker,   Tracker,
     Tracker,   Tracker,   Tracker,   Tracker,   Tracker,
     Tracker,   Tracker,   Tracker,   Tracker,   Tracker,
     Tracker,   Tracker,   Tracker,        HF,        HF,
     Tracker,   Tracker,   Tracker,   Tracker,   Tracker,
     Tracker,   Tracker,   Tracker,   Tracker,   Tracker,
     Tracker,   Tracker,   Tracker,   Tracker,   Tracker,
          HF,        HF,   Tracker,   Tracker,   Tracker,
     Tracker,   Tracker,   Tracker,   Tracker,   Tracker,
     Tracker,   Tracker,   Tracker,   Tracker,   Tracker,
     Tracker,   Tracker 
  };

  const int  EPOrder[]  = {
             1,           1,           1,           1,           1,
             1,           1,           1,           1,           1,
             1,           1,           1,           1,           1,
             1,           1,           1,           1,           1,
             1,           1,           1,           1,           1,
             1,           1,           1,           1,           1,
             1,           1,           1,           1,           1,
             1,           1,           1,           1,           1,
             1,           1,           1,           1,           2,
             2,           2,           2,           2,           2,
             2,           2,           2,           2,           2,
             2,           2,           2,           2,           2,
             2,           2,           2,           2,           2,
             2,           2,           2,           2,           2,
             2,           2,           2,           3,           3,
             3,           3,           3,           3,           3,
             3,           3,           3,           3,           3,
             3,           3,           3,           3,           3,
             3,           3,           3,           3,           3,
             3,           3,           3,           3,           3,
             3,           3,           4,           4,           4,
             4,           4,           4,           4,           4,
             4,           4,           4,           4,           4,
             4,           4,           4,           4,           4,
             4,           4,           4,           4,           4,
             4,           4,           4,           4,           4,
             4,           5,           5,           5,           5,
             5,           5,           5,           5,           5,
             5,           5,           5,           5,           5,
             5,           5,           5,           6,           6,
             6,           6,           6,           6,           6,
             6,           6,           6,           6,           6,
             6,           6,           6,           6,           6,
             7,           7,           7,           7,           7,
             7,           7,           7,           7,           7,
             7,           7,           7,           7,           7,
             7,           7 
  };

  const double  EPEtaMin1[]  = {
         -5.00,        3.00,       -0.80,       -0.50,        0.00,
         -2.40,       -2.00,       -1.60,       -1.20,       -0.80,
         -0.40,        0.00,        0.40,        0.80,        1.20,
          1.60,        2.00,       -0.80,       -0.50,        0.00,
         -2.40,       -2.00,       -1.60,       -1.20,       -0.80,
         -0.40,        0.00,        0.40,        0.80,        1.20,
          1.60,        2.00,       -2.50,       -3.00,       -3.50,
         -4.00,       -4.50,       -5.00,        2.00,        2.50,
          3.00,        3.50,        4.00,        4.50,       -5.00,
          3.00,       -0.80,       -0.50,        0.00,       -2.40,
         -2.00,       -1.60,       -1.20,       -0.80,       -0.40,
          0.00,        0.40,        0.80,        1.20,        1.60,
          2.00,       -2.50,       -3.00,       -3.50,       -4.00,
         -4.50,       -5.00,        2.00,        2.50,        3.00,
          3.50,        4.00,        4.50,       -5.00,        3.00,
         -0.80,       -0.50,        0.00,       -2.40,       -2.00,
         -1.60,       -1.20,       -0.80,       -0.40,        0.00,
          0.40,        0.80,        1.20,        1.60,        2.00,
         -5.00,       -5.00,       -5.00,       -5.00,       -5.00,
         -5.00,        2.00,        2.50,        3.00,        3.50,
          4.00,        4.50,       -5.00,        3.00,       -0.80,
         -0.50,        0.00,       -2.40,       -2.00,       -1.60,
         -1.20,       -0.80,       -0.40,        0.00,        0.40,
          0.80,        1.20,        1.60,        2.00,       -5.00,
         -5.00,       -5.00,       -5.00,       -5.00,       -5.00,
          2.00,        2.50,        3.00,        3.50,        4.00,
          4.50,       -5.00,        3.00,       -0.80,       -0.50,
          0.00,       -2.40,       -2.00,       -1.60,       -1.20,
         -0.80,       -0.40,        0.00,        0.40,        0.80,
          1.20,        1.60,        2.00,       -5.00,        3.00,
         -0.80,       -0.50,        0.00,       -2.40,       -2.00,
         -1.60,       -1.20,       -0.80,       -0.40,        0.00,
          0.40,        0.80,        1.20,        1.60,        2.00,
         -5.00,        3.00,       -0.80,       -0.50,        0.00,
         -2.40,       -2.00,       -1.60,       -1.20,       -0.80,
         -0.40,        0.00,        0.40,        0.80,        1.20,
          1.60,        2.00 
  };

  const double  EPEtaMax1[]  = {
         -3.00,        5.00,        0.80,        0.00,        0.50,
         -2.00,       -1.60,       -1.20,       -0.80,       -0.40,
          0.00,        0.40,        0.80,        1.20,        1.60,
          2.00,        2.40,        0.80,        0.00,        0.50,
         -2.00,       -1.60,       -1.20,       -0.80,       -0.40,
          0.00,        0.40,        0.80,        1.20,        1.60,
          2.00,        2.40,       -2.00,       -2.50,       -3.00,
         -3.50,       -4.00,       -4.50,        2.50,        3.00,
          3.50,        4.00,        4.50,        5.00,       -3.00,
          5.00,        0.80,        0.00,        0.50,       -2.00,
         -1.60,       -1.20,       -0.80,       -0.40,        0.00,
          0.40,        0.80,        1.20,        1.60,        2.00,
          2.40,       -2.00,       -2.50,       -3.00,       -3.50,
         -4.00,       -4.50,        2.50,        3.00,        3.50,
          4.00,        4.50,        5.00,       -3.00,        5.00,
          0.80,        0.00,        0.50,       -2.00,       -1.60,
         -1.20,       -0.80,       -0.40,        0.00,        0.40,
          0.80,        1.20,        1.60,        2.00,        2.40,
         -2.00,       -2.50,       -3.00,       -3.50,       -4.00,
         -4.50,        5.00,        5.00,        5.00,        5.00,
          5.00,        5.00,       -3.00,        5.00,        0.80,
          0.00,        0.50,       -2.00,       -1.60,       -1.20,
         -0.80,       -0.40,        0.00,        0.40,        0.80,
          1.20,        1.60,        2.00,        2.40,       -2.00,
         -2.50,       -3.00,       -3.50,       -4.00,       -4.50,
          5.00,        5.00,        5.00,        5.00,        5.00,
          5.00,       -3.00,        5.00,        0.80,        0.00,
          0.50,       -2.00,       -1.60,       -1.20,       -0.80,
         -0.40,        0.00,        0.40,        0.80,        1.20,
          1.60,        2.00,        2.40,       -3.00,        5.00,
          0.80,        0.00,        0.50,       -2.00,       -1.60,
         -1.20,       -0.80,       -0.40,        0.00,        0.40,
          0.80,        1.20,        1.60,        2.00,        2.40,
         -3.00,        5.00,        0.80,        0.00,        0.50,
         -2.00,       -1.60,       -1.20,       -0.80,       -0.40,
          0.00,        0.40,        0.80,        1.20,        1.60,
          2.00,        2.40 
  };

  const double  EPEtaMin2[]  = {
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00 
  };

  const double  EPEtaMax2[]  = {
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00,        0.00,        0.00,        0.00,
          0.00,        0.00 
  };

  const double  minTransverse[]  = {
          0.01,        0.01,        0.30,        0.30,        0.30,
          0.30,        0.30,        0.30,        0.30,        0.30,
          0.30,        0.30,        0.30,        0.30,        0.30,
          0.30,        0.30,        0.30,        0.30,        0.30,
          0.30,        0.30,        0.30,        0.30,        0.30,
          0.30,        0.30,        0.30,        0.30,        0.30,
          0.30,        0.30,        0.01,        0.01,        0.01,
          0.01,        0.01,        0.01,        0.01,        0.01,
          0.01,        0.01,        0.01,        0.01,        0.01,
          0.01,        0.30,        0.30,        0.30,        0.30,
          0.30,        0.30,        0.30,        0.30,        0.30,
          0.30,        0.30,        0.30,        0.30,        0.30,
          0.30,        0.01,        0.01,        0.01,        0.01,
          0.01,        0.01,        0.01,        0.01,        0.01,
          0.01,        0.01,        0.01,        0.01,        0.01,
          0.30,        0.30,        0.30,        0.30,        0.30,
          0.30,        0.30,        0.30,        0.30,        0.30,
          0.30,        0.30,        0.30,        0.30,        0.30,
          0.01,        0.01,        0.01,        0.01,        0.01,
          0.01,        0.01,        0.01,        0.01,        0.01,
          0.01,        0.01,        0.01,        0.01,        0.30,
          0.30,        0.30,        0.30,        0.30,        0.30,
          0.30,        0.30,        0.30,        0.30,        0.30,
          0.30,        0.30,        0.30,        0.30,        0.01,
          0.01,        0.01,        0.01,        0.01,        0.01,
          0.01,        0.01,        0.01,        0.01,        0.01,
          0.01,        0.01,        0.01,        0.30,        0.30,
          0.30,        0.30,        0.30,        0.30,        0.30,
          0.30,        0.30,        0.30,        0.30,        0.30,
          0.30,        0.30,        0.30,        0.01,        0.01,
          0.30,        0.30,        0.30,        0.30,        0.30,
          0.30,        0.30,        0.30,        0.30,        0.30,
          0.30,        0.30,        0.30,        0.30,        0.30,
          0.01,        0.01,        0.30,        0.30,        0.30,
          0.30,        0.30,        0.30,        0.30,        0.30,
          0.30,        0.30,        0.30,        0.30,        0.30,
          0.30,        0.30 
  };

  const double  maxTransverse[]  = {
         30.00,       30.00,        3.00,        3.00,        3.00,
          3.00,        3.00,        3.00,        3.00,        3.00,
          3.00,        3.00,        3.00,        3.00,        3.00,
          3.00,        3.00,        3.00,        3.00,        3.00,
          3.00,        3.00,        3.00,        3.00,        3.00,
          3.00,        3.00,        3.00,        3.00,        3.00,
          3.00,        3.00,       30.00,       30.00,       30.00,
         30.00,       30.00,       30.00,       30.00,       30.00,
         30.00,       30.00,       30.00,       30.00,       30.00,
         30.00,        3.00,        3.00,        3.00,        3.00,
          3.00,        3.00,        3.00,        3.00,        3.00,
          3.00,        3.00,        3.00,        3.00,        3.00,
          3.00,       30.00,       30.00,       30.00,       30.00,
         30.00,       30.00,       30.00,       30.00,       30.00,
         30.00,       30.00,       30.00,       30.00,       30.00,
          3.00,        3.00,        3.00,        3.00,        3.00,
          3.00,        3.00,        3.00,        3.00,        3.00,
          3.00,        3.00,        3.00,        3.00,        3.00,
         30.00,       30.00,       30.00,       30.00,       30.00,
         30.00,       30.00,       30.00,       30.00,       30.00,
         30.00,       30.00,       30.00,       30.00,        3.00,
          3.00,        3.00,        3.00,        3.00,        3.00,
          3.00,        3.00,        3.00,        3.00,        3.00,
          3.00,        3.00,        3.00,        3.00,       30.00,
         30.00,       30.00,       30.00,       30.00,       30.00,
         30.00,       30.00,       30.00,       30.00,       30.00,
         30.00,       30.00,       30.00,        3.00,        3.00,
          3.00,        3.00,        3.00,        3.00,        3.00,
          3.00,        3.00,        3.00,        3.00,        3.00,
          3.00,        3.00,        3.00,       30.00,       30.00,
          3.00,        3.00,        3.00,        3.00,        3.00,
          3.00,        3.00,        3.00,        3.00,        3.00,
          3.00,        3.00,        3.00,        3.00,        3.00,
         30.00,       30.00,        3.00,        3.00,        3.00,
          3.00,        3.00,        3.00,        3.00,        3.00,
          3.00,        3.00,        3.00,        3.00,        3.00,
          3.00,        3.00 
  };

  const std::string  ResCalcType[]  = {
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub",
        "3sub",      "3sub" 
  };

  const std::string  MomConsWeight[]  = {
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",       "yes",       "yes",       "yes",
         "yes",       "yes",       "yes",       "yes",       "yes",
         "yes",       "yes",       "yes",       "yes",       "yes",
         "yes",       "yes",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no" 
  };

  const int  RCMate1[]  = {
        HFp1,      HFm1,      HFm1,      HFp1,      HFp1,
        HFm1,      HFm1,      HFm1,      HFm1,      HFm1,
        HFm1,      HFm1,      HFm1,      HFm1,      HFm1,
        HFm1,      HFm1,trackm122mc,trackm122mc,trackm122mc,
   trackp1mc, trackp1mc, trackp1mc, trackp1mc,trackp110mc,
  trackp110mc,trackm110mc,trackm110mc, trackm1mc, trackm1mc,
   trackm1mc, trackm1mc,      HFp1,      HFp1,      HFp1,
        HFp1,      HFp1,      HFp1,      HFm1,      HFm1,
        HFm1,      HFm1,      HFm1,      HFm1,      HFp2,
        HFm2,      HFm2,      HFp2,      HFp2,      HFm2,
        HFm2,      HFm2,      HFm2,      HFm2,      HFm2,
        HFm2,      HFm2,      HFm2,      HFm2,      HFm2,
        HFm2,      HFp2,      HFp2,      HFp2,      HFp2,
        HFp2,      HFp2,      HFm2,      HFm2,      HFm2,
        HFm2,      HFm2,      HFm2,      HFp3,      HFm3,
        HFm3,      HFp3,      HFp3,      HFm3,      HFm3,
        HFm3,      HFm3,      HFm3,      HFm3,      HFm3,
        HFm3,      HFm3,      HFm3,      HFm3,      HFm3,
        HFp3,      HFp3,      HFp3,      HFp3,      HFp3,
        HFp3,      HFm3,      HFm3,      HFm3,      HFm3,
        HFm3,      HFm3,      HFp4,      HFm4,      HFm4,
        HFp4,      HFp4,      HFm4,      HFm4,      HFm4,
        HFm4,      HFm4,      HFm4,      HFm4,      HFm4,
        HFm4,      HFm4,      HFm4,      HFm4,      HFp4,
        HFp4,      HFp4,      HFp4,      HFp4,      HFp4,
        HFm4,      HFm4,      HFm4,      HFm4,      HFm4,
        HFm4,      HFp5,      HFm5,      HFm5,      HFp5,
        HFp5,      HFm5,      HFm5,      HFm5,      HFm5,
        HFm5,      HFm5,      HFm5,      HFm5,      HFm5,
        HFm5,      HFm5,      HFm5,      HFp6,      HFm6,
        HFm6,      HFp6,      HFp6,      HFm6,      HFm6,
        HFm6,      HFm6,      HFm6,      HFm6,      HFm6,
        HFm6,      HFm6,      HFm6,      HFm6,      HFm6,
        HFp7,      HFm7,      HFm7,      HFp7,      HFp7,
        HFm7,      HFm7,      HFm7,      HFm7,      HFm7,
        HFm7,      HFm7,      HFm7,      HFm7,      HFm7,
        HFm7,      HFm7 
  };

  const int  RCMate2[]  = {
   trackmid1, trackmid1,      HFp1,      HFm1,      HFm1,
        HFp1,      HFp1,      HFp1,      HFp1,      HFp1,
        HFp1,      HFp1,      HFp1,      HFp1,      HFp1,
        HFp1,      HFp1,trackp122mc,trackp122mc,trackp122mc,
  trackp122mc,trackp122mc,trackp122mc,trackp122mc,trackp122mc,
  trackp122mc,trackm122mc,trackm122mc,trackm122mc,trackm122mc,
  trackm122mc,trackm122mc,   trackp1,   trackp1,   trackp1,
     trackp1,   trackp1,   trackp1,   trackm1,   trackm1,
     trackm1,   trackm1,   trackm1,   trackm1, trackmid2,
   trackmid2,      HFp2,      HFm2,      HFm2,      HFp2,
        HFp2,      HFp2,      HFp2,      HFp2,      HFp2,
        HFp2,      HFp2,      HFp2,      HFp2,      HFp2,
        HFp2,   trackp2,   trackp2,   trackp2,   trackp2,
     trackp2,   trackp2,   trackm2,   trackm2,   trackm2,
     trackm2,   trackm2,   trackm2, trackmid3, trackmid3,
        HFp3,      HFm3,      HFm3,      HFp3,      HFp3,
        HFp3,      HFp3,      HFp3,      HFp3,      HFp3,
        HFp3,      HFp3,      HFp3,      HFp3,      HFp3,
     trackp3,   trackp3,   trackp3,   trackp3,   trackp3,
     trackp3,   trackm3,   trackm3,   trackm3,   trackm3,
     trackm3,   trackm3, trackmid4, trackmid4,      HFp4,
        HFm4,      HFm4,      HFp4,      HFp4,      HFp4,
        HFp4,      HFp4,      HFp4,      HFp4,      HFp4,
        HFp4,      HFp4,      HFp4,      HFp4,   trackp4,
     trackp4,   trackp4,   trackp4,   trackp4,   trackp4,
     trackm4,   trackm4,   trackm4,   trackm4,   trackm4,
     trackm4, trackmid5, trackmid5,      HFp5,      HFm5,
        HFm5,      HFp5,      HFp5,      HFp5,      HFp5,
        HFp5,      HFp5,      HFp5,      HFp5,      HFp5,
        HFp5,      HFp5,      HFp5, trackmid6, trackmid6,
        HFp6,      HFm6,      HFm6,      HFp6,      HFp6,
        HFp6,      HFp6,      HFp6,      HFp6,      HFp6,
        HFp6,      HFp6,      HFp6,      HFp6,      HFp6,
   trackmid7, trackmid7,      HFp7,      HFm7,      HFm7,
        HFp7,      HFp7,      HFp7,      HFp7,      HFp7,
        HFp7,      HFp7,      HFp7,      HFp7,      HFp7,
        HFp7,      HFp7 
  };

  static const int NumEPNames = 182;
}
#endif
