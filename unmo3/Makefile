# $NetBSD: Makefile,v 1.2 2004/01/07 15:00:17 bencollver Exp $
#

DISTNAME=		unmo318
PKGNAME=		unmo3-1.8
WRKSRC=			${WRKDIR}
CATEGORIES=		audio archivers
MASTER_SITES=		http://www.un4seen.com/files/ \
			http://www.un4seen.co.uk/files/
EXTRACT_SUFX=		.zip

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		http://www.un4seen.com/mo3.html
COMMENT=		MO3 decoder

BUILD_DEPENDS+=		upx>=1.24:../../archivers/upx

ONLY_FOR_PLATFORM=	NetBSD-*-i386
ONLY_FOR_PLATFORM+=	Linux-*-i[3-6]86

LICENSE=		no-profit
NO_BUILD=		YES
CHECK_SHLIBS=		NO

do-install:
	${PREFIX}/bin/upx -d ${WRKSRC}/unmo3
	${INSTALL_PROGRAM} ${WRKSRC}/unmo3 ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/unmo3
	${INSTALL_DATA} ${WRKSRC}/unmo3.txt ${PREFIX}/share/doc/unmo3

.include "../../mk/bsd.pkg.mk"
