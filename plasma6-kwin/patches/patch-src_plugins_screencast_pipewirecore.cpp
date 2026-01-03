$NetBSD$

--- src/plugins/screencast/pipewirecore.cpp.orig	2025-11-04 14:59:40.000000000 +0000
+++ src/plugins/screencast/pipewirecore.cpp
@@ -19,7 +19,11 @@ namespace KWin
 
 PipeWireCore::PipeWireCore()
 {
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
     pw_init(nullptr, nullptr);
+#else
+    pipewire_init(nullptr, nullptr);
+#endif
     pwCoreEvents.version = PW_VERSION_CORE_EVENTS;
     pwCoreEvents.error = &PipeWireCore::onCoreError;
 }
@@ -42,7 +46,11 @@ PipeWireCore::~PipeWireCore()
         pw_loop_destroy(pwMainLoop);
     }
 
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
     pw_deinit();
+#else
+    pipewire_deinit();
+#endif
 }
 
 void PipeWireCore::onCoreError(void *data, uint32_t id, int seq, int res, const char *message)
