//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jun 30 07:58:53 2015 by ROOT version 5.34/07
// from TTree tbeamTree/AnalysisTree no mask
// found on file: /afs/cern.ch/user/k/kskovpen/workdir/public/tracker/TBNtuples/USC.00000865.0001.A.storageManager.00.0000.root
//////////////////////////////////////////////////////////

#ifndef tBeamBase_h
#define tBeamBase_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TString.h>
#include <TTree.h>

#include <iostream>
#include <utility>
#include <vector>
#include <iomanip>

#include <map>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::cerr;

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class tBeamBase {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   UInt_t          run;
   UInt_t          lumiSection;
   UInt_t          event;
   Long64_t        time;
   Long64_t        unixtime;
   UInt_t          tdcPhase;
   UInt_t          hvSettings;
   UInt_t          dutAngle;
   UInt_t          stubWord;
   UInt_t          vcth;
   UInt_t          offset;
   UInt_t          window;
   UInt_t          cwd;
   UInt_t          tilt;
   Int_t           condData;
   Int_t           glibStatus;
   Int_t           cbc1Status;
   Int_t           cbc2Status;
   map<string,vector<int> > *dut_channel;
   map<string,vector<int> > *dut_row;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_lumiSection;   //!
   TBranch        *b_event;   //!
   TBranch        *b_time;   //!
   TBranch        *b_unixtime;   //!
   TBranch        *b_tdcPhase;   //!
   TBranch        *b_hvSettings;   //!
   TBranch        *b_dutAngle;   //!
   TBranch        *b_stubWord;   //!
   TBranch        *b_vcth;   //!
   TBranch        *b_offset;   //!
   TBranch        *b_window;   //!
   TBranch        *b_cwd;   //!
   TBranch        *b_tilt;   //!
   TBranch        *b_condData;   //!
   TBranch        *b_glibStatus;   //!
   TBranch        *b_cbc1Status;   //!
   TBranch        *b_cbc2Status;   //!
   TBranch        *b_dut_channel;   //!
   TBranch        *b_dut_row;   //!

   //tBeamBase(TTree *tree=0);
   tBeamBase(const TString& inFile);
   virtual ~tBeamBase();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

};

#endif

#ifdef tBeamBase_cxx
tBeamBase::tBeamBase(const TString& inFile) {
  TFile* f = TFile::Open(inFile);
  if (!f || !f->IsOpen()) {
    cerr << "File not found" << std::endl;
    exit(1);
  }
  fChain = dynamic_cast<TTree*>(f->Get("treeMaker/tbeamTree"));
  if(!fChain) {
    cerr << "Tree does not exist in file" << std::endl;
    exit(1);
  }
  
  Init(fChain);
}
/*
tBeamBase::tBeamBase(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("USC.00000865.0001.A.storageManager.00.0000.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("USC.00000865.0001.A.storageManager.00.0000.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("USC.00000865.0001.A.storageManager.00.0000.root:/treeMaker");
      dir->GetObject("tbeamTree",tree);

   }
   Init(tree);
}
*/
tBeamBase::~tBeamBase()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t tBeamBase::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t tBeamBase::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void tBeamBase::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   dut_channel = 0;
   dut_row = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);


   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumiSection", &lumiSection, &b_lumiSection);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("time", &time, &b_time);
   fChain->SetBranchAddress("unixtime", &unixtime, &b_unixtime);
   fChain->SetBranchAddress("tdcPhase", &tdcPhase, &b_tdcPhase);
   fChain->SetBranchAddress("hvSettings", &hvSettings, &b_hvSettings);
   fChain->SetBranchAddress("dutAngle", &dutAngle, &b_dutAngle);
   fChain->SetBranchAddress("stubWord", &stubWord, &b_stubWord);
   fChain->SetBranchAddress("vcth", &vcth, &b_vcth);
   fChain->SetBranchAddress("offset", &offset, &b_offset);
   fChain->SetBranchAddress("window", &window, &b_window);
   fChain->SetBranchAddress("cwd", &cwd, &b_cwd);
   fChain->SetBranchAddress("tilt", &tilt, &b_tilt);
   fChain->SetBranchAddress("condData", &condData, &b_condData);
   fChain->SetBranchAddress("glibStatus", &glibStatus, &b_glibStatus);
   fChain->SetBranchAddress("cbc1Status", &cbc1Status, &b_cbc1Status);
   fChain->SetBranchAddress("cbc2Status", &cbc2Status, &b_cbc2Status);
   fChain->SetBranchAddress("dut_channel", &dut_channel, &b_dut_channel);
   fChain->SetBranchAddress("dut_row", &dut_row, &b_dut_row);
   Notify();
}

Bool_t tBeamBase::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void tBeamBase::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t tBeamBase::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef tBeamBase_cxx
