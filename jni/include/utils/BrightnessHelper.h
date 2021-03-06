/*
 * BrightnessHelper.h
 *
 *  Created on: Sep 23, 2017
 *      Author: guoxs
 */

#ifndef _UTILS_BRIGHTNESS_HELPER_H_
#define _UTILS_BRIGHTNESS_HELPER_H_

/**
 * @brief 亮度调节帮助类
 */
class BrightnessHelper {
public:
	/**
	 * @brief 获取最大亮度值，目前最大值为100
	 */
	int getMaxBrightness() const;

	/**
	 * @brief 获取当前亮度值
	 */
	int getBrightness() const;

	/**
	 * @brief 设置亮度值
	 * @param brightness 范围：0 ~ 100
	 */
	void setBrightness(int brightness);

	/**
	 * @brief 关屏
	 */
	void screenOff();

	/**
	 * @brief 开屏
	 */
	void screenOn();

	bool screenOffEx();
	bool screenOnEx();

	void setLCDEnable(bool enable);

	/**
	 * @brief 是否是开屏状态
	 */
	bool isScreenOn() const;

	/**
	 * @brief 设置对比度
	 * @param contrast 范围：0 ~ 100
	 */
	void setContrast(int contrast);

	/**
	 * @brief 设置饱和度
	 * @param saturation 范围：0 ~ 100
	 */
	void setSaturation(int saturation);

	/**
	 * @brief 设置色调
	 * @param hue 范围：0 ~ 100
	 */
	void setHue(int hue);

	static BrightnessHelper* getInstance();

private:
	BrightnessHelper();

private:
	int mMinBrightness;
	int mMaxBrightness;
	int mBrightness;

	float mRatio;

	bool mIsScreenOn;
};

#define BRIGHTNESSHELPER		BrightnessHelper::getInstance()

#endif /* _UTILS_BRIGHTNESS_HELPER_H_ */

