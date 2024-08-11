$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/angle/src/gpu_info_util/SystemInfo_x11.cpp.orig	2024-07-24 02:45:19.672950000 +0000
+++ third_party/angle/src/gpu_info_util/SystemInfo_x11.cpp
@@ -8,6 +8,10 @@
 
 #include "gpu_info_util/SystemInfo_internal.h"
 
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+#include <GL/glx.h>
+#include <GL/glxext.h>
+#endif
 #include <X11/Xlib.h>
 
 #include "common/debug.h"
@@ -18,9 +22,47 @@
 #    error SystemInfo_x11.cpp compiled without GPU_INFO_USE_X11
 #endif
 
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+#define GLX_RENDERER_VENDOR_ID_MESA	0x8183
+#define GLX_RENDERER_DEVICE_ID_MESA	0x8184
+#endif
+
 namespace angle
 {
 
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+bool CollectMesaCardInfo(std::vector<GPUDeviceInfo> *devices)
+{
+    unsigned int vid[3], did[3];
+
+    Display *display = XOpenDisplay(NULL);
+    if (!display) {
+        return false;
+    }
+
+    PFNGLXQUERYRENDERERINTEGERMESAPROC queryInteger =
+        (PFNGLXQUERYRENDERERINTEGERMESAPROC) glXGetProcAddressARB((const GLubyte *)
+        "glXQueryRendererIntegerMESA");
+
+    if (!queryInteger)
+        return false;
+
+    bool vendor_ret =
+        queryInteger(display, 0, 0, GLX_RENDERER_VENDOR_ID_MESA, vid);
+    bool device_ret =
+        queryInteger(display, 0, 0, GLX_RENDERER_DEVICE_ID_MESA, did);
+
+    if (vendor_ret && device_ret) {
+        GPUDeviceInfo info;
+        info.vendorId = vid[0];
+        info.deviceId = did[0];
+        devices->push_back(info);
+    }
+
+    return true;
+}
+#endif
+
 bool GetNvidiaDriverVersionWithXNVCtrl(std::string *version)
 {
     *version = "";
