--- /dev/null	2011-02-04 21:03:13 +0000
+++ src/utf8misc.h	2011-02-04 20:49:38 +0000
@@ -0,0 +1,88 @@
+/***************************************************************************
+ *   Copyright (C) 2006 by Jocelyn Merand                                  *
+ *   joc.mer@gmail.com                                                     *
+ *                                                                         *
+ * THE BSD LICENSE
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ *
+ * - Redistributions of source code must retain the above copyright
+ * notice, this list of conditions and the following disclaimer.
+ *
+ * - Redistributions in binary form must reproduce the above copyright
+ * notice, this list of conditions and the following disclaimer in the
+ * documentation and/or other materials provided with the
+ * distribution.
+ *
+ * - Neither the name of the WiseGuys Internet B.V. nor the names of
+ * its contributors may be used to endorse or promote products derived
+ * from this software without specific prior written permission.
+ *
+ * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
+ * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
+ * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
+ * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
+ * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
+ * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
+ * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
+ * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
+ * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
+ * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
+ * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
+ ***************************************************************************/
+
+#ifndef _UTF8_MISC_H_
+#define _UTF8_MISC_H_
+
+/**
+ * These variables are used in character processing functions
+ * These have been added to manage utf-8 symbols, particularly escape chars
+ */
+#ifdef _UTF8_
+#define ESCAPE_MASK 0x80
+#define WEIGHT_MASK 0xF0
+#else
+#define ESCAPE_MASK 0xFF
+#define WEIGHT_MASK 0x00
+#endif
+
+
+/*
+ * Is used to jump to the next start of char
+ * of course it's only usefull when encoding is utf-8
+ * This function have been added by Jocelyn Merand to use libtextcat in OOo
+ */
+int nextcharstart(const char *str, int position);
+
+
+/*Copy the char in str to dest
+ * of course it's only usefull when encoding is utf8 and the symbol is encoded with more than 1 char
+ * return the number of char jumped
+ * This function have been added by Jocelyn Merand to use libtextcat in OOo
+ */
+int charcopy(const char *str, char *dest);
+
+
+/* checks if n-gram lex is a prefix of key and of length len
+* if _UTF8_ is defined, it uses escap characters and len is not realy the length of lex
+* in this case, len is the number of utf-8 char strlen("€") == 3 but len == 1
+*/
+int issame( char *lex, char *key, int len );
+
+
+/* Counts the number of characters
+* if _UTF8_ is defined, it uses escap characters and the result is not realy the length of str
+* in this case, the result is the number of utf-8 char strlen("€") == 3 but utfstrlen("€") == 1
+*/
+#ifdef __cplusplus
+extern "C" {
+#endif
+extern int utfstrlen(const char* str);
+#ifdef __cplusplus
+}
+#endif
+
+#endif
+
