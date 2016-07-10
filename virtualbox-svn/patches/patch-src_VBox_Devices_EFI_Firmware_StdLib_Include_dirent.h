$NetBSD$

--- src/VBox/Devices/EFI/Firmware/StdLib/Include/dirent.h.orig	2016-03-04 19:27:22.000000000 +0000
+++ src/VBox/Devices/EFI/Firmware/StdLib/Include/dirent.h
@@ -83,14 +83,14 @@ __BEGIN_DECLS
   int             closedir(DIR *);
   void            rewinddir(DIR *);
 
-  DIR            *opendir(const char *)                                       __RENAME(__opendir30);
-  struct dirent  *readdir(DIR *)                                              __RENAME(__readdir30);
+  DIR            *opendir(const char *)                                       ;//__RENAME(__opendir30);
+  struct dirent  *readdir(DIR *)                                              ;//__RENAME(__readdir30);
   int             readdir_r(DIR * __restrict, struct dirent * __restrict,
-                            struct dirent ** __restrict)                      __RENAME(__readdir_r30);
+                            struct dirent ** __restrict)                      ;//__RENAME(__readdir_r30);
 
   void            seekdir(DIR *, long);
   long            telldir(DIR *);
-  DIR            *__opendir2(const char *, int)                               __RENAME(__opendir230);
+  DIR            *__opendir2(const char *, int)                               ;//__RENAME(__opendir230);
 
   //#ifndef __LIBC12_SOURCE__
   //int             scandir(const char *, struct dirent ***,
