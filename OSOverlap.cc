#include <OSOverlap.h>

OSOverlap::OSOverlap(string Input, string Active_TreeName, string Passive_TreeName, string OutputName){
    
    
    InputFile_Active = TFile::Open(Input.c_str(), "UPDATE");
    InputFile_Active->ls(); 
    
    
    
    
    InputTree_Active = (TTree*)InputFile_Active->Get(Active_TreeName.c_str()); 
    InputTree_Active->SetBranchAddress("Workflows", &Workflow_Active, &b_Workflow_Active); 
    InputTree_Active->SetBranchAddress("ExitCode1", &ExitCode1_Active, &b_ExitCode1_Active);
    InputTree_Active->SetBranchAddress("ExitCode2", &ExitCode2_Active, &b_ExitCode2_Active);
    InputTree_Active->SetBranchAddress("Keyword", &Keyword_Active, &b_Keyword_Active);
    InputTree_Active->SetBranchAddress("ActionOS", &ActionOS_Active, &b_ActionOS_Active);
    //InputTree_Active->SetBranchAddress("ExitCode1Extra", &ExitCode1Extra_Active, &b_ExitCode1Extra_Active); 
    InputTree_Active->SetBranchAddress("ThresholdPerc", &ThresholdPerc_Active, &b_ThresholdPerc_Active);
    InputTree_Active->SetBranchAddress("ThresholdAbs", &ThresholdAbs_Active, &b_ThresholdAbs_Active);
    //InputTree_Active->SetBranchAddress("ActionWTC", &ActionWTC_Active, &b_ActionWTC_Active);
    //InputTree_Active->SetBranchAddress("ReasonWTC", &ReasonWTC_Active, &b_ReasonWTC_Active);
    
    cout<<"Active List Entries: "<<InputTree_Active->GetEntries()<<endl; 
    InputTree_Active->GetEntry(0); 
    cout<<"FirstEntry: "<<*Workflow_Active<<endl; 
    
   
    
    InputTree_Passive = (TTree*)InputFile_Active->Get(Passive_TreeName.c_str()); 
    InputTree_Passive->SetBranchAddress("Workflows", &Workflow_Passive, &b_Workflow_Passive); 
    InputTree_Passive->SetBranchAddress("ExitCode1", &ExitCode1_Passive, &b_ExitCode1_Passive);
    InputTree_Passive->SetBranchAddress("ExitCode2", &ExitCode2_Passive, &b_ExitCode2_Passive);
    InputTree_Passive->SetBranchAddress("Keyword", &Keyword_Passive, &b_Keyword_Passive);
    InputTree_Passive->SetBranchAddress("ActionOS", &ActionOS_Passive, &b_ActionOS_Passive);
    InputTree_Passive->SetBranchAddress("ThresholdPerc", &ThresholdPerc_Passive, &b_ThresholdPerc_Passive);
    InputTree_Passive->SetBranchAddress("ThresholdAbs", &ThresholdAbs_Passive, &b_ThresholdAbs_Passive);
    InputTree_Passive->SetBranchAddress("ExitCode1Extra", &ExitCode1Extra_Passive, &b_ExitCode1Extra_Passive); 
    InputTree_Passive->SetBranchAddress("ActionWTC", &ActionWTC_Passive, &b_ActionWTC_Passive);
    InputTree_Passive->SetBranchAddress("ReasonWTC", &ReasonWTC_Passive, &b_ReasonWTC_Passive);
    
    cout<<"Passive List Entries: "<<InputTree_Passive->GetEntries()<<endl; 
    InputTree_Passive->GetEntry(0); 
    cout<<"FirstEntry: "<<*Workflow_Passive<<endl; 
    
    
    OutputFile = new TFile(OutputName.c_str(), "RECREATE"); 
    TTree *HelperTree_Active = InputTree_Active->CloneTree(); 
    HelperTree_Active->Write(); 
    
    TTree *HelperTree_Passive = InputTree_Passive->CloneTree(); 
    HelperTree_Passive->Write(); 
    
    
    
    // Initialization of Output: 
    OutputTree_OnBothActive = new TTree("TreeOnBothActive", "Workflows on both Lists"); 
    OutputTree_OnBothActive->Branch("Workflows", &Workflow_Sorted);
    OutputTree_OnBothActive->Branch("ExitCode1", &ExitCode1_Sorted);
    OutputTree_OnBothActive->Branch("ExitCode2", &ExitCode2_Sorted);
    OutputTree_OnBothActive->Branch("Keyword", &Keyword_Sorted);
    OutputTree_OnBothActive->Branch("ActionOS", &ActionOS_Sorted);
    OutputTree_OnBothActive->Branch("ThresholdPerc", &ThresholdPerc_Sorted);    
    OutputTree_OnBothActive->Branch("ThresholdAbs", &ThresholdAbs_Sorted);
    OutputTree_OnBothActive->Branch("ExitCode1Extra", &ExitCode1Extra_Sorted); 
    OutputTree_OnBothActive->Branch("ActionWTC", &ActionWTC_Sorted);
    OutputTree_OnBothActive->Branch("ReasonWTC", &ReasonWTC_Sorted);
    
    OutputTree_OnBothPassive = new TTree("TreeOnBothPassive", "Workflows on both Lists"); 
    OutputTree_OnBothPassive->Branch("Workflows", &Workflow_Sorted);
    OutputTree_OnBothPassive->Branch("ExitCode1", &ExitCode1_Sorted);
    OutputTree_OnBothPassive->Branch("ExitCode2", &ExitCode2_Sorted);
    OutputTree_OnBothPassive->Branch("Keyword", &Keyword_Sorted);
    OutputTree_OnBothPassive->Branch("ActionOS", &ActionOS_Sorted);
    OutputTree_OnBothPassive->Branch("ThresholdPerc", &ThresholdPerc_Sorted);    
    OutputTree_OnBothPassive->Branch("ThresholdAbs", &ThresholdAbs_Sorted);
    OutputTree_OnBothPassive->Branch("ExitCode1Extra", &ExitCode1Extra_Sorted); 
    OutputTree_OnBothPassive->Branch("ActionWTC", &ActionWTC_Sorted);
    OutputTree_OnBothPassive->Branch("ReasonWTC", &ReasonWTC_Sorted);
    
    OutputTree_OnlyActive = new TTree("TreeOnlyActive", "Workflows that only show up on Active List");
    OutputTree_OnlyActive->Branch("Workflows", &Workflow_Sorted);
    OutputTree_OnlyActive->Branch("ExitCode1", &ExitCode1_Sorted);
    OutputTree_OnlyActive->Branch("ExitCode2", &ExitCode2_Sorted);
    OutputTree_OnlyActive->Branch("Keyword", &Keyword_Sorted);
    OutputTree_OnlyActive->Branch("ActionOS", &ActionOS_Sorted);
    OutputTree_OnlyActive->Branch("ThresholdPerc", &ThresholdPerc_Sorted);    
    OutputTree_OnlyActive->Branch("ThresholdAbs", &ThresholdAbs_Sorted);
    OutputTree_OnlyActive->Branch("ExitCode1Extra", &ExitCode1Extra_Sorted); 
    OutputTree_OnlyActive->Branch("ActionWTC", &ActionWTC_Sorted);
    OutputTree_OnlyActive->Branch("ReasonWTC", &ReasonWTC_Sorted);
    
    OutputTree_OnlyPassive = new TTree("TreeOnlyPassive", "Workflows that only show up on the Passive List"); 
    OutputTree_OnlyPassive->Branch("Workflows", &Workflow_Sorted);
    OutputTree_OnlyPassive->Branch("ExitCode1", &ExitCode1_Sorted);
    OutputTree_OnlyPassive->Branch("ExitCode2", &ExitCode2_Sorted);
    OutputTree_OnlyPassive->Branch("Keyword", &Keyword_Sorted);
    OutputTree_OnlyPassive->Branch("ActionOS", &ActionOS_Sorted);
    OutputTree_OnlyPassive->Branch("ThresholdPerc", &ThresholdPerc_Sorted);    
    OutputTree_OnlyPassive->Branch("ThresholdAbs", &ThresholdAbs_Sorted);
    OutputTree_OnlyPassive->Branch("ExitCode1Extra", &ExitCode1Extra_Sorted); 
    OutputTree_OnlyPassive->Branch("ActionWTC", &ActionWTC_Sorted);
    OutputTree_OnlyPassive->Branch("ReasonWTC", &ReasonWTC_Sorted);
    
    
    OutputTree_SortedOutActive = new TTree("TreeSortedOutActive", "Workflows that are sorted out by the Filters"); 
    OutputTree_SortedOutActive->Branch("Workflows", &Workflow_Sorted);
    OutputTree_SortedOutActive->Branch("ExitCode1", &ExitCode1_Sorted);
    OutputTree_SortedOutActive->Branch("ExitCode2", &ExitCode2_Sorted);
    OutputTree_SortedOutActive->Branch("Keyword", &Keyword_Sorted);
    OutputTree_SortedOutActive->Branch("ActionOS", &ActionOS_Sorted);
    OutputTree_SortedOutActive->Branch("ThresholdPerc", &ThresholdPerc_Sorted);    
    OutputTree_SortedOutActive->Branch("ThresholdAbs", &ThresholdAbs_Sorted);
    OutputTree_SortedOutActive->Branch("ExitCode1Extra", &ExitCode1Extra_Sorted); 
    OutputTree_SortedOutActive->Branch("ActionWTC", &ActionWTC_Sorted);
    OutputTree_SortedOutActive->Branch("ReasonWTC", &ReasonWTC_Sorted);
    
    OutputTree_SortedOutPassive = new TTree("TreeSortedOutPassive", "Workflows that are sorted out by the Filters"); 
    OutputTree_SortedOutPassive->Branch("Workflows", &Workflow_Sorted);
    OutputTree_SortedOutPassive->Branch("ExitCode1", &ExitCode1_Sorted);
    OutputTree_SortedOutPassive->Branch("ExitCode2", &ExitCode2_Sorted);
    OutputTree_SortedOutPassive->Branch("Keyword", &Keyword_Sorted);
    OutputTree_SortedOutPassive->Branch("ActionOS", &ActionOS_Sorted);
    OutputTree_SortedOutPassive->Branch("ThresholdPerc", &ThresholdPerc_Sorted);    
    OutputTree_SortedOutPassive->Branch("ThresholdAbs", &ThresholdAbs_Sorted);
    OutputTree_SortedOutPassive->Branch("ExitCode1Extra", &ExitCode1Extra_Sorted); 
    OutputTree_SortedOutPassive->Branch("ActionWTC", &ActionWTC_Sorted);
    OutputTree_SortedOutPassive->Branch("ReasonWTC", &ReasonWTC_Sorted);
    
    
    
    // Start the pre-filter: 
    FilterName = ""; 
    Entries_Active = InputTree_Active->GetEntries(); 
    Entries_Passive = InputTree_Passive->GetEntries(); 
    
    bool hasCounterpart; 
    
    // Loop through the Active tree and look for a counterpart on the passive list. 
    cout<<"Looping through active list. "<<endl; 
    for(int i0(0); i0 < Entries_Active; i0++){
        InputTree_Active->GetEntry(i0); 
        
        hasCounterpart = false; 
        for(int i1(0); i1 < Entries_Passive; i1++){
            InputTree_Passive->GetEntry(i1);
            if(*Workflow_Active == *Workflow_Passive){
                Counterpart.push_back(i1);  // Only for Active list. 
                Sort_Active.push_back("OnBoth");
                hasCounterpart = true; 
            }
        }
        if(!hasCounterpart){
            Sort_Active.push_back("OnlyOnActive"); 
            Counterpart.push_back(-1);  // Only for Active list. 
        }
    }
    
    // Similar treatment for the passive list
    cout<<"Looping through passive list. "<<endl; 
    for(int i0(0); i0 < Entries_Passive; i0++){
        InputTree_Passive->GetEntry(i0); 
        
        hasCounterpart = false; 
        for(int i1(0); i1 < Entries_Active; i1++){
            InputTree_Active->GetEntry(i1);
            if(*Workflow_Passive == *Workflow_Active){
                Sort_Passive.push_back("OnBoth");
                hasCounterpart = true; 
                break; 
            }
        }
        if(!hasCounterpart) Sort_Passive.push_back("OnlyOnPassive"); 
    } 
    
    
}


OSOverlap::FillOutputTrees(){
    
    if(FilterName == "") FilterName = "_noFilter"; 
    
    OutputTree_OnBothActive->SetName(Form("TreeOnBothActive%s", FilterName.c_str())); 
    OutputTree_OnBothPassive->SetName(Form("TreeOnBothPassive%s", FilterName.c_str())); 
    OutputTree_OnlyActive->SetName(Form("TreeOnlyActive%s", FilterName.c_str())); 
    OutputTree_OnlyPassive->SetName(Form("TreeOnlyPassive%s", FilterName.c_str()));
    OutputTree_SortedOutActive->SetName(Form("TreeSortedOutActive%s", FilterName.c_str())); 
    OutputTree_SortedOutPassive->SetName(Form("TreeSortedOutPassive%s", FilterName.c_str())); 
    
    for(int i0(0); i0 < Entries_Active; i0++){
        
        InputTree_Active->GetEntry(i0);
        Workflow_Sorted = *Workflow_Active; 
        ExitCode1_Sorted = *ExitCode1_Active; 
        ExitCode2_Sorted = *ExitCode2_Active; 
        Keyword_Sorted = *Keyword_Active; 
        ActionOS_Sorted = *ActionOS_Active;
        ThresholdPerc_Sorted = *ThresholdPerc_Active; 
        ThresholdAbs_Sorted = *ThresholdAbs_Active;
        //ExitCode1Extra_Sorted = *ExitCode1Extra_Active; 
        //ActionWTC_Sorted = *ActionWTC_Active; 
        //ReasonWTC_Sorted = *ActionWTC_Active; 
        
        
        
        if(Sort_Active[i0] == "OnBoth")             OutputTree_OnBothActive->Fill(); 
        else if(Sort_Active[i0] == "OnlyOnActive")  OutputTree_OnlyActive->Fill(); 
        else if(Sort_Active[i0] == "SortedOut")     OutputTree_SortedOutActive->Fill(); 
        
        
        ExitCode1_Sorted.clear(); 
        ExitCode2_Sorted.clear(); 
        Keyword_Sorted.clear(); 
        ActionOS_Sorted.clear();
        ThresholdPerc_Sorted.clear(); 
        ThresholdAbs_Sorted.clear();
        ExitCode1Extra_Sorted.clear(); 
        ActionWTC_Sorted.clear(); 
        ReasonWTC_Sorted.clear(); 
        
    }
    
    //Same procedure for the passive tree: 
    for(int i0(0); i0 < Entries_Passive; i0++){
        
        InputTree_Passive->GetEntry(i0);
        Workflow_Sorted = *Workflow_Passive; 
        ExitCode1_Sorted = *ExitCode1_Passive; 
        ExitCode2_Sorted = *ExitCode2_Passive; 
        Keyword_Sorted = *Keyword_Passive; 
        ActionOS_Sorted = *ActionOS_Passive;
        ThresholdPerc_Sorted = *ThresholdPerc_Passive; 
        ThresholdAbs_Sorted = *ThresholdAbs_Passive;
        ExitCode1Extra_Sorted = *ExitCode1Extra_Passive; 
        ActionWTC_Sorted = *ActionWTC_Passive; 
        ReasonWTC_Sorted = *ActionWTC_Passive; 
        
        
        if(Sort_Passive[i0] == "OnBoth")            OutputTree_OnBothPassive->Fill(); 
        if(Sort_Passive[i0] == "OnlyOnPassive")     OutputTree_OnlyPassive->Fill(); 
        else if(Sort_Passive[i0] == "SortedOut")    OutputTree_SortedOutPassive->Fill(); 
        
        
        ExitCode1_Sorted.clear(); 
        ExitCode2_Sorted.clear(); 
        Keyword_Sorted.clear(); 
        ActionOS_Sorted.clear();
        ThresholdPerc_Sorted.clear(); 
        ThresholdAbs_Sorted.clear();
        ExitCode1Extra_Sorted.clear(); 
        ActionWTC_Sorted.clear(); 
        ReasonWTC_Sorted.clear(); 
        
    }
    
    
    
    cout<<"OnBothActive: "<<OutputTree_OnBothActive->GetEntries()<<endl; 
    cout<<"OnBothPassive: "<<OutputTree_OnBothPassive->GetEntries()<<endl; 
    cout<<"OnlyActive: "<<OutputTree_OnlyActive->GetEntries()<<endl; 
    cout<<"TreeOnlyPassive: "<<OutputTree_OnlyPassive->GetEntries()<<endl; 
    cout<<"SortedOutActive: "<<OutputTree_SortedOutActive->GetEntries()<<endl; 
    cout<<"SortedOutPassive: "<<OutputTree_SortedOutPassive->GetEntries()<<endl; 
    
    
    OutputTree_OnBothActive->Write(); 
    OutputTree_OnBothPassive->Write(); 
    OutputTree_OnlyActive->Write(); 
    OutputTree_OnlyPassive->Write();
    if(OutputTree_SortedOutActive->GetEntries() > 0)
        OutputTree_SortedOutActive->Write(); 
    if(OutputTree_SortedOutPassive->GetEntries() > 0)
        OutputTree_SortedOutPassive->Write(); 
    
    //
    //
    InputFile_Active->Close(); 
    OutputFile->Close();
}


void OSOverlap::ApplyExitCodeFilter(bool withExitCode1Extra){
    bool sameExitCode; 
    
    for(int i0(0); i0 < Entries_Active; i0++){
        if(Sort_Active[i0] != "OnBoth") continue; 
            
        InputTree_Active->GetEntry(i0); 
        InputTree_Passive->GetEntry(Counterpart[i0]);
        
        sameExitCode = false; 
        for(int i1(0); i1 < ExitCode1_Active->size(); i1++){
            for(int i2(0); i2 < ExitCode1_Passive->size(); i2++){
                if(ExitCode1_Active->at(i1) == ExitCode1_Passive->at(i2)){ 
                    sameExitCode = true;
                    //cout<<ExitCode1_Active->at(i1)<<", "<<ExitCode1_Passive->at(i2)<<endl; 
                    break; 
                }
            }
            if(sameExitCode) break; 
            
            if(withExitCode1Extra){
                for(int i2(0); i2 < ExitCode1Extra_Passive->size(); i2++){
                    if(ExitCode1_Active->at(i1) == ExitCode1Extra_Passive->at(i2)){ 
                        sameExitCode = true;
                        //cout<<ExitCode1_Active->at(i1)<<", "<<ExitCode1Extra_Passive->at(i2)<<endl; 
                        break; 
                    }
                }
            }
        }
       
        if(!sameExitCode){
            Sort_Active[i0] = "SortedOut"; 
            Sort_Passive[Counterpart[i0]] = "SortedOut";
        }
        
    }
    
    
}


void OSOverlap::ApplyWorkflowIssueFilter(){
    bool isWorkflowIssue;
    FilterName += "_WorkflowIssueFilter";
    for(int i0(0); i0 < Entries_Active; i0++){
    
        InputTree_Active->GetEntry(i0); 
        isWorkflowIssue = false; 
        for(int i1(0); i1 < ActionOS_Active->size(); i1++){
            if(ActionOS_Active->at(i1) == "hold workflow")  isWorkflowIssue = true; 
        }
        if(!isWorkflowIssue) Sort_Active[i0] = "SortedOut";
    }
    
}


void OSOverlap::ApplySiteIssueFilter(){
    bool isSiteIssue; 
    FilterName += "_SiteIssueFilter";
    for(int i0(0); i0 < Entries_Active; i0++){
    
        InputTree_Active->GetEntry(i0); 
        isSiteIssue = false; 
        for(int i1(0); i1 < ActionOS_Active->size(); i1++){
            if(ActionOS_Active->at(i1) == "hold site")  isSiteIssue = true; 
        }
        
        if(!isSiteIssue) Sort_Active[i0] = "SortedOut";
    }
    
}


void OSOverlap::FilterMultipleEntries(){
    //Currently under development
    
    for(int i0(0); i0 < Entries_Active; i0++){
        
    }
}




















