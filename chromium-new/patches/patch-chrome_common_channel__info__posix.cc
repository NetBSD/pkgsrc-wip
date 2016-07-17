$NetBSD$

--- chrome/common/channel_info_posix.cc.orig	2016-06-24 01:02:14.000000000 +0000
+++ chrome/common/channel_info_posix.cc
@@ -8,6 +8,8 @@
 #include "build/build_config.h"
 #include "components/version_info/version_info.h"
 
+#include <stdlib.h>
+
 namespace chrome {
 
 namespace {
