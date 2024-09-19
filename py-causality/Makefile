# $NetBSD$

DISTNAME=	causality-0.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/causality/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/akelleh/causality
COMMENT=	Tools for causal analysis
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-decorator>=4.0.10:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-networkx>=1.11:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-patsy>=0.3.0:../../math/py-patsy
DEPENDS+=	${PYPKGPREFIX}-statsmodels>=0.8.0:../../math/py-statsmodels
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.4.0:../../time/py-dateutil

WRKSRC=		${WRKDIR}/causality-0.0.3
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
