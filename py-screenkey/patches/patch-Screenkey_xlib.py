$NetBSD$

--- Screenkey/xlib.py.orig	2021-01-01 20:27:07.000000000 +0000
+++ Screenkey/xlib.py
@@ -4,7 +4,7 @@
 from ctypes import *
 
 ## base X11
-libX11 = CDLL('libX11.so.6')
+libX11 = CDLL('libX11.so')
 
 # types
 Atom = c_ulong
@@ -276,7 +276,7 @@ XkbKeycodeToKeysym.restype = KeySym
 
 
 ## record extensions
-libXtst = CDLL('libXtst.so.6')
+libXtst = CDLL('libXtst.so')
 
 # types
 XPointer = String
