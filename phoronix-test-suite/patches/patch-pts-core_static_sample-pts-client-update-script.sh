$NetBSD$

* When you run "test foo == foo" on a platform that does not support the
  "==" operator, the result will be "false" instead of "true". This can
  lead to unexpected behavior. Hence, this patch replaces the "==" operator
  with "=".

--- pts-core/static/sample-pts-client-update-script.sh.orig	2020-05-25 13:26:05.000000000 +0000
+++ pts-core/static/sample-pts-client-update-script.sh
@@ -20,7 +20,7 @@ fi
 cd /phoronix-test-suite
 CURRENT_GIT_COMMIT=`git rev-parse HEAD`
 
-if [ "$GIT_COMMIT_TO_USE" != "$CURRENT_GIT_COMMIT" ] || [ "$FRESH_CLONE" == "1" ]
+if [ "$GIT_COMMIT_TO_USE" != "$CURRENT_GIT_COMMIT" ] || [ "$FRESH_CLONE" = "1" ]
 then
 	git checkout master
 	git pull
