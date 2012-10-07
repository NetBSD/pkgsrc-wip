# $NetBSD: Makefile,v 1.3 2012/10/07 13:57:29 asau Exp $
#

DISTNAME=	scikits.vectorplot-0.1.1
PKGNAME=	${PYPKGPREFIX}-scikits_vectorplot-0.1.1
CATEGORIES= math python
MASTER_SITES=	http://pypi.python.org/packages/source/s/scikits.vectorplot/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.scipy.org/scipy/scikits
COMMENT=	Vector fields plotting algorithms
LICENSE=	modified-bsd

WRKSRC=	${WRKDIR}/scikits.vectorplot-0.1.1

PYTHON_VERSIONS_ACCEPTED= 26

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
