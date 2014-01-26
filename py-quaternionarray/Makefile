# $NetBSD: Makefile,v 1.3 2014/01/26 15:49:58 thomasklausner Exp $

DISTNAME=	quaternionarray-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/q/quaternionarray/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://andreazonca.com/software/quaternion-array/
COMMENT=	Python package for fast quaternion arrays math
LICENSE=	gnu-gpl-v3

#DEPENDS+=	${PYPKGPREFIX}-docutils>=0.6:../../textproc/py-docutils

USE_LANGUAGES=	# none
#PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-docutils

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
