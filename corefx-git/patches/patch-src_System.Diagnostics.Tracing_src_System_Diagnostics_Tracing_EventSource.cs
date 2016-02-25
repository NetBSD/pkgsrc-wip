$NetBSD$

--- src/System.Diagnostics.Tracing/src/System/Diagnostics/Tracing/EventSource.cs.orig	2016-02-25 00:30:19.899697568 +0000
+++ src/System.Diagnostics.Tracing/src/System/Diagnostics/Tracing/EventSource.cs
@@ -195,8 +195,6 @@ using Microsoft.Win32;
 
 #if ES_BUILD_STANDALONE
 using EventDescriptor = Microsoft.Diagnostics.Tracing.EventDescriptor;
-#else
-using System.Threading.Tasks;
 #endif
 
 using Microsoft.Reflection;
