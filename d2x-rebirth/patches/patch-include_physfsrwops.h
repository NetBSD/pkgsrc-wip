$NetBSD$

--- ./include/physfsrwops.h.orig	2019-03-04 22:58:02.523929348 -0800
+++ ./include/physfsrwops.h	2019-03-04 22:58:18.372226593 -0800
@@ -44,7 +44,7 @@
  *  @return A valid SDL_RWops structure on success, NULL on error. Specifics
  *           of the error can be gleaned from PHYSFS_getLastError().
  */
-__EXPORT__ SDL_RWops *PHYSFSRWOPS_openRead(const char *fname);
+SDL_RWops *PHYSFSRWOPS_openRead(const char *fname);
 
 /**
  * Open a platform-independent filename for writing, and make it accessible
@@ -56,7 +56,7 @@
  *  @return A valid SDL_RWops structure on success, NULL on error. Specifics
  *           of the error can be gleaned from PHYSFS_getLastError().
  */
-__EXPORT__ SDL_RWops *PHYSFSRWOPS_openWrite(const char *fname);
+SDL_RWops *PHYSFSRWOPS_openWrite(const char *fname);
 
 /**
  * Open a platform-independent filename for appending, and make it accessible
@@ -68,7 +68,7 @@
  *  @return A valid SDL_RWops structure on success, NULL on error. Specifics
  *           of the error can be gleaned from PHYSFS_getLastError().
  */
-__EXPORT__ SDL_RWops *PHYSFSRWOPS_openAppend(const char *fname);
+SDL_RWops *PHYSFSRWOPS_openAppend(const char *fname);
 
 /**
  * Make a SDL_RWops from an existing PhysicsFS file handle. You should
@@ -80,7 +80,7 @@
  *  @return A valid SDL_RWops structure on success, NULL on error. Specifics
  *           of the error can be gleaned from PHYSFS_getLastError().
  */
-__EXPORT__ SDL_RWops *PHYSFSRWOPS_makeRWops(PHYSFS_file *handle);
+SDL_RWops *PHYSFSRWOPS_makeRWops(PHYSFS_file *handle);
 
 #ifdef __cplusplus
 }
