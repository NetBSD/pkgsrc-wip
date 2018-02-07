# $NetBSD$

DISTNAME=	cva-0.9.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/12/52/3297aa6eb20d56417e8d02f001d2e3edb72b63762d1f6ee2d042f050797b/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/robertjw/
COMMENT=	Calculus of Variations Solver
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
