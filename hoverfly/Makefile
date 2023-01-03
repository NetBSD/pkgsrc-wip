# $NetBSD$

DISTNAME=	hoverfly-1.4.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=SpectoLabs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hoverfly.io/
COMMENT=	Lightweight API simulation tool for developers and testers
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X main.hoverctlVersion=${GITHUB_TAG}'
GO_BUILD_PATTERN+=	./core/cmd/hoverfly
GO_BUILD_PATTERN+=	./hoverctl

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
