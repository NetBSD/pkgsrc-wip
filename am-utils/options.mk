# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.am-utils
PKG_SUPPORTED_OPTIONS=	hesiod
PKG_SUGGESTED_OPTIONS=	hesiod

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mhesiod)
.include "../../net/hesiod/buildlink3.mk"
CONFIGURE_ARGS+=	--with-hesiod
.else
CONFIGURE_ARGS+=	--without-hesiod
.endif
