$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/spec/api-content-tracing-spec.ts.orig	2024-12-05 00:03:24.000000000 +0000
+++ electron/spec/api-content-tracing-spec.ts
@@ -9,7 +9,8 @@ import { setTimeout } from 'node:timers/
 import { ifdescribe } from './lib/spec-helpers';
 
 // FIXME: The tests are skipped on linux arm/arm64
-ifdescribe(!(['arm', 'arm64'].includes(process.arch)) || (process.platform !== 'linux'))('contentTracing', () => {
+ifdescribe(!(['arm', 'arm64'].includes(process.arch)) || (process.platform !== 'linux' && process.platform !== 'freebsd' &&
+                                                                                                  process.platform !== 'openbsd' && process.platform !== 'netbsd'))('contentTracing', () => {
   const record = async (options: TraceConfig | TraceCategoriesAndOptions, outputFilePath: string | undefined, recordTimeInMilliseconds = 1e1) => {
     await app.whenReady();
 
