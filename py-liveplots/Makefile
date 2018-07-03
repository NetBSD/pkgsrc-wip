# $NetBSD: Makefile,v 1.4 2014/05/09 07:38:48 thomasklausner Exp $

DISTNAME=	liveplots-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics math python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/liveplots/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/liveplots/
COMMENT=	Real-time live plot server
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-gnuplot-[0-9]*:../../graphics/py-gnuplot

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gnuplot

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
