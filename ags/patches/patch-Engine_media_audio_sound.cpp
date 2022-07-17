$NetBSD$

dump_read_mod requires an extra parameter, "int restrict_", set it to 0
which means "no restrictions"; explained at:

  https://github.com/kode54/dumb/issues/53

--- Engine/media/audio/sound.cpp.orig	2021-12-28 18:32:51.000000000 +0000
+++ Engine/media/audio/sound.cpp
@@ -331,7 +331,7 @@ SOUNDCLIP *my_load_mod(const AssetPath &
         modPtr = dumb_read_s3m(df);
     }
     else if (charAfterDot == 'M') {
-        modPtr = dumb_read_mod(df);
+        modPtr = dumb_read_mod(df, 0);
     }
 
     dumbfile_close(df);
