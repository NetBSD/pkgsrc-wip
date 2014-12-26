$NetBSD: patch-src_backend_ps_T1__FontDataBase.cc,v 1.1 2014/12/26 21:16:29 nros Exp $
* strcmp need string.h
--- src/backend/ps/T1_FontDataBase.cc.orig	2007-08-17 10:02:40.000000000 +0000
+++ src/backend/ps/T1_FontDataBase.cc
@@ -21,6 +21,7 @@
 #include <map>
 #include <string>
 #include <stdlib.h>
+#include <string.h>
 #include <iostream>
 #include <list>
 
