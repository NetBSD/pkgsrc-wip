# $NetBSD$

DISTNAME=	go-err113-0.1.0
GITHUB_PROJECT=	go-err113
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Djarvur/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Djarvur/go-err113/
COMMENT=	Golang linter to check the errors handling expressions
LICENSE=	mit

GO_SRCPATH=	github.com/Djarvur/go-err113
GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../devel/go-mod/buildlink3.mk"
.include "../../devel/go-tools/buildlink3.mk"
.include "../../devel/go-xerrors/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
