# $NetBSD$

DISTNAME=	docker-cli-20.10.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=docker/}
GITHUB_PROJECT=	cli
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://github.com/docker/cli/
COMMENT=	Command-line tool for controlling Docker
LICENSE=	apache-2.0

GO_DIST_BASE=	cli-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/docker/cli

INSTALLATION_DIRS+=	bin

#pre-extract:
#	${MKDIR} ${WRKDIR}/src/github.com/docker/cli

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/docker ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
