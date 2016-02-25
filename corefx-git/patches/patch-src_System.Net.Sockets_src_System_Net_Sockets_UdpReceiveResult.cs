$NetBSD$

--- src/System.Net.Sockets/src/System/Net/Sockets/UdpReceiveResult.cs.orig	2016-02-25 00:30:19.953313601 +0000
+++ src/System.Net.Sockets/src/System/Net/Sockets/UdpReceiveResult.cs
@@ -2,8 +2,6 @@
 // The .NET Foundation licenses this file to you under the MIT license.
 // See the LICENSE file in the project root for more information.
 
-using System.Diagnostics.CodeAnalysis;
-
 namespace System.Net.Sockets
 {
     public struct UdpReceiveResult : IEquatable<UdpReceiveResult>
