$NetBSD: patch-aclocal.m4,v 1.1 2012/03/04 04:37:13 phonohawk Exp $

Hunk #1, #2:
  For systems having as(1) that doesn't recognise .ident
  directives. (Already merged to the upstream)

Hunk #3:
  Don't try to find ghc-pkg when we're bootstrapping from HC.

Hunk #4:
  Don't try to build ghc-pwd when we're bootstrapping from HC.


--- aclocal.m4.orig	2012-02-01 18:10:32.000000000 +0000
+++ aclocal.m4
@@ -245,6 +245,16 @@ AC_DEFUN([FPTOOLS_SET_HASKELL_PLATFORM_V
         [HaskellHaveSubsectionsViaSymbols=False
          AC_MSG_RESULT(no)])
 
+    dnl ** check for .ident assembler directive
+
+    AC_MSG_CHECKING(whether your assembler supports .ident directive)
+    AC_COMPILE_IFELSE(
+        [AC_LANG_SOURCE([__asm__ (".ident \"GHC x.y.z\"");])],
+        [AC_MSG_RESULT(yes)
+         HaskellHaveIdentDirective=True],
+        [AC_MSG_RESULT(no)
+         HaskellHaveIdentDirective=False])
+
     dnl *** check for GNU non-executable stack note support (ELF only)
     dnl     (.section .note.GNU-stack,"",@progbits)
 
@@ -277,6 +287,7 @@ AC_DEFUN([FPTOOLS_SET_HASKELL_PLATFORM_V
     AC_SUBST(HaskellTargetArch)
     AC_SUBST(HaskellTargetOs)
     AC_SUBST(HaskellHaveSubsectionsViaSymbols)
+    AC_SUBST(HaskellHaveIdentDirective)
     AC_SUBST(HaskellHaveGnuNonexecStack)
 ])
 
@@ -1415,22 +1426,28 @@ AC_SUBST([FopCmd])
 # Try to find a ghc-pkg matching the ghc mentioned in the environment variable
 # WithGhc. Sets the output variable GhcPkgCmd.
 AC_DEFUN([FP_PROG_GHC_PKG],
-[AC_CACHE_CHECK([for ghc-pkg matching $WithGhc], fp_cv_matching_ghc_pkg,
 [
-# If we are told to use ghc-stage2, then we're using an in-tree
-# compiler. In this case, we just want ghc-pkg, not ghc-pkg-stage2,
-# so we sed off -stage[0-9]$. However, if we are told to use
-# ghc-6.12.1 then we want to use ghc-pkg-6.12.1, so we keep any
-# other suffix.
-fp_ghc_pkg_guess=`echo $WithGhc | sed -e 's/-stage@<:@0-9@:>@$//' -e 's,ghc\(@<:@^/\\@:>@*\)$,ghc-pkg\1,'`
-if "$fp_ghc_pkg_guess" list > /dev/null 2>&1; then
-  fp_cv_matching_ghc_pkg=$fp_ghc_pkg_guess
-else
-  AC_MSG_ERROR([Cannot find matching ghc-pkg])
-fi])
-GhcPkgCmd=$fp_cv_matching_ghc_pkg
-AC_SUBST([GhcPkgCmd])
-])# FP_PROG_GHC_PKG
+    if test "$BootingFromHc" = "YES"; then
+        GhcPkgCmd=
+    else
+        AC_CACHE_CHECK([for ghc-pkg matching $WithGhc], fp_cv_matching_ghc_pkg,
+        [
+            # If we are told to use ghc-stage2, then we're using an in-tree
+            # compiler. In this case, we just want ghc-pkg, not ghc-pkg-stage2,
+            # so we sed off -stage[0-9]$. However, if we are told to use
+            # ghc-6.12.1 then we want to use ghc-pkg-6.12.1, so we keep any
+            # other suffix.
+            fp_ghc_pkg_guess=`echo "$WithGhc" | sed -e 's/-stage@<:@0-9@:>@$//' -e 's,ghc\(@<:@^/\\@:>@*\)$,ghc-pkg\1,'`
+            if "$fp_ghc_pkg_guess" list > /dev/null 2>&1; then
+                fp_cv_matching_ghc_pkg="$fp_ghc_pkg_guess"
+            else
+                AC_MSG_ERROR([Cannot find matching ghc-pkg])
+            fi
+        ])
+        GhcPkgCmd="$fp_cv_matching_ghc_pkg"
+    fi
+    AC_SUBST([GhcPkgCmd])
+])
 
 
 # FP_GCC_EXTRA_FLAGS
@@ -1729,18 +1746,28 @@ fi
 # --------------------------------------------------------------
 
 AC_DEFUN([FP_INTREE_GHC_PWD],[
-AC_MSG_NOTICE(Building in-tree ghc-pwd)
     dnl This would be
     dnl     make -C utils/ghc-pwd clean && make -C utils/ghc-pwd
     dnl except we don't want to have to know what make is called. Sigh.
     rm -rf utils/ghc-pwd/dist-boot
     mkdir  utils/ghc-pwd/dist-boot
-    if ! "$WithGhc" -v0 -no-user-package-conf -hidir utils/ghc-pwd/dist-boot -odir utils/ghc-pwd/dist-boot -stubdir utils/ghc-pwd/dist-boot --make utils/ghc-pwd/Main.hs -o utils/ghc-pwd/dist-boot/ghc-pwd
-    then
-        AC_MSG_ERROR([Building ghc-pwd failed])
-    fi
 
-    GHC_PWD=utils/ghc-pwd/dist-boot/ghc-pwd
+    if test "$BootingFromHc" = "YES"; then
+        AC_MSG_NOTICE([Using pwd instead of in-tree ghc-pwd])
+        GHC_PWD=pwd
+    else
+        AC_MSG_NOTICE(Building in-tree ghc-pwd)
+        if "$WithGhc" -v0 -no-user-package-conf \
+                      -hidir utils/ghc-pwd/dist-boot \
+                      -odir utils/ghc-pwd/dist-boot \
+                      -stubdir utils/ghc-pwd/dist-boot \
+                      --make utils/ghc-pwd/Main.hs \
+                      -o utils/ghc-pwd/dist-boot/ghc-pwd; then
+            GHC_PWD=utils/ghc-pwd/dist-boot/ghc-pwd
+        else
+            AC_MSG_ERROR([Building ghc-pwd failed])
+        fi
+    fi
 ])
 
 AC_DEFUN([FP_BINDIST_GHC_PWD],[
