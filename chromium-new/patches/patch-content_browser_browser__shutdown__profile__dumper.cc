$NetBSD$

--- content/browser/browser_shutdown_profile_dumper.cc.orig	2016-06-24 01:02:20.000000000 +0000
+++ content/browser/browser_shutdown_profile_dumper.cc
@@ -2,6 +2,8 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+#include <stdio.h>
+
 #include "content/browser/browser_shutdown_profile_dumper.h"
 
 #include "base/command_line.h"
