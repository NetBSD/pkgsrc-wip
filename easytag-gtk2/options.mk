# $NetBSD: options.mk,v 1.1 2005/09/06 12:56:13 leonardschmidt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.easytag-gtk2
PKG_SUPPORTED_OPTIONS=	flac ogg
PKG_SUGGESTED_OPTIONS=	flac ogg

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mflac)
.  include "../../audio/flac/buildlink3.mk"
.  include "../../audio/libvorbis/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-flac
.else
CONFIGURE_ARGS+=	--disable-flac
.endif

.if !empty(PKG_OPTIONS:Mogg)
.  include "../../audio/libvorbis/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ogg
.else
CONFIGURE_ARGS+=	--disable-ogg
.endif
