# $NetBSD$

DISTNAME=	err113
PKGREVISION=	1
PKGNAME=	err113-20210110
GITHUB_PROJECT=	go-err113
GITHUB_TAG=	aea10b59be24dbccef6788e95bb147053c8c774c
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Djarvur/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Djarvur/go-err113/
COMMENT=	Golang linter to check error handling expressions
LICENSE=	mit

GO_BUILD_PATTERN=	./cmd/...

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
