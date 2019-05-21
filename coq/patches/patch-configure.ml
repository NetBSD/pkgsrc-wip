$NetBSD$

Correct lablgtk3 detection
--- configure.ml.orig	2019-05-14 14:52:16.000000000 +0000
+++ configure.ml
@@ -703,7 +703,7 @@ let numlib =
 (** Detect and/or verify the Lablgtk3 location *)
 
 let get_lablgtkdir () =
-  tryrun camlexec.find ["query";"lablgtk3-sourceview3"]
+  tryrun camlexec.find ["query";"lablgtk3.sourceview3"]
 
 (** Detect and/or verify the Lablgtk2 version *)
 
