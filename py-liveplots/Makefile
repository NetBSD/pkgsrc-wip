# $NetBSD: Makefile,v 1.2 2012/10/07 12:25:15 asau Exp $
#

DISTNAME=	liveplots-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics math python
MASTER_SITES=	http://pypi.python.org/packages/source/l/liveplots/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/liveplots/
COMMENT=	Real-time live plot server
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-multiprocessing>=:../../devel/py-multiprocessing
DEPENDS+=	${PYPKGPREFIX}-gnuplot>=:../../graphics/py-gnuplot

WRKSRC=		${WRKDIR}/liveplots-0.7.1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
