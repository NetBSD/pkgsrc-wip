$NetBSD: patch-common-edaappl.cpp,v 1.1 2012/02/26 01:21:00 bubuchka Exp $

Building on Mac OS X requires CoreFoundation headers.

--- common/edaappl.cpp.orig	2011-11-27 11:43:14.000000000 +0000
+++ common/edaappl.cpp
@@ -16,6 +16,10 @@
 #include <wx/snglinst.h>
 #include <wx/tokenzr.h>
 
+#ifdef __DARWIN__
+#include <CoreFoundation/CFBundle.h>
+#endif
+
 #include "appl_wxstruct.h"
 #include "wxstruct.h"
 #include "macros.h"
