$NetBSD$

--- src/VBox/Additions/x11/vboxvideo/VBoxVideoIPRT.h.orig	2019-12-01 07:29:52.207638937 +0000
+++ src/VBox/Additions/x11/vboxvideo/VBoxVideoIPRT.h
@@ -78,6 +78,14 @@ RT_C_DECLS_END
 
 RT_C_DECLS_BEGIN
 extern int RTASSERTVAR[1];
+typedef struct RTLISTNODE
+{
+    /** Pointer to the next list node. */
+    struct RTLISTNODE *pNext;
+    /** Pointer to the previous list node. */
+    struct RTLISTNODE *pPrev;
+} RTLISTNODE;
+typedef RTLISTNODE RTLISTANCHOR;
 RT_C_DECLS_END
 
 #define AssertCompile(expr) \
