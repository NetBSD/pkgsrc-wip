# $NetBSD: Makefile,v 1.3 2003/07/18 03:40:19 bencollver Exp $
#

DISTNAME=		vcdgear16_static-e
PKGNAME=		vcdgear-1.6e
CATEGORIES=		sysutils
MASTER_SITES=		http://www.vcdgear.com/files/

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		http://www.vcdgear.com
COMMENT=		the video cd toolbox

ONLY_FOR_PLATFORM=	NetBSD-*-i386

NO_BUILD=		YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vcdgear16 ${PREFIX}/bin
	${LN} -s vcdgear16 ${PREFIX}/bin/vcdgear
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vcdgear
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${WRKSRC}/FAQ ${WRKSRC}/HISTORY \
		${WRKSRC}/MANUAL ${WRKSRC}/WHATSNEW ${PREFIX}/share/doc/vcdgear

.include "../../mk/bsd.pkg.mk"
