# $NetBSD$

GITHUB_PROJECT=	libzahl
DISTNAME=	1.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel math
MASTER_SITES=	${MASTER_SITE_GITHUB:=maandree/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://libs.suckless.org/libzahl/
COMMENT=	Library for arbitrary size integers, bigint
LICENSE=	isc

USE_TOOLS+=	gmake

WRKSRC=	${WRKDIR}/libzahl-1.0

do-build:
	cd ${WRKSRC} && ${MAKE_PROGRAM} CONFIG=config.mk libzahl.a

do-install:
	cd ${WRKSRC} && ${MAKE_PROGRAM} CONFIG=config.mk DESTDIR=${DESTDIR} PREFIX=${PREFIX} MANPREFIX=${PREFIX}/${PKGMANDIR} install

.include "../../mk/bsd.pkg.mk"
