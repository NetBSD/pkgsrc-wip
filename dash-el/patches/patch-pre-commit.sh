$NetBSD$

CHECK_PORTABILITY

--- pre-commit.sh.orig	2019-04-25 03:04:40.000000000 +0900
+++ pre-commit.sh	2019-12-27 22:00:39.398628357 +0900
@@ -3,7 +3,7 @@
 git stash -q --keep-index
 ./run-tests.sh
 RESULT=$?
-[ $RESULT == 0 ] && ./create-docs.sh && git add ./README.md
+[ $RESULT = 0 ] && ./create-docs.sh && git add ./README.md
 git stash pop -q
 [ $RESULT -ne 0 ] && exit 1
 exit 0
