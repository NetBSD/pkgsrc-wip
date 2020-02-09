$NetBSD$

Add "Hard-coded NetBSD-specific features and options..."
    
all of these should really be configure checks of course...

--- hostopts.h.orig	2019-09-10 18:06:20.000000000 +0000
+++ hostopts.h
@@ -297,6 +297,25 @@
 
 
 /*-------------------------------------------------------------------*/
+/* Hard-coded NetBSD-specific features and options...                */
+/*-------------------------------------------------------------------*/
+#elif defined(__NetBSD__)               /* "NetBSD" options          */
+
+#define DLL_IMPORT   extern
+#define DLL_EXPORT
+#define TUNTAP_IFF_RUNNING_NEEDED       /* Needed by tuntap driver?? */
+#undef  OPTION_SCSI_ERASE_TAPE          /* (NOT supported)           */
+#undef  OPTION_SCSI_ERASE_GAP           /* (NOT supported)           */
+#define MAX_DEVICE_THREADS          0   /* (0 == unlimited)          */
+#define MIXEDCASE_FILENAMES_ARE_UNIQUE  /* ("Foo" and "fOo" unique)  */
+#define HOW_TO_IMPLEMENT_SH_COMMAND       USE_ANSI_SYSTEM_API_FOR_SH_COMMAND
+#define SET_CONSOLE_CURSOR_SHAPE_METHOD   CURSOR_SHAPE_NOT_SUPPORTED
+#undef  OPTION_EXTCURS                  /* Normal cursor handling    */
+#define SCANDIR_CONST_STRUCT_DIRENT     /* define if scandir uses
+                                           const for struct dirent   */
+
+
+/*-------------------------------------------------------------------*/
 /* Hard-coded GNU Linux-specific features and options...             */
 /*-------------------------------------------------------------------*/
 #elif defined(__gnu_linux__)            /* GNU Linux options         */
