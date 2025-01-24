$NetBSD$

2024-01-24: Patch modified for FLTK 1.4

--- GUI/Widgets/Fl_LED_Button.cxx.orig	2001-04-19 20:48:11.000000000 +0000
+++ GUI/Widgets/Fl_LED_Button.cxx
@@ -3,7 +3,7 @@
 #include "Fl_LED_Button.H"
 #include <FL/fl_draw.H>
 
-Fl_LED_Button::Fl_LED_Button(int x, int y, int w, int h, const char* l=0):Fl_Light_Button(x,y,w,h,l) {
+Fl_LED_Button::Fl_LED_Button(int x, int y, int w, int h, const char* l):Fl_Light_Button(x,y,w,h,l) {
   box(FL_NO_BOX);
 	down_box(FL_ROUND_DOWN_BOX);
 	selection_color(FL_RED);
@@ -15,7 +15,7 @@ Fl_LED_Button::~Fl_LED_Button() {
 void Fl_LED_Button::draw() {
   uchar r,g,b;
 
-	if (box()) draw_box(this==Fl::pushed() ? down(box()) : box(), color());
+	if (box()) draw_box(this==Fl::pushed() ? down_box() : box(), color());
 	Fl_Color col = value() ? selection_color() : color();
 	Fl::get_color((Fl_Color)selection_color(),r,g,b);
 	int d = h()/6;
@@ -25,7 +25,7 @@ void Fl_LED_Button::draw() {
 	int y1 = y()+d+3;
 	int ww = W-2*d-6;
 	int hh = W-2*d-6;
-	Fl::get_color(parent()->color(),r,g,b);
+	Fl::get_color(color(),r,g,b);
 	modulate(-90,r,g,b);
 	fl_pie(x1-1,y1-1,ww+2,hh+2,0,360);
 	Fl::get_color((Fl_Color)selection_color(),r,g,b);
