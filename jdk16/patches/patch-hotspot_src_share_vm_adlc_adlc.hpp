$NetBSD: patch-hotspot_src_share_vm_adlc_adlc.hpp,v 1.1 2011/07/21 06:07:06 ftigeot Exp $

--- hotspot/src/share/vm/adlc/adlc.hpp.orig	2011-07-20 09:12:42 +0000
+++ hotspot/src/share/vm/adlc/adlc.hpp
@@ -13,11 +13,7 @@
 // standard library constants
 #include "stdio.h"
 #include "stdlib.h"
-#if _MSC_VER >= 1300  // Visual C++ 7.0 or later
 #include <iostream>
-#else
-#include <iostream.h>
-#endif
 #include "string.h"
 #include "ctype.h"
 #include "stdarg.h"
