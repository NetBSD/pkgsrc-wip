# $NetBSD: Makefile,v 1.4 2012/10/16 12:33:35 jihbed Exp $
#

DISTNAME=	scikits.vectorplot-0.1.1
PKGNAME=	${PYPKGPREFIX}-scikits_vectorplot-0.1.1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikits.vectorplot/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.scipy.org/scipy/scikits
COMMENT=	Vector fields plotting algorithms
LICENSE=	modified-bsd

WRKSRC=	${WRKDIR}/scikits.vectorplot-0.1.1


.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
