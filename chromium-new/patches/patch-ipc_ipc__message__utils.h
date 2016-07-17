$NetBSD$

--- ipc/ipc_message_utils.h.orig	2016-06-24 01:02:23.000000000 +0000
+++ ipc/ipc_message_utils.h
@@ -208,7 +208,7 @@ struct ParamTraits<unsigned int> {
 //   3) Android 64 bit also has int64_t typedef'd to long.
 // Since we want to support Android 32<>64 bit IPC, as long as we don't have
 // these traits for 32 bit ARM then that'll catch any errors.
-#if defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     (defined(OS_ANDROID) && defined(ARCH_CPU_64_BITS))
 template <>
 struct ParamTraits<long> {
