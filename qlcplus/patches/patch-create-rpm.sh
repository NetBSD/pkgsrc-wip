$NetBSD$

--- create-rpm.sh.orig	2016-05-29 13:40:10.000000000 +0000
+++ create-rpm.sh
@@ -40,6 +40,6 @@ mv /tmp/qlcplus-$VERSION.tar.gz $RPMBUIL
 
 cd $RPMBUILD/SPECS
 QLCPLUS_VERSION=$VERSION rpmbuild -bb qlcplus.spec
-if [ $? == 0 ]; then
+if [ $? = 0 ]; then
 	echo Packages created in $RPMBUILD/RPMS
 fi
