$NetBSD$

--- src/VBox/Frontends/VBoxManage/VBoxManageModifyVM.cpp.orig	2016-03-04 19:29:00.000000000 +0000
+++ src/VBox/Frontends/VBoxManage/VBoxManageModifyVM.cpp
@@ -2247,7 +2247,7 @@ RTEXITCODE handleModifyVM(HandlerArg *a)
                     CHECK_ERROR(audioAdapter, COMSETTER(Enabled)(true));
                 }
 #endif /* !RT_OS_SOLARIS */
-#ifdef RT_OS_FREEBSD
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
                 else if (!RTStrICmp(ValueUnion.psz, "oss"))
                 {
                     CHECK_ERROR(audioAdapter, COMSETTER(AudioDriver)(AudioDriverType_OSS));
@@ -2260,7 +2260,7 @@ RTEXITCODE handleModifyVM(HandlerArg *a)
                     CHECK_ERROR(audioAdapter, COMSETTER(Enabled)(true));
                 }
 # endif
-#endif /* !RT_OS_FREEBSD */
+#endif /* !RT_OS_FREEBSD && !RT_OS_NETBSD */
 #ifdef RT_OS_DARWIN
                 else if (!RTStrICmp(ValueUnion.psz, "coreaudio"))
                 {
@@ -2269,7 +2269,7 @@ RTEXITCODE handleModifyVM(HandlerArg *a)
                 }
 
 #endif /* !RT_OS_DARWIN */
-# if defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX) || defined(VBOX_WITH_SOLARIS_OSS)
+# if defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX) || defined(VBOX_WITH_SOLARIS_OSS) || defined(RT_OS_NETBSD)
                 else if (!RTStrICmp(ValueUnion.psz, "oss"))
                 {
                     CHECK_ERROR(audioAdapter, COMSETTER(AudioDriver)(AudioDriverType_OSS));
