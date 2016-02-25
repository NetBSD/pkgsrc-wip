$NetBSD$

--- src/System.Net.Primitives/src/System/Net/CookieException.cs.orig	2016-01-30 00:21:00.000000000 +0000
+++ src/System.Net.Primitives/src/System/Net/CookieException.cs
@@ -2,8 +2,6 @@
 // The .NET Foundation licenses this file to you under the MIT license.
 // See the LICENSE file in the project root for more information.
 
-using System.Diagnostics.CodeAnalysis;
-
 // The NETNative_SystemNetHttp #define is used in some source files to indicate we are compiling classes
 // directly into the .NET Native System.Net.Http.dll implementation assembly in order to use internal class
 // methods. Internal methods are needed in order to map cookie response headers from the WinRT Windows.Web.Http APIs.
