# $NetBSD$

DISTNAME=	cdncheck-1.4.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=projectdiscovery/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/projectdiscovery/cdncheck
COMMENT=	Utility to detect various technology for a given IP address
LICENSE=	mit

GO_BUILD_PATTERN+=	./cmd/cdncheck

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
