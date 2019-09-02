$NetBSD$

--- gdb/gdbserver/netbsd-low.h.orig	2019-09-02 20:02:23.503235772 +0000
+++ gdb/gdbserver/netbsd-low.h
@@ -0,0 +1,61 @@
+/* Copyright (C) 2010-2019 Free Software Foundation, Inc.
+
+   This file is part of GDB.
+
+   This program is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 3 of the License, or
+   (at your option) any later version.
+
+   This program is distributed in the hope that it will be useful,
+   but WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
+
+   You should have received a copy of the GNU General Public License
+   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
+
+#ifndef GDBSERVER_NETBSD_LOW_H
+#define GDBSERVER_NETBSD_LOW_H
+
+struct regcache;
+struct target_desc;
+
+/*  Some information relative to a given register set.   */
+
+struct netbsd_regset_info
+{
+  /* The ptrace request needed to get/set registers of this set.  */
+  int get_request, set_request;
+  /* The size of the register set.  */
+  int size;
+  /* Fill the buffer BUF from the contents of the given REGCACHE.  */
+  void (*fill_function) (struct regcache *regcache, char *buf);
+  /* Store the register value in BUF in the given REGCACHE.  */
+  void (*store_function) (struct regcache *regcache, const char *buf);
+};
+
+/* A list of regsets for the target being debugged, terminated by an entry
+   where the size is negative.
+
+   This list should be created by the target-specific code.  */
+
+extern struct netbsd_regset_info netbsd_target_regsets[];
+
+/* The target-specific operations for NetBSD support.  */
+
+struct netbsd_target_ops
+{
+  /* Architecture-specific setup.  */
+  void (*arch_setup) (void);
+
+  /* Hook to support target specific qSupported.  */
+  void (*process_qsupported) (char **, int count);
+};
+
+extern struct netbsd_target_ops the_low_target;
+
+/* XXX: multilib */
+extern const struct target_desc *netbsd_tdesc;
+
+#endif /* GDBSERVER_NETBSD_LOW_H */
