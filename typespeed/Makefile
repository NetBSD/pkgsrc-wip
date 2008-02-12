# $NetBSD: Makefile,v 1.15 2008/02/12 18:26:32 h2m Exp $
#

DISTNAME=		typespeed-0.6.4
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://tobias.eyedacor.org/typespeed/

MAINTAINER=		hernani@vecirex.net
HOMEPAGE=		http://tobias.eyedacor.org/typespeed/
COMMENT=		Game to measure your typing speed, with network mode

USE_LANGUAGES=		c
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX}

SUBST_CLASSES+=		man-paths
SUBST_STAGE.man-paths=	pre-patch
SUBST_FILES.man-paths=	man/typespeed.6
SUBST_SED.man-paths=	-e 's|/etc/|${PREFIX}/etc/|g'
SUBST_MESSAGE.man-paths=	Adjusting path in the game's man page

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
