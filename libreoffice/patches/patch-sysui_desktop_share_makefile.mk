$NetBSD: patch-sysui_desktop_share_makefile.mk,v 1.1 2012/09/02 14:27:56 ftigeot Exp $

Do not change icon names in .desktop files

--- sysui/desktop/share/makefile.mk.orig	2012-08-21 17:01:59.000000000 +0000
+++ sysui/desktop/share/makefile.mk
@@ -152,7 +152,7 @@ $(LAUNCHERFLAGFILE) : $(LAUNCHERDEPN)
     @@-$(MKDIRHIER) $(@:db).$(INPATH).$(@:f)
     @echo Creating desktop entries for $(@:f) ..
     @echo ---------------------------------
-    @$(PERL) brand.pl -p '$${{PRODUCTNAME}} $${{PRODUCTVERSION}}' -u $(UNIXWRAPPERNAME) --iconprefix '$${{UNIXBASISROOTNAME}}-' $< $(@:db).$(INPATH).$(@:f)
+    @$(PERL) brand.pl -p '$${{PRODUCTNAME}} $${{PRODUCTVERSION}}' -u $(UNIXWRAPPERNAME) $< $(@:db).$(INPATH).$(@:f)
     @$(PERL) translate.pl -p '$${{PRODUCTNAME}} $${{PRODUCTVERSION}}' -d $(@:db).$(INPATH).$(@:f) --ext "desktop" --key "Name" $(ULFDIR)$/launcher_name.ulf
     @$(PERL) translate.pl -p '$${{PRODUCTNAME}} $${{PRODUCTVERSION}}' -d $(@:db).$(INPATH).$(@:f) --ext "desktop" --key "Comment" $(ULFDIR)$/launcher_comment.ulf
     @$(PERL) translate.pl -p '$${{PRODUCTNAME}} $${{PRODUCTVERSION}}' -d $(@:db).$(INPATH).$(@:f) --ext "desktop" --key "GenericName" $(ULFDIR)$/launcher_genericname.ulf
