# $NetBSD: options.mk,v 1.1.1.1 2007/11/17 15:50:52 jeremy-c-reed Exp $
#

# see http://www.gnu.org/software/gnash/manual/gnash.html#codedepend

PKG_OPTIONS_VAR=		PKG_OPTIONS.gnash
PKG_SUPPORTED_OPTIONS=		klash mitshm
PKG_OPTIONS_OPTIONAL_GROUPS=	gnash-gui gnash-renderer gnash-media
PKG_OPTIONS_GROUP.gnash-gui=	gtk kde sdl # qt aqua riscos fltk2 fb all
PKG_OPTIONS_GROUP.gnash-renderer=	opengl cairo # agg
PKG_OPTIONS_GROUP.gnash-media=	gstreamer ffmpeg mad
PKG_SUGGESTED_OPTIONS+=         cairo gtk mad

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcairo)
# TODO: check this -- maybe this is needed if gtk is the gui no matter what?
CONFIGURE_ARGS+=	--enable-renderer=cairo
.endif

.if !empty(PKG_OPTIONS:Mklash)
PLIST_SRC+=		${PKGDIR}/PLIST.klash
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
CONFIGURE_ARGS+=	--datadir="${PREFIX}/share"
CONFIGURE_ARGS+=	\
	--with-plugindir=${PREFIX}/share/gnash/plugins
CONFIGURE_ARGS+=	--enable-klash
.else
CONFIGURE_ARGS+=	--disable-klash
#CONFIGURE_ARGS+=	--disable-plugin
.endif

.if !empty(PKG_OPTIONS:Mgtk)
# TODO: another PLIST entry for gtk-gnash
CONFIGURE_ARGS+=	--enable-gui=gtk
.include "../../graphics/gtkglext/buildlink3.mk"
# glib, atk, pango, cairo, gtk2, gtkglext.
.endif

.if !empty(PKG_OPTIONS:Mmad)
CONFIGURE_ARGS+=        --enable-media=mad
.include "../../audio/libmad/buildlink3.mk"
# this needs SDL even if using GTK as user interface
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmitshm)
# check this -- maybe this is the default
CONFIGURE_ARGS+=	--enable-mit-shm
.endif

.if !empty(PKG_OPTIONS:Mopengl)
CONFIGURE_ARGS+=	--enable-renderer=opengl
.endif

# NOTES:
# --disable-nsapi to disable Firefox plugin
# agg uses libagg from http://www.antigrain.com
