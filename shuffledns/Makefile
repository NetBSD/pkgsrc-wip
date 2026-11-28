# $NetBSD$

DISTNAME=	shuffledns-1.2.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=projectdiscovery/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/projectdiscovery/shuffledns
COMMENT=	Wrapper around massdns, written in go
LICENSE=	gnu-gpl-v3

GO_BUILD_PATTERN+=	./cmd/shuffledns

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
