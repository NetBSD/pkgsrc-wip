# $NetBSD$

DISTNAME=	jennifer-1.4.1
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	jennifer
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=dave/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/dave/jennifer/
COMMENT=	Jennifer is a code generator for Go
#LICENSE=	# TODO: (see mk/license.mk)

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/dave/jennifer

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
