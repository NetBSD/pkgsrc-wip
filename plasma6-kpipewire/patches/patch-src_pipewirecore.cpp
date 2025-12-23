$NetBSD$

--- src/pipewirecore.cpp.orig	2025-11-04 14:59:25.000000000 +0000
+++ src/pipewirecore.cpp
@@ -33,7 +33,11 @@ pw_core_events PipeWireCore::s_pwCoreEve
 PipeWireCore::PipeWireCore()
 {
     static std::once_flag pwInitOnce;
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
     std::call_once(pwInitOnce, [] { pw_init(nullptr, nullptr); });
+#else
+    std::call_once(pwInitOnce, [] { pipewire_init(nullptr, nullptr); });
+#endif
 }
 
 void PipeWireCore::onCoreError(void *data, uint32_t id, int seq, int res, const char *message)
