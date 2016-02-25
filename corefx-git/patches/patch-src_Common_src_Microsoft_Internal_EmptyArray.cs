$NetBSD$

--- src/Common/src/Microsoft/Internal/EmptyArray.cs.orig	2016-01-30 00:20:59.000000000 +0000
+++ src/Common/src/Microsoft/Internal/EmptyArray.cs
@@ -2,14 +2,6 @@
 // The .NET Foundation licenses this file to you under the MIT license.
 // See the LICENSE file in the project root for more information.
 
-using System;
-using System.Collections.Generic;
-using System.Composition;
-using System.Diagnostics;
-using System.Diagnostics.Contracts;
-using System.Globalization;
-using System.Reflection;
-
 namespace Microsoft.Internal
 {
     internal static class EmptyArray<T>
