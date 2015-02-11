$NetBSD: patch-src_backend_ps_T1__FontDataBase.cc,v 1.2 2015/02/11 12:03:53 nros Exp $
* strcmp need cstring
--- src/backend/ps/T1_FontDataBase.cc.orig	2007-08-17 10:02:40.000000000 +0000
+++ src/backend/ps/T1_FontDataBase.cc
@@ -20,7 +20,8 @@
 #include <config.h>
 #include <map>
 #include <string>
-#include <stdlib.h>
+#include <cstdlib>
+#include <cstring>
 #include <iostream>
 #include <list>
 
