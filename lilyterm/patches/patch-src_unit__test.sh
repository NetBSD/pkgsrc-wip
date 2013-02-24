$NetBSD: patch-src_unit__test.sh,v 1.1 2013/02/24 23:17:38 othyro Exp $

Fixes whereis flags and PRINTF.

--- src/unit_test.sh.orig	2013-02-08 08:06:31.000000000 +0000
+++ src/unit_test.sh
@@ -88,7 +88,7 @@ fi
 
 PKGCONFIG=`whereis "pkg-config" | tr -s ' ' '\n' | grep "bin/""pkg-config""$" | head -n 1`
 if [ -z "$PKGCONFIG" ]; then
-	$PRINTF "\033[1;31m** ERROR: Command pkg-config is not found!\033[0m\n"
+	$(PRINTF) "\033[1;31m** ERROR: Command pkg-config is not found!\033[0m\n"
 	exit 1
 fi
 
@@ -96,7 +96,7 @@ VTE=`$PKGCONFIG --exists 'vte' && $ECHO 
 if [ "$VTE" = "vte" ]; then
   GTK=`$PKGCONFIG --exists 'gtk+-2.0' && $ECHO 'gtk+-2.0'`
   if [ "$GTK" != "gtk+-2.0" ]; then
-    $PRINTF "\033[1;31m** ERROR: You need GTK+2 to run this unit test program!\033[0m\n"
+    $(PRINTF) "\033[1;31m** ERROR: You need GTK+2 to run this unit test program!\033[0m\n"
     exit 1
   fi
 else
@@ -104,11 +104,11 @@ else
   if [ "$VTE" = "vte-2.90" ]; then
     GTK=`$PKGCONFIG --exists 'gtk+-3.0' && $ECHO 'gtk+-3.0'`
     if [ "$GTK" != "gtk+-3.0" ]; then
-      $PRINTF "\033[1;31m** ERROR: You need GTK+3 to run this unit test program!\033[0m\n"
+      $(PRINTF) "\033[1;31m** ERROR: You need GTK+3 to run this unit test program!\033[0m\n"
       exit 1
     fi
   else
-    $PRINTF "\033[1;31m** ERROR: You need VTE to run this unit test program!\033[0m\n"
+    $(PRINTF) "\033[1;31m** ERROR: You need VTE to run this unit test program!\033[0m\n"
     exit 1
   fi
 fi
@@ -132,11 +132,11 @@ quit
 EOF
 
 if [ -f gdb.log ]; then
-	$PRINTF "\n\033[1;36mDeleting gdb.log...\033[0m\n\n"
+	$(PRINTF) "\n\033[1;36mDeleting gdb.log...\033[0m\n\n"
 	rm -f gdb.log
 fi
 if [ -f valgrind.log ]; then
-	$PRINTF "\n\033[1;36mDeleting valgrind.log...\033[0m\n\n"
+	$(PRINTF) "\n\033[1;36mDeleting valgrind.log...\033[0m\n\n"
 	rm -f valgrind.log
 fi
 
@@ -211,7 +211,7 @@ for DATA in `$CAT $LIB_LISTS | sed '/^\/
 					# sed -e 's/^.* \**\([^ ]*\)/\1/g': clear the declare, like "gchar **"
 					FUNC_NAME=`$ECHO $STR | sed -e 's/_SPACE_/ /g' | sed -e 's/^ *//g' | sed -e 's/ *$//g' | sed -e 's/^.* \**\([^ ]*\)/\1/g'`
 					# $ECHO "GOT FUNC_NAME = $FUNC_NAME"
-					$PRINTF "\033[1;36m$FUNC_NAME(): \033[1;33m** Createing unit_test.c...\033[0m\n"
+					$(PRINTF) "\033[1;36m$FUNC_NAME(): \033[1;33m** Createing unit_test.c...\033[0m\n"
 				fi
 				;;
 			1)
@@ -453,15 +453,15 @@ EOF
 }
 EOF
 	if [ $TEST_SCRIPT_ONLY -eq 0 ]; then
-		$PRINTF "\033[1;36m$FUNC_NAME(): \033[1;33m** Compiling unit_test.o...\033[0m\n"
+		$(PRINTF) "\033[1;36m$FUNC_NAME(): \033[1;33m** Compiling unit_test.o...\033[0m\n"
 		$CC $CFLAGS $INCLUDES -c unit_test.c `$PKGCONFIG --cflags $GTK $VTE` || exit 1
-		$PRINTF "\033[1;36m$FUNC_NAME(): \033[1;33m** Compiling unit_test...\033[0m\n"
+		$(PRINTF) "\033[1;36m$FUNC_NAME(): \033[1;33m** Compiling unit_test...\033[0m\n"
 		$CC $CFLAGS $INCLUDES -o unit_test $OBJ `$PKGCONFIG --cflags --libs $GTK $VTE` || exit 1
 		# if [ $? != 0 ]; then exit 1; fi
 
 		if [ $BUILD_ONLY -eq 0 ]; then
 			if [ $RUN_GDB -eq 1 ]; then
-				$PRINTF "\033[1;36m$FUNC_NAME(): \033[1;33m** Testing with $GDB...\033[0m\n"
+				$(PRINTF) "\033[1;36m$FUNC_NAME(): \033[1;33m** Testing with $GDB...\033[0m\n"
 				if [ -n "$SPECIFIC_FUNCTION" ]; then
 					$GDB -batch -x ./gdb_batch --args ./unit_test $GTK_DEBUG
 				else
@@ -472,14 +472,14 @@ EOF
 						$CAT /tmp/lilyterm_$FUNC_NAME.log >> gdb.log
 						$ECHO "" >> gdb.log
 					else
-						$PRINTF "\033[1;36m$FUNC_NAME(): \033[1;33m** Program exited normally. Clear log...\033[0m\n"
+						$(PRINTF) "\033[1;36m$FUNC_NAME(): \033[1;33m** Program exited normally. Clear log...\033[0m\n"
 					fi
 					rm /tmp/lilyterm_$FUNC_NAME.log
 				fi
 			fi
 
 			if [ $RUN_VALGRIND -eq 1 ]; then
-				$PRINTF "\033[1;36m$FUNC_NAME(): \033[1;33m** Testing with valgrind...\033[0m\n"
+				$(PRINTF) "\033[1;36m$FUNC_NAME(): \033[1;33m** Testing with valgrind...\033[0m\n"
 				$ECHO "Testing $FUNC_NAME() with $VALGRIND..." >> valgrind.log
 				$VALGRIND --leak-check=full ./unit_test >> valgrind.log 2>&1
 				$ECHO "" >> valgrind.log
