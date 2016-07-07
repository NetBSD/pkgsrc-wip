$NetBSD$

--- src/VBox/Additions/common/VBoxGuest/VBoxGuestInternal.h.orig	2016-03-04 19:23:10.000000000 +0000
+++ src/VBox/Additions/common/VBoxGuest/VBoxGuestInternal.h
@@ -249,7 +249,7 @@ typedef struct VBOXGUESTSESSION
 {
     /** The list node. */
     RTLISTNODE                  ListNode;
-#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_OS2) || defined(RT_OS_SOLARIS)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_OS2) || defined(RT_OS_SOLARIS) || defined(RT_OS_NETBSD)
     /** Pointer to the next session with the same hash. */
     PVBOXGUESTSESSION           pNextHash;
 #endif
@@ -348,4 +348,3 @@ int VGDrvNtIOCtl_DpcLatencyChecker(void)
 RT_C_DECLS_END
 
 #endif
-
