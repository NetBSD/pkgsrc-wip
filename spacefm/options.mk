# $NetBSD: Makefile,v 0.3 2018/09/11 14:44:10 andyb Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.spacefm

PKG_OPTIONS_REQUIRED_GROUPS=    gtk
PKG_OPTIONS_GROUP.gtk=          gtk2 gtk3

PKG_SUGGESTED_OPTIONS=  gtk2

.include "../../mk/bsd.options.mk"

PLIST_VARS+=            gtk3
.if !empty(PKG_OPTIONS:Mgtk2)
CONFIGURE_ARGS+=        --with-gtk2
GTK_CFLAGS=      $(pkg-config --cflags gtk+-2.0)
GTK_LIBS=        $(pkg-config --libs gtk+-2.0)
CFLAGS+=          $(pkg-config --cflags gtk+-2.0) $(pkg-config --cflags glib-2.0) $(pkg-config --cflags gdk) $(pkg-config --cflags libffmpegthumbnailer)
LDFLAG+=         $(pkg-config --libs gtk+-2.0) $(pkg-config --libs glib-2.0) $(pkg-config --libs gdk) $(pkg-config --libs libffmpegthumbnailer)
export FFMPEG_CFLAGS=   $(pkg-config --cflags libffmpegthumbnailer)
export FFMPEG_LIBS=     $(pkg-config --libs libffmpegthumbnailer)
AM_CFLAGS+=      $(pkg-config --cflags gtk+-2.0)
CPPFLAGS+=       $(pkg-config --cflags gtk+-2.0) $(pkg-config --cflags glib-2.0) $(pkg-config --cflags gdk) $(pkg-config --cflags libffmpegthumbnailer)

.include "../../x11/gtk2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=        --with-gtk3
GTK_CFLAGS=      $(pkg-config --cflags gtk+-3.0)
GTK_LIBS=        $(pkg-config --libs gtk+-3.0)
CFLAGS+=          $(pkg-config --cflags gtk+-3.0) $(pkg-config --cflags glib-2.0) $(pkg-config --cflags gdk) $(pkg-config --cflags libffmpegthumbnailer)
LDFLAG+=         $(pkg-config --libs gtk+-3.0) $(pkg-config --libs glib-2.0) $(pkg-config --libs gdk) $(pkg-config --libs libffmpegthumbnailer)
export FFMPEG_CFLAGS=   $(pkg-config --cflags libffmpegthumbnailer)
export FFMPEG_LIBS=     $(pkg-config --libs libffmpegthumbnailer)
AM_CFLAGS+=      $(pkg-config --cflags gtk+-3.0)
CPPFLAGS+=       $(pkg-config --cflags gtk+-3.0) $(pkg-config --cflags glib-2.0) $(pkg-config --cflags gdk) $(pkg-config --cflags libffmpegthumbnailer)

.include "../../x11/gtk3/buildlink3.mk"
PLIST.gtk3=             yes
.endif
