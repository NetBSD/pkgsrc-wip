# $NetBSD$

DISTNAME=	ahoy-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=a/ahoy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/eddiejessup/ahoy
COMMENT=	Agent-based simulations of active particles
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-ciabatta>=0.4.0:../../wip/py-ciabatta
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-wheel>=0.26.0:../../devel/py-wheel


WRKSRC=	${WRKDIR}/ahoy-0.8.2

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
