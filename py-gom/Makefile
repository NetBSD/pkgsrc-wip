# $NetBSD$

DISTNAME=	pygom-0.1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/a4/32/f5eb25fd1ee4e2fa2d4a71a9eeb152ec453a5f8610f1d2161382175c1471/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/PublicHealthEngland/pygom
COMMENT=	ODE modeling in Python
#LICENSE=	# TODO: (see mk/license.mk)

#DEPENDS+=       ${PYPKGPREFIX}-enum34>=3.2.2:../../devel/py-enum34
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.2.2:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.25.3:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.4.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.1:../../time/py-dateutil

USE_LANGUAGES=  c c++

BUILDLINK_API_DEPENDS.py-cython+=        ${PYPKGPREFIX}-cython>=0.12.1
.include "../../devel/py-cython/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-numpy+=        ${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
