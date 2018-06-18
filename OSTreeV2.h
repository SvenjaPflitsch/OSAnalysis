#ifndef OSTREEV2_H
#define OSTREEV2_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <TTree.h>
#include <vector>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

//#pragma link C++ class std::vector<std::vector<int> >+; 
//#pragma link C++ class std::vector<std::vector<float> >+; 
//#pragma link C++ class std::vector<std::vector<string> >+;
//#pragma link C++ class vector<vector<int> >+;



class OSTreeV2
{
private: 
    TTree *OS_Analysis_Tree; 
    // Stuff for the es: 
    string line;                            // general tool to read the lists line-by-line
    
    // Workflows
    std::vector<string> Workflows;         // for reading in the lists
    string Workflow;                        // Entry in the Tree
    int    Occurrence;                      // How many times was this reported
    
    // String version (The code is used as a label, not a number. )
    bool hasExitCode1; 
    std::vector<string> ExitCode1_read;    // For reading in the lists
    std::vector<string> ExitCode1;                     // Entry in the Tree
    std::vector<int> ExitCode1_Occurrence;
    
    bool hasExitCode2; 
    std::vector<string> ExitCode2_read;    // For reading in the lists
    std::vector<string> ExitCode2;                     // Entry in the Tree
    std::vector<int> ExitCode2_Occurrence;
    
    bool hasKeyword; 
    std::vector<string> Keyword_read;    // For reading in the lists
    std::vector<string> Keyword;                     // Entry in the Tree
    std::vector<int> Keyword_Occurrence;
    
    bool hasActionOS; 
    std::vector<string> ActionOS_read;    // For reading in the lists
    std::vector<string> ActionOS;                     // Entry in the Tree
    std::vector<int> ActionOS_Occurrence;
    
    bool hasThresholdPerc; 
    std::vector<float> ThresholdPerc_read;    // For reading in the lists
    std::vector<float> ThresholdPerc;                     // Entry in the Tree
    
    bool hasThresholdAbs; 
    std::vector<int> ThresholdAbs_read;    // For reading in the lists
    std::vector<int> ThresholdAbs;                     // Entry in the Tree
    
    bool hasExitCode1Extra; 
    std::vector<string> ExitCode1Extra_read;    // For reading in the lists
    std::vector<string> ExitCode1Extra;                     // Entry in the Tree
    std::vector<int> ExitCode1Extra_Occurrence;
    
    bool hasActionWTC; 
    std::vector<string> ActionWTC_read;    // For reading in the lists
    std::vector<string> ActionWTC;                     // Entry in the Tree
    std::vector<int> ActionWTC_Occurrence;
    
    bool hasReasonWTC; 
    std::vector<string> ReasonWTC_read;    // For reading in the lists
    std::vector<string> ReasonWTC;                     // Entry in the Tree
    std::vector<int> ReasonWTC_Occurrence;
    
    
    
    
public: 
    
    OSTreeV2(); 
    OSTreeV2(std::string TreeName, std::string TreeTitle);
    
    void AddWorkflows(string WorkflowsListName);
    void AddExitCode1(string ExitCode1ListName); 
    void AddExitCode2(string ExitCode2ListName); 
    void AddKeyword(string KeywordListName); 
    void AddActionOS(string ActionListName); 
    void AddThresholdPerc(string ThresholdPercListName);
    void AddThresholdAbs(string ThresholdAbsListName); 
    
    void AddExitCode1Extra(string ExitCode1ExtraName); 
    void AddActionWTC(string ActionListName); 
    void AddResonWTC(string ReasonListName);
    
    
    void InitializeBranches(); 
    void FillTree(); 
    
    
}; 


#endif


















