# $NetBSD: options.mk,v 1.2 2008/02/24 13:52:43 thomasklausner Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.dvtm
PKG_SUPPORTED_OPTIONS=		wide-curses
PKG_SUGGESTED_OPTIONS=		# empty
PKG_LEGACY_OPTS+=		ncursesw:wide-curses

.include "../../mk/bsd.options.mk"

USE_NCURSES=	yes	# mouse extensions (not X/Open Curses compliant)

.if !empty(PKG_OPTIONS:Mwide-curses)
.include "../../devel/ncursesw/buildlink3.mk"
MAKE_FLAGS+=	unicode
.else
.include "../../devel/ncurses/buildlink3.mk"
.endif
