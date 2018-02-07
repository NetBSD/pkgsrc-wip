# $NetBSD$

DISTNAME=	ANNarchy-4.5.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/66/7c/fec2460c9fcd24a96d75160f45703204df93846eda61fa0d20d019e24e81/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.tu-chemnitz.de/informatik/KI/projects/ANNarchy/index.php
COMMENT=	Artificial Neural Networks architect
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.17.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.0:../../math/py-sympy

USE_LANGUAGES=	c c++

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.8.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
