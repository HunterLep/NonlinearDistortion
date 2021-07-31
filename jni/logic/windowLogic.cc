#pragma once
#include "uart/ProtocolSender.h"
#include "cstdio"
#include "../include/control/ZKRadioGroup.h"
#include "../include/control/ZKDiagram.h"
#include "../include/control/ZKTextView.h"
#include "Rewrite.h"
/*
*此文件由GUI工具生成
*文件功能：用于处理用户的逻辑相应代码
*功能说明：
*========================onButtonClick_XXXX
当页面中的按键按下后系统会调用对应的函数，XXX代表GUI工具里面的[ID值]名称，
如Button1,当返回值为false的时候系统将不再处理这个按键，返回true的时候系统将会继续处理此按键。比如SYS_BACK.
*========================onSlideWindowItemClick_XXXX(int index) 
当页面中存在滑动窗口并且用户点击了滑动窗口的图标后系统会调用此函数,XXX代表GUI工具里面的[ID值]名称，
如slideWindow1;index 代表按下图标的偏移值
*========================onSeekBarChange_XXXX(int progress) 
当页面中存在滑动条并且用户改变了进度后系统会调用此函数,XXX代表GUI工具里面的[ID值]名称，
如SeekBar1;progress 代表当前的进度值
*========================ogetListItemCount_XXXX() 
当页面中存在滑动列表的时候，更新的时候系统会调用此接口获取列表的总数目,XXX代表GUI工具里面的[ID值]名称，
如List1;返回值为当前列表的总条数
*========================oobtainListItemData_XXXX(ZKListView::ZKListItem *pListItem, int index)
 当页面中存在滑动列表的时候，更新的时候系统会调用此接口获取列表当前条目下的内容信息,XXX代表GUI工具里面的[ID值]名称，
如List1;pListItem 是贴图中的单条目对象，index是列表总目的偏移量。具体见函数说明
*========================常用接口===============
*LOGD(...)  打印调试信息的接口
*mTextXXXPtr->setText("****") 在控件TextXXX上显示文字****
*mButton1Ptr->setSelected(true); 将控件mButton1设置为选中模式，图片会切换成选中图片，按钮文字会切换为选中后的颜色
*mSeekBarPtr->setProgress(12) 在控件mSeekBar上将进度调整到12
*mListView1Ptr->refreshListView() 让mListView1 重新刷新，当列表数据变化后调用
*mDashbroadView1Ptr->setTargetAngle(120) 在控件mDashbroadView1上指针显示角度调整到120度
*
* 在Eclipse编辑器中  使用 “alt + /”  快捷键可以打开智能提示
*/
static double data[]={
		0.841471,0.891207,0.932039,0.963558,0.985450,0.997495,0.999574,0.991665,0.973848,0.946300,0.909297,0.863209,0.808496,
		0.745705,0.675463,0.598472,0.515501,0.427380,0.334988,0.239249,0.141120,0.041581,-0.058374,-0.157746,-0.255541,-0.350783,
		-0.442520,-0.529836,-0.611858,-0.687766,-0.756802,-0.818277,-0.871576,-0.916166,-0.951602,-0.977530,-0.993691,-0.999923,
		-0.996165,-0.982453,-0.958924,-0.925815,-0.883455,-0.832267,-0.772764,-0.705540,-0.631267,-0.550686,-0.464602,-0.373877,
		-0.279415,-0.182163,-0.083089,0.016814,0.116549,0.215120,0.311541,0.404850,0.494113,0.578440,0.656987,0.728969,0.793668,
		0.850437,0.898708,0.938000,0.967920,0.988168,0.998543,0.998941,0.989358,0.969890,0.940731,0.902172,0.854599,0.798487,
		0.734397,0.662969,0.584917,0.501021,0.412118,0.319098,0.222890,0.124454,0.024775,-0.075151,-0.174327,-0.271761,-0.366479,
		-0.457536,-0.544021,-0.625071,-0.699875,-0.767686,-0.827826,-0.879696,-0.922775,-0.956635,-0.980936,-0.995436,-0.999990,
		-0.994553,-0.979178,-0.954019,-0.919329,-0.875452,-0.822829,-0.761984,-0.693525,-0.618137,-0.536573,-0.449647,-0.358229,
		-0.263232,-0.165604,-0.066322,0.033623,0.133232,0.231510,0.327474,0.420167,0.508661,0.592074,0.669570,0.740376,0.803784,
		0.859162,0.905955,0.943696,0.972008,0.990607,0.999309,0.998027,0.986772,0.965658,0.934895,0.894791,0.845747,0.788252,
		0.722881,0.650288,0.571197,0.486399,0.396741,0.303118,0.206467,0.107754,0.007963,-0.091907,-0.190859,-0.287903,-0.382071,
		-0.472422,-0.558052,-0.638107,-0.711785,-0.778352,-0.837142,-0.887567,-0.929124,-0.961397,-0.984065,-0.996900,-0.999774,
		-0.992659,-0.975626,-0.948844,-0.912582,-0.867202,-0.813157,-0.750987,-0.681314,-0.604833,-0.522309,-0.434566,-0.342481,
		-0.246974,-0.148999,-0.049536,0.050423,0.149877,0.247834,0.343315,0.435365,0.523066,0.605540,0.681964,0.751573,0.813674,
		0.867644,0.912945,0.949125,0.975821,0.992766,0.999793,0.996830,0.983907,0.961153,0.928795,0.887158,0.836656,0.777794,
		0.711161,0.637423,0.557315,0.471639,0.381250,0.287053,0.189987,0.091022,-0.008851,-0.108637,-0.207336,-0.303965,-0.397556,
		-0.487175,-0.571926,-0.650962,-0.723495,-0.788798,-0.846220,-0.895187,-0.935210,-0.965888,-0.986916,-0.998082,-0.999276,
		-0.990486,-0.971798,-0.943401,-0.905578,-0.858707,-0.803256,-0.739779,-0.668910,-0.591358,-0.507897,-0.419361,-0.326635,
		-0.230646,-0.132352,-0.032735,0.067208,0.166480,0.264089,0.359058,0.450441,0.537322,0.618835,0.694165,0.762558,0.823333,
		0.875881,0.919678,0.954285,0.979358,0.994645,0.999994,0.995351,0.980763,0.956376,0.922433,0.879273,0.827328,0.767116,0.699240,
		0.624377,0.543276,0.456746,0.365653,0.270906,0.173452,0.074265,-0.025663,-0.125336,-0.223756,-0.319940,-0.412928,
		-0.501789,-0.585637,-0.663634,-0.735000,-0.799021,-0.855060,-0.902555,-0.941031,-0.970106,-0.989487,-0.998982,-0.998495,
		-0.988032,-0.967696,-0.937692,-0.898318,-0.849969,-0.793127,-0.728361,-0.656317,-0.577715,-0.493341,-0.404038,-0.310697,
		-0.214253,-0.115667,-0.015926,0.083974,0.183036,0.280268,0.374700,0.465388,0.551427,0.631955,0.706169,0.773328,0.832759,
		0.883870,0.926150,0.959176,0.982618,0.996242,0.999912,0.993591,0.977343,0.951329,0.915810,0.871140,0.817766,0.756222,
		0.687121,0.611155,0.529083,0.441724,0.349951,0.254682,0.156869,0.057487,-0.042468,-0.141999,-0.240112,-0.335825,-0.428183,
		-0.516262,-0.599183,-0.676118,-0.746297,-0.809019,-0.863657,-0.909667,-0.946587,-0.974049,-0.991779,-0.999599,-0.997432,
		-0.985298,-0.963320,-0.931717,-0.890804,-0.840991,-0.782775,-0.716737,-0.643538,-0.563909,-0.478646,-0.388600,-0.294672,
		-0.197799,-0.098950,0.000888,0.100717,0.199540,0.296369,0.390236,0.480205,0.565375,0.644897,0.717975,0.783879,0.841951,
		0.891610,0.932361,0.963795,0.985600,0.997557,0.999547,0.991550,0.973645,0.946013,0.908927,0.862761,0.807973,0.745113,
		0.674808,0.597760,0.514740,0.426577,0.334151,0.238387,0.140241,0.040693,-0.059261,-0.158623,-0.256400,-0.351615,-0.443317,-0.530589,
		-0.612560,-0.688411,-0.757383,-0.818787,-0.872011,-0.916522,-0.951875,-0.977717,-0.993790,-0.999934,-0.996087,-0.982287,
		-0.958672,-0.925479,-0.883038,-0.831775,-0.772200,-0.704911,-0.630578,-0.549944,-0.463816,-0.373053,-0.278563,-0.181289,
		-0.082204,0.017702,0.117431,0.215987,0.312385,0.405662,0.494885,0.579164,0.657656,0.729577,0.794208,0.850904,0.899097,
		0.938307,0.968142,0.988304,0.998591,0.998900,0.989229,0.969673,0.940429,0.901788,0.854137,0.797952,0.733794,0.662304,
		0.584197,0.500252,0.411309,0.318257,0.222024,0.123573,0.023888,-0.076037,-0.175201,-0.272615,-0.367305,-0.458325,-0.544766,
		-0.625764,-0.700509,-0.768255,-0.828324,-0.880118,-0.923117,-0.956893,-0.981108,-0.995521,-0.999986,-0.994460,-0.978997,
		-0.953753,-0.918979,-0.875023,-0.822324,-0.761408,-0.692885,-0.617439,-0.535823,-0.448854,-0.357400
};

static const BYTE NormalSignal[2]={CMDID_NormalSignal,0x00};
static const BYTE HighDistortion[2]={CMDID_HighDistortion,0x00};
static const BYTE LowDistortion[2]={CMDID_LowDistortion,0X00};
static const BYTE BothDistortion[2]={CMDID_BothDistortion,0X00};
static const BYTE CrossDistortion[2]={CMDID_CrossDistortion,0x00};

int ID;
static bool sIsRefreshing = false;

static void Changebackground(int checkedID){
	char path[50]={0};
	switch(checkedID){
		case ID_WINDOW_NormalSignal:
			sprintf(path,"NormalSignal.jpg");
			mPhotoShowPtr->setBackgroundPic(path);
			break;
		case ID_WINDOW_HighDistortion:
			sprintf(path,"HighDistortion.jpg");
			mPhotoShowPtr->setBackgroundPic(path);
			break;
		case ID_WINDOW_LowDistortion:
			sprintf(path,"LowDistortion.jpg");
			mPhotoShowPtr->setBackgroundPic(path);
			break;
		case ID_WINDOW_BothDistortion:
			sprintf(path,"BothDistortion.jpg");
			mPhotoShowPtr->setBackgroundPic(path);
			break;
		case ID_WINDOW_CrossDistortion:
			sprintf(path,"CrossDistortion.jpg");
			mPhotoShowPtr->setBackgroundPic(path);
	}
}

/**
 * 注册定时器
 * 填充数组用于注册定时器
 * 注意：id不能重复
 */
static S_ACTIVITY_TIMEER REGISTER_ACTIVITY_TIMER_TAB[] = {
	//{0,  6000}, //定时器id=0, 时间间隔6秒
	//{1,  1000},
};

/**
 * 当界面构造时触发
 */

static void onUI_init(){
    //Tips :添加 UI初始化的显示代码到这里,如:mText1Ptr->setText("123");
	for (int i = 0; i < DIAGRAM_SIZE; i++) {
				sPoints[i].x = (100 * i) / DIAGRAM_SIZE;
				sPoints[i].y = 5;
			}
		mDiagram1Ptr->setData(0, sPoints, DIAGRAM_SIZE);
}

/**
 * 当切换到该界面时触发
 */
static void onUI_intent(const Intent *intentPtr) {
    if (intentPtr != NULL) {
        //TODO
    }
}

/*
 * 当界面显示时触发
 */
static void onUI_show() {

}

/*
 * 当界面隐藏时触发
 */
static void onUI_hide() {

}

/*
 * 当界面完全退出时触发
 */
static void onUI_quit() {

}

/**
 * 串口数据回调接口
 */
static void onProtocolDataUpdate(const SProtocolData &data) {
	char string[50];
	sprintf(string, "非线性失真度:%.3lf%%", data.value);
	mDistortionDegreePtr->setText(string);
}

/**
 * 定时器触发函数
 * 不建议在此函数中写耗时操作，否则将影响UI刷新
 * 参数： id
 *         当前所触发定时器的id，与注册时的id相同
 * 返回值: true
 *             继续运行当前定时器
 *         false
 *             停止运行当前定时器
 */

static int indexa = 0;

static bool onUI_Timer(int id){
	if(!sIsRefreshing){
		return true;
	}
	indexa++;
	indexa = indexa *255 / 50;
	if(id == 0){
		if(indexa>50){
			indexa = 0;
		}
		double v = data[indexa]+5;
//	LOGD("%d %lf\n",indexa,v);
		mDiagram1Ptr->addData(id,v);
	}
	return true;
}

/**
 * 有新的触摸事件时触发
 * 参数：ev
 *         新的触摸事件
 * 返回值：true
 *            表示该触摸事件在此被拦截，系统不再将此触摸事件传递到控件上
 *         false
 *            触摸事件将继续传递到控件上
 */
static bool onwindowActivityTouchEvent(const MotionEvent &ev) {
    switch (ev.mActionStatus) {
		case MotionEvent::E_ACTION_DOWN://触摸按下
			//LOGD("时刻 = %ld 坐标  x = %d, y = %d", ev.mEventTime, ev.mX, ev.mY);
			break;
		case MotionEvent::E_ACTION_MOVE://触摸滑动
			break;
		case MotionEvent::E_ACTION_UP:  //触摸抬起
			break;
		default:
			break;
	}
	return false;
}
static bool onButtonClick_sys_home(ZKButton *pButton) {
    LOGD(" ButtonClick sys_home !!!\n");
    return false;
}


static void onCheckedChanged_RadioGroup1(ZKRadioGroup* pRadioGroup, int checkedID) {
    LOGD(" RadioGroup RadioGroup1 checked %d", checkedID);
    ID=checkedID;
    char str[16] = {0};
    switch(checkedID){
    	case ID_WINDOW_NormalSignal:
    		sprintf(str, "Normal");
    		Changebackground(ID_WINDOW_NormalSignal);
    		break;
    	case ID_WINDOW_HighDistortion:
    		sprintf(str, "High");
    		Changebackground(ID_WINDOW_HighDistortion);
    		break;
    	case ID_WINDOW_LowDistortion:
    		sprintf(str, "Low");
    		Changebackground(ID_WINDOW_LowDistortion);
    		break;
    	case ID_WINDOW_BothDistortion:
    		sprintf(str, "Both");
    		Changebackground(ID_WINDOW_BothDistortion);
    		break;
    	case ID_WINDOW_CrossDistortion:
    		sprintf(str, "Cross");
    		Changebackground(ID_WINDOW_CrossDistortion);
    		break;
    }
    mDebugHandler->addDebugMessage(str);
}
static bool onButtonClick_Measure(ZKButton *pButton) {
    LOGD(" ButtonClick Measure !!!\n");
    switch(ID){
        	case ID_WINDOW_NormalSignal:
        		sendMessage(NormalSignal,2);
        		mDistortionDegreePtr->setText("1234567890");
            	break;
            case ID_WINDOW_HighDistortion:
            	sendMessage(HighDistortion,2);
            	break;
            case ID_WINDOW_LowDistortion:
            	sendMessage(LowDistortion,2);
            	break;
            case ID_WINDOW_BothDistortion:
            	sendMessage(BothDistortion,2);
            	break;
            case ID_WINDOW_CrossDistortion:
            	sendMessage(CrossDistortion,2);
        }
    return false;
}

static bool onButtonClick_Clear(ZKButton *pButton) {
    LOGD(" ButtonClick Clear !!!\n");
    mRadioGroup1Ptr->clearCheck();
    mPhotoShowPtr->setBackgroundPic("");
    mDebugHandler->clear();
    mDistortionDegreePtr->setText("非线性失真度:--");
    mActivityPtr->unregisterUserTimer(0);
    mDiagram1Ptr->ClearData(0);
    return false;
}
static bool onButtonClick_Show(ZKButton *pButton) {
    LOGD(" ButtonClick Show !!!\n");
    if(pButton->isSelected()){
    	LOGD("ShowButtonSelected\n");
    }else{
    	LOGD("ShowButtonUnselected\n");
    }
    pButton->setSelected(!pButton->isSelected());
    sIsRefreshing = !pButton->isSelected();
    if(sIsRefreshing){
    	mShowPtr->setText("不显示波形");
    	mActivityPtr->registerUserTimer(0,60);
    	}
        else{
        	mShowPtr->setText("显示波形");
        	mActivityPtr->unregisterUserTimer(0);
        	mDiagram1Ptr->ClearData(0);
        }


    return false;
}
