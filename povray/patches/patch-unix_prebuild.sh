$NetBSD$

Adapt configuration directory for pkgsrc, and avoid touching $HOME during packaging.

--- unix/prebuild.sh.orig	2021-07-08 09:56:01.000000000 +0000
+++ unix/prebuild.sh
@@ -561,7 +561,7 @@ case "$1" in
 # Directories.
 povlibdir = @datadir@/@PACKAGE@-@VERSION_BASE@
 povdocdir = @datadir@/doc/@PACKAGE@-@VERSION_BASE@
-povconfdir = @sysconfdir@/@PACKAGE@/@VERSION_BASE@
+povconfdir = \$(PREFIX)/share/examples/povray
 povuser = \$(HOME)/.@PACKAGE@
 povconfuser = \$(povuser)/@VERSION_BASE@
 povinstall = \$(top_builddir)/install.log
@@ -640,19 +640,6 @@ install-data-local:
 	for f in \$\$filelist ; do \\
 	  \$(INSTALL_DATA) \$(top_srcdir)/doc/\$\$f \$(DESTDIR)\$(povdocdir)/\$\$f && echo "\$(DESTDIR)\$(povdocdir)/\$\$f" >> \$(povinstall); \\
 	done
-	@echo "Creating user directories..."; \\
-	for p in \$(povuser) \$(povconfuser) ; do \\
-	  \$(mkdir_p) \$\$p && chown \$(povowner) \$\$p && chgrp \$(povgroup) \$\$p && printf "%s\\n" "\$\$p" "\`cat \$(povinstall)\`" > \$(povinstall); \\
-	done
-	@echo "Copying user configuration and INI files..."; \\
-	for f in povray.conf povray.ini ; do \\
-	  if test -f \$(povconfuser)/\$\$f; then \\
-	    echo "Creating backup of \$(povconfuser)/\$\$f"; \\
-	    mv -f \$(povconfuser)/\$\$f \$(povconfuser)/\$\$f.bak; \\
-	  fi; \\
-	done; \\
-	\$(INSTALL_DATA) \$(top_srcdir)/povray.conf \$(povconfuser)/povray.conf && chown \$(povowner) \$(povconfuser)/povray.conf && chgrp \$(povgroup) \$(povconfuser)/povray.conf  && echo "\$(povconfuser)/povray.conf" >> \$(povinstall); \\
-	\$(INSTALL_DATA) \$(top_builddir)/povray.ini \$(povconfuser)/povray.ini && chown \$(povowner) \$(povconfuser)/povray.ini && chgrp \$(povgroup) \$(povconfuser)/povray.ini  && echo "\$(povconfuser)/povray.ini" >> \$(povinstall)
 
 # Remove data, config, and empty folders for 'make uninstall'.
 # Use 'hook' instead of 'local' so as to properly remove *empty* folders (e.g. scripts).
