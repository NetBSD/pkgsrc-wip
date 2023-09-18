# $NetBSD$

DISTNAME=	rq-0.0.7rc1
CATEGORIES=	devel
MASTER_SITES=	-https://git.sr.ht/~charles/rq/archive/v${PKGVERSION_NOREV:S/rc/-RC/}.tar.gz

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~charles/rq
COMMENT=	Rego Query
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME:S/-/-v/:S/rc/-RC/}

GO_BUILD_PATTERN+=	./cmd/rq

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
