$NetBSD: patch-pbdata_utils_SMRTTitle.cpp,v 1.1 2015/09/16 02:36:53 outpaddling Exp $

--- pbdata/utils/SMRTTitle.cpp.orig	2015-08-12 17:41:23.000000000 +0000
+++ pbdata/utils/SMRTTitle.cpp
@@ -1,3 +1,4 @@
+#include <cstdlib>
 #include "utils/SMRTTitle.hpp"
 
 /// Parse a Pacbio read name, it is a SMRTTitle, get movieName, 
