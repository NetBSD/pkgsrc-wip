$NetBSD$

--- src/VBox/Devices/EFI/Firmware/StdLib/Include/sys/socket.h.orig	2016-03-04 19:27:24.000000000 +0000
+++ src/VBox/Devices/EFI/Firmware/StdLib/Include/sys/socket.h
@@ -561,7 +561,7 @@ int shutdown(int, int);
 int sockatmark(int);
 int socket(int, int, int)
 #if !defined(__LIBC12_SOURCE__) && !defined(_STANDALONE)
-__RENAME(__socket30)
+/*__RENAME(__socket30)*/
 #endif
            ;
 int socketpair(int, int, int, int *);
