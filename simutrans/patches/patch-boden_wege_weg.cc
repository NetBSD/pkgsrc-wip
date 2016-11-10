$NetBSD$
Work around threading bug in simutrans
--- boden/wege/weg.cc.orig	2015-11-29 19:41:00.000000000 +0000
+++ boden/wege/weg.cc
@@ -420,9 +420,6 @@ void weg_t::unlock_mutex()
 
 void weg_t::calc_image()
 {
-#ifdef MULTI_THREAD
-	pthread_mutex_lock( &weg_calc_bild_mutex );
-#endif
 	grund_t *from = welt->lookup(get_pos());
 	grund_t *to;
 	image_id old_bild = bild;
@@ -434,9 +431,6 @@ void weg_t::calc_image()
 		if(  from==NULL  ) {
 			dbg->error( "weg_t::calc_bild()", "Own way at %s not found!", get_pos().get_str() );
 		}
-#ifdef MULTI_THREAD
-		pthread_mutex_unlock( &weg_calc_bild_mutex );
-#endif
 		return;	// otherwise crashing during enlargement
 	}
 	else if(  from->ist_tunnel() &&  from->ist_karten_boden()  &&  (grund_t::underground_mode==grund_t::ugm_none || (grund_t::underground_mode==grund_t::ugm_level && from->get_hoehe()<grund_t::underground_level))  ) {
