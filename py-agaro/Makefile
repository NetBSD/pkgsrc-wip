# $NetBSD$

DISTNAME=	agaro-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=a/agaro/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/eddiejessup/agaro
COMMENT=	Framework to run models
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-wheel>=0.26.0:../../devel/py-wheel

WRKSRC=		${WRKDIR}/agaro-0.2.0

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
