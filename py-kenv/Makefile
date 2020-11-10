# $NetBSD$

DISTNAME=	kenv-0.2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kenv/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/fuodorov/kenv
COMMENT=	Solver of the Kapchinsky-Vladimirsky envelope equation
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-scipy>=1.2.3:../../math/py-scipy

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
