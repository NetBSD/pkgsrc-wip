# $NetBSD: Makefile,v 1.6 2015/02/15 21:07:04 yrmt Exp $

DISTNAME=	signify-31
PKGNAME=	${DISTNAME:S,-,-libbsd-,}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=aperezdc/signify/releases/download/v31/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vms@retrobsd.ddns.net
HOMEPAGE=	https://flak.tedunangst.com/post/signify
COMMENT=	Cryptographically sign and verify files, from OpenBSD
LICENSE=	original-bsd AND modified-bsd AND isc

NOT_FOR_PLATFORM=	M*BSD-*-*

USE_TOOLS+=	pkg-config
USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE+=	libwaive/libwaive.pc.in
BUILDLINK_API_DEPENDS.libbsd+=   libbsd>=0.11.0

MAKEFLAGS+=	LTO=1

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/signify ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/signify.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

do-test:
	cd ${WRKSRC}/regress && ${SH} ./run

.include "../../devel/libbsd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
