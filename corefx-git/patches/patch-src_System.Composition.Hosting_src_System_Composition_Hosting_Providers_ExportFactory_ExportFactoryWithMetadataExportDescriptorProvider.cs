$NetBSD$

--- src/System.Composition.Hosting/src/System/Composition/Hosting/Providers/ExportFactory/ExportFactoryWithMetadataExportDescriptorProvider.cs.orig	2016-01-30 00:20:59.000000000 +0000
+++ src/System.Composition.Hosting/src/System/Composition/Hosting/Providers/ExportFactory/ExportFactoryWithMetadataExportDescriptorProvider.cs
@@ -5,12 +5,9 @@
 using System.Reflection;
 using System.Composition.Hosting.Util;
 using System.Composition.Hosting.Core;
-using System.Composition.Runtime;
 using System.Linq;
-using System.Threading;
 using System.Collections.Generic;
 using System.Composition.Hosting.Providers.Metadata;
-using System.Composition.Hosting.Properties;
 using Microsoft.Internal;
 
 namespace System.Composition.Hosting.Providers.ExportFactory
