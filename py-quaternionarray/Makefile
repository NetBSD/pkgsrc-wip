# $NetBSD: Makefile,v 1.4 2014/05/09 07:38:49 thomasklausner Exp $

DISTNAME=	quaternionarray-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=q/quaternionarray/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://andreazonca.com/software/quaternion-array/
COMMENT=	Python package for fast quaternion arrays math
LICENSE=	gnu-gpl-v3

#DEPENDS+=	${PYPKGPREFIX}-docutils>=0.6:../../textproc/py-docutils

USE_LANGUAGES=	# none
#PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-docutils

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
