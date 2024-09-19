# $NetBSD$

DISTNAME=	quhep-0.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/1c/bc/f36b95a35ef861cc524e232e9f4a593d2fe973f11e4c7bc62139114ecf65/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/chnzhangrui/quhep
COMMENT=	Quantum Machine Learning Framework for High Energy Physics
LICENSE=	mit

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.13
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
