# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:29 asau Exp $
#

DISTNAME=	quaternionarray-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/q/quaternionarray/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://andreazonca.com/software/quaternion-array/
COMMENT=	Python package for fast quaternion arrays math
LICENSE=	gnu-gpl-v3

#DEPENDS+=	${PYPKGPREFIX}-docutils>=0.6:../../textproc/py-docutils

WRKSRC=		${WRKDIR}/quaternionarray-0.6.1
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
