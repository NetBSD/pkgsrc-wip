# $NetBSD: options.mk,v 1.2 2013/03/02 23:22:31 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.liboggz
PKG_SUPPORTED_OPTIONS=	valgrind
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mvalgrind)
BUILD_DEPENDS+=	valgrind-[0-9]*:../../devel/valgrind
CONFIGURE_ARGS+=	--enable-valgrind-testing
.else
CONFIGURE_ARGS+=	--disable-valgrind-testing
.endif
