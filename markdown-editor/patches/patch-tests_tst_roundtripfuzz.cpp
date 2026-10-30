$NetBSD$

Qt 6.11 changed QChar::unicode() to return char16_t, which the integral
QString::arg overloads reject; widen to int explicitly so the fuzz test
compiles against newer Qt.

--- tests/tst_roundtripfuzz.cpp.orig
+++ tests/tst_roundtripfuzz.cpp
@@ -254,7 +254,7 @@
             QString esc;
             for (const QChar c : s) {
                 if (c.unicode() < 0x20 || c.unicode() > 0x7e)
-                    esc += QStringLiteral("\\u%1").arg(c.unicode(), 4, 16, QLatin1Char('0'));
+                    esc += QStringLiteral("\\u%1").arg(static_cast<int>(c.unicode()), 4, 16, QLatin1Char('0'));
                 else
                     esc += c;
             }
