$NetBSD$

--- src/System.Composition.TypedParts/src/System/Composition/TypedParts/ActivationFeatures/OnImportsSatisfiedFeature.cs.orig	2016-02-25 00:30:19.880800885 +0000
+++ src/System.Composition.TypedParts/src/System/Composition/TypedParts/ActivationFeatures/OnImportsSatisfiedFeature.cs
@@ -2,12 +2,10 @@
 // The .NET Foundation licenses this file to you under the MIT license.
 // See the LICENSE file in the project root for more information.
 
-using System;
 using System.Collections.Generic;
 using System.Composition.Convention;
 using System.Composition.Hosting;
 using System.Composition.Hosting.Core;
-using System.Composition.Runtime;
 using System.Linq;
 using System.Linq.Expressions;
 using System.Reflection;
