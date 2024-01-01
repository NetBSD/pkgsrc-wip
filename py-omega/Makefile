# $NetBSD$

DISTNAME=	omega-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=o/omega/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/omega/
COMMENT=	Specify and synthesize systems using symbolic algorithms
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-networkx>=3.1:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-humanize>=4.9.0:../../textproc/py-humanize
DEPENDS+=	${PYPKGPREFIX}-natsort>=8.4.0:../../textproc/py-natsort

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
