# $NetBSD$

DISTNAME=	chartsrv-1.0.2
CATEGORIES=	www
MASTER_SITES=	-https://git.sr.ht/~sircmpwn/chartsrv/archive/${PKGVERSION_NOREV}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~sircmpwn/chartsrv/
COMMENT=	Daemon which renders SVG plots from Prometheus data
LICENSE=	mit

GO_BUILD_PATTERN+=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
