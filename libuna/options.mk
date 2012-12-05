# $NetBSD: options.mk,v 1.1 2012/12/05 04:23:21 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libuna
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
