# $NetBSD$

DISTNAME=	hyperbolic-1.0.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/11/e7/481cc9380dce4fbe47a69f245eb8ad9d32a6db056a0f6555d5a33ea1b7c2/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/cduck/hyperbolic
COMMENT=	Python library for generating hyperbolic geometry
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
