# $NetBSD$

DISTNAME=	sympy_to_c-0.1.0
PKGNAME=	${PYPKGPREFIX}-sympy-to-c-0.1.0
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/1f/3f/00de875434f977e8d364eb7466e599e29c3dc4c72842a8137357d7ac453e/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://files.pythonhosted.org/packages/1f/3f/00de875434f977e8d364eb7466e599e29c3dc4c72842a8137357d7ac453e/
COMMENT=	Simple library to create importable C-functions from sympy
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-sympy>=1.2:../../math/py-sympy

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
