# $NetBSD: Makefile,v 1.2 2004/12/02 16:39:04 thomasklausner Exp $
#

DISTNAME=		nestra-0.66
CATEGORIES=		emulators
MASTER_SITES=		http://nestra.linuxgames.com/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://nestra.linuxgames.com/
COMMENT=		NES emulator (without sound)

ONLY_FOR_PLATFORM=	*-*-i386

WRKSRC=			${WRKDIR}/nestra
USE_BUILDLINK3=		yes
USE_X11=		yes

BUILD_TARGET=		nestra

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nestra ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nestra
	${INSTALL_DATA} ${WRKSRC}/BUGS ${PREFIX}/share/doc/nestra
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nestra

.include "../../mk/bsd.pkg.mk"
