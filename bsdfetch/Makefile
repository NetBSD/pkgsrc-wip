# $NetBSD$

DISTNAME=	bsdfetch-20221123
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=jhx0/}
DIST_SUBDIR=	${PKGNAME_NOREV}
GITHUB_TAG=	c75e286bec960d00f71cb166e59c2af7a71c8835

MAINTAINER=	vms@retrobsd.ddns.net
HOMEPAGE=	https://github.com/jhx0/bsdfetch/
COMMENT=	BSD system information tool written in C
LICENSE=	isc

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsdfetch ${DESTDIR}/${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
