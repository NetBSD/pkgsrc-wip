# $NetBSD$

DISTNAME=	safersympify-0.1.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://files.pythonhosted.org/packages/32/3c/ac11e9eec6a074c3422d8853071f8825832c871c2048f49967a80f3d2ec3/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/jpackagebot/safersympify
COMMENT=	Safer way to sympify unsanitized input
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-sympy>=1.2:../../math/py-sympy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
