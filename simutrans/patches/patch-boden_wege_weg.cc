$NetBSD$

--- boden/wege/weg.cc.orig	2017-03-04 01:40:29.000000000 +0000
+++ boden/wege/weg.cc
@@ -420,9 +420,6 @@ void weg_t::unlock_mutex()
 
 void weg_t::calc_image()
 {
-#ifdef MULTI_THREAD
-	pthread_mutex_lock( &weg_calc_image_mutex );
-#endif
 	grund_t *from = welt->lookup(get_pos());
 	grund_t *to;
 	image_id old_image = image;
@@ -434,9 +431,6 @@ void weg_t::calc_image()
 		if(  from==NULL  ) {
 			dbg->error( "weg_t::calc_image()", "Own way at %s not found!", get_pos().get_str() );
 		}
-#ifdef MULTI_THREAD
-		pthread_mutex_unlock( &weg_calc_image_mutex );
-#endif
 		return;	// otherwise crashing during enlargement
 	}
 	else if(  from->ist_tunnel() &&  from->ist_karten_boden()  &&  (grund_t::underground_mode==grund_t::ugm_none || (grund_t::underground_mode==grund_t::ugm_level && from->get_hoehe()<grund_t::underground_level))  ) {
