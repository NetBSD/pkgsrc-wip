$NetBSD$

--- engine/lib/openal/NetBSD/AL/alu.h.orig	2016-07-30 11:47:19.716277314 +0000
+++ engine/lib/openal/NetBSD/AL/alu.h
@@ -0,0 +1,37 @@
+#ifndef __alu_h_
+#define __alu_h_
+
+#ifdef _WIN32
+#define ALAPI       __declspec(dllexport)
+#define ALAPIENTRY  __cdecl
+#else  /* _WIN32 */
+#define ALAPI
+#define ALAPIENTRY
+#define AL_CALLBACK
+#endif /* _WIN32 */
+
+#include <AL/al.h>
+#include <AL/alutypes.h>
+
+#ifdef __cplusplus
+extern "C" {
+#endif
+
+#ifndef AL_NO_PROTOTYPES
+
+
+
+#else
+
+
+
+
+
+#endif /* AL_NO_PROTOTYPES */
+
+#ifdef __cplusplus
+}
+#endif
+
+#endif /* __alu_h_ */
+
