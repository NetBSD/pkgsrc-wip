# $NetBSD$

DISTNAME=	rigidbodysimulator-0.2.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/c8/b4/7525395470cd0cb5af62dd99274f2f9b33359f4fcb0d6713dc45fad490d1/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/martinlarsalbert/rigidbodysimulator
COMMENT=	Rigidbodysimulator simulator
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-test>=1.5.1:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
