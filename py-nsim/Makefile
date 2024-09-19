# $NetBSD$

DISTNAME=	nsim-0.1.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nsim/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/mattja/nsim/
COMMENT=	Simulate systems from ODEs or SDEs, analyze time series
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-distob>=0.3.0:../../wip/py-distob
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
