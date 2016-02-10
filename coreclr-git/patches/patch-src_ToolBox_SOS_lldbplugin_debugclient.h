$NetBSD$

--- src/ToolBox/SOS/lldbplugin/debugclient.h.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/ToolBox/SOS/lldbplugin/debugclient.h
@@ -2,6 +2,8 @@
 // The .NET Foundation licenses this file to you under the MIT license.
 // See the LICENSE file in the project root for more information.
 
+#include <cstdarg>
+
 class DebugClient : public IDebugClient
 {
 private:
