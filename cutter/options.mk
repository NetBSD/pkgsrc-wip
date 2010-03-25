# $NetBSD: options.mk,v 1.1.1.1 2010/03/25 09:13:04 obache Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.cutter
PKG_SUPPORTED_OPTIONS=	goffice gstreamer libsoup
PKG_SUGGESTED_OPTIONS=	#

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	goffice gst gtk soup

###
### goffice support
###
.if !empty(PKG_OPTIONS:Mgoffice)
.include "../../misc/goffice0.6/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-goffice
PLIST.gtk=		yes
.else
CONFIGURE_ARGS+=	--disable-goffice
.endif

###
### gstreamer support
###
.if !empty(PKG_OPTIONS:Mgstreamer)
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gstreamer
PLIST.gst=		yes
.else
CONFIGURE_ARGS+=	--disable-gstreamer
.endif

###
### libsoup support
###
.if !empty(PKG_OPTIONS:Mlibsoup)
.  include "../../net/libsoup24/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libsoup
PLIST.soup=		yes
PLIST.gtk=		yes
.else
CONFIGURE_ARGS+=	--disable-libsoup
.endif
