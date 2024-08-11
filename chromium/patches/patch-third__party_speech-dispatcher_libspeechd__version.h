$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/speech-dispatcher/libspeechd_version.h.orig	2024-08-01 14:09:01.033823374 +0000
+++ third_party/speech-dispatcher/libspeechd_version.h
@@ -0,0 +1,29 @@
+/*
+ * libspeechd_version.h - Shared library for easy access to Speech Dispatcher functions (header)
+ *
+ * Copyright (C) 2001, 2002, 2003, 2004 Brailcom, o.p.s.
+ *
+ * This is free software; you can redistribute it and/or modify it
+ * under the terms of the GNU Lesser General Public License as published by
+ * the Free Software Foundation; either version 2.1, or (at your option)
+ * any later version.
+ *
+ * This software is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+ * Lesser General Public License for more details.
+ *
+ * You should have received a copy of the GNU Lesser General Public License
+ * along with this program.  If not, see <https://www.gnu.org/licenses/>.
+ *
+ * Id: patch-third_party_speech-dispatcher_libspeechd_version_h,v 1.4 2024/03/22 13:10:56 robert
+ */
+
+#ifndef _LIBSPEECHD_VERSION_H
+#define _LIBSPEECHD_VERSION_H
+
+#define LIBSPEECHD_MAJOR_VERSION 0
+#define LIBSPEECHD_MINOR_VERSION 11
+#define LIBSPEECHD_MICRO_VERSION 5
+
+#endif /* ifndef _LIBSPEECHD_VERSION_H */
