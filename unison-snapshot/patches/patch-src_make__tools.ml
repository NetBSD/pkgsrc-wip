$NetBSD$

Use $^ if supported.

Taken from a pending upstream patch.

--- src/make_tools.ml.orig	2025-07-26 12:17:25.000000000 +0000
+++ src/make_tools.ml
@@ -255,9 +255,14 @@ let () = "WINDRES" <--
   end) ^ "windres"
 
 let () =
-  if is_empty inputs.$("_NMAKE_VER") then
-    "ALL__SRC" <-- "$^$>"  (* First one is for GNU and POSIX make, the other for BSD make *)
-  else
+  if is_empty inputs.$("_NMAKE_VER") then begin
+    if is_empty inputs.$("MAKE") || not_empty (
+          shell ~err_null:true ("printf '_cf_test: FRC ; @echo $^\nFRC: ;' | " ^
+            inputs.$("MAKE") ^ " -f -")) then
+      "ALL__SRC" <-- "$^"  (* GNU and POSIX make, new versions of BSD make *)
+    else
+      "ALL__SRC" <-- "$>"  (* Older versions of BSD make *)
+  end else
     "ALL__SRC" <-- "$(**)" (* NMAKE; enclose in brackets for safety if not run by NMAKE *)
 
 let () = "rule_sep" <-- if not_empty inputs.$("ASSUME_DMAKE") then ":=" else ":"
