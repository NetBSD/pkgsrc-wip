# $NetBSD$

DISTNAME=	essm-0.4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/6e/2f/bd6ec3de590af290e6dd2c39d6657518e5fb5c01eb2023fd40ff65f890d9/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://essm.readthedocs.io/en/latest/
COMMENT=	Environmental Science using Symbolic Math
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	${PYPKGPREFIX}-jupyter_core>=4.6.3:../../devel/py-jupyter_core
BUILD_DEPENDS+=	${PYPKGPREFIX}-nbconvert>=5.6.1,:../../www/py-nbconvert
BUILD_DEPENDS+=	${PYPKGPREFIX}-nbsphinx>=0:../../wip/py-nbsphinx
BUILD_DEPENDS+=	${PYPKGPREFIX}-ipython>=7.16.1:../../devel/py-ipython
BUILD_DEPENDS+=	${PYPKGPREFIX}-ipykernel>=5.3.4:../../devel/py-ipykernel
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.5.0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.2.2:../../graphics/py-matplotlib
DEPENDS+=       ${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six

USE_LANGUAGES=	# none

BUILDLINK_DEPENDS.pandoc+=	build
BUILDLINK_API_DEPENDS.pandoc+=	pandoc>=2.9.1
.include "../../converters/pandoc/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
