$NetBSD$

Fix the installation path for csound6 plugins.
Add NetBSD and DragonFlyBSD support.

--- Top/csmodule.c.orig	2019-07-12 21:54:19.000000000 +0000
+++ Top/csmodule.c
@@ -89,7 +89,7 @@
 #endif
 
 #if !(defined (NACL))
-#if defined(LINUX) || defined(NEW_MACH_CODE) || defined(__HAIKU__)
+#if defined(LINUX) || defined(NEW_MACH_CODE) || defined(__HAIKU__) || defined(__NetBSD__) || defined(__DragonFly__)
 #include <dlfcn.h>
 #elif defined(WIN32)
 #include <windows.h>
@@ -149,7 +149,7 @@ static  const   char    *plugindir64_env
         "/boot/home/config/non-packaged/lib/csound6/plugins64";
 # endif
 # define CS_DEFAULT_PLUGINDIR  haikudirs
-#elif !(defined(_CSOUND_RELEASE_) && (defined(LINUX) || defined(__MACH__)))
+#elif !(defined(_CSOUND_RELEASE_) && (defined(LINUX) || defined(__MACH__) || defined(__NetBSD__) || defined(__DragonFly__)))
 #  define ENABLE_OPCODEDIR_WARNINGS 1
 #  ifdef CS_DEFAULT_PLUGINDIR
 #    undef CS_DEFAULT_PLUGINDIR
@@ -159,9 +159,9 @@ static  const   char    *plugindir64_env
 #  define ENABLE_OPCODEDIR_WARNINGS 0
 #  ifndef CS_DEFAULT_PLUGINDIR
 #    ifndef USE_DOUBLE
-#      define CS_DEFAULT_PLUGINDIR  "/usr/local/lib/csound/plugins"
+#      define CS_DEFAULT_PLUGINDIR  __PKGSRC_PREFIX__ "lib/csound6/plugins-6.0"
 #    else
-#      define CS_DEFAULT_PLUGINDIR  "/usr/local/lib/csound/plugins64"
+#      define CS_DEFAULT_PLUGINDIR  __PKGSRC_PREFIX__ "lib/csound6/plugins-6.0"
 #    endif
 #  endif
 #endif
@@ -264,7 +264,7 @@ static CS_NOINLINE int csoundLoadExterna
     err = csoundOpenLibrary(&h, libraryPath);
     if (UNLIKELY(err)) {
       char ERRSTR[256];
- #if !(defined(NACL)) && (defined(LINUX) || defined(__HAIKU__))
+ #if !(defined(NACL)) && (defined(LINUX) || defined(__HAIKU__) || defined(__NetBSD__) || defined(__DragonFly__))
       snprintf(ERRSTR, 256, Str("could not open library '%s' (%s)"),
                libraryPath, dlerror());
  #else
@@ -751,7 +751,7 @@ PUBLIC void *csoundGetLibrarySymbol(void
     return (void*) GetProcAddress((HMODULE) library, procedureName);
 }
 
-#elif !(defined(NACL)) && (defined(LINUX) || defined(NEW_MACH_CODE) || defined(__HAIKU__))
+#elif !(defined(NACL)) && (defined(LINUX) || defined(NEW_MACH_CODE) || defined(__HAIKU__) || defined(__NetBSD__) || defined(__DragonFly__))
 
 PUBLIC int csoundOpenLibrary(void **library, const char *libraryPath)
 {
