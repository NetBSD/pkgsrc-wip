$NetBSD$

--- src/System.Diagnostics.Tracing/src/System/Diagnostics/Tracing/ActivityTracker.cs.orig	2016-01-30 00:20:59.000000000 +0000
+++ src/System.Diagnostics.Tracing/src/System/Diagnostics/Tracing/ActivityTracker.cs
@@ -14,7 +14,6 @@ using Contract = Microsoft.Diagnostics.C
 #if ES_BUILD_STANDALONE
 namespace Microsoft.Diagnostics.Tracing
 #else
-using System.Threading.Tasks;
 namespace System.Diagnostics.Tracing
 #endif
 {
