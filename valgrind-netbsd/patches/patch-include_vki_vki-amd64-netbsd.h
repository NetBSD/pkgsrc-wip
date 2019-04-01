$NetBSD$

--- include/vki/vki-amd64-netbsd.h.orig	2019-03-27 08:10:06.403900938 +0000
+++ include/vki/vki-amd64-netbsd.h
@@ -0,0 +1,37 @@
+/*
+   This file is part of Valgrind, a dynamic binary instrumentation
+   framework.
+
+   Copyright (C) 2000-2005 Julian Seward 
+      jseward@acm.org
+
+   This program is free software; you can redistribute it and/or
+   modify it under the terms of the GNU General Public License as
+   published by the Free Software Foundation; either version 2 of the
+   License, or (at your option) any later version.
+
+   This program is distributed in the hope that it will be useful, but
+   WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+   General Public License for more details.
+
+   You should have received a copy of the GNU General Public License
+   along with this program; if not, write to the Free Software
+   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
+   02111-1307, USA.
+
+   The GNU General Public License is contained in the file COPYING.
+*/
+
+#ifndef __VKI_AMD64_NETBSD_H
+#define __VKI_AMD64_NETBSD_H
+
+/* PAGE_SHIFT determines the page size. */
+#define VKI_PAGE_SHIFT	12
+#define VKI_PAGE_SIZE	(1UL << VKI_PAGE_SHIFT)
+#define VKI_MAX_PAGE_SHIFT      VKI_PAGE_SHIFT
+#define VKI_MAX_PAGE_SIZE       VKI_PAGE_SIZE
+
+#define	VKI_MINSIGSTKSZ	8192
+
+#endif /* __VKI_AMD64_NETBSD_H */
