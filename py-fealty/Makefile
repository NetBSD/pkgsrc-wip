# $NetBSD$

DISTNAME=	fealty-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fealty/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/eddiejessup/fealty
COMMENT=	Discretised field utilities
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-ciabatta>=0.4.0:../../wip/py-ciabatta

WRKSRC=	${WRKDIR}/fealty-0.1.2

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
