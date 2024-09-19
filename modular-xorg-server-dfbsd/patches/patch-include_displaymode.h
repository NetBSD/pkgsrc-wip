$NetBSD$

--- include/displaymode.h.orig	2019-05-30 18:27:34.000000000 +0000
+++ include/displaymode.h
@@ -55,7 +55,12 @@ typedef enum {
 typedef struct _DisplayModeRec {
     struct _DisplayModeRec *prev;
     struct _DisplayModeRec *next;
+#if defined(__NetBSD__)
+    /* dozens of drivers write to this value */
+    /*const*/ char *name;           /* identifier for the mode */
+#else
     const char *name;           /* identifier for the mode */
+#endif
     ModeStatus status;
     int type;
 
