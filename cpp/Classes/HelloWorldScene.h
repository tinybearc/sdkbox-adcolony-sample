#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "PluginAdColony/PluginAdColony.h"

class HelloWorld : public cocos2d::Layer, sdkbox::AdColonyListener
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
private:
    cocos2d::ui::Button* _btnVideo;
    cocos2d::ui::Button* _btnReward;
    cocos2d::ui::Text* _txtCoin;
    int _coin;
    
    void onPlayVideo(cocos2d::Ref* pSender);
    void onPlayReward(cocos2d::Ref* pSender);
    
    void onAdColonyChange(const sdkbox::AdColonyAdInfo& info, bool available);
    void onAdColonyReward(const sdkbox::AdColonyAdInfo& info, const std::string& currencyName, int amount, bool success);
    void onAdColonyStarted(const sdkbox::AdColonyAdInfo& info);
    void onAdColonyFinished(const sdkbox::AdColonyAdInfo& info);
};

#endif // __HELLOWORLD_SCENE_H__
