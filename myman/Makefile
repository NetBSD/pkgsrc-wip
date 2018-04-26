# $NetBSD$

DISTNAME=	myman-0.7.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=myman/}

HOMEPAGE=	https://myman.sourceforge.io/
COMMENT=	Text-mode video game inspired by Namco's Pac-Man
LICENSE=	mit

HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
