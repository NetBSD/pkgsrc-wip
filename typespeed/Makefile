# $NetBSD: Makefile,v 1.12 2006/10/09 14:12:01 h2m Exp $
#

DISTNAME=		typespeed-0.5.3
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://tobias.eyedacor.org/typespeed/

MAINTAINER=		hernani@vecirex.net
HOMEPAGE=		http://tobias.eyedacor.org/typespeed/
COMMENT=		Game to measure your typing speed, with network mode

USE_LANGUAGES+=         c

SUBST_CLASSES+=		man-paths
SUBST_STAGE.man-paths=	pre-patch
SUBST_FILES.man-paths=	typespeed.6
SUBST_SED.man-paths=	-e 's|/etc/|${PREFIX}/etc/|g'
SUBST_SED.man-paths+=	-e 's|/usr/local|${PREFIX}|g'
SUBST_MESSAGE.man-paths=	Adjusting paths in the game's man page

SUBST_CLASSES+=		prefixpath
SUBST_STAGE.prefixpath=	post-patch
SUBST_FILES.prefixpath=	Makefile
SUBST_SED.prefixpath=	-e 's|/usr/local|${PREFIX}|g'
SUBST_MESSAGE.prefixpath=	Adjusting prefix path

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
