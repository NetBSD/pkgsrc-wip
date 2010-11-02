# $NetBSD: options.mk,v 1.1 2010/11/02 13:24:38 silasdb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opencascade
PKG_SUPPORTED_OPTIONS=	x11 debug
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
PLIST.x11=		yes
.include "../../graphics/Mesa/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
INSTALL_UNSTRIPPED=	yes
.endif
