# $NetBSD: Makefile,v 1.16 2021/01/27 13:35:58 leot Exp $

DISTNAME=	terrascan-1.13.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=accurics/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/accurics/terrascan
COMMENT=	Static code analyzer for Infrastructure as Code
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	cmd/terrascan/main.go

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/main ${DESTDIR}${PREFIX}/bin/terrascan

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
