$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/devtools-frontend/src/front_end/entrypoints/main/MainImpl.ts.orig	2024-10-18 12:39:11.774633000 +0000
+++ third_party/devtools-frontend/src/front_end/entrypoints/main/MainImpl.ts
@@ -740,6 +740,8 @@ export class MainImpl {
 globalThis.Main = globalThis.Main || {};
 // @ts-ignore Exported for Tests.js
 globalThis.Main.Main = MainImpl;
+// @ts-ignore Exported for Electron
+globalThis.EUI = UI || {};
 
 export class ZoomActionDelegate implements UI.ActionRegistration.ActionDelegate {
   handleAction(_context: UI.Context.Context, actionId: string): boolean {
