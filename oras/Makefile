# $NetBSD$

DISTNAME=	oras-1.2.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=oras-project/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://oras.land/
COMMENT=	OCI registry client
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X oras.land/oras/internal/version.BuildMetadata=${PKGVERSION_NOREV} \
			-X oras.land/oras/internal/version.GitCommit= \
			-X oras.land/oras/internal/version.GitTreeState=clean'
GO_BUILD_PATTERN+=	./cmd/oras

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
