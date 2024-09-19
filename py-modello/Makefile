# $NetBSD$

DISTNAME=	modello-0.1.0.post1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S\.post1\\}
CATEGORIES=	math
MASTER_SITES=	https://files.pythonhosted.org/packages/74/50/1ae7008ac3864ffcecc8e87ef58c1a2991af2d5e5cc5637e63a644884015/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/Code0x58/modello/
COMMENT=	Sympy expressions in models
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-wheel>=0.32.3:../../devel/py-wheel
#DEPENDS+=	${PYPKGPREFIX}-sympy>=1.2:../../math/py-sympy

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
