$NetBSD: patch-vm_SPSProfiler.cpp,v 1.1 2014/02/06 15:12:18 fhajny Exp $

Unclear fallout from our version of bug 840242, attachment v1: some architectures
fail to link if we do not add the inlines here - might be compiler/arch specific.


--- vm/SPSProfiler.cpp.orig	2013-10-29 20:40:18.000000000 +0000
+++ vm/SPSProfiler.cpp
@@ -8,6 +8,7 @@
 
 #include "jsnum.h"
 #include "jsscript.h"
+#include "jscntxtinlines.h"
 
 #include "vm/SPSProfiler.h"
 #include "vm/StringBuffer.h"
