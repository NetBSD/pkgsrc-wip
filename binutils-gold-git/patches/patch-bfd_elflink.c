$NetBSD$

--- bfd/elflink.c.orig	2017-10-29 23:10:16.380166403 +0000
+++ bfd/elflink.c
@@ -5337,7 +5337,7 @@ _bfd_elf_archive_symbol_lookup (bfd *abf
   len = strlen (name);
   copy = (char *) bfd_alloc (abfd, len);
   if (copy == NULL)
-    return (struct elf_link_hash_entry *) 0 - 1;
+    return (struct elf_link_hash_entry *) -1;
 
   first = p - name + 1;
   memcpy (copy, name, first);
@@ -5435,7 +5435,7 @@ elf_link_add_archive_symbols (bfd *abfd,
 	    }
 
 	  h = archive_symbol_lookup (abfd, info, symdef->name);
-	  if (h == (struct elf_link_hash_entry *) 0 - 1)
+	  if (h == (struct elf_link_hash_entry *) -1)
 	    goto error_return;
 
 	  if (h == NULL)
