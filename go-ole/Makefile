# $NetBSD$

DISTNAME=	go-ole-1.2.0
GITHUB_PROJECT=	go-ole
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=go-ole/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/go-ole/go-ole/
COMMENT=	Go bindings for Windows COM using shared libraries instead of cgo
LICENSE=	mit

GO_SRCPATH=     github.com/go-ole/go-ole
GO_DIST_BASE=   ${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
