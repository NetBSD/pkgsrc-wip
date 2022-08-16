# $NetBSD$

DISTNAME=	1.0.2
PKGNAME=	${DISTNAME:S/^/chartsrv-/}
CATEGORIES=	www
MASTER_SITES=	https://git.sr.ht/~sircmpwn/chartsrv/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~sircmpwn/chartsrv/
COMMENT=	Daemon which renders SVG plots from Prometheus data
LICENSE=	mit

GO_BUILD_PATTERN+=	.

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
