# $NetBSD: Makefile,v 1.8 2014/01/20 12:55:08 thomasklausner Exp $

DISTNAME=	aipy-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	misc python
MASTER_SITES=	http://pypi.python.org/packages/source/a/aipy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://casper.berkeley.edu/astrobaki/index.php/AIPY
COMMENT=	Astronomical Interferometry in Python
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-fits>=2.3.1:../../graphics/py-fits

USE_LANGUAGES=	c c++

PYDISTUTILSPKG=	yes
PYTHON_VERSIONED_DEPENDENCIES=	ephem

BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.0

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
