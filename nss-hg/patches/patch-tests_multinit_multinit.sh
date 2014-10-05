$NetBSD: patch-tests_multinit_multinit.sh,v 1.2 2014/10/05 20:12:38 thomasklausner Exp $

Posix compatibility - avoid bash specific == operator

--- tests/multinit/multinit.sh.orig	2014-09-28 13:54:02.000000000 +0000
+++ tests/multinit/multinit.sh
@@ -91,14 +91,14 @@ multinit_main()
 	# the database type.
 	if [ "$tag" != "all" ]; then
 	    read tag2 expected_result2
-	    if [ "$NSS_DEFAULT_DB_TYPE" == "$tag2" ]; then
+	    if [ "$NSS_DEFAULT_DB_TYPE" = "$tag2" ]; then
 		expected_result=$expected_result2
 	    fi
 	fi
 
 	# convert shutdown type to option flags
 	shutdown_command="";
-	if [ "$shutdown_type" == "old" ]; then
+	if [ "$shutdown_type" = "old" ]; then
 	   shutdown_command="--oldStype"
 	fi
 
@@ -134,7 +134,7 @@ multinit_main()
 	# show what we got and what we expected for diagnostic purposes
 	echo "actual   = |$actual_result|"
 	echo "expected = |$expected_result|"
-	test  "$actual_result" == "$expected_result" 
+	test  "$actual_result" = "$expected_result" 
 	html_msg $? 0 "$testname"
     fi
   done
