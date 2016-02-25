$NetBSD$

--- src/System.Composition.Hosting/src/System/Composition/Hosting/CompositionHost.cs.orig	2016-02-25 00:30:19.880237566 +0000
+++ src/System.Composition.Hosting/src/System/Composition/Hosting/CompositionHost.cs
@@ -8,8 +8,6 @@ using System.Composition.Hosting.Provide
 using System.Composition.Hosting.Providers.ExportFactory;
 using System.Composition.Hosting.Providers.ImportMany;
 using System.Composition.Hosting.Providers.Lazy;
-using System.Composition.Hosting.Providers.Metadata;
-using System.Composition.Runtime;
 using System.Linq;
 
 using Microsoft.Internal;
