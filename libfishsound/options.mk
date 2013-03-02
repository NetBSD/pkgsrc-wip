# $NetBSD: options.mk,v 1.1 2013/03/02 15:41:45 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libfish
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
BUILD_DEPENDS+=	valgrind-[0-9]*:../../devel/valgrind
CONFIGURE_ARGS+=	--enable-valgrind-testing
.else
CONFIGURE_ARGS+=	--disable-valgrind-testing
.endif
