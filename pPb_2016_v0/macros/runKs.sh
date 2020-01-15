#!/bin/bash
nohup root -l -b -q 'vnpt.C+("filelist_Pbp_Ks.dat","Pbp120_150.root")' > logs/Pbp120_150.log &
nohup root -l -b -q 'vnpt.C+("filelist_pPb_Ks.dat","pPb120_150.root")' > logs/pPb120_150.log &
