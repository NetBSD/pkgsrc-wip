# $NetBSD$

DISTNAME=	err113
PKGNAME=	err113-20210110
GITHUB_PROJECT=	go-err113
GITHUB_TAG=	aea10b59be24dbccef6788e95bb147053c8c774c
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Djarvur/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Djarvur/go-err113/
COMMENT=	Golang linter to check the errors handling expressions
LICENSE=	mit

GO_SRCPATH=	github.com/Djarvur/go-err113
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}

.include "../../devel/go-mod/buildlink3.mk"
.include "../../devel/go-tools/buildlink3.mk"
.include "../../devel/go-xerrors/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
