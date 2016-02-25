$NetBSD$

--- src/System.Threading.Tasks.Dataflow/src/Internal/TargetCore.cs.orig	2016-02-25 00:30:20.005981592 +0000
+++ src/System.Threading.Tasks.Dataflow/src/Internal/TargetCore.cs
@@ -11,13 +11,11 @@
 //
 // =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
 
-using System.Collections.Concurrent;
 using System.Collections.Generic;
 using System.Diagnostics;
 using System.Diagnostics.CodeAnalysis;
 using System.Diagnostics.Contracts;
 using System.Linq;
-using System.Security;
 
 namespace System.Threading.Tasks.Dataflow.Internal
 {
