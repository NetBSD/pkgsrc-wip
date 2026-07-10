# $NetBSD$

DISTNAME=	ols-dev-2026-05
PKGNAME=	${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=DanielGavin/}
GITHUB_PROJECT=	ols
GITHUB_TAG=	refs/tags/dev-2026-05
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	mail@andreasjonsson.se
HOMEPAGE=	https://github.com/DanielGavin/ols/
COMMENT=	Language server for Odin
LICENSE=	mit

WRKSRC=		${WRKDIR}/ols-dev-2026-05

USE_CWRAPPERS=		no

DEPENDS+=	odin-26.7.*:../../wip/odin

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && odin build src -collection:src=src -out:ols -o:speed -define:VERSION=dev-${GITHUB_TAG}
	cd ${WRKSRC} && odin build tools/odinfmt/main.odin -file -collection:src=src -out:odinfmt -o:speed

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ols ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/odinfmt ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
