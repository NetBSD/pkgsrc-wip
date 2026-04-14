$NetBSD: patch-mk_make-install.sh,v 1.1 2024/01/17 23:43:02 gdt Exp $

Put the default config in EGDIR so we can use CONF_FILES

--- mk/make-install.sh.orig	2026-04-08 15:18:19.000000000 +0000
+++ mk/make-install.sh
@@ -66,12 +66,13 @@ __mkdir "$VAL_SYSCONFDIR"
 __mkdir "$VAL_MANDIR/man1"
 __mkdir "$VAL_MANDIR/man7"
 __mkdir "$VAL_SYSCONFDIR"
+__mkdir "${VAL_PREFIX}/share/examples/${PKGBASE}"
 
 __copyfile y 0755 "$OBJDIR"/"$VAL_UAGENT" "$VAL_BINDIR"/"$VAL_UAGENT"
 __copyfile n 0444 "$OBJDIR"/uman.1 "$VAL_MANDIR"/man1/"$VAL_UAGENT".1
 __copyfile n 0444 "$OBJDIR"/uman-config.7 "$VAL_MANDIR"/man7/"$VAL_UAGENT"-config.7
 if [ -f "$DESTDIR$VAL_SYSCONFDIR/$VAL_SYSCONFRC" ]; then :; else
-	__copyfile n 0444 "$OBJDIR"/urc.rc "$VAL_SYSCONFDIR/$VAL_SYSCONFRC"
+	__copyfile 0444 "${OBJDIR}"/urc.rc "${VAL_PREFIX}/share/examples/${PKGBASE}/${VAL_SYSCONFRC}"
 fi
 
 if [ "$OPT_DOTLOCK" != 0 ]; then
