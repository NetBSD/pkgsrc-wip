# $NetBSD$

DISTNAME=	nsim-0.1.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nsim/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/mattja/nsim/
COMMENT=	Simulate systems from ODEs or SDEs, analyze time series
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-distob>=0.3.0:../../wip/py-distob

USE_LANGUAGES=	# none

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
