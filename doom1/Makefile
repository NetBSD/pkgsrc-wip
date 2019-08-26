# $NetBSD$

DISTNAME=	shareware_doom_iwad
PKGNAME=	doom1-1.9
CATEGORIES=	games
MASTER_SITES=	http://www.doomworld.com/3ddownloads/ports/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://www.doomworld.com/classicdoom/info/shareware.php
COMMENT=	Shareware levels for Doom
#LICENSE=	shareware

CONFLICTS+=	xdoom<1.10nb4
WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	share/doom
NO_BUILD=		YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/DOOM1.WAD \
		${DESTDIR}${PREFIX}/share/doom/doom1.wad

.include "../../mk/bsd.pkg.mk"
