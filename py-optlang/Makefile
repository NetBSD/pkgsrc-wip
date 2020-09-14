# $NetBSD$

DISTNAME=	optlang-1.4.4
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/13/e4/f755f3cd8371a3cdc620bb8460f8afcd7e0a13b894067cdf12b4740fa740/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/biosustain/optlang
COMMENT=	Formulate optimization problems and solve using SymPy
LICENSE=	apache-2.0

DEPENDS+=       ${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
DEPENDS+=       ${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy
#DEPENDS+=       ${PYPKGPREFIX}-swiglpk>=1.5.1:../../wip/py-swiglpk

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
