
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

-- MainScene.RESOURCE_FILENAME = "MainScene.csb"

function MainScene:onCreate()

	self._coin = 0
    cc.Label:createWithSystemFont("Adcolony - Lua", "Arial", 38)
        :move(display.cx, display.height - 50)
        :addTo(self)

    local btnVideo = cc.MenuItemFont:create("btnVideo"):onClicked(function()
        sdkbox.PluginAdColony:show("video")
    end)

    local btnReward = cc.MenuItemFont:create("btnReward"):onClicked(function()
        sdkbox.PluginAdColony:show("v4vc")
    end)

    local menu = cc.Menu:create(btnVideo, btnReward)
        :move(display.cx, display.cy)
        :addTo(self)
        :alignItemsVerticallyWithPadding(20)

    local txt = cc.Label:createWithSystemFont("Coins:", "Arial", 38)
        :move(display.width - 200, display.height - 100)
        :addTo(self)

    self._txtCoins = cc.Label:createWithSystemFont("0", "Arial", 38)
        :move(txt:getPositionX() + 70, txt:getPositionY())
        :addTo(self)

    sdkbox.PluginAdColony:init()
    sdkbox.PluginAdColony:setListener(function(args)
        if "onAdColonyChange" == args.name then
            if args.available then
                print("Ads available")
            else
                print("Failed to cache ads")
            end
        elseif "onAdColonyReward" ==  args.name then
            if args.success then
                self._coin = self._coin + 1
                self._txtCoins:setString(self._coin)
            end
        elseif "onAdColonyStarted" ==  args.name then
            print("Ad Started")
        elseif "onAdColonyFinished" ==  args.name then
            print("Ad Finished")
        end
    end)
end

return MainScene
