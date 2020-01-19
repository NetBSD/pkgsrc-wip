# $NetBSD$

DISTNAME=	hamopy-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hamopy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://srouchier.github.io/hamopy/
COMMENT=	Heat, air and moisture transfer modelling in python
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.0:../../math/py-scipy

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
