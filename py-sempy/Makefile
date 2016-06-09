# $NetBSD: Makefile,v 1.3 2013/07/26 21:25:58 jihbed Exp $
#

DISTNAME=	sempy-0.0.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sempy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/s/sempy/
COMMENT=	Python implementation of the spectral element method
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/sempy-0.0.18

USE_LANGUAGES=	# none

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
