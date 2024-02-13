$NetBSD: patch-src_alire_alire-platforms.ads,v 1.0 2023/12/27 22:00:00 dkazankov Exp $

Add NetBSD support

--- src/alire/alire-platforms.ads.orig	2023-10-19 15:04:21.000000000 +0000
+++ src/alire/alire-platforms.ads
@@ -21,6 +21,7 @@ package Alire.Platforms with Preelaborat
    --  See e.g. https://stackoverflow.com/a/45125525/761390
 
    type Operating_Systems is (FreeBSD,
+                              NetBSD,
                               Linux,
                               MacOS,
                               Windows,
