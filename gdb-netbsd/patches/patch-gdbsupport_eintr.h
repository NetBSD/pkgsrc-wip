$NetBSD$

--- gdbsupport/eintr.h.orig	2020-09-02 16:10:13.482874765 +0000
+++ gdbsupport/eintr.h
@@ -0,0 +1,41 @@
+/* Utility for handling interrupted syscalls by signals.
+
+   Copyright (C) 2020 Free Software Foundation, Inc.
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
+#ifndef GDBSUPPORT_EINTR_H
+#define GDBSUPPORT_EINTR_H
+
+#include <cerrno>
+
+namespace gdb
+{
+template <typename Fun, typename... Args>
+inline decltype (auto) handle_eintr (const Fun &F, const Args &... A)
+{
+  decltype (F (A...)) ret;
+  do
+    {
+      errno = 0;
+      ret = F (A...);
+    }
+  while (ret == -1 && errno == EINTR);
+  return ret;
+}
+}
+
+#endif /* GDBSUPPORT_EINTR_H */
