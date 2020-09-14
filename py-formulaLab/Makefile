# $NetBSD$

DISTNAME=	FormulaLab-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	https://files.pythonhosted.org/packages/37/95/b301ad2d7659a2c8ac1fd3e652a8deda36b98a5d697bf31b774dd61b1cf5/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://azizalqasem.github.io/FormulaLab/index.html
COMMENT=	Search Engine of Mathmatical Formulas Database
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pandas>=0.25.3:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
