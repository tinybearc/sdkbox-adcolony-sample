
var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {
        this._super();
        this._coin = 0;
        var self = this;

        var size = cc.winSize;

        // var ui = ccs.load(res.MainScene_json);
        // this.addChild(ui.node);

        // var btnVideo = ui.node.getChildByName("btnVideo");
        // btnVideo.addClickEventListener(function(){
        //     sdkbox.PluginAdColony.show("video");
        // });

        // var btnReward = ui.node.getChildByName("btnReward");
        // btnReward.addClickEventListener(function(){
        //     sdkbox.PluginAdColony.show("v4vc");
        // });

        // this._txtCoins = ui.node.getChildByName("txtCoins");

        var btnVideo = new cc.MenuItemFont("btnVideo", function () {
          sdkbox.PluginAdColony.show("video");
        }, this);

        var btnReward = new cc.MenuItemFont("btnReward", function () {
          sdkbox.PluginAdColony.show("v4vc");
        }, this);

        var menu = new cc.Menu(btnVideo, btnReward);
        menu.x = size.width/2;
        menu.y = size.height/2;
        menu.alignItemsVerticallyWithPadding(5);
        this.addChild(menu);

        var txt = new cc.LabelTTF("Coins:", "Arial", 38);
        txt.x = size.width - 200;
        txt.y = size.height - 100;
        this.addChild(txt, 5);

        this._txtCoins = new cc.LabelTTF("0", "Arial", 38);
        this._txtCoins.x = txt.getPositionX() + 70;
        this._txtCoins.y = txt.getPositionY();
        this.addChild(this._txtCoins, 5);

        sdkbox.PluginAdColony.init();
        sdkbox.PluginAdColony.setListener({
            onAdColonyChange : function (data, available) {
                if (available) {
                    //
                    cc.log("Ads available");
                }
                else {
                    //
                    cc.log("Failed to cache ads");
                }
            },
            onAdColonyReward : function (data, currencyName, amount, success) {
                if (success) {
                    //
                    self._coin ++;
                    self._txtCoins.setString(self._coin);
                }

            },
            onAdColonyStarted : function (data) {
                cc.log("Ad Started");
            },
            onAdColonyFinished : function (data) {
                cc.log("Ad Finished");
            }
        });

        return true;
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

