# $NetBSD: Makefile,v 1.1.1.1 2006/12/13 18:34:02 thomasklausner Exp $
#

DISTNAME=	Osmose_0-8-0_src
PKGNAME=	osmose-0.8.0
CATEGORIES=	emulators
MASTER_SITES=	http://bcz.emu-france.com/osmose/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bcz.emu-france.com/index.htm
COMMENT=	Sega Master System/Game Gear emulator

WRKSRC=		${WRKDIR}/Osmose
USE_LANGUAGES=	c c++

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/osmose ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/osmose
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${PREFIX}/share/doc/osmose

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
