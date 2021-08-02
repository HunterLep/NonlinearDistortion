/***********************************************
/gen auto by zuitools
***********************************************/
#ifndef __WINDOWACTIVITY_H__
#define __WINDOWACTIVITY_H__


#include "app/Activity.h"
#include "entry/EasyUIContext.h"

#include "uart/ProtocolData.h"
#include "uart/ProtocolParser.h"

#include "utils/Log.h"
#include "control/ZKDigitalClock.h"
#include "control/ZKButton.h"
#include "control/ZKCircleBar.h"
#include "control/ZKDiagram.h"
#include "control/ZKListView.h"
#include "control/ZKPointer.h"
#include "control/ZKQRCode.h"
#include "control/ZKTextView.h"
#include "control/ZKSeekBar.h"
#include "control/ZKEditText.h"
#include "control/ZKVideoView.h"
#include "control/ZKRadioGroup.h"
#include "window/ZKSlideWindow.h"

/*TAG:Macro宏ID*/
#define ID_WINDOW_TextView1    50021
#define ID_WINDOW_Window1    110001
#define ID_WINDOW_Show    20003
#define ID_WINDOW_Clear    20001
#define ID_WINDOW_Diagram1    120001
#define ID_WINDOW_CrossDistortion    22005
#define ID_WINDOW_PhotoShow    50020
#define ID_WINDOW_DebugText18    50019
#define ID_WINDOW_DebugText17    50018
#define ID_WINDOW_DebugText16    50017
#define ID_WINDOW_DebugText15    50016
#define ID_WINDOW_DebugText14    50015
#define ID_WINDOW_DebugText13    50014
#define ID_WINDOW_DebugText12    50013
#define ID_WINDOW_DebugText11    50012
#define ID_WINDOW_DebugText10    50011
#define ID_WINDOW_DebugText9    50010
#define ID_WINDOW_DebugText8    50009
#define ID_WINDOW_DebugText7    50008
#define ID_WINDOW_DebugText6    50007
#define ID_WINDOW_DebugText5    50006
#define ID_WINDOW_DebugText4    50005
#define ID_WINDOW_DebugText3    50004
#define ID_WINDOW_DebugText2    50003
#define ID_WINDOW_BothDistortion    22004
#define ID_WINDOW_LowDistortion    22003
#define ID_WINDOW_HighDistortion    22002
#define ID_WINDOW_NormalSignal    22001
#define ID_WINDOW_RadioGroup1    94001
#define ID_WINDOW_DebugText1    50002
#define ID_WINDOW_DistortionDegree    50001
#define ID_WINDOW_Measure    20002
#define ID_WINDOW_sys_home   101
/*TAG:Macro宏ID END*/

class windowActivity : public Activity, 
                     public ZKSeekBar::ISeekBarChangeListener, 
                     public ZKListView::IItemClickListener,
                     public ZKListView::AbsListAdapter,
                     public ZKSlideWindow::ISlideItemClickListener,
                     public EasyUIContext::ITouchListener,
                     public ZKRadioGroup::ICheckedChangeListener,
                     public ZKEditText::ITextChangeListener,
                     public ZKVideoView::IVideoPlayerMessageListener
{
public:
    windowActivity();
    virtual ~windowActivity();

    /**
     * 注册定时器
     */
	void registerUserTimer(int id, int time);
	/**
	 * 取消定时器
	 */
	void unregisterUserTimer(int id);
	/**
	 * 重置定时器
	 */
	void resetUserTimer(int id, int time);

protected:
    /*TAG:PROTECTED_FUNCTION*/
    virtual const char* getAppName() const;
    virtual void onCreate();
    virtual void onClick(ZKBase *pBase);
    virtual void onResume();
    virtual void onPause();
    virtual void onIntent(const Intent *intentPtr);
    virtual bool onTimer(int id);

    virtual void onProgressChanged(ZKSeekBar *pSeekBar, int progress);

    virtual int getListItemCount(const ZKListView *pListView) const;
    virtual void obtainListItemData(ZKListView *pListView, ZKListView::ZKListItem *pListItem, int index);
    virtual void onItemClick(ZKListView *pListView, int index, int subItemIndex);

    virtual void onSlideItemClick(ZKSlideWindow *pSlideWindow, int index);

    virtual bool onTouchEvent(const MotionEvent &ev);
    virtual void onCheckedChanged(ZKRadioGroup* pRadioGroup, int checkedID);

    virtual void onTextChanged(ZKTextView *pTextView, const string &text);

    void rigesterActivityTimer();

    virtual void onVideoPlayerMessage(ZKVideoView *pVideoView, int msg);
    void videoLoopPlayback(ZKVideoView *pVideoView, int msg, size_t callbackTabIndex);
    void startVideoLoopPlayback();
    void stopVideoLoopPlayback();
    bool parseVideoFileList(const char *pFileListPath, std::vector<string>& mediaFileList);
    int removeCharFromString(string& nString, char c);


private:
    /*TAG:PRIVATE_VARIABLE*/
    int mVideoLoopIndex;
    int mVideoLoopErrorCount;

};

#endif