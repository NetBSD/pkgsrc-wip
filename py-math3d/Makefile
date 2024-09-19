# $NetBSD$

DISTNAME=	math3d-3.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/da/13/db08737fcb0601c61ee38cec4af4bda1e47de0582b416673cc3698c37d48/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://git.automatics.dyndns.dk/?p=pymath3d.git
COMMENT=	3D Special Euclidean mathematics package for Python
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
