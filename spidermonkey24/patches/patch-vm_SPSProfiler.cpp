$NetBSD: patch-vm_SPSProfiler.cpp,v 1.1 2014/02/06 15:12:18 fhajny Exp $

Unclear fallout from our version of bug 840242, attachment v1: some architectures
fail to link if we do not add the inlines here - might be compiler/arch specific.


--- vm/SPSProfiler.cpp.orig	2013-09-10 03:43:39.000000000 +0000
+++ vm/SPSProfiler.cpp
@@ -8,6 +8,7 @@
 
 #include "jsnum.h"
 #include "jsscript.h"
+#include "jscntxtinlines.h"
 
 #include "vm/SPSProfiler.h"
 #include "vm/StringBuffer.h"
