# $NetBSD: Makefile,v 1.7 2010/12/26 05:01:22 davesainty Exp $
#

DISTNAME=	jp2a-1.0.6
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jp2a/}

MAINTAINER=	emil@math.su.se
HOMEPAGE=	http://jp2a.sourceforge.net/
COMMENT=	JPEG to ASCII converter

PKG_DESTDIR_SUPPORT=	user-destdir

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

.include "../../mk/jpeg.buildlink3.mk"

.if !empty(PKG_OPTIONS:Mcurl)
.include "../../www/curl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mcurses)
.include "../../mk/curses.buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
