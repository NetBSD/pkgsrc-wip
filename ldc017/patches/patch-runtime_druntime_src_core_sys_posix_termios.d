$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/termios.d.orig	2018-08-23 23:29:55.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/termios.d
@@ -638,6 +638,40 @@ version( CRuntime_Glibc )
 
     pid_t   tcgetsid(int);
 }
+else version( NetBSD )
+{
+    enum IXANY      = 0x00000800;
+
+    enum ONLCR      = 0x00000002;
+    enum OCRNL      = 0x00000010;
+    enum ONOCR      = 0x00000020;
+    enum ONLRET     = 0x00000040;
+    //enum OFILL
+    //enum NLDLY
+    //enum     NL0
+    //enum     NL1
+    //enum CRDLY
+    //enum     CR0
+    //enum     CR1
+    //enum     CR2
+    //enum     CR3
+    enum TABDLY     = 0x00000004;
+    enum     TAB0   = 0x00000000;
+    //enum     TAB1
+    //enum     TAB2
+    enum     TAB3   = 0x00000004;
+    //enum BSDLY
+    //enum     BS0
+    //enum     BS1
+    //enum VTDLY
+    //enum     VT0
+    //enum     VT1
+    //enum FFDLY
+    //enum     FF0
+    //enum     FF1
+
+    pid_t   tcgetsid(int);
+}
 
 else version (OSX)
 {
