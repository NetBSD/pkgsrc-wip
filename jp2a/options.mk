# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.jp2a
PKG_SUPPORTED_OPTIONS=	curl curses
PKG_SUGGESTED_OPTIONS=	curses

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Mcurl)
CONFIGURE_ARGS+=	--disable-curl
.endif

.if empty(PKG_OPTIONS:Mcurses)
CONFIGURE_ARGS+=	--disable-termlib
.endif

.if !empty(PKG_OPTIONS:Mcurl)
.include "../../www/curl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mcurses)
.include "../../mk/curses.buildlink3.mk"
.endif
