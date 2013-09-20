# $NetBSD: Makefile,v 1.1 2013/09/20 09:55:29 jihbed Exp $

DISTNAME=	pymbolic-2013.3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/p/pymbolic/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://mathema.tician.de/software/pymbolic
COMMENT=	Python package for symbolic computation
LICENSE=	mit

WRKSRC=		${WRKDIR}/pymbolic-2013.3.5

USE_LANGUAGES=	# none


.include "../../lang/python/egg.mk"
DEPENDS+=       ${PYPKGPREFIX}-pytest>=2.3.5:../../devel/py-test
DEPENDS+=       ${PYPKGPREFIX}-pytools>=2013.5.6:../../wip/py-pytools
.include "../../mk/bsd.pkg.mk"
