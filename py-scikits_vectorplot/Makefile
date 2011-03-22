# $NetBSD: Makefile,v 1.1.1.1 2011/03/22 08:21:39 jihbed Exp $
#

DISTNAME=	scikits.vectorplot-0.1.1
PKGNAME=	${PYPKGPREFIX}-scikits_vectorplot-0.1.1
CATEGORIES= math python
MASTER_SITES=	http://pypi.python.org/packages/source/s/scikits.vectorplot/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.scipy.org/scipy/scikits
COMMENT=	Vector fields plotting algorithms
LICENSE=	modified-bsd


PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/scikits.vectorplot-0.1.1

PYTHON_VERSIONS_ACCEPTED= 26 25

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
