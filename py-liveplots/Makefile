# $NetBSD: Makefile,v 1.3 2014/01/25 10:38:22 thomasklausner Exp $

DISTNAME=	liveplots-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics math python
MASTER_SITES=	http://pypi.python.org/packages/source/l/liveplots/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/liveplots/
COMMENT=	Real-time live plot server
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-multiprocessing-[0-9]*:../../devel/py-multiprocessing
DEPENDS+=	${PYPKGPREFIX}-gnuplot-[0-9]*:../../graphics/py-gnuplot

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-gnuplot, py-multiprocessing

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
