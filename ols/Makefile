# $NetBSD$

DISTNAME=	ols-0.0.0.2213
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=DanielGavin/}
GITHUB_TAG=	fe4c7614d0c154a980158890a404732e45f6b52a

MAINTAINER=		mail@andreasjonsson.se
HOMEPAGE=		https://github.com/DanielGavin/ols
COMMENT=		Language server for Odin
LICENSE=		mit

WRKSRC=			${WRKDIR}/ols-${GITHUB_TAG}

USE_CWRAPPERS=		no

DEPENDS+=	odin-25.8.*:../../wip/odin

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && odin build src -collection:src=src -out:ols -o:speed -define:VERSION=dev-${GITHUB_TAG}
	cd ${WRKSRC} && odin build tools/odinfmt/main.odin -file -collection:src=src -out:odinfmt -o:speed

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ols ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/odinfmt ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
