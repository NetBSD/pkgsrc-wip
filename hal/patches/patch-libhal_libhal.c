$NetBSD$

--- libhal/libhal.c.orig	2009-08-24 12:42:30.000000000 +0000
+++ libhal/libhal.c
@@ -4121,8 +4121,10 @@ out:
 static void
 libhal_changeset_append (LibHalChangeSet *changeset, LibHalChangeSetElement *elem)
 {
+#if !defined(__SUNPRO_C)
 	LIBHAL_CHECK_PARAM_VALID(changeset, "*changeset", (void) NULL );
 	LIBHAL_CHECK_PARAM_VALID(elem, "*elem", (void) NULL);
+#endif
 
 	if (changeset->head == NULL) {
 		changeset->head = elem;
