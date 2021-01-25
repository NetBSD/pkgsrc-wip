# $NetBSD$

DISTNAME=	jsoncolor-0.3.0
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	jsoncolor
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=nwidger/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://godoc.org/github.com/nwidger/jsoncolor
COMMENT=	Colorized JSON output for Go
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/nwidger/jsoncolor

.include "../../wip/go-color/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
