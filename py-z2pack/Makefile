# $NetBSD$

DISTNAME=	z2pack-1.1.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=z/z2pack/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://z2pack.ethz.ch
COMMENT=	Computation of topological numbers of band-structures
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-decorator>=3.4.0:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
