# $NetBSD$

DISTNAME=	rtcp-1.2.6
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	rtcp
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=pion/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/pion/rtcp/
COMMENT=	Go implementation of RTCP
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/pion/rtcp

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
