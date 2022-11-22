# $NetBSD$

DISTNAME=	umoci-0.4.7
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=opencontainers/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://umo.ci/
COMMENT=	Tool to modify Open Container images
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/opencontainers/umoci.gitCommit= \
			-X github.com/opencontainers/umoci.version=${PKGVERSION_NOREV}'
GO_BUILD_PATTERN+=	./cmd/umoci

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
