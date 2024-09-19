# $NetBSD$

DISTNAME=	go-mock-1.5.0
GITHUB_PROJECT=	mock
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=golang/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/golang/mock
COMMENT=	Mocking framework for Go
LICENSE=	apache-2.0

GO_BUILD_PATTERN=	./mockgen

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
