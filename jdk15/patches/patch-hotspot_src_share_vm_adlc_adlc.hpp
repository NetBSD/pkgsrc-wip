$NetBSD: patch-hotspot_src_share_vm_adlc_adlc.hpp,v 1.1 2011/07/21 19:15:31 ftigeot Exp $

--- hotspot/src/share/vm/adlc/adlc.hpp.orig	2011-07-21 18:47:59 +0000
+++ hotspot/src/share/vm/adlc/adlc.hpp
@@ -14,7 +14,7 @@
 
 // standard library constants
 #include "stdio.h"
-#include <iostream.h>
+#include <iostream>
 #include "stdlib.h"
 #include "string.h"
 #include "ctype.h"
