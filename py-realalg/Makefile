# $NetBSD$

DISTNAME=	realalg-0.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/87/9c/315bcff465d24d141f8632a76ff67def808747cada69f1a31bc29c275b5e/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/MarkCBell/realalg
COMMENT=	For manipulating real algebraic numbers
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-sympy>=1.6.2:../../math/py-sympy

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-numpy+=	${PYPKGPREFIX}-numpy>=1.15.1
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
