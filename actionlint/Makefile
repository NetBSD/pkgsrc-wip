# $NetBSD$

DISTNAME=	actionlint-1.6.13
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rhysd/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rhysd/actionlint
COMMENT=	Static checker for GitHub Actions workflow files
LICENSE=	mit

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/rhysd/actionlint.version=${PKGVERSION_NOREV}'
GO_BUILD_PATTERN+=	./cmd/actionlint

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
