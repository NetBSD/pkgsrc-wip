$NetBSD$

--- src/System.Security.Cryptography.Cng/src/System/Security/Cryptography/CngKey.Create.cs.orig	2016-02-25 00:30:19.987564739 +0000
+++ src/System.Security.Cryptography.Cng/src/System/Security/Cryptography/CngKey.Create.cs
@@ -2,10 +2,6 @@
 // The .NET Foundation licenses this file to you under the MIT license.
 // See the LICENSE file in the project root for more information.
 
-using System;
-using System.Diagnostics;
-using System.Diagnostics.Contracts;
-
 using Microsoft.Win32.SafeHandles;
 
 using Internal.Cryptography;
