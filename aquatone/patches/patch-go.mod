$NetBSD$

--- go.mod.orig	2022-10-09 00:01:01.348800404 +0000
+++ go.mod
@@ -0,0 +1,27 @@
+module github.com/michenriksen/aquatone
+
+go 1.18
+
+require (
+	github.com/PuerkitoBio/goquery v1.5.0
+	github.com/asaskevich/EventBus v0.0.0-20180315140547-d46933a94f05
+	github.com/fatih/color v1.7.0
+	github.com/google/uuid v1.1.1
+	github.com/lair-framework/go-nmap v0.0.0-20181105160706-3b9bafddefee
+	github.com/parnurzeal/gorequest v0.2.15
+	github.com/pmezard/go-difflib v1.0.0
+	github.com/remeh/sizedwaitgroup v1.0.0
+	golang.org/x/net v0.0.0-20190424112056-4829fb13d2c6
+	mvdan.cc/xurls/v2 v2.4.0
+)
+
+require (
+	github.com/andybalholm/cascadia v1.0.0 // indirect
+	github.com/elazarl/goproxy v0.0.0-20220901064549-fbd10ff4f5a1 // indirect
+	github.com/mattn/go-colorable v0.0.9 // indirect
+	github.com/mattn/go-isatty v0.0.7 // indirect
+	github.com/moul/http2curl v1.0.0 // indirect
+	github.com/pkg/errors v0.8.1 // indirect
+	github.com/smartystreets/goconvey v1.7.2 // indirect
+	golang.org/x/sys v0.0.0-20190426135247-a129542de9ae // indirect
+)
