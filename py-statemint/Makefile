# $NetBSD$

DISTNAME=	StateMint-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	https://files.pythonhosted.org/packages/dc/d7/1ec40d1d1566250b5e2ea73345dee7a40dbfc4caca078bfa69b41c159aff/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/CameronDevine/StateMint
COMMENT=	Library for finding State Space models of dynamical systems
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sympy>=1.2:../../math/py-sympy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
