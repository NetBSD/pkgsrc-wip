# $NetBSD$

DISTNAME=	ciabatta-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/source/c/ciabatta/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/eddiejessup/ciabatta
COMMENT=	Miscellaneous shared utilities
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-brewer2mpl>=1.4.1:../../wip/py-brewer2mpl
DEPENDS+=	${PYPKGPREFIX}-wheel>=0.26.0:../../devel/py-wheel

WRKSRC=		${WRKDIR}/ciabatta-0.4.0

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
