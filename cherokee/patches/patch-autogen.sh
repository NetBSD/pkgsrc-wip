$NetBSD$

--- autogen.sh.orig	2014-10-17 17:20:36.000000000 +0000
+++ autogen.sh
@@ -29,14 +29,8 @@ test -z "$AUTOMAKE" && AUTOMAKE=automake
 test -z "$ACLOCAL" && ACLOCAL=aclocal
 test -z "$AUTOCONF" && AUTOCONF=autoconf
 test -z "$AUTOHEADER" && AUTOHEADER=autoheader
-
-if hash glibtool 2>&-; then
- test -z "$LIBTOOL" && LIBTOOL=glibtool
- test -z "$LIBTOOLIZE" && LIBTOOLIZE=glibtoolize
-else
- test -z "$LIBTOOL" && LIBTOOL=libtool
- test -z "$LIBTOOLIZE" && LIBTOOLIZE=libtoolize
-fi
+test -z "$LIBTOOL" && LIBTOOL=libtool
+test -z "$LIBTOOLIZE" && LIBTOOLIZE=libtoolize
 
 ($AUTOCONF --version) < /dev/null > /dev/null 2>&1 || {
     echo
@@ -64,56 +58,56 @@ fi
     DIE=1
 }
 
-echo -n "Checking for python2 binary ..."
-	
-hash python2 2>&- || {
-
-	echo " NOT found."
-
-	PYTHON2EXISTS=false
-	
-	for python2 in python2.7 python2.6 python2.5 python2.4; do
-		echo -n "  Checking for $python2 ..."
-		hash $python2 2>&-
-		STATUS=$?
-
-		if [ $STATUS -eq 0 ]
-		then
-			echo " found. :)"
-			PYTHON2EXISTS=true
-			PYTHON2BIN=$(which $python2)
-			
-			prompt=$(echo -n "Create symlink from $PYTHON2BIN to /usr/local/bin/python2? [Yes|no] ")
-			
-			read -p "$prompt" CREATESYMLINK
-			CREATESYMLINK=${CREATESYMLINK:-no}
-
-			if [ "$CREATESYMLINK" = "Yes" ] || [ "$CREATESYMLINK" = "yes" ] || [ "$CREATESYMLINK" = "Y" ] || [ "$CREATESYMLINK" = "y" ]
-			then
-				echo "Symlinking $PYTHON2BIN to /usr/local/bin/python2"
-				ln -s $PYTHON2BIN /usr/local/bin/python2
-			else
-				echo ""
-				echo "Exiting:"
-				echo "  A python2 symlink to a Python 2.x binary (e.g. $PYTHON2BIN) is required to continue."
-				echo "  Please use a Python installation script of your choice that will create the required"
-				echo "  symlink or manually create a symlink in a location accessible from your \$PATH environment"
-				echo "  variable and then rerun this script."
-				DIE=1
-			fi
-			break
-		else
-			echo " NOT found."
-		fi
-	done
-
-	if [ "$PYTHON2EXISTS" = "false" ]
-	then
-		echo "No compatible Python 2.x binary found. Exiting."
-		DIE=1
-	fi
-}
-echo ""
+#echo -n "Checking for python2 binary ..."
+#	
+#command -v python2 2>&- || {
+#
+#	echo " NOT found."
+#
+#	PYTHON2EXISTS=false
+#	
+#	for python2 in python2.7 python2.6 python2.5 python2.4; do
+#		echo -n "  Checking for $python2 ..."
+#		command -v $python2 2>&-
+#		STATUS=$?
+#
+#		if [ $STATUS -eq 0 ]
+#		then
+#			echo " found. :)"
+#			PYTHON2EXISTS=true
+#			PYTHON2BIN=$(which $python2)
+#			
+#			prompt=$(echo -n "Create symlink from $PYTHON2BIN to /usr/local/bin/python2? [Yes|no] ")
+#			
+#			read -p "$prompt" CREATESYMLINK
+#			CREATESYMLINK=${CREATESYMLINK:-no}
+#
+#			if [ "$CREATESYMLINK" = "Yes" ] || [ "$CREATESYMLINK" = "yes" ] || [ "$CREATESYMLINK" = "Y" ] || [ "$CREATESYMLINK" = "y" ]
+#			then
+#				echo "Symlinking $PYTHON2BIN to /usr/local/bin/python2"
+#				ln -s $PYTHON2BIN /usr/local/bin/python2
+#			else
+#				echo ""
+#				echo "Exiting:"
+#				echo "  A python2 symlink to a Python 2.x binary (e.g. $PYTHON2BIN) is required to continue."
+#				echo "  Please use a Python installation script of your choice that will create the required"
+#				echo "  symlink or manually create a symlink in a location accessible from your \$PATH environment"
+#				echo "  variable and then rerun this script."
+#				DIE=1
+#			fi
+#			break
+#		else
+#			echo " NOT found."
+#		fi
+#	done
+#
+#	if [ "$PYTHON2EXISTS" = "false" ]
+#	then
+#		echo "No compatible Python 2.x binary found. Exiting."
+#		DIE=1
+#	fi
+#}
+#echo ""
 
 if test "$DIE" -eq 1; then
     exit 1
