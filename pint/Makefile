# $NetBSD$

DISTNAME=	pint-0.46.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=cloudflare/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cloudflare.github.io/pint/
COMMENT=	Prometheus rule linter/validator
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X main.version=${GITHUB_TAG} \
			-X main.commit='
GO_BUILD_PATTERN+=	./cmd/pint

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
