# $NetBSD: Makefile,v 1.5 2006/05/19 16:51:27 ykomatsu Exp $
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nestra ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nestra
	${INSTALL_DATA} ${WRKSRC}/BUGS ${PREFIX}/share/doc/nestra
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nestra

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
