# $NetBSD$

DISTNAME=	docker-machine-0.16.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=docker/}
GITHUB_PROJECT=	machine
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/docker/machine/
COMMENT=	Machine management for a container-centric world
LICENSE=	apache-2.0

GO_DIST_BASE=	machine-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/docker/machine

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/docker-machine ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
