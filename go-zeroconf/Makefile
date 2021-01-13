# $NetBSD$

DISTNAME=	go-zeroconf-1.0.0
GITHUB_PROJECT=	zeroconf
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=grandcat/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/grandcat/zeroconf/
COMMENT=	Is a pure Golang library that employs Multicast DNS-SD
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/grandcat/zeroconf

.include "../../net/go-dns/buildlink3.mk"
.include "../../net/go-net/buildlink3.mk"
.include "../../wip/go-backoff/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
