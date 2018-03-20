$NetBSD$

--- lib/video.c.orig	2018-03-14 06:17:49.000000000 +0000
+++ lib/video.c
@@ -719,7 +719,7 @@ static int get_filter_str( vlc_object_t 
     module_t *p_obj = module_find( psz_name );
     if( !p_obj )
     {
-        msg_Err( p_parent, "Unable to find filter module \"%s\".", psz_name );
+//        msg_Err( p_parent, "Unable to find filter module \"%s\".", psz_name );
         return VLC_EGENERIC;
     }
 
@@ -737,7 +737,7 @@ static int get_filter_str( vlc_object_t 
     }
     else
     {
-        msg_Err( p_parent, "Unknown video filter type." );
+//        msg_Err( p_parent, "Unknown video filter type." );
         return VLC_EGENERIC;
     }
 
