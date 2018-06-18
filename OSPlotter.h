#ifndef OSPLOTTER_H
#define OSPLOTTER_H



#include <iostream>
#include <fstream>
#include <sstream>
#include <TTree.h>
#include <vector>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TMath.h>
#include <TRandom3.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TFitResult.h>
#include <TF1.h>


class OSPlotter: 
{
private:     
    string Input_FileName; 
    TFile *Input_File; 
    
    //std::vector<string> GlobalXAxisLabels;      
    //std::vector<string> GlobalYAxisLabels; 
    
    
public: 
    
    OSPlotter(); 
    OSPlotter(string FileName);
    
    // Classic 1D Histogramm with X axis sorted by occurrence of the Label(combinations). Not suitable for Thresholds, only strings. 
    void PlotLabelHistogramm(string TreeName, string BranchName, unsigned MinEntries);
    void PlotLabelCombiHistogramm(string TreeName, string BranchName1, string BranchName2, unsigned MinEntries);
    
    // Compare Different 
    void PlotLabelHistogrammComparison(string TreeNameXAxis, string TreeNameComp1, string TreeNameComp2, string BranchName, unsigned MinEntries); 
    void PlotLabelHistogrammComparison(string TreeNameXAxis, string TreeNameComp1, string TreeNameComp2, string TreeNameComp3, string BranchName, unsigned MinEntries);
    
    // Create Stacks of Histogramms e.g. composition of Active or Passive Tree. 
    void PlotLabelHistogrammStack(string TreeNameXAxis, string TreeNameStack1, string TreeNameStack2, string BranchName, unsigned MinEntries); 
    void PlotLabelHistogrammStackNormalized(string TreeNameXAxis, string TreeNameStack1, string TreeNameStack2, string BranchName, unsigned MinEntries); 
    void PlotLabelHistogrammStack(string TreeNameXAxis, string TreeNameStack1, string TreeNameStack2, string TreeNameStack3, string BranchName, unsigned MinEntries); 
    
    
    // 2D Histogramms
    void PlotLabelHistogramm2D(string TreeNameX, string BranchNameX, unsigned MinEntriesX, string TreeNameY, string BranchNameY, unsigned MinEntriesY); 
    void PlotLabelHistogramm2D(string TreeName, string BranchNameX, unsigned MinEntriesX, string BranchNameY, unsigned MinEntriesY); 
    
}; 


#endif





