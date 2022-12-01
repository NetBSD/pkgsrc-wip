# $NetBSD$

DISTNAME=	bsdfetch-0.9
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=jhx0/}
GITHUB_TAG=	9840c3153fcf49150ebcee94f527f4ebcc0b8c1b

MAINTAINER=	vms@retrobsd.ddns.net
HOMEPAGE=	https://github.com/jhx0/bsdfetch/
COMMENT=	BSD system information tool written in C
LICENSE=	isc

ONLY_FOR_PLATFORM+=	FreeBSD-*-*
ONLY_FOR_PLATFORM+=	NetBSD-*-*
ONLY_FOR_PLATFORM+=	OpenBSD-*-*
ONLY_FOR_PLATFORM+=	DragonFly-*-*

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsdfetch ${DESTDIR}/${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
