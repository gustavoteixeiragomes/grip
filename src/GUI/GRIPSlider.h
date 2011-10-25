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

#ifndef GRIP_GRIPSLIDER_H
#define GRIP_GRIPSLIDER_H

#include <wx/wx.h>
#include <string>

using namespace std;

DECLARE_EVENT_TYPE(wxEVT_GRIP_SLIDER_CHANGE, -1)

class GRIPSlider : public wxPanel
{
public:
	GRIPSlider(){}
	GRIPSlider( wxBitmap bmp, double left, double right, int precision, double initialpos,
		    int lineSize, int pageSize,
		    wxWindow *parent, const wxWindowID id = -1, bool vertical = false,
                    const wxPoint& pos = wxDefaultPosition, 
		    const wxSize& size = wxDefaultSize,
                    long style = wxTAB_TRAVERSAL );
	GRIPSlider( const char* name, double left, double right, int precision, double initialpos,
		    int lineSize, int pageSize,
		    wxWindow *parent, const wxWindowID id = -1, bool vertical = false,
                    const wxPoint& pos = wxDefaultPosition, 
		    const wxSize& size = wxDefaultSize,
                    long style = wxTAB_TRAVERSAL);
	virtual ~GRIPSlider(){}

	wxBoxSizer *sizer;

	wxSlider *track;
	wxStaticText *lText;
	wxTextCtrl *rText;
	wxStaticBitmap *bmpButton;

	//string name;
	double pos;
	double leftBound;
	double rightBound;
	double tickfrequency;
	int prec;

	void setRange(double left, double right);
	void setValue(double value, bool sendSignal = true);
	void updateValue(double value, bool sendSignal = true);
	void setPrecision(int precision);

	void OnScroll(wxScrollEvent &evt);
	void OnEnter(wxCommandEvent &evt);


	DECLARE_DYNAMIC_CLASS(GRIPSlider)
	DECLARE_EVENT_TABLE()
};

#endif
