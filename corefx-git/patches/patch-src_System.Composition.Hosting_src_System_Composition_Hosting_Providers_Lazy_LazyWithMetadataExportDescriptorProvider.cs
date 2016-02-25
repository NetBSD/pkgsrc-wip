$NetBSD$

--- src/System.Composition.Hosting/src/System/Composition/Hosting/Providers/Lazy/LazyWithMetadataExportDescriptorProvider.cs.orig	2016-01-30 00:20:59.000000000 +0000
+++ src/System.Composition.Hosting/src/System/Composition/Hosting/Providers/Lazy/LazyWithMetadataExportDescriptorProvider.cs
@@ -4,9 +4,7 @@
 
 using System.Reflection;
 using System.Composition.Hosting.Core;
-using System.Composition.Runtime;
 using System.Linq;
-using System.Threading;
 using System.Composition.Hosting.Util;
 using System.Collections.Generic;
 using System.Composition.Hosting.Providers.Metadata;
