# $NetBSD$

DISTNAME=	eemeter-0.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	https://pypi.python.org/packages/fb/06/8d0cd92b267ef962a6db224d80ea3870df03239fd34c6b25d33dbda20154/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/openeemeter/eemeter/
COMMENT=	Open Energy Efficiency Meter
LICENSE=	mit

WRKSRC=		${WRKDIR}/eemeter-0.5.3
USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-requests>=2.12.4:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-statsmodels-[0-9]*:../../math/py-statsmodels
DEPENDS+=       ${PYPKGPREFIX}-numexpr-[0-9]*:../../math/py-numexpr
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=       ${PYPKGPREFIX}-scipy>=0.7:../../math/py-scipy
DEPENDS+=       ${PYPKGPREFIX}-pytz>=1.5:../../time/py-pytz
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
