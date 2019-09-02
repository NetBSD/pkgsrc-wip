$NetBSD$

--- gdb/user-regs.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/user-regs.c
@@ -41,7 +41,7 @@
 struct user_reg
 {
   const char *name;
-  struct value *(*read) (struct frame_info * frame, const void *baton);
+  struct value *(*xread) (struct frame_info * frame, const void *baton);
   const void *baton;
   struct user_reg *next;
 };
@@ -60,7 +60,7 @@ struct gdb_user_regs
 
 static void
 append_user_reg (struct gdb_user_regs *regs, const char *name,
-		 user_reg_read_ftype *read, const void *baton,
+		 user_reg_read_ftype *xread, const void *baton,
 		 struct user_reg *reg)
 {
   /* The caller is responsible for allocating memory needed to store
@@ -68,7 +68,7 @@ append_user_reg (struct gdb_user_regs *r
      register list stored in the common heap or a specific obstack.  */
   gdb_assert (reg != NULL);
   reg->name = name;
-  reg->read = read;
+  reg->xread = xread;
   reg->baton = baton;
   reg->next = NULL;
   (*regs->last) = reg;
@@ -82,10 +82,10 @@ static struct gdb_user_regs builtin_user
 };
 
 void
-user_reg_add_builtin (const char *name, user_reg_read_ftype *read,
+user_reg_add_builtin (const char *name, user_reg_read_ftype *xread,
 		      const void *baton)
 {
-  append_user_reg (&builtin_user_regs, name, read, baton,
+  append_user_reg (&builtin_user_regs, name, xread, baton,
 		   XNEW (struct user_reg));
 }
 
@@ -103,14 +103,14 @@ user_regs_init (struct gdbarch *gdbarch)
 
   regs->last = &regs->first;
   for (reg = builtin_user_regs.first; reg != NULL; reg = reg->next)
-    append_user_reg (regs, reg->name, reg->read, reg->baton,
+    append_user_reg (regs, reg->name, reg->xread, reg->baton,
 		     GDBARCH_OBSTACK_ZALLOC (gdbarch, struct user_reg));
   return regs;
 }
 
 void
 user_reg_add (struct gdbarch *gdbarch, const char *name,
-	      user_reg_read_ftype *read, const void *baton)
+	      user_reg_read_ftype *xread, const void *baton)
 {
   struct gdb_user_regs *regs
     = (struct gdb_user_regs *) gdbarch_data (gdbarch, user_regs_data);
@@ -122,7 +122,7 @@ user_reg_add (struct gdbarch *gdbarch, c
       regs = (struct gdb_user_regs *) user_regs_init (gdbarch);
       deprecated_set_gdbarch_data (gdbarch, user_regs_data, regs);
     }
-  append_user_reg (regs, name, read, baton,
+  append_user_reg (regs, name, xread, baton,
 		   GDBARCH_OBSTACK_ZALLOC (gdbarch, struct user_reg));
 }
 
@@ -214,7 +214,7 @@ value_of_user_reg (int regnum, struct fr
   struct user_reg *reg = usernum_to_user_reg (gdbarch, regnum - maxregs);
 
   gdb_assert (reg != NULL);
-  return reg->read (frame, reg->baton);
+  return reg->xread (frame, reg->baton);
 }
 
 static void
