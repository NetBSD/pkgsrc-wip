$NetBSD$

* When you run "test foo == foo" on a platform that does not support the
  "==" operator, the result will be "false" instead of "true". This can
  lead to unexpected behavior. Hence, this patch replaces the "==" operator 
  with "=".

$NetBSD$

--- ob-cache/test-profiles/pts/civilization-vi-1.0.0/install.sh.orig	2020-05-25 13:26:05.000000000 +0000
+++ ob-cache/test-profiles/pts/civilization-vi-1.0.0/install.sh
@@ -129,7 +129,7 @@ TelemetryUploadNecessary 1
 IsTouchScreenEnabled 0
 \" > AppOptions.txt
 
-if [ \"\$1\" == \"LOW\" ]
+if [ \"\$1\" = \"LOW\" ]
 then
 
 echo \"
@@ -260,7 +260,7 @@ UIOnlyRendering 0
 
 \" > GraphicsOptions.txt
 
-elif [ \"\$1\" == \"HIGH\" ]
+elif [ \"\$1\" = \"HIGH\" ]
 then
 
 echo \";Altering this number will cause the app to overwrite this file with defaults
