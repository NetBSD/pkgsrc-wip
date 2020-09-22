# $NetBSD$

DISTNAME=	jitcdde-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/36/40/bee04a1b1c790188c600284394854b1031ecf41840279d82e1d91f310717/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/neurophysik/jitcdde
COMMENT=	Just-in-Time Compilation for Delay Differential Equations
#LICENSE=	# TODO: (see mk/license.mk)

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-jitcxde-common-1.5.2:../../wip/py-jitcxde-common


BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
