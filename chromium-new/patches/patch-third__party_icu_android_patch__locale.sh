$NetBSD$

--- third_party/icu/android/patch_locale.sh.orig	2017-02-02 02:03:49.000000000 +0000
+++ third_party/icu/android/patch_locale.sh
@@ -26,7 +26,7 @@ cd source/data
 for i in curr/*.txt
 do
   locale=$(basename $i .txt)
-  [ $locale == 'supplementalData' ] && continue;
+  [ $locale = 'supplementalData' ] && continue;
   echo "Overwriting $i for $locale"
   sed -n -r -i \
     '1, /^'${locale}'\{$/ p
