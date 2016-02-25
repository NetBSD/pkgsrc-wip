$NetBSD$

--- src/System.Diagnostics.Tracing/src/System/Diagnostics/Tracing/EventSourceException.cs.orig	2016-01-30 00:20:59.000000000 +0000
+++ src/System.Diagnostics.Tracing/src/System/Diagnostics/Tracing/EventSourceException.cs
@@ -2,9 +2,6 @@
 // The .NET Foundation licenses this file to you under the MIT license.
 // See the LICENSE file in the project root for more information.
 
-using System;
-using System.Runtime.Serialization;
-
 #if ES_BUILD_STANDALONE
 using Environment = Microsoft.Diagnostics.Tracing.Internal.Environment;
 #endif
