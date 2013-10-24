$NetBSD: patch-stepmake_stepmake_po-targets.make,v 1.1 2013/10/24 19:11:33 thomasklausner Exp $

Fix build with gmake-4.0.
"recipes commence before first target"

--- stepmake/stepmake/po-targets.make.orig	2013-10-06 15:16:08.000000000 +0000
+++ stepmake/stepmake/po-targets.make
@@ -37,10 +37,10 @@ ifneq ($(strip $(ALL_PO_SOURCES)),)
 	 --keyword=_ --keyword=_f --keyword=_i \
 	 $(XGETTEXT_FLAGS) $(ALL_PO_SOURCES)
 endif
-endif
 	sed -i '1,2d' $(po-outdir)/$(package).po
 	sed -i -e 's/^\# This file is distributed.*/$(sed-header)/' $(po-outdir)/$(package).po
 	sed -i -e 's/^\"Content-Type: text\/plain.*/$(sed-content)/' $(po-outdir)/$(package).po
+endif
 
 
 po-update: po
