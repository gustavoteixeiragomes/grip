/*
 * Copyright (c) 2010, Georgia Tech Research Corporation
 * 
 * Humanoid Robotics Lab      Georgia Institute of Technology
 * Director: Mike Stilman     http://www.golems.org
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *     * Redistributions of source code must retain the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials
 *       provided with the distribution.
 *     * Neither the name of the Georgia Tech Research Corporation nor
 *       the names of its contributors may be used to endorse or
 *       promote products derived from this software without specific
 *       prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY GEORGIA TECH RESEARCH CORPORATION ''AS
 * IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL GEORGIA
 * TECH RESEARCH CORPORATION BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef GRIP_GRIPFRAME_H
#define GRIP_GRIPFRAME_H

class GRIPSlider;
class Viewer;
#include <vector>

#include "TreeView.h"
#include <simulation/World.h>

#include <string>
using namespace std;

#define Uses_wxThread
#include "wx/wxprec.h"
#ifndef WX_PRECOMP
	#include "wx/wx.h"
#endif
#include <wx/notebook.h>

typedef struct {
    Eigen::VectorXd state;
    double time;
} GRIPTimeSlice;

/**
 * @class GRIPFrame
 * @brief Main Frame in GRIP
 */
class GRIPFrame : public wxFrame
{
public:
    GRIPFrame(const wxString& title);

    int continueSimulation;
    clock_t timeLastRedraw;
    int renderDuringSimulation;
    clock_t lastFrameTime;
    clock_t simulationTime;
    double filteredRelSimSpeed;

    wxPanel *backPanel;

    GRIPSlider *timeSlider;

    wxSlider *timeTrack;
    wxTextCtrl *timeText;
    wxTextCtrl *timeRelText;

    wxToolBar* filebar;
    wxToolBar* optionbar;
    wxBitmap toolBarBitmaps[13];

    //void OnSize(wxSizeEvent& evt);
    int saveText(wxString scenepath, const char* llfile);
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnLoad(wxCommandEvent& event);
    void OnQuickLoad(wxCommandEvent& event);
    void OnToolOrder(wxCommandEvent& event);
    void OnToolCheckColl(wxCommandEvent& event);
    void OnToolScreenshot(wxCommandEvent& event);
    void OnToolMovie(wxCommandEvent& event);
    void OnViewChange(wxCommandEvent& event);			///< Change the view to front, side or top
    void OnClose(wxCommandEvent& event);

    void OnSimulateStart(wxCommandEvent& event);
    void OnSimulateStop(wxCommandEvent& event);
    void OnSimulateSingle(wxCommandEvent& event);

    void OnRequestUpdateAndRender(wxCommandEvent& event);
    
    void OnPlay(wxCommandEvent& event);

    void OnTimeScroll(wxScrollEvent &evt);
    void OnTimeEnter(wxCommandEvent &evt);

    void OnWhite(wxCommandEvent& event);
    void OnBlack(wxCommandEvent& event);
    void OnMenuRenderDuringSimulation(wxCommandEvent& event);
    void OnVGA(wxCommandEvent& event);
    void OnXGA(wxCommandEvent& event);
    void OnHD(wxCommandEvent& event); 
    void OnCameraReset(wxCommandEvent& event);

    void InitTimer(string title, double period);
    void AddWorld( simulation::World* world );

    vector<GRIPTimeSlice> timeVector;
    double tCurrent;
    double tMax;
    double tIncrement;
    int tPrecision;
    void setTimeValue( double value, bool sendSignal = false );
    void updateTimeValue( double value, bool sendSignal = false );

    void updateAllTabs();
    void UpdateAndRedraw();
    void FireEventRender();

    void DoLoad(string filename, bool savelastload=true);
    void DeleteWorld();

    void onTVChange(wxTreeEvent& event);

    void SimulateFrame(wxCommandEvent& event);

    DECLARE_EVENT_TABLE()
};


enum
{
  MenuSaveScene = wxID_HIGHEST+1,
  MenuSaveRobot,
  MenuLoad,
  MenuQuickLoad,
  MenuClose,
  MenuBgWhite,
  MenuBgBlack,
  MenuRenderXGA,
  MenuRenderVGA,
  MenuRenderHD,
  MenuCameraReset,
  MenuRenderDuringSim,
  MenuSimulateStart,
  MenuSimulateStop,
  MenuSimulateSingle,
  MenuPlay,
  MenuFrontView,
  MenuTopView,
  MenuRightSideView,

  MenuQuit = wxID_EXIT,
  MenuAbout = wxID_ABOUT
};


#endif /** GRIP_GRIPFRAME_H */
