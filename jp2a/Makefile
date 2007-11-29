# $NetBSD: Makefile,v 1.2 2007/11/29 16:42:12 emil_s Exp $
#

DISTNAME=	jp2a-1.0.6
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jp2a/}

MAINTAINER=	emil@math.su.se
HOMEPAGE=	http://jp2a.sourceforge.net/
COMMENT=	JPEG to ASCII converter

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

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

.include "../../graphics/jpeg/buildlink3.mk"

.if !empty(PKG_OPTIONS:Mcurl)
.include "../../www/curl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mcurses)
.include "../../mk/curses.buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
