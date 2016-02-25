$NetBSD$

--- src/System.Composition.Hosting/src/System/Composition/Hosting/Providers/Metadata/MetadataViewProvider.cs.orig	2016-01-30 00:20:59.000000000 +0000
+++ src/System.Composition.Hosting/src/System/Composition/Hosting/Providers/Metadata/MetadataViewProvider.cs
@@ -2,16 +2,11 @@
 // The .NET Foundation licenses this file to you under the MIT license.
 // See the LICENSE file in the project root for more information.
 
-using System;
 using System.Collections.Generic;
 using System.ComponentModel;
-using System.Composition.Hosting.Core;
-using System.Composition.Hosting.Util;
 using System.Linq;
 using System.Linq.Expressions;
 using System.Reflection;
-using System.Text;
-using System.Threading.Tasks;
 using Microsoft.Internal;
 
 namespace System.Composition.Hosting.Providers.Metadata
