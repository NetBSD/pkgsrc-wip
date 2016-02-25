$NetBSD$

--- src/System.Composition.TypedParts/src/System/Composition/TypedParts/Discovery/DiscoveredPart.cs.orig	2016-01-30 00:20:59.000000000 +0000
+++ src/System.Composition.TypedParts/src/System/Composition/TypedParts/Discovery/DiscoveredPart.cs
@@ -2,7 +2,6 @@
 // The .NET Foundation licenses this file to you under the MIT license.
 // See the LICENSE file in the project root for more information.
 
-using System;
 using System.Collections.Generic;
 using System.Linq;
 using System.Reflection;
@@ -11,7 +10,6 @@ using System.Diagnostics;
 using System.Composition.Debugging;
 using System.Composition.TypedParts.ActivationFeatures;
 using System.Composition.Hosting.Core;
-using System.Composition.Runtime;
 using System.Composition.Convention;
 using System.Composition.Hosting;
 
