# $NetBSD: Makefile,v 1.43 2026/10/10 17:32:00 leot Exp $

DISTNAME=	vulnx-2.0.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=projectdiscovery/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/projectdiscovery/dnsx
COMMENT=	Modern CLI for exploring vulnerability data
LICENSE=	mit

GO_BUILD_PATTERN+=	./cmd/vulnx

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
