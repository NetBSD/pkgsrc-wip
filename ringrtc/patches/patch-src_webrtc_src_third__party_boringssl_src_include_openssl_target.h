$NetBSD$

* Import from chromium

--- src/webrtc/src/third_party/boringssl/src/include/openssl/target.h.orig	2026-11-10 15:46:07.993000000 +0000
+++ src/webrtc/src/third_party/boringssl/src/include/openssl/target.h
@@ -177,6 +177,10 @@
 #define OPENSSL_OPENBSD
 #endif
 
+#if defined(__NetBSD__)
+#define OPENSSL_NETBSD
+#endif
+
 // BoringSSL requires platform's locking APIs to make internal global state
 // thread-safe, including the PRNG. On some single-threaded embedded platforms,
 // locking APIs may not exist, so this dependency may be disabled with the
