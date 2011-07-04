$NetBSD: patch-generate-version.sh,v 1.1 2011/07/04 17:46:40 asau Exp $

Bypass some checks.

--- generate-version.sh.orig	2011-07-04 10:19:53.000000000 +0000
+++ generate-version.sh
@@ -32,7 +32,7 @@ generate_version() {
         version_root="$SBCL_BUILDING_RELEASE_FROM"
     fi
     version_base=`git rev-parse "$version_root"`
-    version_tag=`git describe --tags --match="sbcl*" --abbrev=0 $version_base`
+    version_tag=`git describe --always --tags --match="sbcl*" --abbrev=0 $version_base`
     version_release=`echo $version_tag | sed -e 's/sbcl[_-]//' | sed -e 's/_/\./g'`
     # Using wc -l instead of --count argument to rev-list because
     # pre-1.7.2 Gits are still common out in the wilderness.
