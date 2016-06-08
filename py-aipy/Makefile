# $NetBSD$

DISTNAME=	aipy-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aipy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://casper.berkeley.edu/astrobaki/index.php/AIPY
COMMENT=	Astronomical Interferometry in Python
LICENSE=	gnu-gpl-v2

#DEPENDS+=	${PYPKGPREFIX}-fits>=3.2:../../graphics/py-fits

USE_LANGUAGES=	c c++

PYDISTUTILSPKG=	yes
PYTHON_VERSIONED_DEPENDENCIES=	ephem

BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
