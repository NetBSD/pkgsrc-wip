# $NetBSD: Makefile,v 1.1.1.1 2012/01/24 21:31:21 jihbed Exp $
#

DISTNAME=	sempy-0.0.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/s/sempy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pypi.python.org/packages/source/s/sempy/
COMMENT=	Python implementation of the spectral element method

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/sempy-0.0.18

USE_LANGUAGES=	# none

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
