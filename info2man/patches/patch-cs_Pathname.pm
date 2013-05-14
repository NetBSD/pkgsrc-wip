$NetBSD: patch-cs_Pathname.pm,v 1.1 2013/05/14 13:39:50 francksys Exp $

/* Fix the a get directory bug. Otherwise the path is added two times. */
--- cs/Pathname.pm.orig	2013-05-14 12:07:36.000000000 +0000
+++ cs/Pathname.pm
@@ -92,6 +92,8 @@ sub absname($;$)
 { my($path,$dir)=@_;
   $dir=pwd() if ! defined $dir;
 
+  $dir = "";
+
   return $path if $path =~ m:^/:;
   return catpath($dir,$path);
 }
