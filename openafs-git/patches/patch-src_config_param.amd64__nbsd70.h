$NetBSD$

--- src/config/param.amd64_nbsd70.h.orig	2018-05-07 18:33:22.000000000 +0000
+++ src/config/param.amd64_nbsd70.h
@@ -20,3 +20,25 @@
 #endif /* !defined(UKERNEL) */
 
 #endif /* AFS_AMD64_PARAM_H */
+#ifndef AFS_AMD64_PARAM_H
+#define AFS_AMD64_PARAM_H
+
+#define AFS_X86_XBSD_ENV 1
+#define AFS_X86_ENV 1
+#define AFSLITTLE_ENDIAN 1
+
+#define SYS_NAME       "amd64_nbsd70"
+#define SYS_NAME_ID    SYS_NAME_ID_amd64_nbsd70
+
+#define AFS_64BITPOINTER_ENV  1
+#define AFS_64BITUSERPOINTER_ENV	1
+#ifndef UKERNEL
+/* This section for kernel libafs compiles only */
+
+#else /* !defined(UKERNEL) */
+
+/* This section for user space compiles only */
+
+#endif /* !defined(UKERNEL) */
+
+#endif /* AFS_AMD64_PARAM_H */
