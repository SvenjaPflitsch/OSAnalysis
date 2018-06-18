#ifndef OSOVERLAP_H
#define OSOVERLAP_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <TTree.h>
#include <vector>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>


class OSOverlap 
{
private: 
    
    TFile *InputFile_Active; 
    TFile *InputFile_Passive; 
    TFile *OutputFile; 
    
    TTree *InputTree_Active; 
    TTree *InputTree_Passive; 
 
    
    unsigned Entries_Active; 
    unsigned Entries_Passive; 
    std::vector<unsigned> Counterpart; 
    std::vector<string> Sort_Active;          // 1: On both lists, 2: Only on Active, 3: Sorted out by filter
    std::vector<string> Sort_Passive;         // 1: On both lists, 2: Only on Passive, 3: Sorted out by filter; 
    
    string *Workflow_Active; 
    std::vector<string> *ExitCode1_Active;                     // Entry in the Tree
    std::vector<string> *ExitCode2_Active;                     // Entry in the Tree
    std::vector<string> *Keyword_Active;                        // Entry in the Tree
    std::vector<string> *ActionOS_Active;                       // Entry in the Tree
    std::vector<float> *ThresholdPerc_Active;                  // Entry in the Tree
    std::vector<int> *ThresholdAbs_Active;                     // Entry in the Tree
    std::vector<string> *ExitCode1Extra_Active;                // Entry in the Tree
    std::vector<string> *ActionWTC_Active;                     // Entry in the Tree
    std::vector<string> *ReasonWTC_Active;                     // Entry in the Tree
    
    TBranch *b_Workflow_Active; 
    TBranch *b_ExitCode1_Active;                     // Entry in the Tree
    TBranch *b_ExitCode2_Active;                     // Entry in the Tree
    TBranch *b_Keyword_Active;                        // Entry in the Tree
    TBranch *b_ActionOS_Active;                       // Entry in the Tree
    TBranch *b_ThresholdPerc_Active;                  // Entry in the Tree
    TBranch *b_ThresholdAbs_Active;                     // Entry in the Tree
    TBranch *b_ExitCode1Extra_Active;                // Entry in the Tree
    TBranch *b_ActionWTC_Active;                     // Entry in the Tree
    TBranch *b_ReasonWTC_Active;                     // Entry in the Tree
        
    
    string *Workflow_Passive; 
    std::vector<string> *ExitCode1_Passive;                     // Entry in the Tree
    std::vector<string> *ExitCode2_Passive;                     // Entry in the Tree
    std::vector<string> *Keyword_Passive;                        // Entry in the Tree
    std::vector<string> *ActionOS_Passive;                       // Entry in the Tree
    std::vector<float> *ThresholdPerc_Passive;                  // Entry in the Tree
    std::vector<int> *ThresholdAbs_Passive;                     // Entry in the Tree
    std::vector<string> *ExitCode1Extra_Passive;                // Entry in the Tree
    std::vector<string> *ActionWTC_Passive;                     // Entry in the Tree
    std::vector<string> *ReasonWTC_Passive;                     // Entry in the Tree
    
    TBranch *b_Workflow_Passive; 
    TBranch *b_ExitCode1_Passive;                     // Entry in the Tree
    TBranch *b_ExitCode2_Passive;                     // Entry in the Tree
    TBranch *b_Keyword_Passive;                        // Entry in the Tree
    TBranch *b_ActionOS_Passive;                       // Entry in the Tree
    TBranch *b_ThresholdPerc_Passive;                  // Entry in the Tree
    TBranch *b_ThresholdAbs_Passive;                     // Entry in the Tree
    TBranch *b_ExitCode1Extra_Passive;                // Entry in the Tree
    TBranch *b_ActionWTC_Passive;                     // Entry in the Tree
    TBranch *b_ReasonWTC_Passive;                     // Entry in the Tree
    
    
    // Output stuff: 
    TTree *OutputTree_OnBothActive; 
    TTree *OutputTree_OnBothPassive; 
    TTree *OutputTree_OnlyActive; 
    TTree *OutputTree_OnlyPassive; 
    TTree *OutputTree_SortedOutActive; 
    TTree *OutputTree_SortedOutPassive; 
    
    string Workflow_Sorted; 
    std::vector<string> ExitCode1_Sorted;                     // Entry in the Tree
    std::vector<string> ExitCode2_Sorted;                     // Entry in the Tree
    std::vector<string> Keyword_Sorted;                        // Entry in the Tree
    std::vector<string> ActionOS_Sorted;                       // Entry in the Tree
    std::vector<float> ThresholdPerc_Sorted;                  // Entry in the Tree
    std::vector<int> ThresholdAbs_Sorted;                     // Entry in the Tree
    std::vector<string> ExitCode1Extra_Sorted;                // Entry in the Tree
    std::vector<string> ActionWTC_Sorted;                     // Entry in the Tree
    std::vector<string> ReasonWTC_Sorted;                     // Entry in the Tree
    
    
    
    string FilterName;
    
    
    
    
    
    
    
public:     
    
    // Both in the same Input File
    OSOverlap(string Input, string Active_TreeName, string Passive_TreeName); 
    // In different Input Files
    //OSOverlap(string Active_Input, string Active_TreeName, string Passive_Input, string Passive_TreeName); 
    
    void ApplyExitCodeFilter(bool withExitCode1Extra); 
    void ApplyWorkflowIssueFilter(); 
    
    
    
}; 

#endif

