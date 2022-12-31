# $NetBSD$

DISTNAME=	venom-1.1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ovh/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ovh/venom
COMMENT=	Manage and run your integration tests with efficiency
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/ovh/venom.Version=${GITHUB_TAG}'
GO_BUILD_PATTERN+=	./cmd/venom

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
