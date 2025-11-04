# $NetBSD$

DISTNAME=	tangled-1.10.0alpha1
CATEGORIES=	devel
GIT_REPO=	https://tangled.org/@tangled.org/core

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tangled.org/
COMMENT=	Tightly-knit social coding
LICENSE=	mit

WRKSRC=		${WRKDIR}/core

GO_BUILD_PATTERN=	./cmd/knot

.include "go-modules.mk"
.include "../../wip/mk/git-package.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
