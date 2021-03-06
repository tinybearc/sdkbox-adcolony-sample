LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2djs_shared

LOCAL_MODULE_FILENAME := libcocos2djs

LOCAL_SRC_FILES := ../../Classes/AppDelegate.cpp ../../Classes/ide-support/SimpleConfigParser.cpp ../../Classes/ide-support/RuntimeJsImpl.cpp hellojavascript/main.cpp ../../Classes/PluginAdColonyJS.cpp ../../Classes/PluginAdColonyJSHelper.cpp ../../Classes/SDKBoxJSHelper.cpp

LOCAL_LDLIBS := -landroid -llog
LOCAL_CPPFLAGS := -DSDKBOX_ENABLED
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes
LOCAL_WHOLE_STATIC_LIBRARIES := PluginAdColony sdkbox


LOCAL_STATIC_LIBRARIES := cocos2d_js_static

include $(BUILD_SHARED_LIBRARY)
$(call import-add-path,$(LOCAL_PATH))


$(call import-module,scripting/js-bindings/proj.android/prebuilt-mk)
$(call import-module, ./sdkbox)
$(call import-module, ./pluginadcolony)
