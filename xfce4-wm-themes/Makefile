# $NetBSD: Makefile,v 1.11 2011/07/07 18:29:03 reinoudz70 Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/xfce48/Makefile.common"

THEMES_VERSION=	4.6.0

DISTNAME=	xfwm4-themes-${THEMES_VERSION}
PKGNAME=	xfce4-wm-themes-${THEMES_VERSION}
PKGREVISION=	5
CATEGORIES=	wm
COMMENT=	Xfce window manager themes

MASTER_SITES=	http://archive.xfce.org/src/art/xfwm4-themes/4.6/

USE_LANGUAGES=	#empty

MAKE_DIRS+=	${PREFIX}/share/themes/Xfce

.include "../../mk/bsd.pkg.mk"
