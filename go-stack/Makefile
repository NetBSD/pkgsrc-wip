# $NetBSD$

DISTNAME=	go-stack-1.8.0
GITHUB_PROJECT=	stack
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=go-stack/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/go-stack/stack/
COMMENT=	Utilities to capture, manipulate, and format call stacks
LICENSE=	mit

GO_DIST_BASE=   ${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=     github.com/stack/${GITHUB_PROJECT}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
