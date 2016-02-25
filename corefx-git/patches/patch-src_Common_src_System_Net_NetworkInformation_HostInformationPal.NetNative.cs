$NetBSD$

--- src/Common/src/System/Net/NetworkInformation/HostInformationPal.NetNative.cs.orig	2016-01-30 00:20:59.000000000 +0000
+++ src/Common/src/System/Net/NetworkInformation/HostInformationPal.NetNative.cs
@@ -6,9 +6,7 @@ using System.Collections.Generic;
 using System.Net;
 using System.Runtime.InteropServices;
 using System.Threading;
-
 using Windows.Networking;
-using Windows.Networking.Connectivity;
 
 namespace System.Net.NetworkInformation
 {
@@ -37,7 +35,7 @@ namespace System.Net.NetworkInformation
         {
             Interop.IpHlpApi.FIXED_INFO fixedInfo = new Interop.IpHlpApi.FIXED_INFO();
 
-            IReadOnlyList<HostName> hostNamesList = Windows.Networking.Connectivity.NetworkInformation.GetHostNames();
+            IReadOnlyList<HostName> hostNamesList = global::Windows.Networking.Connectivity.NetworkInformation.GetHostNames();
 
             foreach (HostName entry in hostNamesList)
             {
