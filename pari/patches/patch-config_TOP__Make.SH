$NetBSD$

--- config/TOP_Make.SH.orig	2014-07-30 13:38:47.000000000 +0000
+++ config/TOP_Make.SH
@@ -40,7 +40,6 @@ dft target::
 
 all::
 	@\$(MAKE) gp
-	@-cd doc && \$(MAKE) doc
 
 gp bench test-kernel test-all install cleanall cleanobj cleantest nsis install-bin install-doc install-docpdf install-nodata install-data install-lib-sta install-bin-sta dobench dyntest-all statest-all tune $top_test_extra $top_dotest_extra::
 	@dir=\`config/objdir\`; echo "Making \$@ in \$\$dir";\\
