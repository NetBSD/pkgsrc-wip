# $NetBSD$

DISTNAME=	mtail-3.0.0rc48
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV:S/rc/-rc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/mtail
COMMENT=	Extract monitoring data for collection in a timeseries database
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	./cmd/mtail

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
