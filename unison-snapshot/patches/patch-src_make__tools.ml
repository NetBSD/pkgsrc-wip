$NetBSD$

Use $^ if supported.

Taken from a pending upstream patch.

--- src/make_tools.ml.orig	2025-07-26 12:17:25.000000000 +0000
+++ src/make_tools.ml
@@ -255,8 +255,10 @@ let () = "WINDRES" <--
   end) ^ "windres"

 let () =
-  if is_empty inputs.$("_NMAKE_VER") then
-    "ALL__SRC" <-- "$^$>"  (* First one is for GNU and POSIX make, the other for BSD make *)
+  if is_empty inputs.$("BSD_HAS_CF") && not_empty inputs.$("BSD_HAS_GT") then
+    "ALL__SRC" <-- "$>"    (* Older versions of BSD make *)
+  else if is_empty inputs.$("_NMAKE_VER") then
+    "ALL__SRC" <-- "$^"    (* GNU and POSIX make, new versions of BSD make *)
   else
     "ALL__SRC" <-- "$(**)" (* NMAKE; enclose in brackets for safety if not run by NMAKE *)
