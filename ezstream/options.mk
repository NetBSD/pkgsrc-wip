# $NetBSD: options.mk,v 1.1 2012/12/04 00:36:37 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ezstream
PKG_SUPPORTED_OPTIONS=	iconv taglib vorbis
PKG_SUGGESTED_OPTIONS+=	taglib vorbis

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Miconv)
.include "../../converters/libiconv/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-libiconv
.endif

.if !empty(PKG_OPTIONS:Mtaglib)
.include "../../audio/taglib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-taglib
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
.include "../../audio/libvorbis/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-libvorbis
.endif
