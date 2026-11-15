$NetBSD$

* Add Free- and NetBSD support

--- ts/components/SearchInput.dom.tsx.orig	2026-10-28 21:49:13.000000000 +0000
+++ ts/components/SearchInput.dom.tsx
@@ -60,7 +60,7 @@ export const SearchInput = forwardRef<HT
         const { ctrlKey, key } = event;
 
         // On Linux, this key combo selects all text.
-        if (window.platform === 'linux' && ctrlKey && key === '/') {
+        if ((window.platform === 'linux' || window.platform === 'freebsd' || window.platform === 'netbsd') && ctrlKey && key === '/') {
           event.preventDefault();
           event.stopPropagation();
         } else if (key === 'Escape' && onClear) {
