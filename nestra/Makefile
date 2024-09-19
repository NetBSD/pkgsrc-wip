# $NetBSD: Makefile,v 1.6 2012/10/03 17:43:18 asau Exp $
#

DISTNAME=		nestra-0.66
CATEGORIES=		emulators
MASTER_SITES=		http://nestra.linuxgames.com/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://nestra.linuxgames.com/
COMMENT=		NES emulator (without sound)

ONLY_FOR_PLATFORM=	*-*-i386

WRKSRC=			${WRKDIR}/nestra

BUILD_TARGET=		nestra

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nestra ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/nestra
	${INSTALL_DATA} ${WRKSRC}/BUGS ${DESTDIR}${PREFIX}/share/doc/nestra
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/nestra

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
