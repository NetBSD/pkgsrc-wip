# $NetBSD: options.mk,v 1.1 2015/09/06 20:10:45 yhardy Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.commandergenius
PKG_SUPPORTED_OPTIONS=	ogg
PKG_SUGGESTED_OPTIONS=	ogg

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mogg)
CMAKE_CONFIGURE_ARGS+=	-DOGG=Yes
.include "../../audio/libvorbis/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DOGG=No
.endif
