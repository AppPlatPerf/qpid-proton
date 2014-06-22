LOCAL_PATH := $(call my-dir)



include $(CLEAR_VARS)
LOCAL_MODULE    := ext2_uuid-prebuilt
LOCAL_SRC_FILES := ../../androiduuid/obj/local/armeabi/libext2_uuid.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := crypto-prebuilt
LOCAL_SRC_FILES := ../../androidopenssl/libs/armeabi/libcrypto.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := ssl-prebuilt
LOCAL_SRC_FILES := ../../androidopenssl/libs/armeabi/libssl.so
include $(PREBUILT_SHARED_LIBRARY)


include $(CLEAR_VARS)
LOCAL_CFLAGS := -DUSE_CLOCK_GETTIME -DUSE_UUID_GENERATE -DUSE_STRERROR_R -DUSE_ATOLL -std=gnu99 -g

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../../proton-c/include \
$(LOCAL_PATH)/../../../../proton-c/include/proton \
$(LOCAL_PATH)/include/proton

LOCAL_MODULE    := proton-jni
LOCAL_SRC_FILES := ../../../../proton-c/src/error.c \
../../../../proton-c/src/types.c \
../../../../proton-c/src/buffer.c \
../../../../proton-c/src/transport/transport.c \
../../../../proton-c/src/platform.c \
../../../../proton-c/src/scanner.c \
../../../../proton-c/src/parser.c \
../../../../proton-c/src/util.c \
../../../../proton-c/src/posix/driver.c \
../../../../proton-c/src/engine/engine.c \
../../../../proton-c/src/message/message.c \
../../../../proton-c/src/codec/codec.c \
../../../../proton-c/src/codec/encoder.c \
../../../../proton-c/src/codec/decoder.c \
../../../../proton-c/src/framing/framing.c \
../../../../proton-c/src/sasl/sasl.c \
../../../../proton-c/src/dispatcher/dispatcher.c \
../../../../proton-c/src/ssl/openssl.c \
../../../../proton-c/src/messenger/messenger.c \
../../../../proton-c/src/messenger/transform.c \
../../../../proton-c/src/messenger/subscription.c \
../../../../proton-c/src/messenger/store.c \
../../../../proton-c/src/object/object.c \
src/javaJAVA_wrap.c
LOCAL_SHARED_LIBRARIES += crypto-prebuilt \
ssl-prebuilt
LOCAL_STATIC_LIBRARIES += ext2_uuid-prebuilt
LOCAL_LDLIBS := -llog

include $(BUILD_SHARED_LIBRARY)

