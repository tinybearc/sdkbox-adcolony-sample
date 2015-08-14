
var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {
        this._super();
        this._coin = 0;
        var self = this;

        var size = cc.winSize;

        var ui = ccs.load(res.MainScene_json);
        this.addChild(ui.node);

        var btnVideo = ui.node.getChildByName("btnVideo");
        btnVideo.addClickEventListener(function(){
            sdkbox.PluginAdColony.show("video");
        });

        var btnReward = ui.node.getChildByName("btnReward");
        btnReward.addClickEventListener(function(){
            sdkbox.PluginAdColony.show("v4vc");
        });

        this._txtCoins = ui.node.getChildByName("txtCoins");

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

