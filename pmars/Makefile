# $NetBSD: Makefile,v 1.2 2006/04/20 13:36:43 cheusov Exp $
#

PKGNAME=	pmars-0.8.6
DISTNAME=		pmars-0_8_6_tar
CATEGORIES=		wip games
MASTER_SITES=		http://www.koth.org/pmars/
EXTRACT_SUFX=		.gz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.koth.org/pmars/
COMMENT=		The official Core Wars simulator

WRKSRC=		${WRKDIR}/${PKGNAME}
USE_TOOLS+=		pkg-config gmake
MAKEFILE=	makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pmars ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/pmars/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/pmars/
	${INSTALL_DATA} ${WRKSRC}/CONTRIB ${PREFIX}/share/pmars/
	${INSTALL_DATA_DIR} ${PREFIX}/share/pmars/warriors
	${INSTALL_DATA} ${WRKSRC}/*.red ${PREFIX}/share/pmars/warriors/
	${INSTALL_MAN} ${WRKSRC}/pmars.6 ${PREFIX}/${PKGMANDIR}/man6

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
