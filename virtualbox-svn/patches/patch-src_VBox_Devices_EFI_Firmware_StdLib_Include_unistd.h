$NetBSD$

--- src/VBox/Devices/EFI/Firmware/StdLib/Include/unistd.h.orig	2016-03-04 19:27:24.000000000 +0000
+++ src/VBox/Devices/EFI/Firmware/StdLib/Include/unistd.h
@@ -193,7 +193,7 @@ void            swab(const void *, void 
 int             symlink(const char *, const char *);
 void            sync(void);
 useconds_t      ualarm(useconds_t, useconds_t);
-pid_t           vfork(void) __RENAME(__vfork14);
+pid_t           vfork(void) ;//__RENAME(__vfork14);
 
 /*
  * Implementation-defined extensions
