# $NetBSD: options.mk,v 1.1 2013/06/09 21:56:24 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libcfile
PKG_SUPPORTED_OPTIONS=	debug nls static wide-curses
PKG_SUGGESTED_OPTIONS+=	nls static wide-curses

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug-output=yes
.else
CONFIGURE_ARGS+=	--enable-debug-output=no
.endif

.if !empty(PKG_OPTIONS:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.if !empty(PKG_OPTIONS:Mstatic)
CONFIGURE_ARGS+=	--enable-shared=no
.else
CONFIGURE_ARGS+=	--enable-shared=yes
.endif

.if !empty(PKG_OPTIONS:Mwide-curses)
CONFIGURE_ARGS+=	--enable-wide-character-type
.endif
