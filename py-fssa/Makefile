# $NetBSD$

DISTNAME=	fssa-0.7.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/f/fssa/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/packages/source/f/fssa/
COMMENT=	Package for finite-size scaling analysis at phase transitions
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-future>=0.15.2:../../devel/py-future

WRKSRC=		${WRKDIR}/fssa-0.7.4

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
