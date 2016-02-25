$NetBSD$

--- src/System.Net.Sockets/src/System/Net/Sockets/UDPClient.cs.orig	2016-02-25 00:30:19.953274836 +0000
+++ src/System.Net.Sockets/src/System/Net/Sockets/UDPClient.cs
@@ -2,9 +2,7 @@
 // The .NET Foundation licenses this file to you under the MIT license.
 // See the LICENSE file in the project root for more information.
 
-using System.Threading;
 using System.Threading.Tasks;
-using System.Diagnostics.CodeAnalysis;
 
 namespace System.Net.Sockets
 {
