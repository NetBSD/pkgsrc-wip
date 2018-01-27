# $NetBSD$

DISTNAME=	symcxx-0.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=s/symcxx/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/bjodah/
COMMENT=	SymCXX is an experimental Python for symbolic manipulation
LICENSE=	modified-bsd

#DEPENDS+=	sympy>=1.0:../../math/py-sympy

USE_LANGUAGES=	c c++

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
