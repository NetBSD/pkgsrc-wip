# $NetBSD$

GITHUB_PROJECT=	cli
GITHUB_TAG=	v20.10.0-rc1
DISTNAME=	v20.10.0-rc1
PKGNAME=	docker-cli-${DISTNAME:S,^v,,}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=docker/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://github.com/docker/cli/
COMMENT=	Command-line tool for controlling Docker
LICENSE=	apache-2.0

pre-extract:
	mkdir -p ${WRKDIR}/src/github.com/docker/cli

GO_DIST_BASE=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
GO_SRCPATH=	github.com/docker/cli/

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/docker ${DESTDIR}${PREFIX}/bin

INSTALLATION_DIRS+=	bin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
