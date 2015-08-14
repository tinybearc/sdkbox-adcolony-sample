#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "PluginAdColony/PluginAdColony.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    _coin = 0;
    
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    FileUtils::getInstance()->addSearchPath("res");
    
    sdkbox::PluginAdColony::init();
    sdkbox::PluginAdColony::setListener(this);

    auto rootNode = CSLoader::createNode("MainScene.csb");
    addChild(rootNode);
    
    _btnVideo = rootNode->getChildByName<ui::Button*>("btnVideo");
    _btnVideo->addClickEventListener(CC_CALLBACK_1(HelloWorld::onPlayVideo, this));
    _btnVideo->setBright(false);
    
    _btnReward = rootNode->getChildByName<ui::Button*>("btnReward");
    _btnReward->addClickEventListener(CC_CALLBACK_1(HelloWorld::onPlayReward, this));
    _btnReward->setBright(false);
    
    _txtCoin = rootNode->getChildByName<ui::Text*>("txtCoins");
    
    auto btnClose = rootNode->getChildByName<ui::Button*>("btnClose");
    btnClose->addClickEventListener(CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    return true;
}

/**
 * Button callback
 */

void HelloWorld::onPlayVideo(Ref *pSender)
{
    sdkbox::PluginAdColony::show("video");
}

void HelloWorld::onPlayReward(Ref* sender)
{
    sdkbox::PluginAdColony::show("v4vc");
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

/** 
 * AdColony Callback
 */
void HelloWorld::onAdColonyChange(const sdkbox::AdColonyAdInfo& info, bool available)
{
    CCLOG("Finish loading ads %s", info.name.c_str());
    _btnVideo->setBright(true);
    _btnReward->setBright(true);
}

void HelloWorld::onAdColonyReward(const sdkbox::AdColonyAdInfo& info, const std::string& currencyName, int amount, bool success)
{
    if (success)
    {
        //
        _coin ++;
        _txtCoin->setString(std::to_string(_coin));
    }
}

void HelloWorld::onAdColonyStarted(const sdkbox::AdColonyAdInfo& info)
{
    CCLOG("Ad started: %s", info.name.c_str());
}

void HelloWorld::onAdColonyFinished(const sdkbox::AdColonyAdInfo& info)
{
    CCLOG("Ad ended: %s", info.name.c_str());
}
