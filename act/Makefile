# $NetBSD$

DISTNAME=	act-0.2.52
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=nektos/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nektosact.com/
COMMENT=	Run your GitHub Actions locally
LICENSE=	mit

GO_BUILD_PATTERN+=	-ldflags ' \
			-X main.version=${PKGVERSION_NOREV}'

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
