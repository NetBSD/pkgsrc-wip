# $NetBSD$

DISTNAME=	go-color-1.10.0
GITHUB_PROJECT=	color
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=fatih/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/fatih/color/
COMMENT=	Color package for Go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/fatih/color


.include "../../devel/go-colorable/buildlink3.mk"
.include "../../devel/go-isatty/buildlink3.mk"
.include "../../devel/go-sys/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
