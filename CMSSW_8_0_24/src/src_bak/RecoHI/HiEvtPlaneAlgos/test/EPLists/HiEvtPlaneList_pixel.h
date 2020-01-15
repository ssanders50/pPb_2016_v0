#ifndef __HiEvtPlaneList__
#define __HiEvtPlaneList__
/*
Index     Name   Detector Order hmin1 hmax1 hmin2 hmax2 minpt maxpt nsub mcw    rmate1    rmate2
    0      HFm1        HF     1 -5.00 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp1 trackmid1
    1      HFp1        HF     1  3.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm1 trackmid1
    2 trackmid1   Tracker     1 -0.80  0.80  0.00  0.00  0.30  3.00 3sub  no      HFm1      HFp1
    3   trackm1   Tracker     1 -0.50  0.00  0.00  0.00  0.30  3.00 3sub  no      HFp1      HFm1
    4   trackp1   Tracker     1  0.00  0.50  0.00  0.00  0.30  3.00 3sub  no      HFp1      HFm1
    5 trackm1mc   Tracker     1 -0.50  0.00  0.00  0.00  0.30  3.00 3sub yestrackm122mctrackp122mc
    6 trackp1mc   Tracker     1  0.00  0.50  0.00  0.00  0.30  3.00 3sub yestrackm122mctrackp122mc
    7trackmid1mc   Tracker     1 -0.80  0.80  0.00  0.00  0.30  3.00 3sub yestrackm122mctrackp122mc
    8trackm122mc   Tracker     1 -2.40 -2.00  0.00  0.00  0.30  3.00 3sub yes trackp1mctrackp122mc
    9trackm118mc   Tracker     1 -2.00 -1.60  0.00  0.00  0.30  3.00 3sub yes trackp1mctrackp122mc
   10trackm114mc   Tracker     1 -1.60 -1.20  0.00  0.00  0.30  3.00 3sub yes trackp1mctrackp122mc
   11trackm110mc   Tracker     1 -1.20 -0.80  0.00  0.00  0.30  3.00 3sub yes trackp1mctrackp122mc
   12trackm106mc   Tracker     1 -0.80 -0.40  0.00  0.00  0.30  3.00 3sub yestrackp110mctrackp122mc
   13trackm102mc   Tracker     1 -0.40  0.00  0.00  0.00  0.30  3.00 3sub yestrackp110mctrackp122mc
   14trackp102mc   Tracker     1  0.00  0.40  0.00  0.00  0.30  3.00 3sub yestrackm110mctrackm122mc
   15trackp106mc   Tracker     1  0.40  0.80  0.00  0.00  0.30  3.00 3sub yestrackm110mctrackm122mc
   16trackp110mc   Tracker     1  0.80  1.20  0.00  0.00  0.30  3.00 3sub yes trackm1mctrackm122mc
   17trackp114mc   Tracker     1  1.20  1.60  0.00  0.00  0.30  3.00 3sub yes trackm1mctrackm122mc
   18trackp118mc   Tracker     1  1.60  2.00  0.00  0.00  0.30  3.00 3sub yes trackm1mctrackm122mc
   19trackp122mc   Tracker     1  2.00  2.40  0.00  0.00  0.30  3.00 3sub yes trackm1mctrackm122mc
   20      HFm2        HF     2 -5.00 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp2 trackmid2
   21      HFp2        HF     2  3.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm2 trackmid2
   22 trackmid2   Tracker     2 -0.80  0.80  0.00  0.00  0.30  3.00 3sub  no      HFm2      HFp2
   23   trackm2   Tracker     2 -0.50  0.00  0.00  0.00  0.30  3.00 3sub  no      HFp2      HFm2
   24   trackp2   Tracker     2  0.00  0.50  0.00  0.00  0.30  3.00 3sub  no      HFp2      HFm2
   25      HFm3        HF     3 -5.00 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp3 trackmid3
   26      HFp3        HF     3  3.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm3 trackmid3
   27 trackmid3   Tracker     3 -0.80  0.80  0.00  0.00  0.30  3.00 3sub  no      HFm3      HFp3
   28   trackm3   Tracker     3 -0.50  0.00  0.00  0.00  0.30  3.00 3sub  no      HFp3      HFm3
   29   trackp3   Tracker     3  0.00  0.50  0.00  0.00  0.30  3.00 3sub  no      HFp3      HFm3
   30      HFm4        HF     4 -5.00 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp4 trackmid4
   31      HFp4        HF     4  3.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm4 trackmid4
   32 trackmid4   Tracker     4 -0.80  0.80  0.00  0.00  0.30  3.00 3sub  no      HFm4      HFp4
   33   trackm4   Tracker     4 -0.50  0.00  0.00  0.00  0.30  3.00 3sub  no      HFp4      HFm4
   34   trackp4   Tracker     4  0.00  0.50  0.00  0.00  0.30  3.00 3sub  no      HFp4      HFm4
   35      HFm5        HF     5 -5.00 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp5 trackmid5
   36      HFp5        HF     5  3.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm5 trackmid5
   37 trackmid5   Tracker     5 -0.80  0.80  0.00  0.00  0.30  3.00 3sub  no      HFm5      HFp5
   38   trackm5   Tracker     5 -0.50  0.00  0.00  0.00  0.30  3.00 3sub  no      HFp5      HFm5
   39   trackp5   Tracker     5  0.00  0.50  0.00  0.00  0.30  3.00 3sub  no      HFp5      HFm5
   40      HFm6        HF     6 -5.00 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp6 trackmid6
   41      HFp6        HF     6  3.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm6 trackmid6
   42 trackmid6   Tracker     6 -0.80  0.80  0.00  0.00  0.30  3.00 3sub  no      HFm6      HFp6
   43   trackm6   Tracker     6 -0.50  0.00  0.00  0.00  0.30  3.00 3sub  no      HFp6      HFm6
   44   trackp6   Tracker     6  0.00  0.50  0.00  0.00  0.30  3.00 3sub  no      HFp6      HFm6
   45      HFm7        HF     7 -5.00 -3.00  0.00  0.00  0.01 30.00 3sub  no      HFp7 trackmid7
   46      HFp7        HF     7  3.00  5.00  0.00  0.00  0.01 30.00 3sub  no      HFm7 trackmid7
   47 trackmid7   Tracker     7 -0.80  0.80  0.00  0.00  0.30  3.00 3sub  no      HFm7      HFp7
   48   trackm7   Tracker     7 -0.50  0.00  0.00  0.00  0.30  3.00 3sub  no      HFp7      HFm7
   49   trackp7   Tracker     7  0.00  0.50  0.00  0.00  0.30  3.00 3sub  no      HFp7      HFm7
*/
#include <string>
using namespace std;
namespace hi{

  enum EPNamesInd {
          HFm1,        HFp1,   trackmid1,     trackm1,     trackp1,
     trackm1mc,   trackp1mc, trackmid1mc, trackm122mc, trackm118mc,
   trackm114mc, trackm110mc, trackm106mc, trackm102mc, trackp102mc,
   trackp106mc, trackp110mc, trackp114mc, trackp118mc, trackp122mc,
          HFm2,        HFp2,   trackmid2,     trackm2,     trackp2,
          HFm3,        HFp3,   trackmid3,     trackm3,     trackp3,
          HFm4,        HFp4,   trackmid4,     trackm4,     trackp4,
          HFm5,        HFp5,   trackmid5,     trackm5,     trackp5,
          HFm6,        HFp6,   trackmid6,     trackm6,     trackp6,
          HFm7,        HFp7,   trackmid7,     trackm7,     trackp7,
     EPBLANK
  };

  const std::string  EPNames[]  = {
        "HFm1",      "HFp1", "trackmid1",   "trackm1",   "trackp1",
   "trackm1mc", "trackp1mc","trackmid1mc","trackm122mc","trackm118mc",
  "trackm114mc","trackm110mc","trackm106mc","trackm102mc","trackp102mc",
  "trackp106mc","trackp110mc","trackp114mc","trackp118mc","trackp122mc",
        "HFm2",      "HFp2", "trackmid2",   "trackm2",   "trackp2",
        "HFm3",      "HFp3", "trackmid3",   "trackm3",   "trackp3",
        "HFm4",      "HFp4", "trackmid4",   "trackm4",   "trackp4",
        "HFm5",      "HFp5", "trackmid5",   "trackm5",   "trackp5",
        "HFm6",      "HFp6", "trackmid6",   "trackm6",   "trackp6",
        "HFm7",      "HFp7", "trackmid7",   "trackm7",   "trackp7"
   
  };

  enum Detectors {Tracker, HF, Castor};

  const int  EPDet[]  = {
          HF,        HF,   Tracker,   Tracker,   Tracker,
     Tracker,   Tracker,   Tracker,   Tracker,   Tracker,
     Tracker,   Tracker,   Tracker,   Tracker,   Tracker,
     Tracker,   Tracker,   Tracker,   Tracker,   Tracker,
          HF,        HF,   Tracker,   Tracker,   Tracker,
          HF,        HF,   Tracker,   Tracker,   Tracker,
          HF,        HF,   Tracker,   Tracker,   Tracker,
          HF,        HF,   Tracker,   Tracker,   Tracker,
          HF,        HF,   Tracker,   Tracker,   Tracker,
          HF,        HF,   Tracker,   Tracker,   Tracker
   
  };

  const int  EPOrder[]  = {
             1,           1,           1,           1,           1,
             1,           1,           1,           1,           1,
             1,           1,           1,           1,           1,
             1,           1,           1,           1,           1,
             2,           2,           2,           2,           2,
             3,           3,           3,           3,           3,
             4,           4,           4,           4,           4,
             5,           5,           5,           5,           5,
             6,           6,           6,           6,           6,
             7,           7,           7,           7,           7
   
  };

  const double  EPEtaMin1[]  = {
         -5.00,        3.00,       -0.80,       -0.50,        0.00,
         -0.50,        0.00,       -0.80,       -2.40,       -2.00,
         -1.60,       -1.20,       -0.80,       -0.40,        0.00,
          0.40,        0.80,        1.20,        1.60,        2.00,
         -5.00,        3.00,       -0.80,       -0.50,        0.00,
         -5.00,        3.00,       -0.80,       -0.50,        0.00,
         -5.00,        3.00,       -0.80,       -0.50,        0.00,
         -5.00,        3.00,       -0.80,       -0.50,        0.00,
         -5.00,        3.00,       -0.80,       -0.50,        0.00,
         -5.00,        3.00,       -0.80,       -0.50,        0.00
   
  };

  const double  EPEtaMax1[]  = {
         -3.00,        5.00,        0.80,        0.00,        0.50,
          0.00,        0.50,        0.80,       -2.00,       -1.60,
         -1.20,       -0.80,       -0.40,        0.00,        0.40,
          0.80,        1.20,        1.60,        2.00,        2.40,
         -3.00,        5.00,        0.80,        0.00,        0.50,
         -3.00,        5.00,        0.80,        0.00,        0.50,
         -3.00,        5.00,        0.80,        0.00,        0.50,
         -3.00,        5.00,        0.80,        0.00,        0.50,
         -3.00,        5.00,        0.80,        0.00,        0.50,
         -3.00,        5.00,        0.80,        0.00,        0.50
   
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
          0.00,        0.00,        0.00,        0.00,        0.00
   
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
          0.00,        0.00,        0.00,        0.00,        0.00
   
  };

  const double  minTransverse[]  = {
          0.01,        0.01,        0.30,        0.30,        0.30,
          0.30,        0.30,        0.30,        0.30,        0.30,
          0.30,        0.30,        0.30,        0.30,        0.30,
          0.30,        0.30,        0.30,        0.30,        0.30,
          0.01,        0.01,        0.30,        0.30,        0.30,
          0.01,        0.01,        0.30,        0.30,        0.30,
          0.01,        0.01,        0.30,        0.30,        0.30,
          0.01,        0.01,        0.30,        0.30,        0.30,
          0.01,        0.01,        0.30,        0.30,        0.30,
          0.01,        0.01,        0.30,        0.30,        0.30
   
  };

  const double  maxTransverse[]  = {
         30.00,       30.00,        3.00,        3.00,        3.00,
          3.00,        3.00,        3.00,        3.00,        3.00,
          3.00,        3.00,        3.00,        3.00,        3.00,
          3.00,        3.00,        3.00,        3.00,        3.00,
         30.00,       30.00,        3.00,        3.00,        3.00,
         30.00,       30.00,        3.00,        3.00,        3.00,
         30.00,       30.00,        3.00,        3.00,        3.00,
         30.00,       30.00,        3.00,        3.00,        3.00,
         30.00,       30.00,        3.00,        3.00,        3.00,
         30.00,       30.00,        3.00,        3.00,        3.00
   
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
        "3sub",      "3sub",      "3sub",      "3sub",      "3sub"
   
  };

  const std::string  MomConsWeight[]  = {
          "no",        "no",        "no",        "no",        "no",
         "yes",       "yes",       "yes",       "yes",       "yes",
         "yes",       "yes",       "yes",       "yes",       "yes",
         "yes",       "yes",       "yes",       "yes",       "yes",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no",
          "no",        "no",        "no",        "no",        "no"
   
  };

  const int  RCMate1[]  = {
        HFp1,      HFm1,      HFm1,      HFp1,      HFp1,
  trackm122mc,trackm122mc,trackm122mc, trackp1mc, trackp1mc,
   trackp1mc, trackp1mc,trackp110mc,trackp110mc,trackm110mc,
  trackm110mc, trackm1mc, trackm1mc, trackm1mc, trackm1mc,
        HFp2,      HFm2,      HFm2,      HFp2,      HFp2,
        HFp3,      HFm3,      HFm3,      HFp3,      HFp3,
        HFp4,      HFm4,      HFm4,      HFp4,      HFp4,
        HFp5,      HFm5,      HFm5,      HFp5,      HFp5,
        HFp6,      HFm6,      HFm6,      HFp6,      HFp6,
        HFp7,      HFm7,      HFm7,      HFp7,      HFp7
   
  };

  const int  RCMate2[]  = {
   trackmid1, trackmid1,      HFp1,      HFm1,      HFm1,
  trackp122mc,trackp122mc,trackp122mc,trackp122mc,trackp122mc,
  trackp122mc,trackp122mc,trackp122mc,trackp122mc,trackm122mc,
  trackm122mc,trackm122mc,trackm122mc,trackm122mc,trackm122mc,
   trackmid2, trackmid2,      HFp2,      HFm2,      HFm2,
   trackmid3, trackmid3,      HFp3,      HFm3,      HFm3,
   trackmid4, trackmid4,      HFp4,      HFm4,      HFm4,
   trackmid5, trackmid5,      HFp5,      HFm5,      HFm5,
   trackmid6, trackmid6,      HFp6,      HFm6,      HFm6,
   trackmid7, trackmid7,      HFp7,      HFm7,      HFm7
   
  };

  static const int NumEPNames = 50;
}
#endif
