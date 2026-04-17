# $NetBSD$

DISTNAME=	core-v${VERSION}
PKGNAME=	tangled-${VERSION:S/-alpha/alpha1/}
CATEGORIES=	devel
MASTER_SITES=	-https://tangled.org/tangled.org/core/archive/refs%2Ftags%2Fv${VERSION}
VERSION=	1.13.0-alpha

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tangled.org/
COMMENT=	Tightly-knit social coding
LICENSE=	mit

WRKSRC=		${WRKDIR}

GO_BUILD_PATTERN=	./cmd/knot

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
