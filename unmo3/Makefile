# $NetBSD: Makefile,v 1.5 2012/10/07 17:25:49 asau Exp $
#

DISTNAME=		unmo318
PKGNAME=		unmo3-1.8
WRKSRC=			${WRKDIR}
CATEGORIES=		audio archivers
MASTER_SITES=		http://www.un4seen.com/files/ \
			http://www.un4seen.co.uk/files/
EXTRACT_SUFX=		.zip

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		https://www.un4seen.com/mo3.html
COMMENT=		MO3 decoder
LICENSE=		no-profit

BUILD_DEPENDS+=		upx>=1.24:../../archivers/upx

ONLY_FOR_PLATFORM=	NetBSD-*-i386
ONLY_FOR_PLATFORM+=	Linux-*-i[3-6]86

CHECK_SHLIBS=		NO

do-build:
	${PREFIX}/bin/upx -d ${WRKSRC}/unmo3

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unmo3 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/unmo3
	${INSTALL_DATA} ${WRKSRC}/unmo3.txt ${DESTDIR}${PREFIX}/share/doc/unmo3

.include "../../mk/bsd.pkg.mk"
