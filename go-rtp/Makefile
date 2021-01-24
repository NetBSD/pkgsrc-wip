# $NetBSD$

DISTNAME=	rtp-1.6.2
PKGNAME=	go-${DISTNAME}
GITHUB_PROJECT=	rtp
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=pion/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/pion/rtp/
COMMENT=	Go implementation of RTP
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/pion/rtp

.include "../../wip/go-randutil/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
