# $NetBSD: Makefile,v 1.1.1.1 2003/04/12 12:49:08 virtus Exp $
#

DISTNAME=		vcdgear16_static-e
PKGNAME=		vcdgear-1.6e
CATEGORIES=		sysutils
MASTER_SITES=		http://www.vcdgear.com/files/

MAINTAINER=		collver1@attbi.com
HOMEPAGE=		http://www.vcdgear.com
COMMENT=		the video cd toolbox

ONLY_FOR_PLATFORM=	NetBSD-*-i386

do-build:

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vcdgear16 ${PREFIX}/bin
	${LN} -s vcdgear16 ${PREFIX}/bin/vcdgear
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vcdgear
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${WRKSRC}/FAQ ${WRKSRC}/HISTORY \
		${WRKSRC}/MANUAL ${WRKSRC}/WHATSNEW ${PREFIX}/share/doc/vcdgear

.include "../../mk/bsd.pkg.mk"
