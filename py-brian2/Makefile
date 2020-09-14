# $NetBSD$

DISTNAME=	Brian2-2.3.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/97/16/eda80475d70da06d59cee1a39192ee117f970eaf18adbf5fa2c926db1713/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://briansimulator.org/
COMMENT=	Clock-driven simulator for spiking neural networks
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=       ${PYPKGPREFIX}-future>=0.18.2:../../devel/py-future
DEPENDS+=       ${PYPKGPREFIX}-pyparsing>=2.4.7:../../devel/py-pyparsing
DEPENDS+=       ${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy
DEPENDS+=       ${PYPKGPREFIX}-jinja2>=2.11.2:../../textproc/py-jinja2

USE_LANGUAGES=	c c++

.include "../../devel/py-cython/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-numpy+=        ${PYPKGPREFIX}-numpy>=1.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
