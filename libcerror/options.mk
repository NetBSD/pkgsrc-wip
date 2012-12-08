# $NetBSD: options.mk,v 1.1 2012/12/08 22:41:37 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libcerror
PKG_SUPPORTED_OPTIONS=	nls wide-curses
PKG_SUGGESTED_OPTIONS+=	nls wide-curses

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.if !empty(PKG_OPTIONS:Mwide-curses)
CONFIGURE_ARGS+=	--enable-wide-character-type
.endif
