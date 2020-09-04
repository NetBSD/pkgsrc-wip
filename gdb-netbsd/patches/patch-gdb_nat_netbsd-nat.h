$NetBSD$

--- gdb/nat/netbsd-nat.h.orig	2020-09-04 21:53:29.055935316 +0000
+++ gdb/nat/netbsd-nat.h
@@ -0,0 +1,46 @@
+/* Internal interfaces for the NetBSD code.
+
+   Copyright (C) 2006-2020 Free Software Foundation, Inc.
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
+#ifndef NAT_NETBSD_NAT_H
+#define NAT_NETBSD_NAT_H
+
+#include "gdbsupport/function-view.h"
+
+#include <unistd.h>
+
+namespace netbsd_nat
+{
+
+extern char *pid_to_exec_file (pid_t pid);
+
+extern bool thread_alive (ptid_t ptid);
+
+extern const char *thread_name (ptid_t ptid);
+
+extern void for_each_thread (pid_t pid,
+			     gdb::function_view<void (ptid_t)> callback);
+
+extern void enable_proc_events (pid_t pid);
+
+extern int qxfer_siginfo (pid_t pid, const char *annex, unsigned char *readbuf,
+			  unsigned const char *writebuf, CORE_ADDR offset,
+			  int len);
+}
+
+#endif
