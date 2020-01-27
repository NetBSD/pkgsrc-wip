# $NetBSD: Makefile,v 1.1 2015/08/17 20:49:53 yhardy Exp $

DISTNAME=	rott-1.1.2
CATEGORIES=	games
MASTER_SITES=	http://icculus.org/rott/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://icculus.org/rott/
COMMENT=	Fast scrolling first-person perspective 3D action game
LICENSE=	gnu-gpl-v2

BUILD_DIRS=	rott

USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	bin share/doc/rott ${PKGMANDIR}/man6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rott/rott ${DESTDIR}${PREFIX}/bin/rott
	${INSTALL_DATA} ${WRKSRC}/doc/cheats.txt ${DESTDIR}${PREFIX}/share/doc/rott/cheats.txt
	${INSTALL_DATA} ${WRKSRC}/doc/hacker.txt ${DESTDIR}${PREFIX}/share/doc/rott/hacker.txt
	${INSTALL_DATA} ${WRKSRC}/doc/readme.txt ${DESTDIR}${PREFIX}/share/doc/rott/readme.txt
	${INSTALL_DATA} ${WRKSRC}/doc/wad.txt ${DESTDIR}${PREFIX}/share/doc/rott/wad.txt
	${INSTALL_MAN} ${WRKSRC}/doc/rott.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/rott.6

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
