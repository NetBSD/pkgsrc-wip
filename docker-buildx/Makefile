# $NetBSD$

DISTNAME=	docker-buildx-0.12.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=docker/}
GITHUB_PROJECT=	buildx
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/docker/buildx
COMMENT=	Docker CLI plugin for extended build capabilities with BuildKit
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/docker/buildx/version.Version=TODO \
			-X github.com/docker/buildx/version.Revision=TODO \
			-X github.com/docker/buildx/version.Package=github.com/docker/buildx'
GO_BUILD_PATTERN+=	./cmd/buildx

#INSTALLATION_DIRS+=	bin lib/docker/cli-plugins

#post-install:
#	${MV} ${DESTDIR}${PREFIX}/bin/cmd ${DESTDIR}${PREFIX}/bin/docker-compose
#	${LN} -sf ${DESTDIR}${PREFIX}/bin/docker-compose ${DESTDIR}${PREFIX}/lib/docker/cli-plugins

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
