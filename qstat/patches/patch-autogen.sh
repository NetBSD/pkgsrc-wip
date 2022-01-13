--- autogen.sh~	2021-09-28 13:17:51.000000000 +0200
+++ autogen.sh	2022-01-13 17:59:48.399336996 +0100
@@ -13,51 +13,6 @@
 AUTOCONF_VERS="-2.61 261 -2.59 259 -2.58 258 -2.57 257 -2.54 254 -2.53 253"
 AUTOMAKE_VERS="-1.9 19 -1.8 18 -1.7 17 -1.6 16 -1.5 15"
 
-# We don't use variable here for remembering the type ... strings. Local 
-# variables are not that portable, but we fear namespace issues with our
-# includer.
-check_autoconf()
-{
-	echo "Checking autoconf version..."
-	for ver in $AUTOCONF_VERS; do
-		if test -x "`$WHICH $AUTOCONF$ver 2>/dev/null`"; then
-			AUTOCONF="`$WHICH $AUTOCONF$ver`"
-			AUTOHEADER="`$WHICH $AUTOHEADER$ver`"
-			AUTOM4TE="`$WHICH $AUTOM4TE$ver`"
-			break
-		fi
-	done
-}
-
-check_automake()
-{
-	echo "Checking automake version..."
-	for ver in $AUTOMAKE_VERS; do
-		if test -x "`$WHICH $AUTOMAKE$ver 2>/dev/null`"; then
-			AUTOMAKE="`$WHICH $AUTOMAKE$ver`"
-			ACLOCAL="`$WHICH $ACLOCAL$ver`"
-			break
-		fi
-	done
-
-	if test -n "$UNSERMAKE"; then 
-		AUTOMAKE="$UNSERMAKE"
-	fi
-}
-
-check_which()
-{
-	WHICH=""
-	for i in "type -p" "which" "type" ; do
-		T=`$i sh 2> /dev/null`
-		test -x "$T" && WHICH="$i" && break
-	done
-}
-
-check_which
-check_autoconf
-check_automake
-
 export AUTOCONF AUTOHEADER AUTOM4TE AUTOMAKE ACLOCAL
 
 set -e
