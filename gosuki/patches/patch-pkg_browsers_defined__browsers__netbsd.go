$NetBSD$

Add NetBSD support (generated file).

--- pkg/browsers/defined_browsers_netbsd.go.orig	2025-12-20 21:23:22.504348696 +0000
+++ pkg/browsers/defined_browsers_netbsd.go
@@ -0,0 +1,57 @@
+// Code generated DO NOT EDIT.
+
+//go:build netbsd
+package browsers
+
+var DefinedBrowsers = []BrowserDef{
+	{
+		"chrome",
+		1,
+		"~/.config/google-chrome",
+		"",
+		"",
+	},
+	{
+		"chromium",
+		1,
+		"~/.config/chromium",
+		"",
+		"",
+	},
+	{
+		"firefox",
+		0,
+		"~/.mozilla/firefox",
+		"",
+		"",
+	},
+	{
+		"librewolf",
+		0,
+		"~/.librewolf",
+		"",
+		"",
+	},
+	{
+		"qutebrowser",
+		2,
+		"~/.config/qutebrowser",
+		"",
+		"",
+	},
+}
+
+func Defined(family BrowserFamily) map[string]BrowserDef {
+	result := map[string]BrowserDef{}
+	for _, bd := range DefinedBrowsers {
+		if bd.Family == family {
+			result[bd.Flavour] = bd
+		}
+	}
+
+	return result
+}
+
+func AddBrowserDef(b BrowserDef) {
+	DefinedBrowsers = append(DefinedBrowsers, b)
+}
