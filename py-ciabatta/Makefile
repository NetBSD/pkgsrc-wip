# $NetBSD: Makefile,v 1.1 2015/08/11 22:42:24 jihbed Exp $

DISTNAME=	ciabatta-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/source/c/ciabatta/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/eddiejessup/ciabatta
COMMENT=	Miscellaneous shared utilities
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-brewer2mpl>=1.4.1:../../wip/py-brewer2mpl
DEPENDS+=	${PYPKGPREFIX}-wheel>=0.24.0:../../wip/py-wheel

WRKSRC=		${WRKDIR}/ciabatta-0.3.0

USE_LANGUAGES=	# none

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
