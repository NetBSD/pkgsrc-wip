# $NetBSD: Makefile,v 1.4 2003/07/18 04:34:08 bencollver Exp $
#

DISTNAME=		vcdgear16_static-e
PKGNAME=		vcdgear-1.6e
CATEGORIES=		sysutils
MASTER_SITES=		http://www.vcdgear.com/files/

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		http://www.vcdgear.com
COMMENT=		Video CD toolbox and MPEG repair tool

ONLY_FOR_PLATFORM=	NetBSD-*-i386
ONLY_FOR_PLATFORM+=	Linux-*-i[3-6]86

NO_BUILD=		YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vcdgear16 ${PREFIX}/bin
	${LN} -s vcdgear16 ${PREFIX}/bin/vcdgear
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vcdgear
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${PREFIX}/share/doc/vcdgear
	${INSTALL_DATA} ${WRKSRC}/FAQ ${PREFIX}/share/doc/vcdgear
	${INSTALL_DATA} ${WRKSRC}/HISTORY ${PREFIX}/share/doc/vcdgear
	${INSTALL_DATA} ${WRKSRC}/MANUAL ${PREFIX}/share/doc/vcdgear
	${INSTALL_DATA} ${WRKSRC}/WHATSNEW ${PREFIX}/share/doc/vcdgear

.include "../../mk/bsd.pkg.mk"
