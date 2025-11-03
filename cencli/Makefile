# $NetBSD$

DISTNAME=	cencli-0.0.3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=censys/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/censys/cencli
COMMENT=	Censys CLI
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/censys/cencli/internal/version.Version=${GITHUB_TAG} \
			-X github.com/censys/cencli/internal/version.Commit= \
			-X github.com/censys/cencli/internal/version.Date='
GO_BUILD_PATTERN+=	./cmd/cencli

MAKE_ENV+=	CGO_ENABLED=0

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
