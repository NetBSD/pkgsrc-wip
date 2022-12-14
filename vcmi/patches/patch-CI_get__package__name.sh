$NetBSD$

Fix unportable test(1) operator.

--- CI/get_package_name.sh.orig	2022-09-11 10:42:21.000000000 +0000
+++ CI/get_package_name.sh
@@ -27,7 +27,7 @@ fi
 
 VCMI_PACKAGE_FILE_NAME="${TMP_JOBID}-vcmi"
 VCMI_PACKAGE_NAME_SUFFIX=""
-if [ -z "$TMP_PRID" ] || [ "$TMP_PRID" == "false" ];
+if [ -z "$TMP_PRID" ] || [ "$TMP_PRID" = "false" ];
 then
 	branch_name=$(echo "$TMP_BRANCH" | sed 's/[^[:alnum:]]\+/_/g')
 	VCMI_PACKAGE_FILE_NAME="${VCMI_PACKAGE_FILE_NAME}-branch-${branch_name}-${TMP_COMMIT}"
