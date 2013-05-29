# $NetBSD: options.mk,v 1.1 2013/05/29 03:01:04 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libclocale
PKG_SUPPORTED_OPTIONS=	nls wide-curses
PKG_SUGGESTED_OPTIONS+=	nls wide-curses

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnls)
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.if !empty(PKG_OPTIONS:Mwide-curses)
CONFIGURE_ARGS+=	--enable-wide-character-type
.endif
