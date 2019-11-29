/******************************************************************************
 *   Copyright (C) 2019 GSI Helmholtzzentrum für Schwerionenforschung GmbH    *
 *   Copyright (C) 2019 Members of R3B Collaboration                          *
 *                                                                            *
 *             This software is distributed under the terms of the            *
 *                 GNU General Public Licence (GPL) version 3,                *
 *                    copied verbatim in the file "LICENSE".                  *
 *                                                                            *
 * In applying this license GSI does not waive the privileges and immunities  *
 * granted to it by virtue of its status as an Intergovernmental Organization *
 * or submit itself to any jurisdiction.                                      *
 ******************************************************************************/

// ----------------------------------------------------------------------
// -----                                                            -----
// -----                     R3BAmsStripCal2Hit                     -----
// -----             Created 01/06/18  by J.L. Rodriguez-Sanchez    -----
// ----------------------------------------------------------------------

#ifndef R3BAmsStripCal2Hit_H
#define R3BAmsStripCal2Hit_H

#include "FairTask.h"
#include "R3BAmsHitData.h"
#include "R3BAmsStripCal2Hit.h"
#include "R3BAmsStripCalData.h"
#include "TVector3.h"

class TClonesArray;

class R3BAmsStripCal2Hit : public FairTask
{

  public:
    /** Default constructor **/
    R3BAmsStripCal2Hit();

    /** Standard constructor **/
    R3BAmsStripCal2Hit(const TString& name, Int_t iVerbose = 1);

    /** Destructor **/
    virtual ~R3BAmsStripCal2Hit();

    /** Virtual method Exec **/
    virtual void Exec(Option_t* option);

    /** Virtual method Reset **/
    virtual void Reset();

    // Fair specific
    /** Virtual method Init **/
    virtual InitStatus Init();

    /** Virtual method ReInit **/
    virtual InitStatus ReInit();

    /** Virtual method Finish **/
    virtual void Finish();

    virtual void DefineClusters(Int_t* nfound, Double_t fPitch, Double_t* fChannels, TH1F* hsst, Double_t cluster[][2]);

    void SetOnline(Bool_t option) { fOnline = option; }
    void SetMaxNumDet(Int_t NbDet) { fMaxNumDet = NbDet; }
    void SetMaxNumClusters(Int_t max) { fMaxNumClusters = max; }

  private:
    Double_t fPitchK, fPitchS;
    Int_t fMaxNumDet, fMaxNumClusters;
    TH1F* hams[16];

    TClonesArray* fAmsStripCalDataCA; /**< Array with AMS Cal- input data. >*/
    TClonesArray* fAmsHitDataCA;      /**< Array with AMS Hit- output data. >*/

    Bool_t fOnline; // Don't store data for online
    Double_t* fChannelPeaks;

    /** Private method AddHitData **/
    //** Adds a AmsHitData to the HitCollection
    R3BAmsHitData* AddHitData(Int_t detid,
                              Int_t numhit,
                              Double_t x,
                              Double_t y,
                              TVector3 master,
                              Double_t energy_x,
                              Double_t energy_y);

  public:
    // Class definition
    ClassDef(R3BAmsStripCal2Hit, 1)
};

#endif
