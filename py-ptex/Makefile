# $NetBSD$

DISTNAME=	pyptex-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	print python
MASTER_SITES=	https://files.pythonhosted.org/packages/03/a9/69448ed93c993c9752d5d31ce5e8918b13dd0fc685bbe474a3f9b2411a13/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/sloisel/pyptex
COMMENT=	Python Preprocessor for (La)TeX
LICENSE=	mit

DEPENDS+=       ${PYPKGPREFIX}-sympy>=1.5.1:../../math/py-sympy

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
