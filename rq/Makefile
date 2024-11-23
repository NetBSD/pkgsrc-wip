# $NetBSD$

DISTNAME=	rq-0.0.10
CATEGORIES=	devel
MASTER_SITES=	-https://git.sr.ht/~charles/rq/archive/v${PKGVERSION_NOREV}.tar.gz

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~charles/rq
COMMENT=	Rego Query
LICENSE=	mit

WRKSRC=		${WRKDIR}/${PKGBASE}-v${PKGVERSION_NOREV}

GO_BUILD_PATTERN+=	./cmd/rq

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
