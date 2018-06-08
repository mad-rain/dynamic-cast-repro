LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := test
LOCAL_SRC_FILES := test.cpp throw.cpp
LOCAL_SHARED_LIBRARIES := test
LOCAL_CFLAGS += -flto=thin
LOCAL_LDFLAGS := -flto=thin -fuse-ld=gold    
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := foo
LOCAL_SRC_FILES := foo.cpp
include $(BUILD_EXECUTABLE)
